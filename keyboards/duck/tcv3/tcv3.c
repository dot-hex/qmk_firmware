/* Copyright 2019 MechMerlin <mechmerlin@gmail.com>
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
#include "quantum.h"
#include "indicator_leds.h"

enum BACKLIGHT_AREAS {
  BACKLIGHT_ALPHA    = 0b0000001,
  BACKLIGHT_FROW     = 0b0000010,
  BACKLIGHT_MOD      = 0b0000100,
  BACKLIGHT_MACRO    = 0b0001000,
  BACKLIGHT_SWITCH   = 0b0001111
};

// Q5, Q6, Q7 is connected to B1 - alphas
// Q8, Q9 is connected to B2 - frow
// Q1, Q2, Q3 is connected to B3 - mods
// Q4 is connected to E6 - macro keys 

void backlight_set(uint8_t level) {
  level & BACKLIGHT_ALPHA ? (PORTB |= 0b00000010) : (PORTB &= ~0b00000010);
  level & BACKLIGHT_FROW ? (PORTB |= 0b00000100) : (PORTB &= ~0b00000100);
  level & BACKLIGHT_MOD ? (PORTB |= 0b00001000) : (PORTB &= ~0b00001000);
  level & BACKLIGHT_MACRO ? (PORTE |= 0b01000000) : (PORTE &= ~0b01000000);
}

<<<<<<< HEAD
// // Port from backlight_update_state
// void led_set_kb(uint8_t usb_led) {
//     bool status[7] = {
//     backlight_os_state & (1<<USB_LED_CAPS_LOCK),
//     backlight_os_state & (1<<USB_LED_SCROLL_LOCK),
//     backlight_os_state & (1<<USB_LED_NUM_LOCK),
//     backlight_layer_state & (1<<1),
//     backlight_layer_state & (1<<2),
//     backlight_layer_state & (1<<3),
//     backlight_layer_state & (1<<4)
//   };
//   indicator_leds_set(status);
//   backlight_os_state & (1<<USB_LED_CAPS_LOCK) ? (PORTB &= ~0b00000001) : (PORTB |= 0b00000001);
//   backlight_os_state & (1<<USB_LED_SCROLL_LOCK) ? (PORTB &= ~0b00010000) : (PORTB |= 0b00010000);
// }

=======
>>>>>>> upstream/master
// U5 Pin 1, 2, 3 connected to top left LEDs

// U6 Pin 1, 2, 3 connected to bottom right leds col of 3
// U7 Pin 1 connected to row connected to bottom right leds solo LED
// U7 Pin 2, 3 connected to bottom right leds row of 2
// U6 Pin 5 connected to U7 Pin 6

// U5 pin 5 connected to U6 Pin 6

// U5, U6, U7 Pin 8 VCC
// U5, U6, U7 Pin 4 GRND

// U5 Pin 6 connected to atmega32u4 D4
