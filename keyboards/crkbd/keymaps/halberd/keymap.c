/*
Copyright 2022 halberd
*/

#include QMK_KEYBOARD_H

#define DESKR LCTL(LWIN(KC_RGHT))
#define DESKL LCTL(LWIN(KC_LEFT))

#define JIME LALT(KC_GRV)
#define SLEP MEH(KC_EQL)


// Macro Ctrl-V + Enter
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
  // Default Qwerty
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,     KC_F,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2), KC_BSPC, KC_LWIN,    KC_LALT,  KC_SPC,   MO(1)
                                      //`--------------------------'  `--------------------------'
  ),
  
  // Top: Punctuations, Left: Functions, Right: Punctuations
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    A(KC_GRV), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F6,   KC_F7,   KC_F9,   KC_F8,  KC_F10,  KC_F12,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2),   TO(3),   TO(4),    XXXXXXX, XXXXXXX,   MO(1)
                                      //`--------------------------'  `--------------------------'
  ),
  
  // Top: Numbers, Left: Arrows, Right: Mouse
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    A(KC_GRV),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        DESKL, KC_HOME, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP,                      C(KC_C), C(KC_V), PSTEENT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        DESKR,  KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2), XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   MO(1)
                                      //`--------------------------'  `--------------------------'
  ),
  
  // Left: RGB, Right: Mouse
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,   RESET,                      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_L, KC_BTN3,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MUTE, KC_VOLU, KC_VOLD, XXXXXXX, XXXXXXX,    SLEP,                      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,  KC_APP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2), XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,   MO(1)
                                      //`--------------------------'  `--------------------------'
  ),

  // Left: Audio, Right: NumPad
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PDOT,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_NUBS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PENT, KC_PEQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TO(0), XXXXXXX, XXXXXXX,    XXXXXXX,   KC_P0,   TO(0)
                                      //`--------------------------'  `--------------------------'
  )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, 1, 2, 3);
    return state;
}

#ifdef OLED_DRIVER_ENABLE
    #include "oled1.c"
#endif
