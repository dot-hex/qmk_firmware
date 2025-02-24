/*
 * matrix.c testing macros
 *   MATRIX_DEBUG_SCAN:  Measuring execution time of `matrix_scan()`
 *   MATRIX_DEBUG_DELAY: Observation of delay after `unselect_row()`
 */
#pragma once
#ifndef __ASSEMBLER__
#include <gpio.h>

static inline void setDebugPinOutput_Low(void) {
<<<<<<< HEAD
    setPinOutput(MATRIX_DEBUG_PIN);
    writePinLow(MATRIX_DEBUG_PIN);
=======
    gpio_set_pin_output(MATRIX_DEBUG_PIN);
    gpio_write_pin_low(MATRIX_DEBUG_PIN);
>>>>>>> upstream/master
}

#define MATRIX_DEBUG_PIN_INIT()   setDebugPinOutput_Low()

#ifdef MATRIX_DEBUG_SCAN
<<<<<<< HEAD
#  define MATRIX_DEBUG_SCAN_START() writePinHigh(MATRIX_DEBUG_PIN)
#  define MATRIX_DEBUG_SCAN_END()   writePinLow(MATRIX_DEBUG_PIN)
=======
#  define MATRIX_DEBUG_SCAN_START() gpio_write_pin_high(MATRIX_DEBUG_PIN)
#  define MATRIX_DEBUG_SCAN_END()   gpio_write_pin_low(MATRIX_DEBUG_PIN)
>>>>>>> upstream/master
#else
#  define MATRIX_DEBUG_SCAN_START()
#  define MATRIX_DEBUG_SCAN_END()
#endif

#ifdef MATRIX_DEBUG_DELAY
<<<<<<< HEAD
#  define MATRIX_DEBUG_DELAY_START() writePinHigh(MATRIX_DEBUG_PIN)
#  define MATRIX_DEBUG_DELAY_END()   writePinLow(MATRIX_DEBUG_PIN)
=======
#  define MATRIX_DEBUG_DELAY_START() gpio_write_pin_high(MATRIX_DEBUG_PIN)
#  define MATRIX_DEBUG_DELAY_END()   gpio_write_pin_low(MATRIX_DEBUG_PIN)
>>>>>>> upstream/master
#else
#  define MATRIX_DEBUG_DELAY_START()
#  define MATRIX_DEBUG_DELAY_END()
#endif

#endif // __ASSEMBLER__
