/* Copyright 2021 n2
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
<<<<<<< HEAD
#include "keymap_jp.h"
=======
#include "keymap_japanese.h"
>>>>>>> upstream/master

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DEFAULT = 0,
    _RAISE,
    _LOWER,
    _ADJUST
/*    _FN */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* DEFAULT
    * ,--------------------------------------------------------------------------------------------------------------------------------------.
    * |ZEN/HAN |   1    |   2    |   3    |   4    |   5    |        |   6    |   7    |   8    |   9    |   0    |   -    |   ^    |   \    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | TAB    |   q    |   w    |   e    |   r    |   t    |        |   y    |   u    |   i    |   o    |   p    |   @    |   [    | BSPC   |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | CAPS   |   a    |   s    |   d    |   f    |   g    |        |   h    |   j    |   k    |   l    |   ;    |   :    |   ]    | ENT    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | LSHIFT |   z    |   x    |   c    |   v    |   b    |        |   n    |   m    |   ,    |   .    |   /    |   \    |  UP    | RSHIFT |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | CTRL   | LGUI   | ALT    | MUHEN  | SPACE  | SPACE  | LOWER  | RAISE  | SPACE  | HENKAN | KANA   | APP    | LEFT   | DOWN   | RIGHT  |
    * `--------------------------------------------------------------------------------------------------------------------------------------'
    */
    [_DEFAULT] = LAYOUT(
<<<<<<< HEAD
      KC_ZKHK, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   _______,    KC_6,       KC_7,   KC_8,    KC_9,    KC_0,    JP_MINS, JP_CIRC, JP_YEN,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   _______,    KC_Y,       KC_U,   KC_I,    KC_O,    KC_P,    JP_AT  , JP_LBRC, KC_BSPC,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   _______,    KC_H,       KC_J,   KC_K,    KC_L,    KC_SCLN, JP_COLN, JP_RBRC, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   _______,    KC_N,       KC_M,   KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, KC_UP,   KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT, KC_MHEN, KC_SPC,  KC_SPC, MO(_LOWER), MO(_RAISE), KC_SPC, KC_HENK, KC_KANA, KC_APP,  KC_LEFT, KC_DOWN, KC_RGHT
=======
      JP_ZKHK, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   _______,    KC_6,       KC_7,   KC_8,    KC_9,    KC_0,    JP_MINS, JP_CIRC, JP_YEN,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   _______,    KC_Y,       KC_U,   KC_I,    KC_O,    KC_P,    JP_AT  , JP_LBRC, KC_BSPC,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   _______,    KC_H,       KC_J,   KC_K,    KC_L,    KC_SCLN, JP_COLN, JP_RBRC, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   _______,    KC_N,       KC_M,   KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, KC_UP,   KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT, JP_MHEN, KC_SPC,  KC_SPC, MO(_LOWER), MO(_RAISE), KC_SPC, JP_HENK, JP_KANA, KC_APP,  KC_LEFT, KC_DOWN, KC_RGHT
>>>>>>> upstream/master
    ),
   /* RAISE
    * ,--------------------------------------------------------------------------------------------------------------------------------------.
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |   1    |   2    |   3    |   4    |   5    |        |   6    |   7    |   8    |   9    |   0    |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * `--------------------------------------------------------------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
   /* LOWER
    * ,--------------------------------------------------------------------------------------------------------------------------------------.
<<<<<<< HEAD
    * |        |        |        |        |        |        |RGB_TOG |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |RGB_VAI |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |RGB_HUI |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |RGB_SAI |        |        |        |        |        |        |        |        |
=======
    * |        |        |        |        |        |        |UG_TOGG |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |UG_VALU |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |UG_HUEU |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |UG_SATU |        |        |        |        |        |        |        |        |
>>>>>>> upstream/master
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * `--------------------------------------------------------------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT(
<<<<<<< HEAD
      _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,
=======
      _______, _______, _______, _______, _______, _______, UG_TOGG, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, UG_VALU, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, UG_HUEU, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, UG_SATU, _______, _______, _______, _______, _______, _______, _______, _______,
>>>>>>> upstream/master
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
   /* ADJUST
    * ,--------------------------------------------------------------------------------------------------------------------------------------.
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * `--------------------------------------------------------------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
