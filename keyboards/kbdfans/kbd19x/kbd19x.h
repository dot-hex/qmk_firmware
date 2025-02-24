/*
Copyright 2018 Jeff Shufelt <jshuf@puppyfish.com> @jshuf

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

#include "quantum.h"
#include "led.h"

inline void kbd19x_caps_led_on(void)    { gpio_write_pin_high(LED_CAPS_LOCK_PIN); }
inline void kbd19x_caps_led_off(void)   { gpio_write_pin_low(LED_CAPS_LOCK_PIN); }

inline void kbd19x_sclk_led_on(void)    { gpio_write_pin_high(LED_SCROLL_LOCK_PIN); }
inline void kbd19x_sclk_led_off(void)   { gpio_write_pin_low(LED_SCROLL_LOCK_PIN); }

<<<<<<< HEAD
inline void kbd19x_nmlk_led_on(void)    { writePinHigh(LED_NUM_LOCK_PIN); }
inline void kbd19x_nmlk_led_off(void)   { writePinLow(LED_NUM_LOCK_PIN); }

// readability
#define XXX KC_NO

/*
 *              ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐ ┌───┬───┬───┬───┐
 *              │00 ││01 │02 │03 │04 ││60 │61 │62 │63 ││05 │06 │07 │08 ││72 │ │09 │0A │0B │0C │
 *              └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘ └───┴───┴───┴───┘
 *              ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┐    ┌───────┐
 *              │10 │11 │12 │13 │14 │64 │65 │66 │67 │15 │16 │17 │18 │70 │71 │ │19 │1A │1B │1C │    │71     │ 2u Backspace
 *              ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┼───┤    └─┬─────┤                ┌───┐
 *              │20   │21 │22 │23 │24 │68 │69 │6a │6b │25 │26 │27 │28 │73   │ │29 │2A │2B │2C │      │     │                │   │
 *  2.25u       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┼───┼───┼───┤   ┌──┴┐38  │ ISO Enter      │2C │ 2u Plus
 *  LShift      │30    │31 │32 │33 │34 │6c │75 │76 │77 │35 │36 │37 │38      │ │39 │3A │3B │3C │   │73 │    │                │   │
 * ┌────────┐   ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┘ ├───┼───┼───┼───┤   └───┴────┘                ├───┤
 * │40      │   │40  │41 │42 │43 │44 │78 │79 │7a │7b │45 │46 │47 │48    │┌───┐│49 │4A │4B │4C │                             │   │
 * └────────┘   ├────┼───┼───┴┬──┴───┴───┴───┴───┴───┴─┬─┴─┬─┴─┬─┴──┬───┘│74 │└───┼───┼───┼───┤                             │4C │ 2u Enter
 *              │50  │51 │52  │59                      │55 │56 │57  │┌───┼───┼───┐│5A │5B │5C │                             │   │
 *              └────┴───┴────┴────────────────────────┴───┴───┴────┘│58 │53 │54 │└───┴───┴───┘                             └───┘
 *              ┌─────┬─────┬───────────────────────────┬─────┬─────┐└───┴───┴───┘
 *              │50   │52   │59                         │55   │57   │ WKL
 *              └─────┴─────┴───────────────────────────┴─────┴─────┘
 */

#define LAYOUT_all( \
  k00,  k01, k02, k03, k04,  k60, k61, k62, k63,  k05, k06, k07, k08,   k72,  k09, k0a, k0b, k0c, \
  k10, k11, k12, k13, k14, k64, k65, k66, k67, k15, k16, k17, k18, k70, k71,  k19, k1a, k1b, k1c, \
  k20,  k21, k22, k23, k24, k68, k69, k6a, k6b, k25, k26, k27, k28,     k73,  k29, k2a, k2b, k2c, \
  k30,    k31, k32, k33, k34, k6c, k75, k76, k77, k35, k36, k37,        k38,  k39, k3a, k3b, k3c, \
  k40,  k41, k42, k43, k44, k78, k79, k7a, k7b, k45, k46, k47, k48,    k74,   k49, k4a, k4b, k4c, \
  k50,  k51, k52,                k59,            k55, k56, k57,   k58, k53, k54,   k5a, k5b, k5c  \
)\
{\
  {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c},\
  {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c},\
  {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c},\
  {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c},\
  {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c},\
  {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c},\
  {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b, k6c},\
  {k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, XXX},\
}

#define LAYOUT_ansi( \
  k00,  k01, k02, k03, k04,  k60, k61, k62, k63,  k05, k06, k07, k08, k72,     k09, k0a, k0b, k0c, \
  k10, k11, k12, k13, k14, k64, k65, k66, k67, k15, k16, k17, k18,    k71,     k19, k1a, k1b, k1c, \
  k20,  k21, k22, k23, k24, k68, k69, k6a, k6b, k25, k26, k27, k28,   k73,     k29, k2a, k2b, k2c, \
  k30,    k31, k32, k33, k34, k6c, k75, k76, k77, k35, k36, k37,      k38,     k39, k3a, k3b,      \
  k40,      k42, k43, k44, k78, k79, k7a, k7b, k45, k46, k47,    k48,   k74,   k49, k4a, k4b, k4c, \
  k50, k51, k52,                k59,            k55, k56, k57,     k58, k53, k54,   k5a, k5b       \
)\
{\
  {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c},\
  {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c},\
  {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c},\
  {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX},\
  {k40, XXX, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c},\
  {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, XXX},\
  {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b, k6c},\
  {XXX, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, XXX},\
}

#define LAYOUT_iso( \
  k00,  k01, k02, k03, k04,  k60, k61, k62, k63,  k05, k06, k07, k08, k72,     k09, k0a, k0b, k0c, \
  k10, k11, k12, k13, k14, k64, k65, k66, k67, k15, k16, k17, k18,    k71,     k19, k1a, k1b, k1c, \
  k20,  k21, k22, k23, k24, k68, k69, k6a, k6b, k25, k26, k27, k28,            k29, k2a, k2b, k2c, \
  k30,    k31, k32, k33, k34, k6c, k75, k76, k77, k35, k36, k37, k73, k38,     k39, k3a, k3b,      \
  k40, k41, k42, k43, k44, k78, k79, k7a, k7b, k45, k46, k47,    k48,   k74,   k49, k4a, k4b, k4c, \
  k50, k51, k52,                k59,            k55, k56, k57,     k58, k53, k54,   k5a, k5b       \
)\
{\
  {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c},\
  {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c},\
  {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c},\
  {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX},\
  {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c},\
  {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, XXX},\
  {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b, k6c},\
  {XXX, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, XXX},\
}
=======
inline void kbd19x_nmlk_led_on(void)    { gpio_write_pin_high(LED_NUM_LOCK_PIN); }
inline void kbd19x_nmlk_led_off(void)   { gpio_write_pin_low(LED_NUM_LOCK_PIN); }
>>>>>>> upstream/master
