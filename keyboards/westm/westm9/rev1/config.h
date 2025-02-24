/* Copyright 2021 WestM
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

<<<<<<< HEAD:keyboards/handwired/tractyl_manuform/4x6_right/keymaps/drashna/config.h
// #define USE_I2C
// #define SELECT_SOFT_SERIAL_SPEED 1
// #define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_MODS_ENABLE
#define EE_HANDS

#define TRACKBALL_DPI_OPTIONS { 1200, 1800, 2600, 3400 }

#define RGBLIGHT_MAX_BRIGHTNESS 60

#undef DEBOUNCE
#define DEBOUNCE 10

#define SOLENOID_PIN F1
#define SOLENOID_DEFAULT_DWELL 8

#define OLED_DISPLAY_128X64
#define OLED_BRIGHTNESS 50
=======
/* Default Oled init */
#define OLED_DISPLAY_128X64
#define OLED_BRIGHTNESS 255

/* I2C for Oled */
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

/* Required for SH1106 Oled Driver */
#define OLED_IC OLED_IC_SH1106
#define OLED_COLUMN_OFFSET 2 // SH1106 screen is a little off to the left

#define I2C1_TIMINGR_PRESC 0x00U
#define I2C1_TIMINGR_SCLDEL 0x03U
#define I2C1_TIMINGR_SDADEL 0x01U
#define I2C1_TIMINGR_SCLH 0x03U
#define I2C1_TIMINGR_SCLL 0x09U

#define OLED_UPDATE_INTERVAL 66
>>>>>>> upstream/master:keyboards/westm/westm9/rev1/config.h
