/* Copyright 2017 Jason Williams
 * Copyright 2018 Jack Humbert
 * Copyright 2018 Yiancar
 * Copyright 2020 MelGeek
 * Copyright 2021 MasterSpoon
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
// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 00 <-> GND
// 01 <-> SCL
// 10 <-> SDA
// 11 <-> VCC
// ADDR1 represents A1:A0 of the 7-bit address.
// ADDR2 represents A3:A2 of the 7-bit address.
// The result is: 0b010(ADDR2)(ADDR1)
#ifndef DRIVER_ADDR_1
#    define DRIVER_ADDR_1 0b0100000
#endif

// Set defaults for Spread Spectrum Register
#ifndef ISSI_SSR_1
#    if DRIVER_COUNT == 1
#        define ISSI_SSR_1 0x00
#    else
#        define ISSI_SSR_1 0xC0
#    endif
#endif
#ifndef ISSI_SSR_2
#    define ISSI_SSR_2 0x80
#endif
#ifndef ISSI_SSR_3
#    define ISSI_SSR_3 0x80
#endif
#ifndef ISSI_SSR_4
#    define ISSI_SSR_4 0x80
#endif

// Command Registers
#define ISSI_COMMANDREGISTER_WRITELOCK 0xFE
#define ISSI_COMMANDREGISTER 0xFD
#define ISSI_IDREGISTER 0xFC
#define ISSI_REGISTER_UNLOCK 0xC5

// Response Registers
#define ISSI_PAGE_PWM 0x00
#define ISSI_PAGE_SCALING 0x01
#define ISSI_PAGE_FUNCTION 0x02

// Registers under Function Register
#define ISSI_REG_CONFIGURATION 0x00
#define ISSI_REG_GLOBALCURRENT 0x01
#define ISSI_REG_PULLDOWNUP 0x02
#define ISSI_REG_TEMP 0x24
#define ISSI_REG_SSR 0x25
#define ISSI_REG_RESET 0x2F

// Set defaults for Function Registers
#ifndef ISSI_CONFIGURATION
#    define ISSI_CONFIGURATION 0x31
#endif
#ifndef ISSI_GLOBALCURRENT
#    define ISSI_GLOBALCURRENT 0xFF
#endif
#ifndef ISSI_PULLDOWNUP
#    define ISSI_PULLDOWNUP 0x33
#endif
#ifndef ISSI_TEMP
#    define ISSI_TEMP 0x00
#endif

// Set defaults for Scaling registers
#ifndef ISSI_SCAL_RED
#    define ISSI_SCAL_RED 0xFF
#endif
#ifndef ISSI_SCAL_BLUE
#    define ISSI_SCAL_BLUE 0xFF
#endif
#ifndef ISSI_SCAL_GREEN
#    define ISSI_SCAL_GREEN 0xFF
#endif
#define ISSI_SCAL_RED_OFF 0x00
#define ISSI_SCAL_GREEN_OFF 0x00
#define ISSI_SCAL_BLUE_OFF 0x00

#ifndef ISSI_SCAL_LED
#    define ISSI_SCAL_LED 0xFF
#endif
#define ISSI_SCAL_LED_OFF 0x00

// Set buffer sizes
#define ISSI_MAX_LEDS 144
#define ISSI_SCALING_SIZE 144
#define ISSI_PWM_TRF_SIZE 18
#define ISSI_SCALING_TRF_SIZE 18

// Location of 1st bit for PWM and Scaling registers
#define ISSI_PWM_REG_1ST 0x01
#define ISSI_SCL_REG_1ST 0x01

// Map CS SW locations to order in PWM / Scaling buffers
// This matches the ORDER in the Datasheet Register not the POSITION
// It will always count from 0x00 to (ISSI_MAX_LEDS - 1)
#define CS1_SW1 0x00
#define CS2_SW1 0x01
#define CS3_SW1 0x02
#define CS4_SW1 0x03
#define CS5_SW1 0x04
#define CS6_SW1 0x05
#define CS7_SW1 0x06
#define CS8_SW1 0x07
#define CS9_SW1 0x08
#define CS10_SW1 0x09
#define CS11_SW1 0x0A
#define CS12_SW1 0x0B
#define CS13_SW1 0x0C
#define CS14_SW1 0x0D
#define CS15_SW1 0x0E
#define CS16_SW1 0x0F
#define CS17_SW1 0x10
#define CS18_SW1 0x11

#define CS1_SW2 0x12
#define CS2_SW2 0x13
#define CS3_SW2 0x14
#define CS4_SW2 0x15
#define CS5_SW2 0x16
#define CS6_SW2 0x17
#define CS7_SW2 0x18
#define CS8_SW2 0x19
#define CS9_SW2 0x1A
#define CS10_SW2 0x1B
#define CS11_SW2 0x1C
#define CS12_SW2 0x1D
#define CS13_SW2 0x1E
#define CS14_SW2 0x1F
#define CS15_SW2 0x20
#define CS16_SW2 0x21
#define CS17_SW2 0x22
#define CS18_SW2 0x23

#define CS1_SW3 0x24
#define CS2_SW3 0x25
#define CS3_SW3 0x26
#define CS4_SW3 0x27
#define CS5_SW3 0x28
#define CS6_SW3 0x29
#define CS7_SW3 0x2A
#define CS8_SW3 0x2B
#define CS9_SW3 0x2C
#define CS10_SW3 0x2D
#define CS11_SW3 0x2E
#define CS12_SW3 0x2F
#define CS13_SW3 0x30
#define CS14_SW3 0x31
#define CS15_SW3 0x32
#define CS16_SW3 0x33
#define CS17_SW3 0x34
#define CS18_SW3 0x35

#define CS1_SW4 0x36
#define CS2_SW4 0x37
#define CS3_SW4 0x38
#define CS4_SW4 0x39
#define CS5_SW4 0x3A
#define CS6_SW4 0x3B
#define CS7_SW4 0x3C
#define CS8_SW4 0x3D
#define CS9_SW4 0x3E
#define CS10_SW4 0x3F
#define CS11_SW4 0x40
#define CS12_SW4 0x41
#define CS13_SW4 0x42
#define CS14_SW4 0x43
#define CS15_SW4 0x44
#define CS16_SW4 0x45
#define CS17_SW4 0x46
#define CS18_SW4 0x47

#define CS1_SW5 0x48
#define CS2_SW5 0x49
#define CS3_SW5 0x4A
#define CS4_SW5 0x4B
#define CS5_SW5 0x4C
#define CS6_SW5 0x4D
#define CS7_SW5 0x4E
#define CS8_SW5 0x4F
#define CS9_SW5 0x50
#define CS10_SW5 0x51
#define CS11_SW5 0x52
#define CS12_SW5 0x53
#define CS13_SW5 0x54
#define CS14_SW5 0x55
#define CS15_SW5 0x56
#define CS16_SW5 0x57
#define CS17_SW5 0x58
#define CS18_SW5 0x59

#define CS1_SW6 0x5A
#define CS2_SW6 0x5B
#define CS3_SW6 0x5C
#define CS4_SW6 0x5D
#define CS5_SW6 0x5E
#define CS6_SW6 0x5F
#define CS7_SW6 0x60
#define CS8_SW6 0x61
#define CS9_SW6 0x62
#define CS10_SW6 0x63
#define CS11_SW6 0x64
#define CS12_SW6 0x65
#define CS13_SW6 0x66
#define CS14_SW6 0x67
#define CS15_SW6 0x68
#define CS16_SW6 0x69
#define CS17_SW6 0x6A
#define CS18_SW6 0x6B

#define CS1_SW7 0x6C
#define CS2_SW7 0x6D
#define CS3_SW7 0x6E
#define CS4_SW7 0x6F
#define CS5_SW7 0x70
#define CS6_SW7 0x71
#define CS7_SW7 0x72
#define CS8_SW7 0x73
#define CS9_SW7 0x74
#define CS10_SW7 0x75
#define CS11_SW7 0x76
#define CS12_SW7 0x77
#define CS13_SW7 0x78
#define CS14_SW7 0x79
#define CS15_SW7 0x7A
#define CS16_SW7 0x7B
#define CS17_SW7 0x7C
#define CS18_SW7 0x7D

#define CS1_SW8 0x7E
#define CS2_SW8 0x7F
#define CS3_SW8 0x80
#define CS4_SW8 0x81
#define CS5_SW8 0x82
#define CS6_SW8 0x83
#define CS7_SW8 0x84
#define CS8_SW8 0x85
#define CS9_SW8 0x86
#define CS10_SW8 0x87
#define CS11_SW8 0x88
#define CS12_SW8 0x89
#define CS13_SW8 0x8A
#define CS14_SW8 0x8B
#define CS15_SW8 0x8C
#define CS16_SW8 0x8D
#define CS17_SW8 0x8E
#define CS18_SW8 0x8F
=======
#include <stdint.h>
#include <stdbool.h>
#include "progmem.h"
#include "util.h"

#define IS31FL3745_REG_ID 0xFC

#define IS31FL3745_REG_COMMAND 0xFD

#define IS31FL3745_COMMAND_PWM 0x00
#define IS31FL3745_COMMAND_SCALING 0x01
#define IS31FL3745_COMMAND_FUNCTION 0x02

#define IS31FL3745_FUNCTION_REG_CONFIGURATION 0x00
#define IS31FL3745_FUNCTION_REG_GLOBAL_CURRENT 0x01
#define IS31FL3745_FUNCTION_REG_PULLDOWNUP 0x02
#define IS31FL3745_FUNCTION_REG_TEMPERATURE 0x24
#define IS31FL3745_FUNCTION_REG_SPREAD_SPECTRUM 0x25
#define IS31FL3745_FUNCTION_REG_RESET 0x2F

#define IS31FL3745_REG_COMMAND_WRITE_LOCK 0xFE
#define IS31FL3745_COMMAND_WRITE_LOCK_MAGIC 0xC5

#define IS31FL3745_I2C_ADDRESS_GND_GND 0x20
#define IS31FL3745_I2C_ADDRESS_GND_SCL 0x21
#define IS31FL3745_I2C_ADDRESS_GND_SDA 0x22
#define IS31FL3745_I2C_ADDRESS_GND_VCC 0x23
#define IS31FL3745_I2C_ADDRESS_SCL_GND 0x24
#define IS31FL3745_I2C_ADDRESS_SCL_SCL 0x25
#define IS31FL3745_I2C_ADDRESS_SCL_SDA 0x26
#define IS31FL3745_I2C_ADDRESS_SCL_VCC 0x27
#define IS31FL3745_I2C_ADDRESS_SDA_GND 0x28
#define IS31FL3745_I2C_ADDRESS_SDA_SCL 0x29
#define IS31FL3745_I2C_ADDRESS_SDA_SDA 0x2A
#define IS31FL3745_I2C_ADDRESS_SDA_VCC 0x2B
#define IS31FL3745_I2C_ADDRESS_VCC_GND 0x2C
#define IS31FL3745_I2C_ADDRESS_VCC_SCL 0x2D
#define IS31FL3745_I2C_ADDRESS_VCC_SDA 0x2E
#define IS31FL3745_I2C_ADDRESS_VCC_VCC 0x2F

#if defined(RGB_MATRIX_IS31FL3745)
#    define IS31FL3745_LED_COUNT RGB_MATRIX_LED_COUNT
#endif

#if defined(IS31FL3745_I2C_ADDRESS_4)
#    define IS31FL3745_DRIVER_COUNT 4
#elif defined(IS31FL3745_I2C_ADDRESS_3)
#    define IS31FL3745_DRIVER_COUNT 3
#elif defined(IS31FL3745_I2C_ADDRESS_2)
#    define IS31FL3745_DRIVER_COUNT 2
#elif defined(IS31FL3745_I2C_ADDRESS_1)
#    define IS31FL3745_DRIVER_COUNT 1
#endif

typedef struct is31fl3745_led_t {
    uint8_t driver : 2;
    uint8_t r;
    uint8_t g;
    uint8_t b;
} PACKED is31fl3745_led_t;

extern const is31fl3745_led_t PROGMEM g_is31fl3745_leds[IS31FL3745_LED_COUNT];

void is31fl3745_init_drivers(void);
void is31fl3745_init(uint8_t index);
void is31fl3745_write_register(uint8_t index, uint8_t reg, uint8_t data);
void is31fl3745_select_page(uint8_t index, uint8_t page);

void is31fl3745_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);
void is31fl3745_set_color_all(uint8_t red, uint8_t green, uint8_t blue);

void is31fl3745_set_scaling_register(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);

void is31fl3745_update_pwm_buffers(uint8_t index);
void is31fl3745_update_scaling_registers(uint8_t index);

void is31fl3745_flush(void);

#define IS31FL3745_PDR_0_OHM 0b000          // No pull-down resistor
#define IS31FL3745_PDR_0K5_OHM_SW_OFF 0b001 // 0.5 kOhm resistor in SWx off time
#define IS31FL3745_PDR_1K_OHM_SW_OFF 0b010  // 1 kOhm resistor in SWx off time
#define IS31FL3745_PDR_2K_OHM_SW_OFF 0b011  // 2 kOhm resistor in SWx off time
#define IS31FL3745_PDR_1K_OHM 0b100         // 1 kOhm resistor
#define IS31FL3745_PDR_2K_OHM 0b101         // 2 kOhm resistor
#define IS31FL3745_PDR_4K_OHM 0b110         // 4 kOhm resistor
#define IS31FL3745_PDR_8K_OHM 0b111         // 8 kOhm resistor

#define IS31FL3745_PUR_0_OHM 0b000          // No pull-up resistor
#define IS31FL3745_PUR_0K5_OHM_CS_OFF 0b001 // 0.5 kOhm resistor in CSy off time
#define IS31FL3745_PUR_1K_OHM_CS_OFF 0b010  // 1 kOhm resistor in CSy off time
#define IS31FL3745_PUR_2K_OHM_CS_OFF 0b011  // 2 kOhm resistor in CSy off time
#define IS31FL3745_PUR_1K_OHM 0b100         // 1 kOhm resistor
#define IS31FL3745_PUR_2K_OHM 0b101         // 2 kOhm resistor
#define IS31FL3745_PUR_4K_OHM 0b110         // 4 kOhm resistor
#define IS31FL3745_PUR_8K_OHM 0b111         // 8 kOhm resistor

#define IS31FL3745_SYNC_NONE 0b00
#define IS31FL3745_SYNC_SLAVE 0b10
#define IS31FL3745_SYNC_MASTER 0b11

#define SW1_CS1 0x00
#define SW1_CS2 0x01
#define SW1_CS3 0x02
#define SW1_CS4 0x03
#define SW1_CS5 0x04
#define SW1_CS6 0x05
#define SW1_CS7 0x06
#define SW1_CS8 0x07
#define SW1_CS9 0x08
#define SW1_CS10 0x09
#define SW1_CS11 0x0A
#define SW1_CS12 0x0B
#define SW1_CS13 0x0C
#define SW1_CS14 0x0D
#define SW1_CS15 0x0E
#define SW1_CS16 0x0F
#define SW1_CS17 0x10
#define SW1_CS18 0x11

#define SW2_CS1 0x12
#define SW2_CS2 0x13
#define SW2_CS3 0x14
#define SW2_CS4 0x15
#define SW2_CS5 0x16
#define SW2_CS6 0x17
#define SW2_CS7 0x18
#define SW2_CS8 0x19
#define SW2_CS9 0x1A
#define SW2_CS10 0x1B
#define SW2_CS11 0x1C
#define SW2_CS12 0x1D
#define SW2_CS13 0x1E
#define SW2_CS14 0x1F
#define SW2_CS15 0x20
#define SW2_CS16 0x21
#define SW2_CS17 0x22
#define SW2_CS18 0x23

#define SW3_CS1 0x24
#define SW3_CS2 0x25
#define SW3_CS3 0x26
#define SW3_CS4 0x27
#define SW3_CS5 0x28
#define SW3_CS6 0x29
#define SW3_CS7 0x2A
#define SW3_CS8 0x2B
#define SW3_CS9 0x2C
#define SW3_CS10 0x2D
#define SW3_CS11 0x2E
#define SW3_CS12 0x2F
#define SW3_CS13 0x30
#define SW3_CS14 0x31
#define SW3_CS15 0x32
#define SW3_CS16 0x33
#define SW3_CS17 0x34
#define SW3_CS18 0x35

#define SW4_CS1 0x36
#define SW4_CS2 0x37
#define SW4_CS3 0x38
#define SW4_CS4 0x39
#define SW4_CS5 0x3A
#define SW4_CS6 0x3B
#define SW4_CS7 0x3C
#define SW4_CS8 0x3D
#define SW4_CS9 0x3E
#define SW4_CS10 0x3F
#define SW4_CS11 0x40
#define SW4_CS12 0x41
#define SW4_CS13 0x42
#define SW4_CS14 0x43
#define SW4_CS15 0x44
#define SW4_CS16 0x45
#define SW4_CS17 0x46
#define SW4_CS18 0x47

#define SW5_CS1 0x48
#define SW5_CS2 0x49
#define SW5_CS3 0x4A
#define SW5_CS4 0x4B
#define SW5_CS5 0x4C
#define SW5_CS6 0x4D
#define SW5_CS7 0x4E
#define SW5_CS8 0x4F
#define SW5_CS9 0x50
#define SW5_CS10 0x51
#define SW5_CS11 0x52
#define SW5_CS12 0x53
#define SW5_CS13 0x54
#define SW5_CS14 0x55
#define SW5_CS15 0x56
#define SW5_CS16 0x57
#define SW5_CS17 0x58
#define SW5_CS18 0x59

#define SW6_CS1 0x5A
#define SW6_CS2 0x5B
#define SW6_CS3 0x5C
#define SW6_CS4 0x5D
#define SW6_CS5 0x5E
#define SW6_CS6 0x5F
#define SW6_CS7 0x60
#define SW6_CS8 0x61
#define SW6_CS9 0x62
#define SW6_CS10 0x63
#define SW6_CS11 0x64
#define SW6_CS12 0x65
#define SW6_CS13 0x66
#define SW6_CS14 0x67
#define SW6_CS15 0x68
#define SW6_CS16 0x69
#define SW6_CS17 0x6A
#define SW6_CS18 0x6B

#define SW7_CS1 0x6C
#define SW7_CS2 0x6D
#define SW7_CS3 0x6E
#define SW7_CS4 0x6F
#define SW7_CS5 0x70
#define SW7_CS6 0x71
#define SW7_CS7 0x72
#define SW7_CS8 0x73
#define SW7_CS9 0x74
#define SW7_CS10 0x75
#define SW7_CS11 0x76
#define SW7_CS12 0x77
#define SW7_CS13 0x78
#define SW7_CS14 0x79
#define SW7_CS15 0x7A
#define SW7_CS16 0x7B
#define SW7_CS17 0x7C
#define SW7_CS18 0x7D

#define SW8_CS1 0x7E
#define SW8_CS2 0x7F
#define SW8_CS3 0x80
#define SW8_CS4 0x81
#define SW8_CS5 0x82
#define SW8_CS6 0x83
#define SW8_CS7 0x84
#define SW8_CS8 0x85
#define SW8_CS9 0x86
#define SW8_CS10 0x87
#define SW8_CS11 0x88
#define SW8_CS12 0x89
#define SW8_CS13 0x8A
#define SW8_CS14 0x8B
#define SW8_CS15 0x8C
#define SW8_CS16 0x8D
#define SW8_CS17 0x8E
#define SW8_CS18 0x8F
>>>>>>> upstream/master
