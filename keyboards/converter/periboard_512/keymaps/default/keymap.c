/* Copyright 2021 Sife
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
  [0] = LAYOUT( /* Base layer */
<<<<<<< HEAD
    KC_ESC,         KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5,         KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,         KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,   KC_7,  KC_8,  KC_9,  KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    LALT_T(KC_TAB), KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,   KC_U,  KC_I,  KC_O,  KC_P,    KC_LBRC, KC_RBRC, RALT_T(KC_BSLS),  KC_DEL,  KC_END,  KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,  KC_F,  KC_G,          KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT, RCTL_T(KC_BSPC),                              KC_P4,   KC_P5,   KC_P6,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,                 KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    MO(1),          KC_LALT, LGUI_T(KC_F13),               KC_SPC,        RGUI_T(KC_F13), RALT_T(KC_ENT), KC_HENK, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,  KC_P0,            KC_PDOT
=======
    KC_ESC,         KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5,         KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,
    KC_GRV,         KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,   KC_7,  KC_8,  KC_9,  KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    LALT_T(KC_TAB), KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,   KC_U,  KC_I,  KC_O,  KC_P,    KC_LBRC, KC_RBRC, RALT_T(KC_BSLS),  KC_DEL,  KC_END,  KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,  KC_F,  KC_G,          KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT, RCTL_T(KC_BSPC),                              KC_P4,   KC_P5,   KC_P6,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,                 KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    MO(1),          KC_LALT, LGUI_T(KC_F13),               KC_SPC,        RGUI_T(KC_F13), RALT_T(KC_ENT), KC_INT4, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,  KC_P0,            KC_PDOT
>>>>>>> upstream/master
  ),

  [1] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,                              _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_DOWN, KC_ENT,  _______, _______, _______, _______,           _______,           _______, _______, _______, _______,
    _______, MO(2),   _______,                   _______,                                     _______, _______, _______, _______,  _______, _______, _______,  _______,          _______
  ),

  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_PGDN, KC_PGUP, _______, _______, _______, _______,                              _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,           _______,           _______, _______, _______, _______,
    _______, _______, _______,                   _______,                                     _______, _______, _______, _______,  _______, _______, _______,  _______,          _______
  ),

  /* [<++>] = LAYOUT( */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,                              _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,           _______,           _______, _______, _______, _______, */
  /*   _______, _______, _______,                   _______,                                     _______, _______, _______, _______,  _______, _______, _______,  _______,          _______ */
  /* ), */

};
