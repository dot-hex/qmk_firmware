<<<<<<< HEAD
<<<<<<<< HEAD:keyboards/durgod/dgk6x/dgk6x.c
/* Copyright 2021 Jessica Sullivan and Don Kjer 
========
/* Copyright 2021 kuenhlee, Don Kjer, Tyler Tidman
 * Copyright 2021 Simon Arlott
>>>>>>>> upstream/master:keyboards/durgod/k320/k320.c
=======
/* Copyright 2021 Jessica Sullivan and Don Kjer
>>>>>>> upstream/master
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
<<<<<<<< HEAD:keyboards/durgod/dgk6x/dgk6x.c
=======
>>>>>>> upstream/master
#include "dgk6x.h"

/* Private Functions */
void off_all_leds(void) {
<<<<<<< HEAD
    writePinHigh(LED_CAPS_LOCK_PIN);
    writePinHigh(LED_WIN_LOCK_PIN);
    writePinHigh(LED_MR_LOCK_PIN);
}

void on_all_leds(void) {
    writePinLow(LED_CAPS_LOCK_PIN);
    writePinLow(LED_WIN_LOCK_PIN);
    writePinLow(LED_MR_LOCK_PIN);
========
#include "k320.h"
#include <ch.h>
#include <hal.h>

/* Private Functions */
void off_all_leds(void) {
#ifdef LED_NUM_LOCK_PIN
    gpio_write_pin_high(LED_NUM_LOCK_PIN);
#endif
    gpio_write_pin_high(LED_CAPS_LOCK_PIN);
    gpio_write_pin_high(LED_SCROLL_LOCK_PIN);
=======
    gpio_write_pin_high(LED_CAPS_LOCK_PIN);
>>>>>>> upstream/master
    gpio_write_pin_high(LED_WIN_LOCK_PIN);
    gpio_write_pin_high(LED_MR_LOCK_PIN);
}

void on_all_leds(void) {
<<<<<<< HEAD
#ifdef LED_NUM_LOCK_PIN
    gpio_write_pin_low(LED_NUM_LOCK_PIN);
#endif
    gpio_write_pin_low(LED_CAPS_LOCK_PIN);
    gpio_write_pin_low(LED_SCROLL_LOCK_PIN);
    gpio_write_pin_low(LED_WIN_LOCK_PIN);
    gpio_write_pin_low(LED_MR_LOCK_PIN);
>>>>>>>> upstream/master:keyboards/durgod/k320/k320.c
=======
    gpio_write_pin_low(LED_CAPS_LOCK_PIN);
    gpio_write_pin_low(LED_WIN_LOCK_PIN);
    gpio_write_pin_low(LED_MR_LOCK_PIN);
>>>>>>> upstream/master
}

/* WinLock and MR LEDs are non-standard. Need to override led init */
void led_init_ports(void) {
<<<<<<< HEAD
<<<<<<<< HEAD:keyboards/durgod/dgk6x/dgk6x.c
    setPinOutput(LED_CAPS_LOCK_PIN);
    setPinOutput(LED_WIN_LOCK_PIN);
    setPinOutput(LED_MR_LOCK_PIN);
    off_all_leds();
}


#ifndef WINLOCK_DISABLED
static bool win_key_locked = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TGUI:
            if (record->event.pressed) {
                // Toggle GUI lock on key press
                win_key_locked = !win_key_locked;
                writePin(LED_WIN_LOCK_PIN, !win_key_locked);
            }
            break;
        case KC_LGUI:
            if (win_key_locked) { return false; }
            break;
========
#ifdef LED_NUM_LOCK_PIN
    gpio_set_pin_output(LED_NUM_LOCK_PIN);
#endif
    gpio_set_pin_output(LED_CAPS_LOCK_PIN);
    gpio_set_pin_output(LED_SCROLL_LOCK_PIN);
=======
    gpio_set_pin_output(LED_CAPS_LOCK_PIN);
>>>>>>> upstream/master
    gpio_set_pin_output(LED_WIN_LOCK_PIN);
    gpio_set_pin_output(LED_MR_LOCK_PIN);
    off_all_leds();
}

<<<<<<< HEAD
=======

>>>>>>> upstream/master
#ifndef WINLOCK_DISABLED
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GU_TOGG:
            if (record->event.pressed) {
                // Toggle LED on key press
                gpio_toggle_pin(LED_WIN_LOCK_PIN);
            }
            break;
<<<<<<< HEAD
>>>>>>>> upstream/master:keyboards/durgod/k320/k320.c
=======
>>>>>>> upstream/master
    }
    return process_record_user(keycode, record);
}
#endif /* WINLOCK_DISABLED */

<<<<<<< HEAD
<<<<<<<< HEAD:keyboards/durgod/dgk6x/dgk6x.c
#ifdef RGB_MATRIX_ENABLE

__attribute__ ((weak))
void rgb_matrix_indicators_user(void)
{
    if (host_keyboard_led_state().caps_lock)
    {
        rgb_matrix_set_color(CAPS_LED, 0xFF, 0xFF, 0xFF);
    }
}
#endif /* RGB_MATRIX_ENABLE */


========
#ifndef HW_RESET_PIN_DISABLED
static void hardware_reset_cb(void *arg) {
    chSysLockFromISR();
    bootloader_jump();
    chSysUnlockFromISR();
}
#endif

void keyboard_pre_init_kb(void) {
    gpio_set_pin_input_high(HARDWARE_RESET_PIN);

#ifndef HW_RESET_PIN_DISABLED
    /* Jump to bootloader when the hardware reset button is pressed */
    palEnablePadEvent(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), PAL_EVENT_MODE_FALLING_EDGE);
    palSetPadCallback(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), hardware_reset_cb, NULL);

    /* The interrupt is edge-triggered so check that it's not already pressed */
    if (!gpio_read_pin(HARDWARE_RESET_PIN)) {
        bootloader_jump();
    }
#endif

    keyboard_pre_init_user();
}
>>>>>>>> upstream/master:keyboards/durgod/k320/k320.c
=======
#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LED, 0xFF, 0xFF, 0xFF);
    }
    return true;
}
#endif /* RGB_MATRIX_ENABLE */
>>>>>>> upstream/master
