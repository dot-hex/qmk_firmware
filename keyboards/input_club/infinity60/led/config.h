<<<<<<< HEAD
/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

#pragma once

// Keyboard Matrix Assignments
#define MATRIX_ROW_PINS { D1, D2, D3, D4, D5, D6, D7 }
#define MATRIX_COL_PINS { C0, C1, C2, C3, C4, C5, C6, C7, D0 }
#define UNUSED_PINS
=======
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define IS31FL3731_I2C_ADDRESS_1 IS31FL3731_I2C_ADDRESS_GND

#define I2C1_CLOCK_SPEED 400000
#define I2C1_SCL_PIN B0
#define I2C1_SDA_PIN B1
#define I2C1_SCL_PAL_MODE PAL_MODE_ALTERNATIVE_2
#define I2C1_SDA_PAL_MODE PAL_MODE_ALTERNATIVE_2
>>>>>>> upstream/master
