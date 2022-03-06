/*
Copyright 2012-2018 Jun Wako, Jack Humbert, Yiancar
Copyright 2019 Evy Dekkers

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

#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

#ifdef DIRECT_PINS
static pin_t direct_pins[MATRIX_ROWS][MATRIX_COLS] = DIRECT_PINS;
#elif (DIODE_DIRECTION == ROW2COL) || (DIODE_DIRECTION == COL2ROW)
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
//static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
#endif

// matrix code

#ifdef DIRECT_PINS

static void init_pins(void) {
    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            pin_t pin = direct_pins[row][col];
            if (pin != NO_PIN) {
                setPinInputHigh(pin);
            }
        }
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    matrix_row_t last_row_value = current_matrix[current_row];
    current_matrix[current_row] = 0;

    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        pin_t pin = direct_pins[current_row][col_index];
        if (pin != NO_PIN) {
            current_matrix[current_row] |= readPin(pin) ? 0 : (MATRIX_ROW_SHIFTER << col_index);
        }
    }

    return (last_row_value != current_matrix[current_row]);
}

<<<<<<< HEAD
#elif (DIODE_DIRECTION == COL2ROW)

static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
}

static void unselect_row(uint8_t row) { setPinInputHigh(row_pins[row]); }

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    wait_us(30);

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {

        // Select the col pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_matrix[current_row] |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

#elif (DIODE_DIRECTION == ROW2COL)

/* Cols 0 - 16
 * These columns use two 74HC138 3 to 8 bit demultiplexer. D6, D7 is the enable pin, must be set high (1) to use it.
 *
 * col / pin:     PA0  PA1  PA2  PD6  PD7  PC4
=======
#elif (DIODE_DIRECTION == ROW2COL)

/* Cols 0 - 16
 * These columns use two 74HC138 3 to 8 bit demultiplexer. B0, F1 is the enable pin, must be set high (1) to use it.
 *
 * col / pin:     PB5  PB7  PF0  PB0  PF1  PE6
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
 * 0:              0 ── 0 ── 0    1 ── 0    0 
 * ────────────────────────────────────────────
 * 1:              0 ── 0 ── 1    1 ── 0    0
 * ────────────────────────────────────────────    
 * 2:              0 ── 1 ── 0    1 ── 0    0 
 * ────────────────────────────────────────────    
 * 3:              0 ── 1 ── 1    1 ── 0    0 
 * ────────────────────────────────────────────    
 * 4:              1 ── 0 ── 0    1 ── 0    0 
 * ────────────────────────────────────────────    
 * 5:              1 ── 0 ── 1    1 ── 0    0 
 * ────────────────────────────────────────────    
 * 6:              1 ── 1 ── 0    1 ── 0    0 
 * ────────────────────────────────────────────    
 * 7:              1 ── 1 ── 1    1 ── 0    0 
 * ────────────────────────────────────────────    
 * 8:              0 ── 0 ── 0    0 ── 1    0 
 * ────────────────────────────────────────────    
 * 9:              0 ── 0 ── 1    0 ── 1    0 
 * ────────────────────────────────────────────    
 *10:              0 ── 1 ── 0    0 ── 1    0 
 * ────────────────────────────────────────────    
 *11:              0 ── 1 ── 1    0 ── 1    0 
 * ────────────────────────────────────────────    
 *12:              1 ── 0 ── 0    0 ── 1    0 
 * ────────────────────────────────────────────    
 *13:              1 ── 0 ── 1    0 ── 1    0 
 * ────────────────────────────────────────────    
 *14:              1 ── 1 ── 1    0 ── 1    0 
 * ────────────────────────────────────────────    
 *15:              1 ── 1 ── 0    0 ── 1    0 
 * ────────────────────────────────────────────    
 *16:              0 ── 0 ── 0    0 ── 0    1  
 *
 */
static void select_col(uint8_t col) {
    switch (col) {
        case 0:
<<<<<<< HEAD
          writePinLow(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinHigh(D6);
          break;
        case 1:
          writePinLow(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinHigh(D6);
          break;
        case 2:
          writePinLow(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinHigh(D6);
          break;
        case 3:
          writePinLow(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinHigh(D6);
          break;
        case 4:
          writePinHigh(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinHigh(D6);
          break;
        case 5:
          writePinHigh(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinHigh(D6);
          break;
        case 6:
          writePinHigh(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinHigh(D6);
          break;
        case 7:
          writePinHigh(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinHigh(D6);
          break;
        case 8:
          writePinLow(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinHigh(D7);
          break;
        case 9:
          writePinLow(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinHigh(D7);
          break;
        case 10:
          writePinLow(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinHigh(D7);
          break;
        case 11:
          writePinLow(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinHigh(D7);
          break;
        case 12:
          writePinHigh(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinHigh(D7);
          break;
        case 13:
          writePinHigh(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinHigh(D7);
          break;
        case 14:
          writePinHigh(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinHigh(D7);
          break;
        case 15:
          writePinHigh(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinHigh(D7);
          break;
        case 16:
          writePinLow(C4);
=======
          writePinLow(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinHigh(B0);
          break;
        case 1:
          writePinLow(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinHigh(B0);
          break;
        case 2:
          writePinLow(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinHigh(B0);
          break;
        case 3:
          writePinLow(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinHigh(B0);
          break;
        case 4:
          writePinHigh(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinHigh(B0);
          break;
        case 5:
          writePinHigh(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinHigh(B0);
          break;
        case 6:
          writePinHigh(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinHigh(B0);
          break;
        case 7:
          writePinHigh(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinHigh(B0);
          break;
        case 8:
          writePinLow(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinHigh(F1);
          break;
        case 9:
          writePinLow(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinHigh(F1);
          break;
        case 10:
          writePinLow(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinHigh(F1);
          break;
        case 11:
          writePinLow(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinHigh(F1);
          break;
        case 12:
          writePinHigh(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinHigh(F1);
          break;
        case 13:
          writePinHigh(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinHigh(F1);
          break;
        case 14:
          writePinHigh(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinHigh(F1);
          break;
        case 15:
          writePinHigh(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinHigh(F1);
          break;
        case 16:
          writePinLow(E6);
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
          break;
    }
}

static void unselect_col(uint8_t col) {
    switch (col) {
        case 0:
<<<<<<< HEAD
          writePinHigh(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinLow(D6);
          break;
        case 1:
          writePinHigh(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinLow(D6);
          break;
        case 2:
          writePinHigh(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinLow(D6);
          break;
        case 3:
          writePinHigh(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinLow(D6);
          break;
        case 4:
          writePinLow(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinLow(D6);
          break;
        case 5:
          writePinLow(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinLow(D6);
          break;
        case 6:
          writePinLow(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinLow(D6);
          break;
        case 7:
          writePinLow(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinLow(D6);
          break;
        case 8:
          writePinHigh(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinLow(D7);
          break;
        case 9:
          writePinHigh(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinLow(D7);
          break;
        case 10:
          writePinHigh(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinLow(D7);
          break;
        case 11:
          writePinHigh(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinLow(D7);
          break;
        case 12:
          writePinLow(A0);
          writePinHigh(A1);
          writePinHigh(A2);
          writePinLow(D7);
          break;
        case 13:
          writePinLow(A0);
          writePinHigh(A1);
          writePinLow(A2);
          writePinLow(D7);
          break;
        case 14:
          writePinLow(A0);
          writePinLow(A1);
          writePinLow(A2);
          writePinLow(D7);
          break;
        case 15:
          writePinLow(A0);
          writePinLow(A1);
          writePinHigh(A2);
          writePinLow(D7);
          break;
        case 16:
          writePinHigh(C4);
=======
          writePinHigh(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinLow(B0);
          break;
        case 1:
          writePinHigh(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinLow(B0);
          break;
        case 2:
          writePinHigh(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinLow(B0);
          break;
        case 3:
          writePinHigh(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinLow(B0);
          break;
        case 4:
          writePinLow(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinLow(B0);
          break;
        case 5:
          writePinLow(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinLow(B0);
          break;
        case 6:
          writePinLow(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinLow(B0);
          break;
        case 7:
          writePinLow(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinLow(B0);
          break;
        case 8:
          writePinHigh(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinLow(F1);
          break;
        case 9:
          writePinHigh(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinLow(F1);
          break;
        case 10:
          writePinHigh(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinLow(F1);
          break;
        case 11:
          writePinHigh(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinLow(F1);
          break;
        case 12:
          writePinLow(B5);
          writePinHigh(B7);
          writePinHigh(F0);
          writePinLow(F1);
          break;
        case 13:
          writePinLow(B5);
          writePinHigh(B7);
          writePinLow(F0);
          writePinLow(F1);
          break;
        case 14:
          writePinLow(B5);
          writePinLow(B7);
          writePinLow(F0);
          writePinLow(F1);
          break;
        case 15:
          writePinLow(B5);
          writePinLow(B7);
          writePinHigh(F0);
          writePinLow(F1);
          break;
        case 16:
          writePinHigh(E6);
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
          break;
    }
}

static void unselect_cols(void) {
    //Native
<<<<<<< HEAD
    writePinHigh(C4);

    //Demultiplexer
    writePinLow(D6);
    writePinLow(D7);
    writePinHigh(A0);
    writePinHigh(A1);
    writePinHigh(A2);
=======
    writePinHigh(E6);

    //Demultiplexer
    writePinLow(B0);
    writePinLow(F1);
    writePinHigh(B5);
    writePinHigh(B7);
    writePinHigh(F0);
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
}

static void init_pins(void) {
    unselect_cols();
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
<<<<<<< HEAD
    setPinOutput(A0);
    setPinOutput(A1);
    setPinOutput(A2);
    setPinOutput(D6);
    setPinOutput(D7);
    setPinOutput(C4);
=======
    setPinOutput(B5);
    setPinOutput(B7);
    setPinOutput(F0);
    setPinOutput(B0);
    setPinOutput(F1);
    setPinOutput(E6);
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    bool matrix_changed = false;

    // Select col and wait for col selecton to stabilize
    select_col(current_col);
    wait_us(30);

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // Store last value of row prior to reading
        matrix_row_t last_row_value = current_matrix[row_index];

        // Check row pin state
        if (readPin(row_pins[row_index]) == 0) {
            // Pin LO, set col bit
            current_matrix[row_index] |= (MATRIX_ROW_SHIFTER << current_col);
        } else {
            // Pin HI, clear col bit
            current_matrix[row_index] &= ~(MATRIX_ROW_SHIFTER << current_col);
        }

        // Determine if the matrix changed state
        if ((last_row_value != current_matrix[row_index]) && !(matrix_changed)) {
            matrix_changed = true;
        }
    }

    // Unselect col
    unselect_col(current_col);

    return matrix_changed;
}

#endif

void matrix_init_custom(void) {
    // initialize key pins
    init_pins();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

<<<<<<< HEAD
#if defined(DIRECT_PINS) || (DIODE_DIRECTION == COL2ROW)
    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(current_matrix, current_row);
    }
#elif (DIODE_DIRECTION == ROW2COL)
=======
#if defined(DIRECT_PINS) || (DIODE_DIRECTION == ROW2COL)
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
    // Set col, read rows
    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
        changed |= read_rows_on_col(current_matrix, current_col);
    }
#endif

    return changed;
}
