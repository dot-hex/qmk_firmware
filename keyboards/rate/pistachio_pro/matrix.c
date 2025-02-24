/*
Copyright 2012-2018 Jun Wako, Jack Humbert, Yiancar

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
<<<<<<< HEAD
#include <stdint.h>
#include <stdbool.h>
#include "matrix.h"
#include "quantum.h"
=======
#include "matrix.h"
#include "atomic_util.h"
>>>>>>> upstream/master

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

<<<<<<< HEAD
static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinInputHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON { setPinInputHigh(pin); }
}

static void select_row(uint8_t row) {
    setPinOutput_writeLow(row_pins[row]);
}

static void unselect_row(uint8_t row) {
    setPinInputHigh_atomic(row_pins[row]);
=======
static inline void gpio_atomic_set_pin_output_low(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_output(pin);
        gpio_write_pin_low(pin);
    }
}

static inline void gpio_atomic_set_pin_input_high(pin_t pin) {
    ATOMIC_BLOCK_FORCEON { gpio_set_pin_input_high(pin); }
}

static void select_row(uint8_t row) {
    gpio_atomic_set_pin_output_low(row_pins[row]);
}

static void unselect_row(uint8_t row) {
    gpio_atomic_set_pin_input_high(row_pins[row]);
>>>>>>> upstream/master
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
<<<<<<< HEAD
        setPinInputHigh_atomic(row_pins[x]);
=======
        gpio_atomic_set_pin_input_high(row_pins[x]);
>>>>>>> upstream/master
    }
}

static void select_col(uint8_t col) {
<<<<<<< HEAD
    setPinOutput_writeLow(col_pins[col]);
}

static void unselect_col(uint8_t col) {
    setPinInputHigh_atomic(col_pins[col]);
=======
    gpio_atomic_set_pin_output_low(col_pins[col]);
}

static void unselect_col(uint8_t col) {
    gpio_atomic_set_pin_input_high(col_pins[col]);
>>>>>>> upstream/master
}

static void unselect_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
<<<<<<< HEAD
        setPinInputHigh_atomic(col_pins[x]);
=======
        gpio_atomic_set_pin_input_high(col_pins[x]);
>>>>>>> upstream/master
    }
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
<<<<<<< HEAD
        setPinInputHigh_atomic(col_pins[x]);
    }
    unselect_cols();
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh_atomic(row_pins[x]);
=======
        gpio_atomic_set_pin_input_high(col_pins[x]);
    }
    unselect_cols();
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        gpio_atomic_set_pin_input_high(row_pins[x]);
>>>>>>> upstream/master
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Select row
    select_row(current_row);
    matrix_io_delay();

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS / 2; col_index++) {
        // Check row pin state
<<<<<<< HEAD
        if (readPin(col_pins[col_index])) {
=======
        if (gpio_read_pin(col_pins[col_index])) {
>>>>>>> upstream/master
            // Pin HI, clear col bit
            current_matrix[current_row] &= ~(MATRIX_ROW_SHIFTER << col_index);
        } else {
            // Pin LO, set col bit
            current_matrix[current_row] |= (MATRIX_ROW_SHIFTER << col_index);
        }
    }

    // Unselect row
    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    bool matrix_changed = false;

    // Select col
    select_col(current_col);
    matrix_io_delay();

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // Store last value of row prior to reading
        matrix_row_t last_row_value = current_matrix[row_index];

        // Check row pin state
<<<<<<< HEAD
        if (readPin(row_pins[row_index])) {
=======
        if (gpio_read_pin(row_pins[row_index])) {
>>>>>>> upstream/master
            // Pin HI, clear col bit
            current_matrix[row_index] &= ~(MATRIX_ROW_SHIFTER << ( current_col + MATRIX_COLS/2));
        } else {
            // Pin LO, set col bit
            current_matrix[row_index] |= (MATRIX_ROW_SHIFTER << ( current_col + MATRIX_COLS/2));
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

void matrix_init_custom(void) {
    init_pins();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(current_matrix, current_row);
    }
    // Set col, read rows
    for (uint8_t current_col = 0; current_col < (MATRIX_COLS/2); current_col++) {
        changed |= read_rows_on_col(current_matrix, current_col);
    }

    return (uint8_t)changed;
}
