/* Copyright 2021 QMK
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


<<<<<<< HEAD
#define PRODUCT Onekey Blackpill STM32F411

#define MATRIX_COL_PINS { B0 }
#define MATRIX_ROW_PINS { A7 }
#define UNUSED_PINS

#define BACKLIGHT_PIN         A0
#define BACKLIGHT_PWM_DRIVER  PWMD5
#define BACKLIGHT_PWM_CHANNEL 1

#define RGB_DI_PIN A1
=======
#define BACKLIGHT_PWM_DRIVER  PWMD5
#define BACKLIGHT_PWM_CHANNEL 1
>>>>>>> upstream/master

#define ADC_PIN A0

#define SOLENOID_PIN B12
#define SOLENOID_PINS { B12, B13, B14, B15 }
#define SOLENOID_PINS_ACTIVE_STATE { high, high, low }
