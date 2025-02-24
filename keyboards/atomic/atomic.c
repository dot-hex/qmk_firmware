/* Copyright 2015 Jack Humbert
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

<<<<<<< HEAD
#include "atomic.h"
=======
#include "quantum.h"
>>>>>>> upstream/master

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    // Turn status LED on
<<<<<<< HEAD
    setPinOutput(E6);
    writePinHigh(E6);
=======
    gpio_set_pin_output(E6);
    gpio_write_pin_high(E6);
>>>>>>> upstream/master

    matrix_init_user();
}
