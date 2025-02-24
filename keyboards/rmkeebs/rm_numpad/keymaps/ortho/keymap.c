/* Copyright 2021 RuckerMachine
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

enum custom_keycodes {
  DBL_ZRO = SAFE_RANGE,
};

<<<<<<< HEAD:keyboards/takashiski/namecard2x4/keymaps/brainfuck/keymap.c


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[JP] = LAYOUT(
		JP_LABK,JP_RABK,JP_PLUS,JP_MINS,\
		LT(CONFIG,JP_DOT),JP_COMM,JP_LBRC,LT(CONFIG,JP_RBRC)\
		),
[EN] = LAYOUT(
		KC_LT,KC_GT,KC_PLUS,KC_MINS,\
		LT(CONFIG,KC_DOT),KC_COMM,KC_LBRC,LT(CONFIG,KC_RBRC)\
		),
[CONFIG]= LAYOUT(
		KC_NO,DF(JP),DF(JP),KC_NO,\
		KC_TRNS,DF(EN),DF(JP),KC_TRNS\
		)

};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

=======
>>>>>>> upstream/master:keyboards/rmkeebs/rm_numpad/keymaps/ortho/keymap.c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DBL_ZRO:
      if (record->event.pressed) {
        // when keycode DBL_ZRO is pressed
        SEND_STRING("00");
      } else {
        // when keycode DBL_ZRO is released
      }
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    LAYOUT_ortho_6x4(
        KC_MPLY, KC_MPRV, KC_MNXT, KC_MUTE,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, 
        KC_P7,   KC_P8,   KC_P9,   KC_EQL,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS, 
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,   DBL_ZRO, KC_PDOT, KC_DEL
    )
};

