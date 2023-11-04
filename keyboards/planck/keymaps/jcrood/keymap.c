/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "jcrood.h"

#ifdef AUDIO_ENABLE
float planck_sound[][2] = SONG(PLANCK_SOUND);
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_planck_wrapper(M_QWERTY),
    [_LOWER] = LAYOUT_planck_wrapper(M_LOWER),
    [_RAISE] = LAYOUT_planck_wrapper(M_RAISE),
    [_FN1_LAYER] = LAYOUT_planck_wrapper(M_FN1_LAYER),
    [_MOUSE] = LAYOUT_planck_wrapper(M_MOUSE),
    [_ADJUST] = LAYOUT_planck_wrapper(M_ADJUST),
};


const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, 127, 0, 0});
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_BLUE});
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_ORANGE});
const rgblight_segment_t PROGMEM fn1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_GREEN});
const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_PURPLE});
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_RED});


// Later layers take precedence.
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    lower_layer,
    raise_layer,
    fn1_layer,
    mouse_layer,
    adjust_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    //rgblight_set_layer_state(0, true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN1_LAYER));
    rgblight_set_layer_state(4, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(5, layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _RAISE));

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


