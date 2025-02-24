/* Copyright 2017 Jack Humbert
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
#include "quantum.h"

#if defined(UNICODE_ENABLE) + defined(UNICODEMAP_ENABLE) + defined(UCIS_ENABLE) > 1
#    error "Cannot enable more than one Unicode method (UNICODE, UNICODEMAP, UCIS) at the same time"
#endif

// Keycodes used for starting Unicode input on different platforms
#ifndef UNICODE_KEY_MAC
#    define UNICODE_KEY_MAC KC_LEFT_ALT
#endif
#ifndef UNICODE_KEY_LNX
#    define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#endif
#ifndef UNICODE_KEY_WINC
#    define UNICODE_KEY_WINC KC_RIGHT_ALT
#endif

// Comma-delimited, ordered list of input modes selected for use (e.g. in cycle)
// Example: #define UNICODE_SELECTED_MODES UC_WINC, UC_LNX
#ifndef UNICODE_SELECTED_MODES
#    define UNICODE_SELECTED_MODES -1
#endif

// Whether input mode changes in cycle should be written to EEPROM
#ifndef UNICODE_CYCLE_PERSIST
#    define UNICODE_CYCLE_PERSIST true
#endif

// Delay between starting Unicode input and sending a sequence, in ms
#ifndef UNICODE_TYPE_DELAY
#    define UNICODE_TYPE_DELAY 10
#endif

// Deprecated aliases
#if !defined(UNICODE_KEY_MAC) && defined(UNICODE_KEY_OSX)
#    define UNICODE_KEY_MAC UNICODE_KEY_OSX
#endif
#if !defined(UNICODE_SONG_MAC) && defined(UNICODE_SONG_OSX)
#    define UNICODE_SONG_MAC UNICODE_SONG_OSX
#endif
#define UC_OSX UC_MAC

enum unicode_input_modes {
    UC_MAC,   // macOS using Unicode Hex Input
    UC_LNX,   // Linux using IBus
    UC_WIN,   // Windows using EnableHexNumpad
    UC_BSD,   // BSD (not implemented)
    UC_WINC,  // Windows using WinCompose (https://github.com/samhocevar/wincompose)
    UC__COUNT // Number of available input modes (always leave at the end)
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t input_mode : 8;
    };
} unicode_config_t;

extern unicode_config_t unicode_config;

void    unicode_input_mode_init(void);
uint8_t get_unicode_input_mode(void);
void    set_unicode_input_mode(uint8_t mode);
void    cycle_unicode_input_mode(int8_t offset);
void    persist_unicode_input_mode(void);

void unicode_input_start(void);
void unicode_input_finish(void);
void unicode_input_cancel(void);

void register_hex(uint16_t hex);
void register_hex32(uint32_t hex);
void register_unicode(uint32_t code_point);

void send_unicode_hex_string(const char *str);
void send_unicode_string(const char *str);
=======
#include <stdbool.h>
#include <stdint.h>
#include "action.h"
>>>>>>> upstream/master

bool process_unicode_common(uint16_t keycode, keyrecord_t *record);
