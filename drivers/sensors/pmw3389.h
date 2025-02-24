<<<<<<< HEAD
/* Copyright 2021 Alabastard (@Alabastard-64)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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
=======
// Copyright 2022 Stefan Kerkmann (KarlK90)
// Copyright 2021 Alabastard (@Alabastard-64)
// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2019 Sunjun Kim
// Copyright 2020 Ploopy Corporation
// SPDX-License-Identifier: GPL-2.0-or-later
>>>>>>> upstream/master

#pragma once

#include <stdint.h>

<<<<<<< HEAD
#ifndef PMW3389_CPI
#    define PMW3389_CPI 2000
#endif

#ifndef PMW3389_CLOCK_SPEED
#    define PMW3389_CLOCK_SPEED 2000000
#endif

#ifndef PMW3389_SPI_LSBFIRST
#    define PMW3389_SPI_LSBFIRST false
#endif

#ifndef PMW3389_SPI_MODE
#    define PMW3389_SPI_MODE 3
#endif

#ifndef PMW3389_SPI_DIVISOR
#    ifdef __AVR__
#        define PMW3389_SPI_DIVISOR (F_CPU / PMW3389_CLOCK_SPEED)
#    else
#        define PMW3389_SPI_DIVISOR 64
#    endif
#endif

#ifndef PMW3389_LIFTOFF_DISTANCE
#    define PMW3389_LIFTOFF_DISTANCE 0x02
#endif

#ifndef ROTATIONAL_TRANSFORM_ANGLE
#    define ROTATIONAL_TRANSFORM_ANGLE 0x00
#endif

#ifndef PMW3389_CS_PIN
#    error "No chip select pin defined -- missing PMW3389_CS_PIN"
#endif

typedef struct {
    int8_t  motion;
    bool    isMotion;    // True if a motion is detected.
    bool    isOnSurface; // True when a chip is on a surface
    int16_t dx;          // displacement on x directions. Unit: Count. (CPI * Count = Inch value)
    int8_t  mdx;
    int16_t dy; // displacement on y directions.
    int8_t  mdy;
} report_pmw3389_t;

bool     pmw3389_init(void);
void     pmw3389_upload_firmware(void);
bool     pmw3389_check_signature(void);
uint16_t pmw3389_get_cpi(void);
void     pmw3389_set_cpi(uint16_t cpi);
/* Reads and clears the current delta values on the sensor */
report_pmw3389_t pmw3389_read_burst(void);
=======
#if !defined(PMW33XX_CPI)
#    define PMW33XX_CPI 2000
#endif

#define PMW33XX_CPI_STEP 50
#define PMW33XX_CPI_MIN 50
#define PMW33XX_CPI_MAX 16000

// PMW3389 register addresses
// clang-format off
#define REG_Product_ID                 0x00
#define REG_Revision_ID                0x01
#define REG_Motion                     0x02
#define REG_Delta_X_L                  0x03
#define REG_Delta_X_H                  0x04
#define REG_Delta_Y_L                  0x05
#define REG_Delta_Y_H                  0x06
#define REG_SQUAL                      0x07
#define REG_RawData_Sum                0x08
#define REG_Maximum_RawData            0x09
#define REG_Minimum_RawData            0x0a
#define REG_Shutter_Lower              0x0b
#define REG_Shutter_Upper              0x0c
#define REG_Ripple_Control             0x0d
#define REG_Resolution_L               0x0e
#define REG_Resolution_H               0x0f
#define REG_Config2                    0x10
#define REG_Angle_Tune                 0x11
#define REG_Frame_Capture              0x12
#define REG_SROM_Enable                0x13
#define REG_Run_Downshift              0x14
#define REG_Rest1_Rate_Lower           0x15
#define REG_Rest1_Rate_Upper           0x16
#define REG_Rest1_Downshift            0x17
#define REG_Rest2_Rate_Lower           0x18
#define REG_Rest2_Rate_Upper           0x19
#define REG_Rest2_Downshift            0x1a
#define REG_Rest3_Rate_Lower           0x1b
#define REG_Rest3_Rate_Upper           0x1c
#define REG_Observation                0x24
#define REG_Data_Out_Lower             0x25
#define REG_Data_Out_Upper             0x26
#define REG_SROM_ID                    0x2a
#define REG_Min_SQ_Run                 0x2b
#define REG_RawData_Threshold          0x2c
#define REG_Control2                   0x2d
#define REG_Config5_L                  0x2e
#define REG_Config5_H                  0x2f
#define REG_Power_Up_Reset             0X3a
#define REG_Shutdown                   0x3b
#define REG_Inverse_Product_ID         0x3f
#define REG_LiftCutoff_Cal3            0x41
#define REG_Angle_Snap                 0x42
#define REG_LiftCutoff_Cal1            0x4a
#define REG_Motion_Burst               0x50
#define REG_SROM_Load_Burst            0x62
#define REG_Lift_Config                0x63
#define REG_RawData_Burst              0x64
#define REG_LiftCutoff_Cal2            0x65
#define REG_LiftCutoff_Cal_Timeout     0x71
#define REG_LiftCutoff_Cal_Min_Length  0x72
#define REG_PWM_Period_Cnt             0x73
#define REG_PWM_Width_Cnt              0x74
// clang-format on
>>>>>>> upstream/master
