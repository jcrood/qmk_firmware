// MINE - Anne Pro 2

#include QMK_KEYBOARD_H

enum anne_pro_layers {
  _BASE_LAYER,
  _FN,
  _MAC,
  _FN4
};

// cursor keys
#define RSHFTU RSFT_T(KC_UP)
#define RALTL RALT_T(KC_LEFT)
#define FNDWN LT(_MAC,KC_DOWN)
#define CTRLR RCTL_T(KC_RGHT)

// fn4 stuffs
#define FN_TAB LT(_FN4, KC_TAB)
#define CMDGRV LGUI(KC_GRV)             // cmd ` - focus to next window
#define LOCKSCR LCTL(LGUI(KC_Q))        // ctrl cmd Q  - lock screen
#define CAPSCR SGUI(KC_3)               // shift cmd 3 - capture screen
#define CAPSEL SGUI(KC_4)               // shift cmd 4 - capture selection

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | TabFN  |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Ctrl    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Fn    |  Alt  |  UI   |               space             |  UI   |  Alt  | FnMac | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_60_ansi( /* Base */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        FN_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   RSHFTU,
        MO(_FN), KC_LALT, KC_LGUI,                   KC_SPC,                                      KC_RGUI, RALTL,   FNDWN,   CTRLR
    ),

    [_FN] = LAYOUT_60_ansi( 
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______
    ),

    [_MAC] = LAYOUT_60_ansi( 
        KC_GRV,  KC_BRID, KC_BRIU, _______, _______, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______
    ),

    [_FN4] = LAYOUT_60_ansi( 
        CMDGRV,  _______, CAPSCR,  CAPSEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, LOCKSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______
    ),
};

void keyboard_post_init_user(void) {
    ap2_led_disable();
}

