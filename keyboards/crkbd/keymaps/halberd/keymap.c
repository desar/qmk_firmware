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
	_MACRO,
    _NPAD,
    _MOUSE,
    _ADJUST,
};

#define DESKR LCTL(LWIN(KC_RGHT))
#define DESKL LCTL(LWIN(KC_LEFT))

#define COPY LCTL(KC_C)
#define PSTE LCTL(KC_V)
#define RERE LCTL(KC_R)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)

#define JIME LALT(KC_GRV)
#define SLEP MEH(KC_EQL)

enum custom_keycodes {
	PSTEENT = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case PSTEENT:
		if (record->event.pressed) {
			register_code(KC_LCTL);
			register_code(KC_V);
			unregister_code(KC_V);
			unregister_code(KC_LCTL);
			tap_code(KC_ENT);
		} else {
		}
		break;
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,   KC_E,     KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
    KC_LSFT, KC_A,    KC_S,   KC_D,     KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,   KC_C,     KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                        MO(_LOWER),   KC_BSPC, KC_LWIN, KC_LALT, KC_SPC,  MO(_RAISE)
  ),
  
  [_RAISE] = LAYOUT(
    JIME,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    DESKL,   KC_HOME, COPY,    KC_UP,   PSTE,    KC_PGUP,                   KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
    DESKR,   KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
                                        MO(_LOWER), TO(_MACRO), TO(_NPAD), XXXXXXX, XXXXXXX, MO(_RAISE)
  ),
  
  [_LOWER] = LAYOUT(
    JIME,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    DESKL,   KC_HOME, COPY,    KC_UP,   PSTE,    KC_PGUP,                   KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_L, KC_BTN3,
    DESKR,   KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_APP,
                                        MO(_LOWER), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_RAISE)
  ),

  [_MACRO] = LAYOUT(
    UNDO,    COPY,    PSTE,    PSTEENT, REDO,    XXXXXXX,                   UNDO,    COPY,    PSTE,    PSTEENT, REDO,  KC_ESC,
    KC_LSFT, KC_HOME, XXXXXXX, KC_UP,   XXXXXXX, KC_PGUP,                   KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, KC_HOME, XXXXXXX,
    KC_LCTL, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_ENT,
                                        TO(_QWERTY),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, TO(_QWERTY)
  ),

  [_NPAD] = LAYOUT(
    UNDO,    COPY,    PSTE,    PSTEENT, REDO,    KC_NLCK,                   KC_PDOT,  KC_P7,  KC_P8,  KC_P9,  KC_PMNS,  KC_PSLS,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_NUBS,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,  KC_PAST,
    KC_LCTL, XXXXXXX, KC_MUTE, KC_VOLU, KC_VOLD, XXXXXXX,                   XXXXXXX,  KC_P1,  KC_P2,  KC_P3,  KC_PENT,  KC_PEQL,
                                        TO(_QWERTY),  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P0, TO(_QWERTY)
  ),

  [_ADJUST] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   KC_INS,  KC_HOME, KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   KC_DEL,  KC_END,  KC_PGDN, XXXXXXX, RESET,   SLEP,
                                        MO(_LOWER),   KC_BSPC, KC_LWIN, KC_LALT, KC_SPC, MO(_RAISE)
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

#ifdef OLED_DRIVER_ENABLE
    #include "oled1.c"
#endif
