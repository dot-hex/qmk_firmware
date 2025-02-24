/*
<<<<<<< HEAD
Copyright 2021 keebnewb
=======
<<<<<<< HEAD:keyboards/the_uni/keymaps/qwerty/keymap.c
Copyright 2021 Peter C. Park <peter@stenokeyboards.com>
=======
Copyright 2021 keebnewb
>>>>>>> upstream/master:keyboards/keebzdotnet/fme/keymaps/default/keymap.c
>>>>>>> upstream/master

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
<<<<<<< HEAD
=======
<<<<<<< HEAD:keyboards/the_uni/keymaps/qwerty/keymap.c

#include QMK_KEYBOARD_H

enum uni_layers {
    _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                    KC_1, KC_C, KC_V, KC_N, KC_M, KC_2),

=======
>>>>>>> upstream/master
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_F,   KC_U,   KC_C,   KC_K, KC_BSPC,
        KC_Y,   KC_O,   KC_U,   MO(1),
        KC_SPC, KC_SPC, KC_SPC, KC_SPC
    ),

    [1] = LAYOUT_all(
<<<<<<< HEAD
      RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
=======
      QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
>>>>>>> upstream/master:keyboards/keebzdotnet/fme/keymaps/default/keymap.c
>>>>>>> upstream/master
};
