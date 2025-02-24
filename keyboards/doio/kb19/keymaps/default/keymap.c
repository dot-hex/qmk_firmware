<<<<<<< HEAD:keyboards/paprikman/albacore/keymaps/via/keymap.c
/* Copyright 2021 paprikman
=======
/* Copyright 2022 DOIO
 * Copyright 2022 DOIO2022 <https://github.com/DOIO2022>
>>>>>>> upstream/master:keyboards/doio/kb19/keymaps/default/keymap.c
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
<<<<<<< HEAD:keyboards/paprikman/albacore/keymaps/via/keymap.c
          KC_VOLD, KC_MUTE, KC_VOLU,
    MO(1), KC_MPRV, KC_MPLY, KC_MNXT
  ),
  [1] = LAYOUT(
          RGB_TOG, RGB_MOD, RGB_VAI,
    _______, RGB_SPI, RGB_SPD, RGB_VAD
  ),
  [2] = LAYOUT(
            _______, _______, _______,
    _______, _______, _______, _______
  ),
  [3] = LAYOUT(
            _______, _______, _______,
    _______, _______, _______, _______
  ),
};
=======
        KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, UG_NEXT,
        KC_P7,  KC_P8,   KC_P9,   KC_PPLS, UG_TOGG,
        KC_P4,  KC_P5,   KC_P6,
        KC_P1,  KC_P2,   KC_P3,   KC_PENT,
        KC_P0,  KC_PDOT, KC_MUTE
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
>>>>>>> upstream/master:keyboards/doio/kb19/keymaps/default/keymap.c
