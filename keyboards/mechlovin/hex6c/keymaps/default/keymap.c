/* Copyright 2021 Mechlovin' Studio
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
<<<<<<< HEAD
    [0] = LAYOUT_ALL(
=======
    [0] = LAYOUT_all(
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
        KC_CALC, KC_MAIL, KC_MYCM, KC_MUTE,   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,             KC_PSCR, KC_SLCK, KC_PAUS,
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL,   KC_INS,  KC_HOME, KC_PGUP,
=======
    [0] = LAYOUT_all(
        KC_CALC, KC_MAIL, KC_MYCM, KC_MUTE,   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,             KC_PSCR, KC_SCRL, KC_PAUS,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL,   KC_INS,  KC_HOME, KC_PGUP,
>>>>>>> upstream/master
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,            KC_DEL,  KC_END,  KC_PGDN,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,   KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_SPC,                      KC_UP,
        KC_0,    KC_PCMM, KC_PDOT, KC_PEQL,   KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(1), KC_RCTL,              KC_LEFT, KC_DOWN, KC_RGHT
    ),

};

#ifdef ENCODER_ENABLE
<<<<<<< HEAD
<<<<<<< HEAD
void encoder_update_user(uint8_t index, bool clockwise) {
=======
bool encoder_update_user(uint8_t index, bool clockwise) {
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
=======
bool encoder_update_user(uint8_t index, bool clockwise) {
>>>>>>> upstream/master
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RGHT);
        }
    }
    else if (index == 2) {
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
}

  #endif
=======
    return true;
}
#endif
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
=======
    return true;
}
#endif
>>>>>>> upstream/master
