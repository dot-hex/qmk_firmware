/*
Copyright 2021 Terry Mathews

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


#include "portico75.h"

<<<<<<< HEAD
#ifdef RGB_MATRIX_ENABLE

const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, CS18_SW1, CS17_SW1, CS16_SW1},
    {0, CS18_SW2, CS17_SW2, CS16_SW2},
    {0, CS18_SW3, CS17_SW3, CS16_SW3},
    {0, CS18_SW4, CS17_SW4, CS16_SW4},
    {0, CS18_SW5, CS17_SW5, CS16_SW5},
    {0, CS18_SW6, CS17_SW6, CS16_SW6},
    {0, CS18_SW7, CS17_SW7, CS16_SW7},
    {0, CS18_SW8, CS17_SW8, CS16_SW8},
    {0, CS18_SW9, CS17_SW9, CS16_SW9},

    {0, CS21_SW1, CS20_SW1, CS19_SW1},
    {0, CS21_SW2, CS20_SW2, CS19_SW2},
    {0, CS21_SW3, CS20_SW3, CS19_SW3},
    {0, CS21_SW4, CS20_SW4, CS19_SW4},
    {0, CS21_SW5, CS20_SW5, CS19_SW5},
    {0, CS21_SW6, CS20_SW6, CS19_SW6}, //Encoder, NO_LED

    {0, CS15_SW1, CS14_SW1, CS13_SW1},
    {0, CS15_SW2, CS14_SW2, CS13_SW2},
    {0, CS15_SW3, CS14_SW3, CS13_SW3},
    {0, CS15_SW4, CS14_SW4, CS13_SW4},
    {0, CS15_SW5, CS14_SW5, CS13_SW5},
    {0, CS15_SW6, CS14_SW6, CS13_SW6},
    {0, CS15_SW7, CS14_SW7, CS13_SW7},
    {0, CS15_SW8, CS14_SW8, CS13_SW8},
    {0, CS15_SW9, CS14_SW9, CS13_SW9},

    {0, CS24_SW1, CS23_SW1, CS22_SW1},
    {0, CS24_SW2, CS23_SW2, CS22_SW2},
    {0, CS24_SW3, CS23_SW3, CS22_SW3},
    {0, CS24_SW4, CS23_SW4, CS22_SW4},
    {0, CS24_SW5, CS23_SW5, CS22_SW5},
    {0, CS24_SW6, CS23_SW6, CS22_SW6},

    {0, CS12_SW1, CS11_SW1, CS10_SW1},
    {0, CS12_SW2, CS11_SW2, CS10_SW2},
    {0, CS12_SW3, CS11_SW3, CS10_SW3},
    {0, CS12_SW4, CS11_SW4, CS10_SW4},
    {0, CS12_SW5, CS11_SW5, CS10_SW5},
    {0, CS12_SW6, CS11_SW6, CS10_SW6},
    {0, CS12_SW7, CS11_SW7, CS10_SW7},
    {0, CS12_SW8, CS11_SW8, CS10_SW8},
    {0, CS12_SW9, CS11_SW9, CS10_SW9},

    {0, CS27_SW1, CS26_SW1, CS25_SW1},
    {0, CS27_SW2, CS26_SW2, CS25_SW2},
    {0, CS27_SW3, CS26_SW3, CS25_SW3},
    {0, CS27_SW4, CS26_SW4, CS25_SW4},
    {0, CS27_SW5, CS26_SW5, CS25_SW5},
    {0, CS27_SW6, CS26_SW6, CS25_SW6},

    {0, CS9_SW1, CS8_SW1, CS7_SW1},
    {0, CS9_SW2, CS8_SW2, CS7_SW2},
    {0, CS9_SW3, CS8_SW3, CS7_SW3},
    {0, CS9_SW4, CS8_SW4, CS7_SW4},
    {0, CS9_SW5, CS8_SW5, CS7_SW5},
    {0, CS9_SW6, CS8_SW6, CS7_SW6},
    {0, CS9_SW7, CS8_SW7, CS7_SW7},
    {0, CS9_SW8, CS8_SW8, CS7_SW8},
    {0, CS9_SW9, CS8_SW9, CS7_SW9},

    {0, CS30_SW1, CS29_SW1, CS28_SW1},
    {0, CS30_SW2, CS29_SW2, CS28_SW2},
    {0, CS30_SW3, CS29_SW3, CS28_SW3},
    {0, CS30_SW4, CS29_SW4, CS28_SW4},

    {0, CS6_SW1, CS5_SW1, CS4_SW1},
    {0, CS6_SW2, CS5_SW2, CS4_SW2},
    {0, CS6_SW3, CS5_SW3, CS4_SW3},
    {0, CS6_SW4, CS5_SW4, CS4_SW4},
    {0, CS6_SW5, CS5_SW5, CS4_SW5},
    {0, CS6_SW6, CS5_SW6, CS4_SW6},
    {0, CS6_SW7, CS5_SW7, CS4_SW7},
    {0, CS6_SW8, CS5_SW8, CS4_SW8},
    {0, CS6_SW9, CS5_SW9, CS4_SW9},

    {0, CS33_SW1, CS32_SW1, CS31_SW1},
    {0, CS33_SW2, CS32_SW2, CS31_SW2},
    {0, CS33_SW3, CS32_SW3, CS31_SW3},
    {0, CS33_SW4, CS32_SW4, CS31_SW4},

    {0, CS3_SW1, CS2_SW1, CS1_SW1},
    {0, CS3_SW2, CS2_SW2, CS1_SW2},
    {0, CS3_SW3, CS2_SW3, CS1_SW3},
    {0, CS3_SW6, CS2_SW6, CS1_SW6},
    {0, CS3_SW8, CS2_SW8, CS1_SW8},
    {0, CS3_SW9, CS2_SW9, CS1_SW9},

    {0, CS36_SW1, CS35_SW1, CS34_SW1},
    {0, CS36_SW2, CS35_SW2, CS34_SW2},
    {0, CS36_SW3, CS35_SW3, CS34_SW3},

/*UNDERGLOW*/
    {0, CS39_SW1, CS38_SW1, CS37_SW1},
    {0, CS39_SW2, CS38_SW2, CS37_SW2},
    {0, CS39_SW3, CS38_SW3, CS37_SW3},
    {0, CS39_SW4, CS38_SW4, CS37_SW4},
    {0, CS39_SW5, CS38_SW5, CS37_SW5},
    {0, CS39_SW6, CS38_SW6, CS37_SW6},
    {0, CS39_SW7, CS38_SW7, CS37_SW7},
    {0, CS39_SW8, CS38_SW8, CS37_SW8},
    {0, CS39_SW9, CS38_SW9, CS37_SW9},

    {0, CS36_SW4, CS35_SW4, CS34_SW4},
    {0, CS36_SW5, CS35_SW5, CS34_SW5},
    {0, CS36_SW6, CS35_SW6, CS34_SW6},
    {0, CS36_SW7, CS35_SW7, CS34_SW7},
    {0, CS36_SW8, CS35_SW8, CS34_SW8},
    {0, CS36_SW9, CS35_SW9, CS34_SW9},

    {0, CS33_SW5, CS32_SW5, CS31_SW5},
    {0, CS33_SW6, CS32_SW6, CS31_SW6},
    {0, CS33_SW7, CS32_SW7, CS31_SW7},

};
=======
#ifdef RGB_BACKLIGHT_PORTICO75
#    include "drivers/led/issi/is31fl3741.h"
#endif

#if defined(RGB_MATRIX_ENABLE) || defined(RGB_BACKLIGHT_PORTICO75)

const is31fl3741_led_t PROGMEM g_is31fl3741_leds[IS31FL3741_LED_COUNT] = {
    {0, SW1_CS18, SW1_CS17, SW1_CS16},
    {0, SW2_CS18, SW2_CS17, SW2_CS16},
    {0, SW3_CS18, SW3_CS17, SW3_CS16},
    {0, SW4_CS18, SW4_CS17, SW4_CS16},
    {0, SW5_CS18, SW5_CS17, SW5_CS16},
    {0, SW6_CS18, SW6_CS17, SW6_CS16},
    {0, SW7_CS18, SW7_CS17, SW7_CS16},
    {0, SW8_CS18, SW8_CS17, SW8_CS16},
    {0, SW9_CS18, SW9_CS17, SW9_CS16},

    {0, SW1_CS21, SW1_CS20, SW1_CS19},
    {0, SW2_CS21, SW2_CS20, SW2_CS19},
    {0, SW3_CS21, SW3_CS20, SW3_CS19},
    {0, SW4_CS21, SW4_CS20, SW4_CS19},
    {0, SW5_CS21, SW5_CS20, SW5_CS19},
    {0, SW6_CS21, SW6_CS20, SW6_CS19}, //Encoder, NO_LED

    {0, SW1_CS15, SW1_CS14, SW1_CS13},
    {0, SW2_CS15, SW2_CS14, SW2_CS13},
    {0, SW3_CS15, SW3_CS14, SW3_CS13},
    {0, SW4_CS15, SW4_CS14, SW4_CS13},
    {0, SW5_CS15, SW5_CS14, SW5_CS13},
    {0, SW6_CS15, SW6_CS14, SW6_CS13},
    {0, SW7_CS15, SW7_CS14, SW7_CS13},
    {0, SW8_CS15, SW8_CS14, SW8_CS13},
    {0, SW9_CS15, SW9_CS14, SW9_CS13},

    {0, SW1_CS24, SW1_CS23, SW1_CS22},
    {0, SW2_CS24, SW2_CS23, SW2_CS22},
    {0, SW3_CS24, SW3_CS23, SW3_CS22},
    {0, SW4_CS24, SW4_CS23, SW4_CS22},
    {0, SW5_CS24, SW5_CS23, SW5_CS22},
    {0, SW6_CS24, SW6_CS23, SW6_CS22},

    {0, SW1_CS12, SW1_CS11, SW1_CS10},
    {0, SW2_CS12, SW2_CS11, SW2_CS10},
    {0, SW3_CS12, SW3_CS11, SW3_CS10},
    {0, SW4_CS12, SW4_CS11, SW4_CS10},
    {0, SW5_CS12, SW5_CS11, SW5_CS10},
    {0, SW6_CS12, SW6_CS11, SW6_CS10},
    {0, SW7_CS12, SW7_CS11, SW7_CS10},
    {0, SW8_CS12, SW8_CS11, SW8_CS10},
    {0, SW9_CS12, SW9_CS11, SW9_CS10},

    {0, SW1_CS27, SW1_CS26, SW1_CS25},
    {0, SW2_CS27, SW2_CS26, SW2_CS25},
    {0, SW3_CS27, SW3_CS26, SW3_CS25},
    {0, SW4_CS27, SW4_CS26, SW4_CS25},
    {0, SW5_CS27, SW5_CS26, SW5_CS25},
    {0, SW6_CS27, SW6_CS26, SW6_CS25},

    {0, SW1_CS9, SW1_CS8, SW1_CS7},
    {0, SW2_CS9, SW2_CS8, SW2_CS7},
    {0, SW3_CS9, SW3_CS8, SW3_CS7},
    {0, SW4_CS9, SW4_CS8, SW4_CS7},
    {0, SW5_CS9, SW5_CS8, SW5_CS7},
    {0, SW6_CS9, SW6_CS8, SW6_CS7},
    {0, SW7_CS9, SW7_CS8, SW7_CS7},
    {0, SW8_CS9, SW8_CS8, SW8_CS7},
    {0, SW9_CS9, SW9_CS8, SW9_CS7},

    {0, SW1_CS30, SW1_CS29, SW1_CS28},
    {0, SW2_CS30, SW2_CS29, SW2_CS28},
    {0, SW3_CS30, SW3_CS29, SW3_CS28},
    {0, SW4_CS30, SW4_CS29, SW4_CS28},

    {0, SW1_CS6, SW1_CS5, SW1_CS4},
    {0, SW2_CS6, SW2_CS5, SW2_CS4},
    {0, SW3_CS6, SW3_CS5, SW3_CS4},
    {0, SW4_CS6, SW4_CS5, SW4_CS4},
    {0, SW5_CS6, SW5_CS5, SW5_CS4},
    {0, SW6_CS6, SW6_CS5, SW6_CS4},
    {0, SW7_CS6, SW7_CS5, SW7_CS4},
    {0, SW8_CS6, SW8_CS5, SW8_CS4},
    {0, SW9_CS6, SW9_CS5, SW9_CS4},

    {0, SW1_CS33, SW1_CS32, SW1_CS31},
    {0, SW2_CS33, SW2_CS32, SW2_CS31},
    {0, SW3_CS33, SW3_CS32, SW3_CS31},
    {0, SW4_CS33, SW4_CS32, SW4_CS31},

    {0, SW1_CS3, SW1_CS2, SW1_CS1},
    {0, SW2_CS3, SW2_CS2, SW2_CS1},
    {0, SW3_CS3, SW3_CS2, SW3_CS1},
    {0, SW6_CS3, SW6_CS2, SW6_CS1},
    {0, SW8_CS3, SW8_CS2, SW8_CS1},
    {0, SW9_CS3, SW9_CS2, SW9_CS1},

    {0, SW1_CS36, SW1_CS35, SW1_CS34},
    {0, SW2_CS36, SW2_CS35, SW2_CS34},
    {0, SW3_CS36, SW3_CS35, SW3_CS34},

/*UNDERGLOW*/
    {0, SW1_CS39, SW1_CS38, SW1_CS37},
    {0, SW2_CS39, SW2_CS38, SW2_CS37},
    {0, SW3_CS39, SW3_CS38, SW3_CS37},
    {0, SW4_CS39, SW4_CS38, SW4_CS37},
    {0, SW5_CS39, SW5_CS38, SW5_CS37},
    {0, SW6_CS39, SW6_CS38, SW6_CS37},
    {0, SW7_CS39, SW7_CS38, SW7_CS37},
    {0, SW8_CS39, SW8_CS38, SW8_CS37},
    {0, SW9_CS39, SW9_CS38, SW9_CS37},

    {0, SW4_CS36, SW4_CS35, SW4_CS34},
    {0, SW5_CS36, SW5_CS35, SW5_CS34},
    {0, SW6_CS36, SW6_CS35, SW6_CS34},
    {0, SW7_CS36, SW7_CS35, SW7_CS34},
    {0, SW8_CS36, SW8_CS35, SW8_CS34},
    {0, SW9_CS36, SW9_CS35, SW9_CS34},

    {0, SW5_CS33, SW5_CS32, SW5_CS31},
    {0, SW6_CS33, SW6_CS32, SW6_CS31},
    {0, SW7_CS33, SW7_CS32, SW7_CS31},
};
#endif

#ifdef RGB_MATRIX_ENABLE
>>>>>>> upstream/master
led_config_t g_led_config = { {
    {   0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14},
    {  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
    {  30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44},
    {  45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, NO_LED, NO_LED},
    {  58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, NO_LED, NO_LED},
    {  71, 72, 73, NO_LED, NO_LED, 74, NO_LED, NO_LED, NO_LED, 75, 76, 77, 78, 79, NO_LED},
}, {
    {0,0},{18,0},{33,0},{48,0},{62,0},{81,0},{96,0},{110,0},{125,0},{143,0},{158,0},{173,0},{187,0},{205,0},{224,0},
    {0,15},{15,15},{29,15},{44,15},{59,15},{74,15},{88,15},{103,15},{118,15},{132,15},{147,15},{162,15},{176,15},{198,15},{224,15},
    {4,26},{22,26},{37,26},{51,26},{66,26},{81,26},{96,26},{110,26},{125,26},{140,26},{154,26},{169,26},{183,26},{202,26},{224,26},
    {5,38},{25,38},{40,38},{54,38},{69,38},{84,38},{98,38},{113,38},{128,38},{143,38},{157,38},{172,38},{197,38},
    {9,49},{33,49},{48,49},{62,49},{77,49},{92,49},{107,49},{121,49},{136,49},{151,49},{165,49},{186,49},{209,52},
    {2,61},{20,61},{39,61},{94,61},{151,61},{173,61},{195,64},{209,64},{224,64},
    {2,0},{46,0},{90,0},{134,0},{178,0},{222,0},{224,2},{224,32},{224,62},{2,64},{46,64},{90,64},{134,64},{178,64},{222,64},{0,2},{0,32},{0,62},
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
} };

<<<<<<< HEAD
__attribute__ ((weak))
void rgb_matrix_indicators_user(void)
{
    if (host_keyboard_led_state().caps_lock)
    {
        rgb_matrix_set_color(45, 0xFF, 0xFF, 0xFF);
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
=======
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(45, 0xFF, 0xFF, 0xFF);
>>>>>>> upstream/master
    }
    return true;
}
#endif
