// my bm40 layout

#include QMK_KEYBOARD_H
#include "jcrood.h"
#include "planck.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_planck_wrapper(M_QWERTY),
    [_LOWER] = LAYOUT_planck_wrapper(M_LOWER),
    [_RAISE] = LAYOUT_planck_wrapper(M_RAISE),
    [_FN1_LAYER] = LAYOUT_planck_wrapper(M_FN1_LAYER),
    [_MOUSE] = LAYOUT_planck_wrapper(M_MOUSE),
    [_ADJUST] = LAYOUT_planck_wrapper(M_ADJUST),
};

void keyboard_post_init(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
    rgb_matrix_enable_noeeprom();
}


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool rgb_matrix_indicators_user(void) {
    
    switch (biton32(layer_state)) {
    case _ADJUST:
        rgb_matrix_set_color(1, 0xff, 0x00, 0x00); // Q / reset
        rgb_matrix_set_color(2, 0x00, 0xcc, 0x00); // W / debug

        rgb_matrix_set_color(3, 0x7f,  0xff, 0x00); // E / RGB onoff
        rgb_matrix_set_color(4, 0x7f,  0xff, 0x00); // R / RGB mod
        
        rgb_matrix_set_color(5, 0x00, 0x7f,  0xff); // T / hue++
        rgb_matrix_set_color(6, 0x00, 0x3f,  0x7f); // Y / hue--
        
        rgb_matrix_set_color(7, 0x7f, 0x00, 0xff); // U / sat++
        rgb_matrix_set_color(8, 0x3f, 0x00, 0x7f); // I / sat--
        
        rgb_matrix_set_color(9, 0x00, 0x00, 0xff); // O / bri++
        rgb_matrix_set_color(10, 0x00, 0x00, 0x7f); // P / bri--
        
        rgb_matrix_set_color(15, 0x00, 0xcc, 0x00); // d / au on
        rgb_matrix_set_color(16, 0x00, 0xcc, 0x00); // f / au off
        
        rgb_matrix_set_color(40, 0xff, 0x00, 0x00); // lower
        rgb_matrix_set_color(42, 0xff, 0x00, 0x00); // raise
        break;
    case _LOWER:
        // rgb_matrix_set_color(1, RGB_YELLOW); // q / <
        // rgb_matrix_set_color(2, RGB_GREEN); // W / [
        // rgb_matrix_set_color(3, RGB_BLUE); // E / {
        // rgb_matrix_set_color(4, RGB_MAGENTA); // R / (
        //
        // rgb_matrix_set_color(7, RGB_MAGENTA); // U / sat++
        // rgb_matrix_set_color(8, RGB_BLUE); // I / }
        // rgb_matrix_set_color(9, RGB_GREEN); // O / ]
        // rgb_matrix_set_color(10, RGB_YELLOW); // P / >

        rgb_matrix_set_color(40, 0x00, 0x00, 0xff); // lower
        break;
    case _RAISE:
        // rgb_matrix_set_color(1, RGB_YELLOW); // q / f1
        // rgb_matrix_set_color(2, RGB_YELLOW); // W / f2
        // rgb_matrix_set_color(3, RGB_YELLOW); // E / f3
        // rgb_matrix_set_color(4, RGB_YELLOW); // R / f4
        // rgb_matrix_set_color(5, RGB_YELLOW); // T / f5
        //
        // rgb_matrix_set_color(6, RGB_CYAN); // Y / f6
        // rgb_matrix_set_color(7, RGB_CYAN); // U / f7
        // rgb_matrix_set_color(8, RGB_CYAN); // I / f8
        // rgb_matrix_set_color(9, RGB_CYAN); // O / f9
        // rgb_matrix_set_color(10, RGB_CYAN); // P / f10
    
        rgb_matrix_set_color(42, 0xff, 0xa5, 0x00); // raise
        break;
    case _FN1_LAYER:
        rgb_matrix_set_color(12, 0x00, 0xff, 0x00); // tab / Fn
        break;
    case _MOUSE:
        rgb_matrix_set_color(41, 0x80, 0x00, 0x80); // space / mouse
        break;
    }
    return false;
}
