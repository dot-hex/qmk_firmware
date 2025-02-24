/* Copyright 2019 Fate
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
  [0] = LAYOUT(
<<<<<<< HEAD
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV, KC_PGUP,
=======
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV, KC_PGUP,
>>>>>>> upstream/master
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGDN,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    MO(1),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
    KC_LCTL,          KC_LALT,          KC_SPC,  KC_LGUI,          KC_SPC,           KC_RALT,                   KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [1] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  _______, _______, _______,
<<<<<<< HEAD
    _______, _______, _______, _______, RESET,   RGB_TOG, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
    _______, RGB_MOD, RGB_RMOD,RGB_HUI, RGB_HUD, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,_______,                   _______,
    _______, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,          _______,
=======
    _______, _______, _______, _______, QK_BOOT, UG_TOGG, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
    _______, UG_NEXT, UG_PREV, UG_HUEU, UG_HUED, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,_______,                   _______,
    _______, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______, _______, _______, _______, _______, _______,          _______,
>>>>>>> upstream/master
    _______,          _______,          _______, _______,          _______,          _______,                   _______, _______, _______
  )
};
