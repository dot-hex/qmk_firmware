#pragma once

<<<<<<< HEAD
/* USB Device descriptor parameter */
#define DEVICE_VER 0x2019

#undef MATRIX_ROWS
#undef MATRIX_COLS
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

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

#define MATRIX_ROW_PINS { A3, B8, B9, B1 }
#define MATRIX_COL_PINS { A7, A8, B2, B10 }

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
    #define STARTUP_SONG SONG(ONE_UP_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

#define AUDIO_CLICKY
  /* to enable clicky on startup */
  //#define AUDIO_CLICKY_ON
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f
#endif

// configure oled driver for the 128x32 oled
#define OLED_UPDATE_INTERVAL 33 // ~30fps
<<<<<<< HEAD

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

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 6

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
