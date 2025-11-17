// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later


#include "quantum.h"

void keyboard_pre_init_kb(void) {
    gpio_set_pin_output(A5);
    gpio_write_pin_high(A5);
    gpio_set_pin_output(D2);
    gpio_write_pin_high(D2);
    keyboard_pre_init_user();
}


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case QK_RGB_MATRIX_TOGGLE:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;

        default:
            return true;
    }
}

bool dip_switch_update_mask_kb(uint32_t state) {
    if (!dip_switch_update_mask_user(state)) {
        return false;
    }
    // Check switch position based on both pins
    // Mac mode: C15 (bit 0) high AND C14 (bit 1) low
    bool win_pin = state & (1UL << 0);  // C15
    bool mac_pin = state & (1UL << 1);  // C14

    bool is_mac_mode = win_pin && !mac_pin;

    if (is_mac_mode) {
        default_layer_set(2);
    } else {
        default_layer_set(0);
    }

    return true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock)
        rgb_matrix_set_color(52, 0x20, 0x20, 0x20);

    return true;
}
