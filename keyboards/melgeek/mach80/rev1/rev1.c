/* Copyright 2020 MelGeek <melgeek001365@gmail.com>
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
#include "mach80.h"
=======
#include "quantum.h"
>>>>>>> upstream/master

#ifdef RGB_MATRIX_ENABLE


<<<<<<< HEAD
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, CS9_SW1,  CS8_SW1,  CS7_SW1},  /* RGB1 */
    {0, CS9_SW2,  CS8_SW2,  CS7_SW2},  /* RGB2 */
    {0, CS9_SW3,  CS8_SW3,  CS7_SW3},  /* RGB3 */
    {0, CS9_SW4,  CS8_SW4,  CS7_SW4},  /* RGB4 */
    {0, CS9_SW5,  CS8_SW5,  CS7_SW5},  /* RGB5 */
    {0, CS9_SW6,  CS8_SW6,  CS7_SW6},  /* RGB6 */
    {0, CS9_SW7,  CS8_SW7,  CS7_SW7},  /* RGB7 */
    {0, CS9_SW8,  CS8_SW8,  CS7_SW8},  /* RGB8 */
    {0, CS9_SW9,  CS8_SW9,  CS7_SW9},  /* RGB9 */
    {0, CS27_SW1, CS26_SW1, CS25_SW1}, /* RGB65 */
    {0, CS27_SW2, CS26_SW2, CS25_SW2}, /* RGB56 */
    {0, CS27_SW3, CS26_SW3, CS25_SW3}, /* RGB57 */
    {0, CS27_SW4, CS26_SW4, CS25_SW4}, /* RGB58 */
    {0, CS27_SW5, CS26_SW5, CS25_SW5}, /* RGB59 */
    {0, CS27_SW6, CS26_SW6, CS25_SW6}, /* RGB67 */
    {0, CS27_SW7, CS26_SW7, CS25_SW7}, /* RGB68 */
    {0, CS12_SW1, CS11_SW1, CS10_SW1}, /* RGB10 */
	{0, CS12_SW2, CS11_SW2, CS10_SW2}, /* RGB11 */
    {0, CS12_SW3, CS11_SW3, CS10_SW3}, /* RGB12 */
	{0, CS12_SW4, CS11_SW4, CS10_SW4}, /* RGB13 */
	{0, CS12_SW5, CS11_SW5, CS10_SW5}, /* RGB14 */
    {0, CS12_SW6, CS11_SW6, CS10_SW6}, /* RGB15 */
    {0, CS12_SW7, CS11_SW7, CS10_SW7}, /* RGB16 */
    {0, CS12_SW8, CS11_SW8, CS10_SW8}, /* RGB17 */
    {0, CS12_SW9, CS11_SW9, CS10_SW9}, /* RGB18 */
    {0, CS27_SW8, CS26_SW8, CS25_SW8}, /* RGB69 */
    {0, CS27_SW9, CS26_SW9, CS25_SW9}, /* RGB70 */
    {0, CS30_SW1, CS29_SW1, CS28_SW1}, /* RGB64 */
    {0, CS30_SW2, CS29_SW2, CS28_SW2}, /* RGB55 */
    {0, CS30_SW3, CS29_SW3, CS28_SW3}, /* RGB71 */
    {0, CS30_SW4, CS29_SW4, CS28_SW4}, /* RGB72 */
    {0, CS30_SW5, CS29_SW5, CS28_SW5}, /* RGB66 */
    {0, CS30_SW6, CS29_SW6, CS28_SW6}, /* RGB60 */
    {0, CS30_SW7, CS29_SW7, CS28_SW7}, /* RGB61 */
    {0, CS30_SW8, CS29_SW8, CS28_SW8}, /* RGB73 */
    {0, CS15_SW1, CS14_SW1, CS13_SW1}, /* RGB19 */
    {0, CS15_SW2, CS14_SW2, CS13_SW2}, /* RGB20 */
    {0, CS15_SW3, CS14_SW3, CS13_SW3}, /* RGB21 */
    {0, CS15_SW4, CS14_SW4, CS13_SW4}, /* RGB22 */
    {0, CS15_SW5, CS14_SW5, CS13_SW5}, /* RGB23 */
    {0, CS15_SW6, CS14_SW6, CS13_SW6}, /* RGB24 */
    {0, CS15_SW7, CS14_SW7, CS13_SW7}, /* RGB25 */
    {0, CS15_SW8, CS14_SW8, CS13_SW8}, /* RGB26 */
    {0, CS15_SW9, CS14_SW9, CS13_SW9}, /* RGB27 */
    {0, CS30_SW9, CS29_SW9, CS28_SW9}, /* RGB74 */
	{0, CS33_SW1, CS32_SW1, CS31_SW1}, /* RGB75 */
    {0, CS33_SW2, CS32_SW2, CS31_SW2}, /* RGB76 */
    {0, CS33_SW3, CS32_SW3, CS31_SW3}, /* RGB77 */
    {0, CS33_SW4, CS32_SW4, CS31_SW4}, /* RGB78 */
    {0, CS33_SW5, CS32_SW5, CS31_SW5}, /* RGB79 */
    {0, CS33_SW6, CS32_SW6, CS31_SW6}, /* RGB80 */
    {0, CS33_SW7, CS32_SW7, CS31_SW7}, /* RGB83 */
    {0, CS18_SW1, CS17_SW1, CS16_SW1}, /* RGB28 */
    {0, CS18_SW2, CS17_SW2, CS16_SW2}, /* RGB29 */
	{0, CS18_SW3, CS17_SW3, CS16_SW3}, /* RGB30 */
    {0, CS18_SW4, CS17_SW4, CS16_SW4}, /* RGB31 */
    {0, CS18_SW5, CS17_SW5, CS16_SW5}, /* RGB32 */
    {0, CS18_SW6, CS17_SW6, CS16_SW6}, /* RGB33 */
    {0, CS18_SW7, CS17_SW7, CS16_SW7}, /* RGB34 */
    {0, CS18_SW8, CS17_SW8, CS16_SW8}, /* RGB35 */
    {0, CS18_SW9, CS17_SW9, CS16_SW9}, /* RGB36 */
    {0, CS33_SW8, CS32_SW8, CS31_SW8}, /* RGB81 */
    {0, CS33_SW9, CS32_SW9, CS31_SW9}, /* RGB82 */
    {0, CS36_SW1, CS35_SW1, CS34_SW1}, /* RGB89 */
    {0, CS36_SW2, CS35_SW2, CS34_SW2}, /* RGB90 */
    {0, CS36_SW3, CS35_SW3, CS34_SW3}, /* RGB91 */
    {0, CS36_SW4, CS35_SW4, CS34_SW4}, /* RGB92 */
    {0, CS21_SW1, CS20_SW1, CS19_SW1}, /* RGB37 */
    {0, CS21_SW2, CS20_SW2, CS19_SW2}, /* RGB38 */
    {0, CS21_SW3, CS20_SW3, CS19_SW3}, /* RGB39 */
    {0, CS21_SW4, CS20_SW4, CS19_SW4}, /* RGB40 */
    {0, CS21_SW5, CS20_SW5, CS19_SW5}, /* RGB41 */
    {0, CS21_SW6, CS20_SW6, CS19_SW6}, /* RGB42 */
    {0, CS21_SW7, CS20_SW7, CS19_SW7}, /* RGB43 */
    {0, CS21_SW8, CS20_SW8, CS19_SW8}, /* RGB44 */
    {0, CS21_SW9, CS20_SW9, CS19_SW9}, /* RGB45 */
    {0, CS36_SW5, CS35_SW5, CS34_SW5}, /* RGB84 */
    {0, CS36_SW6, CS35_SW6, CS34_SW6}, /* RGB85 */
    {0, CS36_SW7, CS35_SW7, CS34_SW7}, /* RGB88 */
    {0, CS36_SW8, CS35_SW8, CS34_SW8}, /* RGB86 */
    {0, CS36_SW9, CS35_SW9, CS34_SW9}, /* RGB87 */
    {0, CS39_SW1, CS38_SW1, CS37_SW1}, /* RGB98 */
    {0, CS39_SW2, CS38_SW2, CS37_SW2}, /* RGB99 */
    {0, CS39_SW3, CS38_SW3, CS37_SW3}, /* RGB100 */
    {0, CS24_SW1, CS23_SW1, CS22_SW1}, /* RGB46 */
    {0, CS24_SW2, CS23_SW2, CS22_SW2}, /* RGB47 */
    {0, CS24_SW3, CS23_SW3, CS22_SW3}, /* RGB48 */
    {0, CS24_SW4, CS23_SW4, CS22_SW4}, /* RGB49 */
    {0, CS24_SW5, CS23_SW5, CS22_SW5}, /* RGB50 */
    {0, CS24_SW6, CS23_SW6, CS22_SW6}, /* RGB51 */
    {0, CS24_SW7, CS23_SW7, CS22_SW7}, /* RGB52 */
    {0, CS24_SW8, CS23_SW8, CS22_SW8}, /* RGB53 */
    {0, CS24_SW9, CS23_SW9, CS22_SW9}, /* RGB54 */
    {0, CS39_SW4, CS38_SW4, CS37_SW4}, /* RGB101 */
    {0, CS39_SW5, CS38_SW5, CS37_SW5}, /* RGB110 */
    {0, CS39_SW6, CS38_SW6, CS37_SW6}, /* RGB111 */
    {0, CS39_SW7, CS38_SW7, CS37_SW7}, /* RGB112 */
=======
const is31fl3741_led_t PROGMEM g_is31fl3741_leds[IS31FL3741_LED_COUNT] = {
    {0, SW1_CS9,  SW1_CS8,  SW1_CS7},  /* RGB1 */
    {0, SW2_CS9,  SW2_CS8,  SW2_CS7},  /* RGB2 */
    {0, SW3_CS9,  SW3_CS8,  SW3_CS7},  /* RGB3 */
    {0, SW4_CS9,  SW4_CS8,  SW4_CS7},  /* RGB4 */
    {0, SW5_CS9,  SW5_CS8,  SW5_CS7},  /* RGB5 */
    {0, SW6_CS9,  SW6_CS8,  SW6_CS7},  /* RGB6 */
    {0, SW7_CS9,  SW7_CS8,  SW7_CS7},  /* RGB7 */
    {0, SW8_CS9,  SW8_CS8,  SW8_CS7},  /* RGB8 */
    {0, SW9_CS9,  SW9_CS8,  SW9_CS7},  /* RGB9 */
    {0, SW1_CS27, SW1_CS26, SW1_CS25}, /* RGB65 */
    {0, SW2_CS27, SW2_CS26, SW2_CS25}, /* RGB56 */
    {0, SW3_CS27, SW3_CS26, SW3_CS25}, /* RGB57 */
    {0, SW4_CS27, SW4_CS26, SW4_CS25}, /* RGB58 */
    {0, SW5_CS27, SW5_CS26, SW5_CS25}, /* RGB59 */
    {0, SW6_CS27, SW6_CS26, SW6_CS25}, /* RGB67 */
    {0, SW7_CS27, SW7_CS26, SW7_CS25}, /* RGB68 */
    {0, SW1_CS12, SW1_CS11, SW1_CS10}, /* RGB10 */
	{0, SW2_CS12, SW2_CS11, SW2_CS10}, /* RGB11 */
    {0, SW3_CS12, SW3_CS11, SW3_CS10}, /* RGB12 */
	{0, SW4_CS12, SW4_CS11, SW4_CS10}, /* RGB13 */
	{0, SW5_CS12, SW5_CS11, SW5_CS10}, /* RGB14 */
    {0, SW6_CS12, SW6_CS11, SW6_CS10}, /* RGB15 */
    {0, SW7_CS12, SW7_CS11, SW7_CS10}, /* RGB16 */
    {0, SW8_CS12, SW8_CS11, SW8_CS10}, /* RGB17 */
    {0, SW9_CS12, SW9_CS11, SW9_CS10}, /* RGB18 */
    {0, SW8_CS27, SW8_CS26, SW8_CS25}, /* RGB69 */
    {0, SW9_CS27, SW9_CS26, SW9_CS25}, /* RGB70 */
    {0, SW1_CS30, SW1_CS29, SW1_CS28}, /* RGB64 */
    {0, SW2_CS30, SW2_CS29, SW2_CS28}, /* RGB55 */
    {0, SW3_CS30, SW3_CS29, SW3_CS28}, /* RGB71 */
    {0, SW4_CS30, SW4_CS29, SW4_CS28}, /* RGB72 */
    {0, SW5_CS30, SW5_CS29, SW5_CS28}, /* RGB66 */
    {0, SW6_CS30, SW6_CS29, SW6_CS28}, /* RGB60 */
    {0, SW7_CS30, SW7_CS29, SW7_CS28}, /* RGB61 */
    {0, SW8_CS30, SW8_CS29, SW8_CS28}, /* RGB73 */
    {0, SW1_CS15, SW1_CS14, SW1_CS13}, /* RGB19 */
    {0, SW2_CS15, SW2_CS14, SW2_CS13}, /* RGB20 */
    {0, SW3_CS15, SW3_CS14, SW3_CS13}, /* RGB21 */
    {0, SW4_CS15, SW4_CS14, SW4_CS13}, /* RGB22 */
    {0, SW5_CS15, SW5_CS14, SW5_CS13}, /* RGB23 */
    {0, SW6_CS15, SW6_CS14, SW6_CS13}, /* RGB24 */
    {0, SW7_CS15, SW7_CS14, SW7_CS13}, /* RGB25 */
    {0, SW8_CS15, SW8_CS14, SW8_CS13}, /* RGB26 */
    {0, SW9_CS15, SW9_CS14, SW9_CS13}, /* RGB27 */
    {0, SW9_CS30, SW9_CS29, SW9_CS28}, /* RGB74 */
	{0, SW1_CS33, SW1_CS32, SW1_CS31}, /* RGB75 */
    {0, SW2_CS33, SW2_CS32, SW2_CS31}, /* RGB76 */
    {0, SW3_CS33, SW3_CS32, SW3_CS31}, /* RGB77 */
    {0, SW4_CS33, SW4_CS32, SW4_CS31}, /* RGB78 */
    {0, SW5_CS33, SW5_CS32, SW5_CS31}, /* RGB79 */
    {0, SW6_CS33, SW6_CS32, SW6_CS31}, /* RGB80 */
    {0, SW7_CS33, SW7_CS32, SW7_CS31}, /* RGB83 */
    {0, SW1_CS18, SW1_CS17, SW1_CS16}, /* RGB28 */
    {0, SW2_CS18, SW2_CS17, SW2_CS16}, /* RGB29 */
	{0, SW3_CS18, SW3_CS17, SW3_CS16}, /* RGB30 */
    {0, SW4_CS18, SW4_CS17, SW4_CS16}, /* RGB31 */
    {0, SW5_CS18, SW5_CS17, SW5_CS16}, /* RGB32 */
    {0, SW6_CS18, SW6_CS17, SW6_CS16}, /* RGB33 */
    {0, SW7_CS18, SW7_CS17, SW7_CS16}, /* RGB34 */
    {0, SW8_CS18, SW8_CS17, SW8_CS16}, /* RGB35 */
    {0, SW9_CS18, SW9_CS17, SW9_CS16}, /* RGB36 */
    {0, SW8_CS33, SW8_CS32, SW8_CS31}, /* RGB81 */
    {0, SW9_CS33, SW9_CS32, SW9_CS31}, /* RGB82 */
    {0, SW1_CS36, SW1_CS35, SW1_CS34}, /* RGB89 */
    {0, SW2_CS36, SW2_CS35, SW2_CS34}, /* RGB90 */
    {0, SW3_CS36, SW3_CS35, SW3_CS34}, /* RGB91 */
    {0, SW4_CS36, SW4_CS35, SW4_CS34}, /* RGB92 */
    {0, SW1_CS21, SW1_CS20, SW1_CS19}, /* RGB37 */
    {0, SW2_CS21, SW2_CS20, SW2_CS19}, /* RGB38 */
    {0, SW3_CS21, SW3_CS20, SW3_CS19}, /* RGB39 */
    {0, SW4_CS21, SW4_CS20, SW4_CS19}, /* RGB40 */
    {0, SW5_CS21, SW5_CS20, SW5_CS19}, /* RGB41 */
    {0, SW6_CS21, SW6_CS20, SW6_CS19}, /* RGB42 */
    {0, SW7_CS21, SW7_CS20, SW7_CS19}, /* RGB43 */
    {0, SW8_CS21, SW8_CS20, SW8_CS19}, /* RGB44 */
    {0, SW9_CS21, SW9_CS20, SW9_CS19}, /* RGB45 */
    {0, SW5_CS36, SW5_CS35, SW5_CS34}, /* RGB84 */
    {0, SW6_CS36, SW6_CS35, SW6_CS34}, /* RGB85 */
    {0, SW7_CS36, SW7_CS35, SW7_CS34}, /* RGB88 */
    {0, SW8_CS36, SW8_CS35, SW8_CS34}, /* RGB86 */
    {0, SW9_CS36, SW9_CS35, SW9_CS34}, /* RGB87 */
    {0, SW1_CS39, SW1_CS38, SW1_CS37}, /* RGB98 */
    {0, SW2_CS39, SW2_CS38, SW2_CS37}, /* RGB99 */
    {0, SW3_CS39, SW3_CS38, SW3_CS37}, /* RGB100 */
    {0, SW1_CS24, SW1_CS23, SW1_CS22}, /* RGB46 */
    {0, SW2_CS24, SW2_CS23, SW2_CS22}, /* RGB47 */
    {0, SW3_CS24, SW3_CS23, SW3_CS22}, /* RGB48 */
    {0, SW4_CS24, SW4_CS23, SW4_CS22}, /* RGB49 */
    {0, SW5_CS24, SW5_CS23, SW5_CS22}, /* RGB50 */
    {0, SW6_CS24, SW6_CS23, SW6_CS22}, /* RGB51 */
    {0, SW7_CS24, SW7_CS23, SW7_CS22}, /* RGB52 */
    {0, SW8_CS24, SW8_CS23, SW8_CS22}, /* RGB53 */
    {0, SW9_CS24, SW9_CS23, SW9_CS22}, /* RGB54 */
    {0, SW4_CS39, SW4_CS38, SW4_CS37}, /* RGB101 */
    {0, SW5_CS39, SW5_CS38, SW5_CS37}, /* RGB110 */
    {0, SW6_CS39, SW6_CS38, SW6_CS37}, /* RGB111 */
    {0, SW7_CS39, SW7_CS38, SW7_CS37}, /* RGB112 */
>>>>>>> upstream/master
};
led_config_t g_led_config = {
	{
		/* C0       C1       C2       C3       C4       C5       C6       C7       C8       C9       C10       C11       C12       C13       C14       C15 */
		{  0,  NO_LED,       1,       2,       3,       4,       5,       6,       7,       8,        9,       10,       11,       12,       13,       14 }, /* R0 */
		{ 16,      17,      18,      19,      20,      21,      22,      23,      24,      25,       26,       27,       28,       30,       32,       33 }, /* R1 */
		{ 35,      36,      37,      38,      39,      40,      41,      42,      43,      44,       45,       46,       47,       48,       49,       50 }, /* R2 */
		{ 52,      53,      54,      55,      56,      57,      58,      59,      60,      61,       62,       63,       65,       15,       34,       51 }, /* R3 */
		{ 68,      70,      71,      72,      73,      74,      75,      76,      77,      78,       79,       81,   NO_LED,   NO_LED,       83,   NO_LED }, /* R4 */
		{ 84,      85,      86,  NO_LED,  NO_LED,      88,  NO_LED,  NO_LED,  NO_LED,      90,       91,       92,       93,       94,       95,       96 }  /* R5 */
    }, {
        {0, 0},   {12, 0},   {24, 0},  {36, 0},  {48, 0},  {60, 0},  {72, 0},  {84, 0},  {96, 0},  {108, 0},  {120, 0},  {132, 0},  {144, 0},  {156, 0},  {168, 0},  {180, 0},                                   //16
		{0, 12},  {12, 12},  {24, 12}, {36, 12}, {48, 12}, {60, 12}, {72, 12}, {84, 12}, {96, 12}, {108, 12}, {120, 12}, {132, 12}, {144, 12}, {156, 12}, {168, 12}, {180, 12}, {192, 12}, {204, 12}, {216, 12}, //19
		{0, 24},  {12, 24},  {24, 24}, {36, 24}, {48, 24}, {60, 24}, {72, 24}, {84, 24}, {96, 24}, {108, 24}, {120, 24}, {132, 24}, {144, 24}, {156, 24}, {168, 24}, {180, 24}, {192, 24},                       //17
		{0, 36},  {12, 36},  {24, 36}, {36, 36}, {48, 36}, {60, 36}, {72, 36}, {84, 36}, {96, 36}, {108, 36}, {120, 36}, {132, 36}, {144, 36}, {156, 36}, {168, 36},                                             //15
		{0, 48},  {12, 48},  {24, 48}, {36, 48}, {48, 48}, {60, 48}, {72, 48}, {84, 48}, {96, 48}, {108, 48}, {120, 48}, {132, 48}, {144, 48}, {156, 48}, {168, 48}, {180, 48}, {192, 48},                       //17
		{0, 60},  {12, 60},  {24, 60}, {36, 60}, {48, 60}, {60, 60}, {72, 60}, {84, 60}, {96, 60}, {108, 60}, {120, 60}, {132, 60}, {144, 60}                                                                    //13
	}, {          
	       4,         4,         4,        4,        4,        4,        4,         4,         4,         4,         4,         4,         4,         4,         4,         4,       
		   4,         4,         4,        4,        4,        4,        4,         4,         4,         4,         4,         4,         4,         4,         4,         4,         4,         4,         4,
		   4,         4,         4,        4,        4,        4,        4,         4,         4,         4,         4,         4,         4,         4,         4,         4,         4,
		   4,         4,         4,        4,        4,        4,        4,         4,         4,         4,         4,         4,         4,         4,         4,         
		   4,         4,         4,        4,        4,        4,        4,         4,         4,         4,         4,         4,         4,         4,         4,         4,         4,
		   4,         4,         4,        4,        4,        4,        4,         4,         4,         4,         4,         4,         4,
	}
};

<<<<<<< HEAD
const is31_led g_is31_indicator_leds[3] = {
    {0, CS6_SW1, CS5_SW1, CS4_SW1}, /* RGB107 */
    {0, CS6_SW2, CS5_SW2, CS4_SW2}, /* RGB108 */
    {0, CS6_SW3, CS5_SW3, CS4_SW3}, /* RGB109 */
=======
const is31fl3741_led_t g_is31_indicator_leds[3] = {
    {0, SW1_CS6, SW1_CS5, SW1_CS4}, /* RGB107 */
    {0, SW2_CS6, SW2_CS5, SW2_CS4}, /* RGB108 */
    {0, SW3_CS6, SW3_CS5, SW3_CS4}, /* RGB109 */
>>>>>>> upstream/master
};

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        if (led_state.caps_lock) {
<<<<<<< HEAD
            IS31FL3741_set_pwm_buffer(&g_is31_indicator_leds[2], 0x00, 0x00, 0xff);
        } else {
            IS31FL3741_set_pwm_buffer(&g_is31_indicator_leds[2], 0x00, 0x00, 0x00);
        }

        if (led_state.num_lock) {
            IS31FL3741_set_pwm_buffer(&g_is31_indicator_leds[1], 0xff, 0x00, 0x00);
        } else {
            IS31FL3741_set_pwm_buffer(&g_is31_indicator_leds[1], 0x00, 0x00, 0x00);
        }

        if (led_state.scroll_lock) {
            IS31FL3741_set_pwm_buffer(&g_is31_indicator_leds[0], 0x00, 0xff, 0x00);
        } else {
            IS31FL3741_set_pwm_buffer(&g_is31_indicator_leds[0], 0x00, 0x00, 0x00);
=======
            is31fl3741_set_pwm_buffer(&g_is31_indicator_leds[2], 0x00, 0x00, 0xff);
        } else {
            is31fl3741_set_pwm_buffer(&g_is31_indicator_leds[2], 0x00, 0x00, 0x00);
        }

        if (led_state.num_lock) {
            is31fl3741_set_pwm_buffer(&g_is31_indicator_leds[1], 0xff, 0x00, 0x00);
        } else {
            is31fl3741_set_pwm_buffer(&g_is31_indicator_leds[1], 0x00, 0x00, 0x00);
        }

        if (led_state.scroll_lock) {
            is31fl3741_set_pwm_buffer(&g_is31_indicator_leds[0], 0x00, 0xff, 0x00);
        } else {
            is31fl3741_set_pwm_buffer(&g_is31_indicator_leds[0], 0x00, 0x00, 0x00);
>>>>>>> upstream/master
        }
    }
    return true;
}

void matrix_init_kb(void) {
    for (int i = 0; i < DRIVER_INDICATOR_LED_TOTAL; ++i) {
<<<<<<< HEAD
        is31_led led = g_is31_indicator_leds[i];
        IS31FL3741_set_scaling_registers(&led, 0xFF, 0xFF, 0xFF);
    }

    IS31FL3741_update_led_control_registers(DRIVER_ADDR_1, 0);

    matrix_init_user();
}


void keyboard_pre_init_kb(void) {
    setPinOutput(B7);
    writePinHigh(B7);
    keyboard_pre_init_user();
}
=======
        is31fl3741_led_t led = g_is31_indicator_leds[i];
        is31fl3741_set_scaling_registers(&led, 0xFF, 0xFF, 0xFF);
    }

    is31fl3741_update_led_control_registers(0);

    matrix_init_user();
}
>>>>>>> upstream/master
#endif
