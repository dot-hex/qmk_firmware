<<<<<<< HEAD:keyboards/takashicompany/dogtag/dogtag.c
/* Copyright 2021 takashicompany
=======
/* Copyright 2022 Harrison Chan (Xelus)
>>>>>>> upstream/master:keyboards/aeboards/ext65/rev3/rev3.c
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

<<<<<<< HEAD:keyboards/takashicompany/dogtag/dogtag.c
#include "dogtag.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (clockwise) {
        tap_code(KC_MS_WH_DOWN);
    } else {
        tap_code(KC_MS_WH_UP);
    }

    return true;
=======
#include "quantum.h"

// Tested and verified working on EXT65 Rev3
void matrix_io_delay(void) { __asm__ volatile("nop\nnop\nnop\n"); }

void keyboard_pre_init_kb(void) {
  // Call the keyboard pre init code.
  // Set our LED pins as output
  gpio_set_pin_output(LED_LAYERS_PIN);

  keyboard_pre_init_user();
>>>>>>> upstream/master:keyboards/aeboards/ext65/rev3/rev3.c
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(state)) {
      case 1:
        gpio_write_pin_high(LED_LAYERS_PIN);
        break;
      default: //  for any other layers, or the default layer
        gpio_write_pin_low(LED_LAYERS_PIN);
        break;
      }
    return layer_state_set_user(state);
}
