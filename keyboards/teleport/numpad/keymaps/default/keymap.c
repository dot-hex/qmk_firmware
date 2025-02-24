/* Copyright 2021 Moritz Plattner
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
<<<<<<< HEAD

  [0] = LAYOUT_numpad_5x4(
    LT(1, KC_NLCK), KC_PSLS,  KC_PAST, KC_PMNS,
=======
<<<<<<<< HEAD:keyboards/40percentclub/25/keymaps/macro/keymap.c
  [0] = LAYOUT_macro(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,
    KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC,  KC_SPC
========

  [0] = LAYOUT_numpad_5x4(
    LT(1, KC_NUM),  KC_PSLS,  KC_PAST, KC_PMNS,
>>>>>>> upstream/master
    KC_P7,          KC_P8,    KC_P9,
    KC_P4,          KC_P5,    KC_P6,   KC_PPLS,
    KC_P1,          KC_P2,    KC_P3,
              KC_P0,          KC_PDOT,  KC_PENT
  ),

  [1] = LAYOUT_numpad_5x4(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
<<<<<<< HEAD
             KC_TRNS, KC_TRNS, RESET
=======
             KC_TRNS, KC_TRNS, QK_BOOT
>>>>>>>> upstream/master:keyboards/teleport/numpad/keymaps/default/keymap.c
>>>>>>> upstream/master
  ),
};
