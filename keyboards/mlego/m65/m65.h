<<<<<<< HEAD
/*
Copyright 2021-2022 Alin M Elena <alinm.elena@gmail.com>

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

#define LAYOUT_ortho_5x13( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412  \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312 }, \
    { K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412 }  \
}

enum unicode_names {
    la = 0,
    lA,
    lb,
    lB,
    lc,
    lC,
    ld,
    lD,
    le,
    lE,
    lf,
    lF,
    lg,
    lG,
    lh,
    lH,
    li,
    lI,
    lj,
    lJ,
    lk,
    lK,
    ll,
    lL,
    lm,
    lM,
    ln,
    lN,
    lo,
    lO,
    lp,
    lP,
    lq,
    lQ,
    lr,
    lR,
    ls,
    lS,
    lt,
    lT,
    lu,
    lU,
    lv,
    lV,
    lw,
    lW,
    lx,
    lX,
    ly,
    lY,
    lz,
    lZ,
    lc1,
    lC1,
    lp1,
    lP1,
    lq1,
    lQ1,
    ll1,
    lL1,
    lk1,
    lK1,
    ra,
    rA,
    ra1,
    rA1,
    rc,
    rC,
    ri,
    rI,
    rs,
    rS,
    rt,
    rT,
};

static inline void led_lwr(const bool on) {
#ifdef LED_NUM_LOCK_PIN
    writePin(LED_NUM_LOCK_PIN, on);
#endif
}

static inline void led_rse(const bool on) {
#ifdef LED_SCROLL_LOCK_PIN
    writePin(LED_SCROLL_LOCK_PIN, on);
#endif
}
static inline void led_caps(const bool on) {
#ifdef LED_CAPS_LOCK_PIN
    if ((DEVICE_VER == 0x0001) || (DEVICE_VER == 0x0003) || (DEVICE_VER == 0x0004)) {
        writePin(LED_CAPS_LOCK_PIN, !on);
    }
    if (DEVICE_VER == 0x0002) {
        writePin(LED_CAPS_LOCK_PIN, on);
=======
// Copyright 2020-2023 alin m elena (@alinelena)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#if defined(UNICODEMAP_ENABLE)
enum unicode_names { la = 0, lA, lb, lB, lc, lC, ld, lD, le, lE, lf, lF, lg, lG, lh, lH, li, lI, lj, lJ, lk, lK, ll, lL, lm, lM, ln, lN, lo, lO, lp, lP, lq, lQ, lr, lR, ls, lS, lt, lT, lu, lU, lv, lV, lw, lW, lx, lX, ly, lY, lz, lZ, lc1, lC1, lp1, lP1, lq1, lQ1, ll1, lL1, lk1, lK1, lbo1, lbo2, lbc1, lbc2, ls1, ls2, ra, rA, ra1, rA1, rc, rC, ri, rI, rs, rS, rt, rT, ro, rO, ra2, rA2, ra3, rA3, rx, rX, rv, rV, rb, rB, rn, rN };
#endif

enum layer_names { _QW = 0, _LWR, _RSE, _ADJ };


#if defined(OLED_ENABLE)
void user_oled_magic(void);
void render_logo(void);
void clear_screen(void);
void init_timer(void);
#endif

#if defined(RGBLIGHT_ENABLE)
void                             set_rgb_layers(layer_state_t);
const rgblight_segment_t* const* my_rgb(void);
void                             set_default_rgb_layers(layer_state_t);
#endif

void toggle_leds(const bool, const bool);
void set_led_toggle(const uint8_t, const bool);

static inline void init_lwr_rse_led(void) {
#if defined(LED_LWR_PIN)
    gpio_set_pin_output(LED_LWR_PIN);
    gpio_write_pin(LED_LWR_PIN, false);
    wait_ms(30);
#endif

#if defined(LED_RSE_PIN)
    gpio_set_pin_output(LED_RSE_PIN);
    gpio_write_pin(LED_RSE_PIN, false);
    wait_ms(30);
#endif
}

static inline void led_lwr(const bool on) {
#if defined(LED_LWR_PIN)
    if ((PRODUCT_ID == 0x6064) || (PRODUCT_ID == 0x6065) ||
        (PRODUCT_ID == 0x6066) || (PRODUCT_ID == 0x6067)) {
        gpio_write_pin(LED_LWR_PIN, !on);
    }else{
        gpio_write_pin(LED_LWR_PIN, on);
    }
#endif
}

static inline void led_rse(const bool on) {
#if defined(LED_RSE_PIN)
    if ((PRODUCT_ID == 0x6064) || (PRODUCT_ID == 0x6065) ||
        (PRODUCT_ID == 0x6066) || (PRODUCT_ID == 0x6067)) {
        gpio_write_pin(LED_RSE_PIN, !on);
    }else{
        gpio_write_pin(LED_RSE_PIN, on);
>>>>>>> upstream/master
    }
#endif
}
