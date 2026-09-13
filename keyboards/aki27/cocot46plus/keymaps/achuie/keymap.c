/*
Copyright 2026 achuie

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
#include <stdio.h>
#include "quantum.h"


#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define CTL_ENT MT(MOD_LCTL,KC_ENT)
#define GUI_SPC MT(MOD_LGUI,KC_SPC)
#define DIR_LBC LT(_DIRECT,KC_LBRC)
#define DIR_RBC LT(_DIRECT,KC_RBRC)
#define ALT_LAB MT(MOD_LALT,KC_COMM)
#define GUI_RAB MT(MOD_RGUI,KC_DOT)


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_LAB:
            if (record->tap.count && record->event.pressed) {  // On tap
                tap_code16(KC_LABK);
                return false;  // Return false to ignore further processing of key
            }
            break;
        case GUI_RAB:
            if (record->tap.count && record->event.pressed) {  // On tap
                tap_code16(KC_RABK);
                return false;  // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}


enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _DIRECT = 3,
    _TRACKBALL = 4
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      CTL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CTL_ENT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_RSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        ALT_LAB, DIR_LBC,   MO(1),    GUI_SPC, KC_MS_BTN1,             KC_MS_BTN2,  KC_SPC, MO(2),   DIR_RBC,  GUI_RAB,
                                                                 KC_PGUP, KC_MS_BTN3,    KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,   KC_MINS, KC_EQL,  KC_BSLS, KC_QUOT, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                                        KC_F12,  XXXXXXX, _______, _______, _______, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______, KC_MS_BTN4,             KC_MS_BTN5,  _______, MO(4), _______,  _______,
                                                                 KC_PGUP,  _______,   KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,   KC_UNDS, KC_PLUS,  KC_PIPE, KC_DQUO, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                                        KC_F12,  XXXXXXX, _______, _______, _______, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______, KC_MS_BTN4,             KC_MS_BTN5,  _______, _______, _______,  _______,
                                                                 _______,  _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_DIRECT] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,                                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             _______,  _______, _______, _______,  KC_CAPS,
                                                                 _______, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_TRACKBALL] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,                _______, _______, _______, _______, _______,
                                                                 _______,  _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [2] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [3] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [4] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
};
#endif



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _DIRECT:
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _TRACKBALL:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    default:
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
      return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

