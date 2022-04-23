/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
enum crkbd_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)
#define DESKR LCTL(LWIN(KC_RGHT))
#define DESKL LCTL(LWIN(KC_LEFT))

#define COPY LCTL(KC_C)
#define PSTE LCTL(KC_V)
#define RERE LCTL(KC_R)

#define JIME LALT(KC_GRV)
#define SLEP MEH(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,   KC_E,     KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
    KC_LSFT, KC_A,    KC_S,   KC_D,     KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,   KC_C,     KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                        LOWER,   KC_BSPC, KC_LWIN, KC_LALT, KC_SPC,  RAISE
  ),

  [_LOWER] = LAYOUT(
    JIME,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_BTN1, KC_BTN3, KC_LEFT, KC_UP,   KC_RGHT, DESKL,                     KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_L, KC_BTN3,
    KC_BTN2, RERE,    COPY,    KC_DOWN, PSTE,    DESKR,                     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, XXXXXXX,
                                        LOWER,   KC_BSPC, KC_LWIN, KC_LALT, KC_SPC,  RAISE
  ),

  [_RAISE] = LAYOUT(
    JIME,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_APP,                    KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
                                        LOWER,   KC_BSPC, KC_LWIN, KC_LALT, KC_SPC,  RAISE

  ),

  [_ADJUST] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   KC_INS,  KC_HOME, KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   KC_DEL,  KC_END,  KC_PGDN, XXXXXXX, RESET,   SLEP,
                                        LOWER,   KC_BSPC, KC_LWIN, KC_LALT, KC_SPC,  RAISE
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

#ifdef OLED_DRIVER_ENABLE
    #include "oled0.c"
#endif
