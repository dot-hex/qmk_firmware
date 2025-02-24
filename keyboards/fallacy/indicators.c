/* Copyright 2020 B. Fletcher (toraifu) <typefast@kyaa.gg>
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

#include "indicators.h"
<<<<<<< HEAD
#include "drivers/led/issi/is31fl3731-simple.h"
=======
#include "drivers/led/issi/is31fl3731-mono.h"
>>>>>>> upstream/master
#include "i2c_master.h"

/* Set up IS31FL3731 for use in powering indicator LEDs. Absolutely overkill for this job but it was already in the design.
 * init IS31FL3731 and i2c
 */
void init_fallacy_leds(void) {
    is31fl3731_init_drivers();
}


/* update the buffer
 */
void update_fallacy_leds(void) {
    is31fl3731_flush();
}


/* wrapper to actually set the LED PWM
 */
void set_fallacy_led(int index, bool state) {
    if (state) {
        is31fl3731_set_value(index, 128);
    } 
    else {
        is31fl3731_set_value(index, 0);
    }
}


/* define LED matrix
 */
<<<<<<< HEAD
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
=======
const is31fl3731_led_t PROGMEM g_is31fl3731_leds[IS31FL3731_LED_COUNT] = {
>>>>>>> upstream/master
    {0, C1_1},
    {0, C2_1},
    {0, C3_1},
};
