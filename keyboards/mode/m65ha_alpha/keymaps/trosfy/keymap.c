/*
Copyright 2020 Álvaro "Gondolindrim" Volpato <alvaro.volpato@usp.br>

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

//define layers
enum layers {
    BASE,
    MAC,
    NUMPAD,
    MOUSE,
    FN1,
    FN2,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    QUADRIPLE_TAP,
    QUADRIPLE_HOLD,
};

enum {
    ESC_TAP_DANCE,
    GRV_TAP_DANCE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [BASE] = LAYOUT_all( /* Base */
        TD(GRV_TAP_DANCE) , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_PGUP ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
        TD(ESC_TAP_DANCE), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT , KC_HOME,
	KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , KC_END ,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC ,                            KC_RALT, MO(FN2)  , KC_LEFT, KC_DOWN, KC_RGHT 
	),
   [MAC] = LAYOUT_all(
	TD(GRV_TAP_DANCE)  ,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	TD(ESC_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, 
	KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	KC_LGUI, KC_LALT, KC_LCTL,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
   [NUMPAD] = LAYOUT_all(
	TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	_______, _______, _______, _______, _______, _______, _______,    KC_7,    KC_P8,    KC_P9, KC_PMNS, KC_PSLS, _______, KC_NUMLOCK, KC_TRNS, 
	_______, _______, _______, _______, _______, _______, _______,    KC_P4,    KC_P5,    KC_P6, KC_PPLS, KC_PAST, _______, KC_TRNS, 
	 _______, _______, _______, _______, _______, _______, _______,    KC_P1,    KC_P2,    KC_P3, KC_PENT, _______, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS,                            KC_P0,                            _______, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS
	),
   [MOUSE] = LAYOUT_all(
	TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_MS_U, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN4, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_SPC,                            KC_BTN1,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
    [FN1] = LAYOUT_all(
	RESET, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, KC_LEAD, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, 
	KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
    [FN2] = LAYOUT_all(
	KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_PSCR, KC_TRNS, 
	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU,          KC_TRNS, KC_INS, 
	KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT, KC_ASTG, KC_TRNS, KC_DEL, 
	KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	)
};


uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case AUTO_SHIFT_NUMERIC:
            return 2 * get_generic_autoshift_timeout();
        case AUTO_SHIFT_SPECIAL:
            return get_generic_autoshift_timeout() + 50;
        case AUTO_SHIFT_ALPHA:
        default:
            return get_generic_autoshift_timeout();
    }
}

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (!state->pressed) return DOUBLE_TAP;
    else return DOUBLE_HOLD;
  } else if (state->count == 3) {
    if (!state->pressed) return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  } else if (state->count == 4) {
    if (!state->pressed) return QUADRIPLE_TAP;
    else return QUADRIPLE_HOLD;
  } else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap esc_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap grav_tap_state = {
  .is_press_action = true,
  .state = 0
};

// Functions that control what our tap dance key does
void esc_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
  esc_tap_state.state = cur_dance(state);

  switch (esc_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_CAPS);
      break;
    case SINGLE_HOLD:
      layer_on(FN1);
      break;
    case DOUBLE_HOLD:
      layer_on(NUMPAD);
      break;
    case TRIPLE_HOLD:
      layer_on(MOUSE);
      break;
  }
}

void esc_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
  // If the key was held down and now is released then switch off the layer
  if (esc_tap_state.state == SINGLE_HOLD) {
    if (layer_state_is(FN1)) {
      layer_off(FN1);
    }
  }
  if (esc_tap_state.state == DOUBLE_HOLD) {
    if (layer_state_is(NUMPAD)) {
      layer_off(NUMPAD);
    }
  }
  if (esc_tap_state.state == TRIPLE_HOLD) {
    if (layer_state_is(MOUSE)) {
      layer_off(MOUSE);
    }
  }
  esc_tap_state.state = 0;
}

// Functions that control what our tap dance key does
void grave_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
  grav_tap_state.state = cur_dance(state);

  switch (grav_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_ESC);
      break;
    case SINGLE_HOLD:
      if(!layer_state_is(MAC)){
        layer_on(MAC);
      } else {
        layer_off(MAC);
      }
      break;
    case DOUBLE_TAP:
      if(!layer_state_is(NUMPAD)){
        layer_on(NUMPAD);
      } else {
        layer_off(NUMPAD);
      }
      break;
    case TRIPLE_TAP:
      if(!layer_state_is(MOUSE)){
        layer_on(MOUSE);
      } else {
        layer_off(MOUSE);
      }
      break;
    case QUADRIPLE_TAP:
      layer_move(BASE);
      break;
  }
}

void grave_layer_reset(qk_tap_dance_state_t *state, void *user_data) {

}

qk_tap_dance_action_t tap_dance_actions[] = {
  [ESC_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, esc_layer_finished, esc_layer_reset, 250),
  [GRV_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, grave_layer_finished, grave_layer_reset, 300),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // SEQ_ONE_KEY(KC_F) {
    //   // Anything you can do in a macro.
    //   SEND_STRING("QMK is awesome.");
    // }
    // SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // }
    // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
    //   SEND_STRING("https://start.duckduckgo.com\n");
    // }

    SEQ_TWO_KEYS(KC_PGDN, KC_HOME) {
      register_code(KC_SLEP);
    }
    SEQ_FOUR_KEYS(KC_PGDN, KC_HOME, KC_END, KC_RGHT) {
      register_code(KC_PWR);
    }
  }
}