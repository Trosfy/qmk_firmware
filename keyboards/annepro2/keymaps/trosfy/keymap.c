 /* Copyright 2021 OpenAnnePro community
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

enum anne_pro_layers {
    BASE,
    MAC,
    ARROW,
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
// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* |-----------------------------------------------------------------------------------------+ | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  Win  |  Alt  |                Space            |  Alt  |  FN2  |  FN1  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |GRV  |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* | TAPDANCE|     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |      UP        |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT |  DOWN | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
            TD(GRV_TAP_DANCE),    KC_1,    KC_2,  KC_3,  KC_4,  KC_5,      KC_6,    KC_7,    KC_8,           KC_9,     KC_0,   KC_MINS,  KC_EQL, KC_BSPC,
            KC_TAB,    KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,      KC_Y,    KC_U,    KC_I,           KC_O,     KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,
 TD(ESC_TAP_DANCE),    KC_A,    KC_S,  KC_D,  KC_F,  KC_G,      KC_H,    KC_J,    KC_K,           KC_L,  KC_SCLN,   KC_QUOT,  KC_ENT,
           KC_LSFT,    KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,      KC_N,    KC_M, KC_COMM,         KC_DOT,  KC_SLSH,   RSFT_T(KC_UP),
           KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(FN1, KC_LEFT), LT(FN2, KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer MAC
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |ACL0 |ACL1 |ACL2       |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |WL-U |MS-U |WL-D |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |      |      |      |     |     |MS-L |MS-D |MS-R |BTN2 |     |          |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |BTN4 |BTN3 |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       | Space |              BTN1               |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [MAC] = LAYOUT_60_ansi( /* Mac */
    TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    TD(ESC_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
  /*
  * Layer _ARROW_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |      UP        |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |  LEFT |  DOWN | RIGHT |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [ARROW] = LAYOUT_60_ansi( /* Arrow */
    TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    TD(ESC_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
),
  /*
  * Layer NUMPAD
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |  7  |  8  |  9  |  -  |  /  |     |NUMLOCK |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |     |  4  |  5  |  6  |  +  |  *  |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |  1  |  2  |  3  |ENTER|                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |               0                 | ./Del |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [NUMPAD] = LAYOUT_60_ansi( /* Numpad */
    TD(GRV_TAP_DANCE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
    _______, _______, _______, _______, _______, _______, _______,    KC_7,    KC_P8,    KC_P9, KC_PMNS, KC_PSLS, _______, KC_NUMLOCK,
    _______, _______, _______, _______, _______, _______, _______,    KC_P4,    KC_P5,    KC_P6, KC_PPLS, KC_PAST, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_P1,    KC_P2,    KC_P3, KC_PENT, _______,
    _______, _______, _______,    KC_0, KC_PDOT, _______, _______, _______
 ),
  /*
  * Layer MOUSE
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |ACL0 |ACL1 |ACL2       |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |WL-U |MS-U |WL-D |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |      |      |      |     |     |MS-L |MS-D |MS-R |BTN2 |     |          |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |BTN4 |BTN3 |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       | Space |              BTN1               |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [MOUSE] = LAYOUT_60_ansi( /* Mouse */
    TD(GRV_TAP_DANCE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_MS_U, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN4, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_SPC, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * | `/~ |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     | UP  |     |     | HOME| END | PRTSCR |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |     | LFT |DOWN | RGT |PGUP |PGDWN|             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     | INS | DEL |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
    KC_GRAVE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, KC_LEAD, KC_HOME, KC_END, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT,   KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN, KC_TRNS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_DEL, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * | USB | BT1 | BT2 | BT3 | BT4 |     |     |     |     |LEDOF|LEDON|LDINT|LDSPD| BT_UNPAIR |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     | PLAY|HOME|END   |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |     |     |     |     |BRDWN|BRUP |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     | MUTE|VOLDN|VOLUP|     |   TOGGLE AS    |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
    KC_AP2_USB, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______,  KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_AP2_BT_UNPAIR,
       MO(FN2),    _______,    _______,    _______,    _______, _______, _______, _______, _______,       _______,                KC_MPLY, KC_MPRV, KC_MNXT, _______,
       _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______,        _______,                KC_BRID, KC_BRIU, _______,
       _______,    _______,    _______,    _______,    _______, _______, _______, KC_MUTE, KC_VOLD,       KC_VOLU,                _______, _______,
       _______,    _______,    _______,    _______,    _______, MO(FN1), MO(FN2), _______
 ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
      if(get_highest_layer(state) == MAC) {
        // Set the leds to none
        ap2_led_set_foreground_color(0x00, 0x00, 0x00);

        // Set the white color_white
        const ap2_led_t color_white = {.p.red = 0xFF, .p.green = 0xFF, .p.blue = 0xFF, .p.alpha = 0xff};
        ap2_led_mask_set_key(0, 7, color_white); // 7
        ap2_led_mask_set_key(1, 5, color_white); // t
        ap2_led_mask_set_key(1, 6, color_white); // y
        ap2_led_mask_set_key(1, 7, color_white); // u
        ap2_led_mask_set_key(2, 4, color_white); // f
        ap2_led_mask_set_key(2, 5, color_white); // g
        ap2_led_mask_set_key(2, 6, color_white); // h
        ap2_led_mask_set_key(3, 5, color_white); // v
        ap2_led_mask_set_key(3, 6, color_white); // b
        ap2_led_mask_set_key(3, 7, color_white); // n

    } else if(get_highest_layer(state) == ARROW){
        // Set the leds to none
        ap2_led_set_foreground_color(0x00, 0x00, 0x00);

        // Set the white color
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0xFF, .p.blue = 0xFF, .p.alpha = 0xff};

        ap2_led_mask_set_key(3, 12, color); // rshft
        ap2_led_mask_set_key(4, 10, color); // fn1
        ap2_led_mask_set_key(4, 11, color); // fn2
        ap2_led_mask_set_key(4, 12, color); // rctrl

    }else if(get_highest_layer(state) == NUMPAD){
        // Set the leds to none
        ap2_led_set_foreground_color(0x00, 0x00, 0x00);

        // Set the green color
        const ap2_led_t color = {.p.red = 0x00, .p.green = 0xFF, .p.blue = 0x00, .p.alpha = 0xff};
        
        ap2_led_mask_set_key(1, 7, color); // u
        ap2_led_mask_set_key(1, 8, color); // i
        ap2_led_mask_set_key(1, 9, color); // o
        ap2_led_mask_set_key(1, 13, color); /* \ */
        ap2_led_mask_set_key(2, 7, color); // j
        ap2_led_mask_set_key(2, 8, color); // k
        ap2_led_mask_set_key(2, 9, color); // l
        ap2_led_mask_set_key(3, 8, color); // m
        ap2_led_mask_set_key(3, 9, color); // ,
        ap2_led_mask_set_key(3, 10, color); // .
        ap2_led_mask_set_key(4, 6, color); // space

        // Set the red green color
        const ap2_led_t color_green = {.p.red = 0xFF, .p.green = 0xFF, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(1, 10, color_green); // p
        ap2_led_mask_set_key(1, 11, color_green); // [
        ap2_led_mask_set_key(2, 10, color_green); // ;
        ap2_led_mask_set_key(2, 11, color_green); // '

        // Set the white color_white
        const ap2_led_t color_white = {.p.red = 0xFF, .p.green = 0xFF, .p.blue = 0xFF, .p.alpha = 0xff};
        ap2_led_mask_set_key(3, 11, color_white); // /

        // Set the red color_red
        const ap2_led_t color_red = {.p.red = 0xFF, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(4, 9, color_red); // ralt

    }else if(get_highest_layer(state) == MOUSE){
        // Set the leds to none
        ap2_led_set_foreground_color(0x00, 0x00, 0x00);

        // Set the green color
        const ap2_led_t color_green = {.p.red = 0x00, .p.green = 0xFF, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(1, 8, color_green); // i
        ap2_led_mask_set_key(2, 7, color_green); // j
        ap2_led_mask_set_key(2, 8, color_green); // k
        ap2_led_mask_set_key(2, 9, color_green); // l

        // Set the green blue color
        const ap2_led_t color_green_blue = {.p.red = 0x00, .p.green = 0xFF, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(1, 7, color_green_blue); // u
        ap2_led_mask_set_key(1, 9, color_green_blue); // o

        // Set the blue color
        const ap2_led_t color_blue = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0xFF, .p.alpha = 0xff};
        ap2_led_mask_set_key(0, 11, color_blue); // -
        ap2_led_mask_set_key(0, 12, color_blue); // =
        ap2_led_mask_set_key(0, 13, color_blue); // bksp

        // Set the white color_white
        const ap2_led_t color_white = {.p.red = 0xFF, .p.green = 0xFF, .p.blue = 0xFF, .p.alpha = 0xff};
        ap2_led_mask_set_key(2, 10, color_white); // ;
        ap2_led_mask_set_key(3, 7, color_white); // n
        ap2_led_mask_set_key(3, 8, color_white); // m
        ap2_led_mask_set_key(4, 6, color_white); // space

        // Set the red color_red_blue
        const ap2_led_t color_red_blue = {.p.red = 0xFF, .p.green = 0x00, .p.blue = 0xFF, .p.alpha = 0xff};
        ap2_led_mask_set_key(4, 3, color_red_blue); // lalt

    } else if(get_highest_layer(state) == FN1){
        // Set the leds to none
        ap2_led_set_foreground_color(0x00, 0x00, 0x00);

        // Set the green color
        const ap2_led_t color = {.p.red = 0x00, .p.green = 0xFF, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(1, 8, color); // i
        ap2_led_mask_set_key(2, 7, color); // j
        ap2_led_mask_set_key(2, 8, color); // k
        ap2_led_mask_set_key(2, 9, color); // l

        // Set the white color_white
        const ap2_led_t color_white = {.p.red = 0xFF, .p.green = 0xFF, .p.blue = 0xFF, .p.alpha = 0xff};
        ap2_led_mask_set_key(0, 0, color_white); // esc
        ap2_led_mask_set_key(0, 1, color_white); // 1
        ap2_led_mask_set_key(0, 2, color_white); // 2
        ap2_led_mask_set_key(0, 3, color_white); // 3
        ap2_led_mask_set_key(0, 4, color_white); // 4
        ap2_led_mask_set_key(0, 5, color_white); // 5
        ap2_led_mask_set_key(0, 6, color_white); // 6
        ap2_led_mask_set_key(0, 7, color_white); // 7
        ap2_led_mask_set_key(0, 8, color_white); // 8
        ap2_led_mask_set_key(0, 9, color_white); // 9
        ap2_led_mask_set_key(0, 10, color_white); // 0
        ap2_led_mask_set_key(0, 11, color_white); // -
        ap2_led_mask_set_key(0, 12, color_white); // =
        ap2_led_mask_set_key(1, 11, color_white); // [
        ap2_led_mask_set_key(1, 12, color_white); // ]
        ap2_led_mask_set_key(1, 13, color_white); /* \ */
        ap2_led_mask_set_key(2, 10, color_white); // ;
        ap2_led_mask_set_key(2, 11, color_white); // '
        ap2_led_mask_set_key(3, 10, color_white); // .

        // Set the red color_red
        const ap2_led_t color_red = {.p.red = 0xFF, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(0, 13, color_red); // bksp
        ap2_led_mask_set_key(3, 11, color_red); // .

    } else if(get_highest_layer(state) == FN2){
        // Set the leds to none
        ap2_led_set_foreground_color(0x00, 0x00, 0x00);

        // Set the white color_white
        const ap2_led_t color_white = {.p.red = 0xFF, .p.green = 0xFF, .p.blue = 0xFF, .p.alpha = 0xff};
        ap2_led_mask_set_key(0, 0, color_white); // esc
        ap2_led_mask_set_key(0, 1, color_white); // 1
        ap2_led_mask_set_key(0, 2, color_white); // 2
        ap2_led_mask_set_key(0, 3, color_white); // 3
        ap2_led_mask_set_key(0, 4, color_white); // 4 
        ap2_led_mask_set_key(0, 10, color_white); // -
        ap2_led_mask_set_key(1, 10, color_white); // p
        ap2_led_mask_set_key(1, 11, color_white); // [
        ap2_led_mask_set_key(1, 12, color_white); // ]
        ap2_led_mask_set_key(3, 9, color_white); // ,
        ap2_led_mask_set_key(3, 10, color_white); // .

        // Set the red green color
        const ap2_led_t color_red_green = {.p.red = 0xFF, .p.green = 0xFF, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(0, 10, color_red_green); // 0
        ap2_led_mask_set_key(0, 12, color_red_green); // =
        ap2_led_mask_set_key(2, 10, color_red_green); // ;
        ap2_led_mask_set_key(2, 11, color_red_green); // '

        // Set the red color_red
        const ap2_led_t color_red = {.p.red = 0xFF, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_mask_set_key(0, 9, color_red); // 9
        ap2_led_mask_set_key(0, 13, color_red); // bksp
        ap2_led_mask_set_key(3, 8, color_red); // m
        ap2_led_mask_set_key(3, 12, color_red); // rshft

    } else {
        // Reset back to the current profile
        ap2_led_reset_foreground_color();
    }
    return state;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};

        ap2_led_mask_set_key(2, 0, color);
        /* NOTE: Instead of colouring the capslock only, you can change the whole
           keyboard with ap2_led_set_foreground_color */
    } else {
        // Reset the capslock if there is no layer active
        if (!layer_state_is(FN1) && !layer_state_is(FN2)) {
            const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
            ap2_led_mask_set_key(2, 0, color);
        }
    }

    return true;
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
      if(!layer_state_is(ARROW)){
        layer_on(ARROW);
      } else {
        layer_off(ARROW);
      }
      break;
    case QUADRIPLE_HOLD:
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

	  SEQ_THREE_KEYS(KC_P, KC_P, KC_P) {
      SEND_STRING("Hello World!");
    }
  }
}