#include QMK_KEYBOARD_H
#include "process_unicode.h"
#include <sendstring_german.h>

// qmk compile -kb keebio/iris/rev2 -km cineafx
// make iris/rev2:cineafx

extern keymap_config_t keymap_config;

// Most of this is based on https://gist.github.com/itspngu/9159f06153b440a754b33c6d65c5f302
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOD_L 3
#define _MOD_U 4
#define _MACRO 5

#define CUSTOMMACRO(MACROKEYCODE, DOWN) case MACROKEYCODE : \
      if (record->event.pressed) { \
        DOWN \
      } \
      break;

#define PYRAMID(AMOUNT) \
int i; \
register_code(KC_LCTL); \
for(i = 0; i< AMOUNT ; i++) { \
	tap_code(KC_V); \
	_delay_ms(50); \
	tap_code(KC_ENTER); \
	_delay_ms(50); \
} \
for(i = 0; i< AMOUNT ; i++) { \
	tap_code(KC_BSPC); \
	_delay_ms(50); \
	tap_code(KC_ENTER); \
	_delay_ms(50); \
} \
unregister_code(KC_LCTL);

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MACRO,
  TRUELULW,
  SHRUG,
  HEAD,
  OKAY,
  FDM,
  PP_H,
  ICDANK,
  ICTHINK,
  APPDATA,
  NICEMEME,
  ARMALOGI,
  ARMAMISS,
  PYRA5,
  PYRA10,
  PYRA20,
};


// #define KC_ KC_TRNS
#define _______ KC_TRNS

// #define KC_LOWR LOWER
// #define KC_RASE RAISE
// #define KC_RST RESET
// #define KC_BL_S BL_STEP
// #define KC_DBUG DEBUG


#define KC_SNUBS RSFT(KC_NUBS)
#define CTRL_ESC LCTL_T(KC_ESC)


enum unicode_names {
  LAB,
  RAB,
  SQUBL,
  SQUBR,
  CURBL,
  CURBR,
  PPIPE,
  TTILD,
  BBSL,
  NOCHAR,

  M_L_A, M_L_B, M_L_C, M_L_D, M_L_E, M_L_F, M_L_G, M_L_H,
  M_L_I, M_L_J, M_L_K, M_L_L, M_L_M, M_L_N, M_L_O, M_L_P, /*M_L_Q,*/
  M_L_R, M_L_S, M_L_T, M_L_U, M_L_V, M_L_W, M_L_X, M_L_Y, M_L_Z,

  M_U_A, M_U_B, /*M_U_C,*/ M_U_D, M_U_E, /*M_U_F,*/ M_U_G, M_U_H,
  M_U_I, M_U_J, M_U_K, M_U_L, M_U_M, M_U_N, M_U_O, M_U_P, /*M_U_Q,*/
  M_U_R, /*M_U_S,*/ M_U_T, M_U_U, M_U_V, M_U_W, /*M_U_X,*/ /*M_U_Y,*/ /*M_U_Z,*/
};

const uint32_t PROGMEM unicode_map[] = {
  [LAB]    = 0x3008,  // 〈
  [RAB]    = 0x3009,  // 〉
  [SQUBL]  = 0x005B,  // [
  [SQUBR]  = 0x005D,  // ]
  [CURBL]  = 0x007B,  // {
  [CURBR]  = 0x007D,  // }
  [PPIPE]  = 0x007C,  // |
  [TTILD]  = 0x007E,  // ~
  [BBSL]   = 0x005C,  // backslash
  [NOCHAR] = 0xE0000, // <not a character>

  /* LOWER CASE */
  [M_L_A]  = 0x1D43,  // ᵃ
  [M_L_B]  = 0x1D47,  // ᵇ
  [M_L_C]  = 0x1D9C,  // ᶜ
  [M_L_D]  = 0x1D48,  // ᵈ
  [M_L_E]  = 0x1D49,  // ᵉ
  [M_L_F]  = 0x1DA0,  // ᶠ
  [M_L_G]  = 0x1D4D,  // ᵍ
  [M_L_H]  = 0x02B0,  // ʰ
  [M_L_I]  = 0x1DA4,  // ᶤ FAKE ONE. Doesn't exist
  [M_L_J]  = 0x02B2,  // ʲ
  [M_L_K]  = 0x1D4F,  // ᵏ
  [M_L_L]  = 0x02E1,  // ˡ
  [M_L_M]  = 0x1D50,  // ᵐ
  [M_L_N]  = 0x1dAF,  // ᶯ FAKE ONE. Doesn't exist
  [M_L_O]  = 0x1D52,  // ᵒ
  [M_L_P]  = 0x1D56,  // ᵖ
  //[M_L_Q]  = 0x0000,  // Doesn't exist
  [M_L_R]  = 0x02B3,  // ʳ
  [M_L_S]  = 0x02E2,  // ˢ
  [M_L_T]  = 0x1D57,  // ᵗ
  [M_L_U]  = 0x1D58,  // ᵘ
  [M_L_V]  = 0x1D5B,  // ᵛ
  [M_L_W]  = 0x02B7,  // ʷ
  [M_L_X]  = 0x02E3,  // ˣ
  [M_L_Y]  = 0x02B8,  // ʸ
  [M_L_Z]  = 0x1DBB,  // ᶻ

  /* UPPER CASE */
  [M_U_A]  = 0x1D2C,  // ᴬ
  [M_U_B]  = 0x1D2E,  // ᴮ
  //[M_U_C]  = 0x0000,  // Doesn't exist
  [M_U_D]  = 0x1D30,  // ᴰ
  [M_U_E]  = 0x1D31,  // ᴱ
  //[M_U_F]  = 0x0000,  // Doesn't exist
  [M_U_G]  = 0x1D33,  // ᴳ
  [M_U_H]  = 0x1D34,  // ᴴ
  [M_U_I]  = 0x1D35,  // ᴵ
  [M_U_J]  = 0x1D36,  // ᴶ
  [M_U_K]  = 0x1D37,  // ᴷ
  [M_U_L]  = 0x1D38,  // ᴸ
  [M_U_M]  = 0x1D39,  // ᴹ
  [M_U_N]  = 0x1D3A,  // ᴺ
  [M_U_O]  = 0x1D3C,  // ᴼ
  [M_U_P]  = 0x1D3E,  // ᴾ
  //[M_U_Q]  = 0x0000,  // Doesn't exist
  [M_U_R]  = 0x1D3F,  // ᴿ
  //[M_U_S]  = 0x0000,  // Doesn't exist
  [M_U_T]  = 0x1D40,  // ᵀ
  [M_U_U]  = 0x1D41,  // ᵁ
  [M_U_V]  = 0x2C7D,  // ⱽ
  [M_U_W]  = 0x1D42,  // ᵂ
  //[M_U_X]  = 0x0000,  // Doesn't exist
  //[M_U_Y]  = 0x0000,  // Doesn't exist
  //[M_U_Z]  = 0x0000,  // Doesn't exist
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
     QK_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,KC_MINS ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,KC_LBRC ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   ,KC_SCLN ,KC_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
     KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,KC_LGUI,       MACRO  , KC_N   , KC_M   ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //`--------+--------+--------+--+-+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                   KC_LALT , LOWER  ,KC_SPC  ,              KC_ENT , RAISE  ,KC_BSPC
  //                              `--------+--------+--------'            `--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
     KC_GRV  , _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_INS  ,KC_PGUP ,KC_HOME ,KC_PGDN ,KC_PSCR ,KC_RBRC ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     _______ , _______, _______, _______, _______, _______,                       KC_LEFT ,KC_DOWN , KC_UP  ,KC_RGHT , _______,KC_BSLS ,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
     _______ ,KC_NUBS ,KC_SNUBS, _______, _______, _______, _______,     KC_SCRL ,KC_END  , _______, _______, _______, _______, _______,
  //`--------+--------+--------+--+-+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                _______, _______, _______,              _______, _______, KC_DEL
  //                  			  `--------+--------+--------'            `--------+--------+--------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                        X(BBSL),X(CURBL),X(SQUBL),X(SQUBR),X(CURBR), KC_F12 ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 ,                        KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 ,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
      _______,KC_NUBS ,KC_SNUBS,X(PPIPE),X(TTILD), _______, KC_CAPS,     KC_PAUS , X(LAB) , X(RAB) , _______, _______, KC_F24 , _______,
  //`--------+--------+--------+--+-+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                    _______, _______, _______,              _______, _______, KC_DEL
  //                              `~--------+--------+--------'            `--------+--------+--------'
  ),

  [_MOD_L] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,X(M_L_W),X(M_L_E),X(M_L_R),X(M_L_T),                           X(M_L_Z),X(M_L_U),X(M_L_I),X(M_L_O),X(M_L_P), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      XXXXXXX,X(M_L_A),X(M_L_S),X(M_L_D),X(M_L_F),X(M_L_G),                           X(M_L_H),X(M_L_J),X(M_L_K),X(M_L_L), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______,X(M_L_Y),X(M_L_X),X(M_L_C),X(M_L_V),X(M_L_B), _______,          _______,X(M_L_N),X(M_L_M), XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,               _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),

  [_MOD_U] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,X(M_U_W),X(M_U_E),X(M_U_R),X(M_U_T),                            XXXXXXX,X(M_U_U),X(M_U_I),X(M_U_O),X(M_U_P), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      XXXXXXX,X(M_U_A), XXXXXXX,X(M_U_D), XXXXXXX,X(M_U_G),                           X(M_U_H),X(M_U_J),X(M_U_K),X(M_U_L), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX,X(M_U_V),X(M_U_B), _______,          _______,X(M_U_N),X(M_U_M), XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,               _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),

  [_MACRO] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, PYRA5  , PYRA10 , PYRA20 , _______, _______,                          X(NOCHAR), _______, _______, _______, _______, UC_WINC,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, APPDATA, ICTHINK,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, SHRUG  , _______, FDM    , ICDANK ,                           PP_H    , _______, OKAY   ,ARMALOGI, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, KC_ALGR,          _______,NICEMEME,ARMAMISS, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,               _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t shift_mask;
  shift_mask = get_mods() & MODS_SHIFT_MASK;

  switch (keycode) {
   // case QWERTY:
   //   if (record->event.pressed) {
   //     persistent_default_layer_set(1UL<<_QWERTY);
   //   }
   //   return false;
   //   break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        if (shift_mask){
          update_tri_layer(_LOWER, _RAISE, _MOD_U);
        } else {
          update_tri_layer(_LOWER, _RAISE, _MOD_L);
        }
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MOD_U);
        update_tri_layer(_LOWER, _RAISE, _MOD_L);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        if (shift_mask){
          update_tri_layer(_LOWER, _RAISE, _MOD_U);
        } else {
          update_tri_layer(_LOWER, _RAISE, _MOD_L);
        }
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MOD_U);
        update_tri_layer(_LOWER, _RAISE, _MOD_L);
      }
      return false;
      break;
    case KC_LSFT:
    case KC_RSFT:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_MOD_L)){
          layer_on(_MOD_U);
        }
      } else {
        if (IS_LAYER_ON(_MOD_U)){
          layer_on(_MOD_L);
          layer_off(_MOD_U);
        }
      }
      return true;
      break;
    case MACRO:
      if (record->event.pressed) {
        layer_on(_MACRO);
      } else {
        layer_off(_MACRO);
      }
      return false;
      break;

	//MACROS
	CUSTOMMACRO(TRUELULW, SEND_STRING("+:regional_indicator_t:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:regional_indicator_r:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:regional_indicator_u:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:regional_indicator_e:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:LULW" SS_TAP(X_ENTER)); \
               )
	CUSTOMMACRO(SHRUG,	  SEND_STRING(" icdbShrug ");)
	CUSTOMMACRO(HEAD,     SEND_STRING(" forsenHead ");)
	CUSTOMMACRO(OKAY,     SEND_STRING(" pajaM "); \
                            send_unicode_string("👌");)
	CUSTOMMACRO(FDM,	  SEND_STRING(" FeelsDankMan ");)
	CUSTOMMACRO(PP_H, 	  SEND_STRING(" pupperH ");)
	CUSTOMMACRO(ICDANK,   SEND_STRING(" icdbDank ");)
	CUSTOMMACRO(ICTHINK,  SEND_STRING(" icdbThink ");)
	CUSTOMMACRO(APPDATA,  register_code(KC_LGUI);
							register_code(KC_R);
							unregister_code(KC_R);
							unregister_code(KC_LGUI);
							_delay_ms(100);
							SEND_STRING("%appdata%"SS_TAP(X_ENTER));
		)
    CUSTOMMACRO(NICEMEME, send_unicode_string("nͫiͤcͫeͤ");)
	CUSTOMMACRO(ARMALOGI, SEND_STRING("-#login"SS_TAP(X_ENTER));)
	CUSTOMMACRO(ARMAMISS, SEND_STRING("-#missions"SS_TAP(X_ENTER));)
	CUSTOMMACRO(PYRA5,    PYRAMID(5))
	CUSTOMMACRO(PYRA10,   PYRAMID(10))
	CUSTOMMACRO(PYRA20,   PYRAMID(20))
  }
  return true;
}
