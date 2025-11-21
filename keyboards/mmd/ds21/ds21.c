// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later


#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "matrix.h"

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

#ifdef ENCODERS_MATRIX_MAP
static keypos_t encoders_matrix_map[NUM_ENCODERS_MAX_PER_SIDE][2] = ENCODERS_MATRIX_MAP;
#endif

bool encoder_update_kb(uint8_t index, bool clockwise)
{
#ifndef ENCODERS_MATRIX_MAP
    return encoder_update_user(index, clockwise);
#else
    keypos_t key = encoders_matrix_map[index][!clockwise];
    uint8_t layerIndex = layer_switch_get_layer(key);
    uint16_t keycode = keymap_key_to_keycode(layerIndex, key);

    if (keycode != KC_NO)
    {
        tap_code_delay(keycode, 0);
        return false;
    }
    else
    {
        return true;
    }
#endif
}
