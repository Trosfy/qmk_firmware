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

	// BASE layer
	[BASE] = LAYOUT_all(
		TD(GRV_TAP_DANCE),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  KC_HOME,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
		TD(ESC_TAP_DANCE), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   KC_END,
		KC_LCTL,   KC_LGUI, KC_LALT,                            KC_SPC,                                      MO(FN2),            KC_LEFT, KC_DOWN, KC_RGHT),

	// MAC Layer
	[MAC] = LAYOUT_all(
		TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
		TD(ESC_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,
		KC_LGUI, KC_LALT, KC_LCTL,                            KC_TRNS,                                     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS),

	// NUMPAD Layer
	[NUMPAD] = LAYOUT_all(
		TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_PSLS, KC_TRNS, KC_NUMLOCK,       KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PAST, KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_P1,   KC_P2,   KC_P3, KC_PENT, KC_TRNS,                   KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                                      KC_PDOT,          KC_TRNS, KC_TRNS, KC_TRNS),

	// MOUSE Layer
	[MOUSE] = LAYOUT_all(
		TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_MS_U, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS, KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_SPC,                            KC_BTN1,                                      KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS),
	
	// FN1 Layer
	[FN1] = LAYOUT_all(
		RESET,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS, KC_LEAD,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEAD, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                                     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS),
	
	// FN2 Layer / Media Layer
	[FN2] = LAYOUT_all(
		KC_GRAVE,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  BR_DEC,  BR_INC,  EF_DEC,  EF_INC, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_PSCR,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT, KC_TRNS,                   KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                                     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS),

};

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
  [ESC_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_layer_finished, esc_layer_reset),
  [GRV_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, grave_layer_finished, grave_layer_reset),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_PGUP, KC_PGDN) {
      register_code(KC_SLEP);
    }
	  SEQ_THREE_KEYS(KC_P, KC_P, KC_P) {
      SEND_STRING("Hello World");
    }
    SEQ_FOUR_KEYS(KC_PGUP, KC_PGDN, KC_END, KC_RIGHT) {
      register_code(KC_PWR);
    }
  }
}
