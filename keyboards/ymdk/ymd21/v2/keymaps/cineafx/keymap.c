/* Copyright 2022 QMK / James Young (@noroadsleft)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// qmk compile -kb ymdk/ymd21/v2 -km cineafx

#define DIS_MUT S(KC_F14)
#define DIS_VAD A(KC_F14)
#define TS_MUT S(KC_F15)
#define TS_VAD A(KC_F15)
#define TS_TFAR KC_F16

#define CSF11 C(S(KC_F11))

const uint32_t PROGMEM unicode_map[] = {

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_6x4(
        KC_ESC , KC_TAB , KC_BSPC, MO(1),
        KC_NUM , KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7  , KC_P8  , KC_P9  , KC_NO,
        KC_P4  , KC_P5  , KC_P6  , KC_PPLS,
        KC_P1  , KC_P2  , KC_P3  , KC_NO,
        KC_NO  , KC_P0  , KC_PDOT, KC_PENT
    ),

    [1] = LAYOUT_ortho_6x4(
        KC_CALC, RGB_MOD, RGB_TOG, _______,
        DIS_MUT, TS_MUT , TS_TFAR, CSF11  ,
        DIS_VAD, TS_VAD , _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, QK_BOOT
    ),

};
