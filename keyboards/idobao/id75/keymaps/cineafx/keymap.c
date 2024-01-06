/* Copyright 2018 MechMerlin
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

// qmk compile -kb idobao/id75/v1 -km cineafx

//PTTTGL: Push to talk toggle
enum ptt_states {
    OFF,
    ON
};
int ptt_state = OFF;

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  PTTTGL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_ortho_5x15( \
     KC_F13, KC_F14, KC_F15, MI_C4 , MI_Cs4, MI_D4 , MI_Ds4, MI_E4 , MI_F4 , MI_Fs4, MI_G4 , MI_Gs4, MI_A4 , MI_As4, MI_B4 ,  \
     KC_F16, KC_F17, KC_F18, MI_C3 , MI_Cs3, MI_D3 , MI_Ds3, MI_E3 , MI_F3 , MI_Fs3, MI_G3 , MI_Gs3, MI_A3 , MI_As3, MI_B3 ,  \
     KC_F19, KC_F20, KC_F21, MI_C2 , MI_Cs2, MI_D2 , MI_Ds2, MI_E2 , MI_F2 , MI_Fs2, MI_G2 , MI_Gs2, MI_A2 , MI_As2, MI_B2 ,  \
     KC_F22, KC_F23, KC_F24, MI_C1 , MI_Cs1, MI_D1 , MI_Ds1, MI_E1 , MI_F1 , MI_Fs1, MI_G1 , MI_Gs1, MI_A1 , MI_As1, MI_B1 , \
    KC_BTN5, PTTTGL, KC_ESC, MI_C  , MI_Cs , MI_D  , MI_Ds , MI_E  , MI_F  , MI_Fs , MI_G  , MI_Gs , MI_A  , MI_As , MI_B   \
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PTTTGL:
      if (record->event.pressed) {
        if (ptt_state == ON) {  // it is 1, so you were talking and want to switch it off
          ptt_state = OFF;       // set the new state to OFF
          unregister_code(KC_BTN5);  // toggle M5 off
        } else {  // it is not ON, so you want to talk
          ptt_state = ON;   // set the state to ON
          register_code(KC_BTN5);  // toggle M5 on
        }
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

/*
 [0] = LAYOUT_ortho_5x15( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RCTL, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
*/
