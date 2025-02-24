/*
Copyright 2021 Martin Arnstad
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
#include "edda.h"
=======
#include "quantum.h"
>>>>>>> upstream/master

void keyboard_pre_init_kb(void) {
  // Call the keyboard pre init code.
  keyboard_pre_init_user();

  // Set our LED pins as output
<<<<<<< HEAD
  setPinOutput(B2);
  setPinOutput(B1);
  setPinOutput(B0);
=======
  gpio_set_pin_output(B2);
  gpio_set_pin_output(B1);
  gpio_set_pin_output(B0);
>>>>>>> upstream/master
}

__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
<<<<<<< HEAD
        writePin(B2, 1);
        writePin(B1, 0);
        writePin(B0, 0);
        break;
    case 2:
        writePin(B2, 1);
        writePin(B1, 1);
        writePin(B0, 0);
        break;
    case 3:
        writePin(B2, 1);
        writePin(B1, 1);
        writePin(B0, 1);
        break;
    default: //  for any other layers, or the default layer
        writePin(B2, 0);
        writePin(B1, 0);
        writePin(B0, 0);
=======
        gpio_write_pin(B2, 1);
        gpio_write_pin(B1, 0);
        gpio_write_pin(B0, 0);
        break;
    case 2:
        gpio_write_pin(B2, 1);
        gpio_write_pin(B1, 1);
        gpio_write_pin(B0, 0);
        break;
    case 3:
        gpio_write_pin(B2, 1);
        gpio_write_pin(B1, 1);
        gpio_write_pin(B0, 1);
        break;
    default: //  for any other layers, or the default layer
        gpio_write_pin(B2, 0);
        gpio_write_pin(B1, 0);
        gpio_write_pin(B0, 0);
>>>>>>> upstream/master
        break;
    }
  return state;
}
