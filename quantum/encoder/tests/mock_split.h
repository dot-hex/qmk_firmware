/* Copyright 2021 Balz Guenat
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

#pragma once

#include <stdint.h>
#include <stdbool.h>

#define SPLIT_KEYBOARD
<<<<<<< HEAD
/* Here, "pins" from 0 to 31 are allowed. */
#define ENCODERS_PAD_A \
    { 0 }
#define ENCODERS_PAD_B \
    { 1 }
#define ENCODERS_PAD_A_RIGHT \
    { 2 }
#define ENCODERS_PAD_B_RIGHT \
    { 3 }

typedef uint8_t pin_t;
extern bool     isLeftHand;
void            encoder_state_raw(uint8_t* slave_state);
void            encoder_update_raw(uint8_t* slave_state);
=======
typedef uint8_t pin_t;
>>>>>>> upstream/master

extern bool pins[];
extern bool pinIsInputHigh[];

<<<<<<< HEAD
#define setPinInputHigh(pin) (mockSetPinInputHigh(pin))
#define readPin(pin) (mockReadPin(pin))

uint8_t mockSetPinInputHigh(pin_t pin);

bool mockReadPin(pin_t pin);
=======
#define gpio_set_pin_input_high(pin) (mock_set_pin_input_high(pin))
#define gpio_read_pin(pin) (mock_read_pin(pin))

uint8_t mock_set_pin_input_high(pin_t pin);

bool mock_read_pin(pin_t pin);
>>>>>>> upstream/master

bool setPin(pin_t pin, bool val);
