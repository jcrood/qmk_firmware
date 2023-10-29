/* 
 * MINE!
 *
 */

#include QMK_KEYBOARD_H

enum layers{
    _BASE,
    _FN,
    _MAC,
    _KEYB,
    _FN4
};

#define FN4_TAB LT(_FN4, KC_TAB)
#define CMDGRV LGUI(KC_GRV)             // cmd ` - focus to next window
#define LOCKSCR LCTL(LGUI(KC_Q))        // ctrl cmd Q  - lock screen
#define CAPSCR SGUI(KC_3)               // shift cmd 3 - capture screen
#define CAPSEL SGUI(KC_4)               // shift cmd 4 - capture selection


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          MO(_KEYB),
        FN4_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        MO(_FN),KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, KC_ROPT, MO(_MAC), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN] = LAYOUT_ansi_67(
        KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,          _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,          KC_END,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______, _______, _______, _______),

    [_MAC] = LAYOUT_ansi_67(
        KC_GRV, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______, _______, _______, _______),


    [_KEYB] = LAYOUT_ansi_67(
        _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,           _______,          _______,
        _______,          _______, _______, _______, _______, QK_BOOT, NK_TOGG, _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______, _______, _______, _______),

    [_FN4] = LAYOUT_ansi_67(
        CMDGRV,  _______, CAPSCR,  CAPSEL,  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______, LOCKSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,           _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______, _______, _______, _______)

};



bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    switch(layer) {
                        case _FN4:
                            rgb_matrix_set_color(index, RGB_GREEN);
                            break;
                        case _KEYB:
                            rgb_matrix_set_color(index, RGB_RED);
                            break;
                        case _MAC:
                            rgb_matrix_set_color(index, RGB_BLUE);
                            break;
                        case _FN:
                            rgb_matrix_set_color(index, RGB_YELLOW);
                            break;
                        default:
                            break;                 
                    }
                }
            }
        }
    }
    return false;
}
