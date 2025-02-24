/* Copyright 2018 MechMerlin

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

#pragma once

#include "quantum.h"

<<<<<<< HEAD:keyboards/treasure/type9/type9.h
/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01, k02, \
    k10, k11, k12, \
    k20, k21, k22 \
) { \
    { k00, k01, k02 }, \
    { k10, k11, k12 }, \
    { k20, k21, k22 } \
}
=======
#define KIRA75_CAPS_LOCK_LED_PIN D7
#define KIRA75_NUM_LOCK_LED_PIN D6

// Functions for setting LEDs on toggle keys
inline void caps_led_on(void) {
    gpio_set_pin_output(KIRA75_CAPS_LOCK_LED_PIN);
    gpio_write_pin_low(KIRA75_CAPS_LOCK_LED_PIN);
}
inline void caps_led_off(void) {
    gpio_set_pin_input(KIRA75_CAPS_LOCK_LED_PIN);
}

inline void num_led_on(void) {
    gpio_set_pin_output(KIRA75_NUM_LOCK_LED_PIN);
    gpio_write_pin_low(KIRA75_NUM_LOCK_LED_PIN);
}
inline void num_led_off(void) {
    gpio_set_pin_input(KIRA75_NUM_LOCK_LED_PIN);
}
>>>>>>> upstream/master:keyboards/kira/kira75/kira75.h
