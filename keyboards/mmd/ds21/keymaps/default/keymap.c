/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        //1      2        3        4        5        6        7        8        9        10       11       12       13       14       15       16       17       18       19       20       21

        LT(0, KC_MUTE), LT(1, KC_MPLY), LT(2, KC_MPLY), KC_BSPC,       LT(3, KC_MUTE),

        MO(1),          KC_PSLS,        KC_PAST,        KC_PMNS,
        KC_7,           KC_8,           KC_9,
        KC_4,           KC_5,           KC_6,           KC_PPLS,
        KC_1,           KC_2,           KC_3,           KC_PENT,
        KC_0,                           KC_DOT

    ),
    [1] = LAYOUT(
        //1      2        3        4        5        6        7        8        9        10       11       12       13       14       15       16       17       18       19       20       21
        LT(0, KC_MUTE), LT(1, KC_MPLY), LT(2, KC_MPLY), KC_BSPC,       LT(3, KC_MUTE),
        KC_TRNS,        MO(2),          KC_TRNS,        KC_CALC,
        KC_TRNS,        KC_VOLU,        KC_TRNS,
        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_TRNS,
        KC_TRNS,        KC_VOLD,        KC_TRNS,        KC_TRNS,
        KC_MUTE,                        KC_TRNS

    ),
    [2] = LAYOUT(
        //1      2        3        4        5        6        7        8        9        10       11       12       13       14       15       16       17       18       19       20       21
        LT(0, KC_MUTE), LT(1, KC_MPLY), LT(2, KC_MPLY), KC_BSPC,       LT(3, KC_MUTE),
        KC_TRNS,        KC_TRNS,          MO(3),        RM_VALU,
        RM_TOGG,        RM_SATU,        KC_TRNS,
        RM_HUED,        EE_CLR,         RM_HUEU,        RM_VALD,
        KC_TRNS,        RM_SATD,        KC_TRNS,        KC_TRNS,
        RM_NEXT,                        KC_TRNS

    ),
    [3] = LAYOUT(
        //1      2        3        4        5        6        7        8        9        10       11       12       13       14       15       16       17       18       19       20       21
        LT(0, KC_MUTE), LT(1, KC_MPLY), LT(2, KC_MPLY), KC_BSPC,       LT(3, KC_MUTE),
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        NK_TOGG,                        QK_BOOT

    )

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BSPC, KC_BSPC)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BSPC, KC_BSPC)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BSPC, KC_BSPC)},
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BSPC, KC_BSPC)},
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // num lock white
    /*
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(5, 255, 255, 255);
    }
    */

    // layer state
    switch (get_highest_layer(layer_state)) {
        case 1:
            RGB_MATRIX_INDICATOR_SET_COLOR(16, 255, 255, 255);
            break;
        case 2:
            RGB_MATRIX_INDICATOR_SET_COLOR(17, 255, 255, 255);
            break;
        case 3:
            RGB_MATRIX_INDICATOR_SET_COLOR(18, 255, 255, 255);
            break;
        case 4:
            RGB_MATRIX_INDICATOR_SET_COLOR(13, 255, 255, 255);
            break;
        case 5:
            RGB_MATRIX_INDICATOR_SET_COLOR(14, 255, 255, 255);
            break;
        case 6:
            RGB_MATRIX_INDICATOR_SET_COLOR(15, 255, 255, 255);
            break;
        case 7:
            RGB_MATRIX_INDICATOR_SET_COLOR(9, 255, 255, 255);
            break;

    }
    return false;
}
