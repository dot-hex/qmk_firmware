/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
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

/* USB Device descriptor parameter */
#define DEVICE_VER 0x0003

#undef MATRIX_ROWS
#undef MATRIX_COLS
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROW_PINS { C15, C14, A10, A9, A8 }
#define MATRIX_COL_PINS { B8,  B2,  B10, A0, A1, A2, B0, A3, B1, A6, A7, B12, C13, B11, B9 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { B13 }
#define ENCODERS_PAD_B { B14 }

=======
>>>>>>> upstream/master

//Audio
#undef AUDIO_VOICES
#undef AUDIO_PIN
#define AUDIO_PIN A5
#define AUDIO_PIN_ALT A4
#define AUDIO_PIN_ALT_AS_NEGATIVE


#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#define AUDIO_CLICKY
  /* to enable clicky on startup */
  //#define AUDIO_CLICKY_ON
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f
#endif

// configure oled driver for the 128x32 oled
#define OLED_UPDATE_INTERVAL 33 // ~30fps
<<<<<<< HEAD

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
// #define DEBOUNCE 6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO
=======
>>>>>>> upstream/master

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
<<<<<<< HEAD
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
=======
>>>>>>> upstream/master

/* Haptic Driver initialization settings
 * Feedback Control Settings */
#define DRV2605L_FB_ERM_LRA 1 /* For ERM:0 or LRA:1*/
#define DRV2605L_FB_BRAKEFACTOR 6 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define DRV2605L_FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* default 3V ERM vibration motor voltage and library*/
#if DRV2605L_FB_ERM_LRA == 0
#define DRV2605L_RATED_VOLTAGE 3
#define DRV2605L_V_RMS 2.3
#define DRV2605L_V_PEAK 3.30
/* Library Selection */
#define DRV2605L_LIBRARY 4 /* For Empty:0' TS2200 library A to D:1-5, LRA Library: 6 */

/* default 2V LRA voltage and library */
#elif DRV2605L_FB_ERM_LRA == 1
#define DRV2605L_RATED_VOLTAGE 2
#define DRV2605L_V_RMS 2.0
#define DRV2605L_V_PEAK 2.85
#define DRV2605L_F_LRA 200
/* Library Selection */
#define DRV2605L_LIBRARY 6 /* For Empty:0' TS2200 library A to D:1-5, LRA Library: 6 */

#endif

/* Control 1 register settings */
#define DRV2605L_DRIVE_TIME 25
#define DRV2605L_AC_COUPLE 0
#define DRV2605L_STARTUP_BOOST 1

/* Control 2 Settings */
#define DRV2605L_BIDIR_INPUT 1
#define DRV2605L_BRAKE_STAB 1 /* Loopgain is reduced when braking is almost complete to improve stability */
#define DRV2605L_SAMPLE_TIME 3
#define DRV2605L_BLANKING_TIME 1
#define DRV2605L_IDISS_TIME 1

/* Control 3 settings */
#define DRV2605L_NG_THRESH 2
#define DRV2605L_ERM_OPEN_LOOP 1
#define DRV2605L_SUPPLY_COMP_DIS 0
#define DRV2605L_DATA_FORMAT_RTO 0
#define DRV2605L_LRA_DRIVE_MODE 0
#define DRV2605L_N_PWM_ANALOG 0
#define DRV2605L_LRA_OPEN_LOOP 0
/* Control 4 settings */
#define DRV2605L_ZC_DET_TIME 0
#define DRV2605L_AUTO_CAL_TIME 3

#define SOLENOID_PIN A14
