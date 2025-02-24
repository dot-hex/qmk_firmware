<<<<<<< HEAD
#include "matrix.h"

#include "gpio.h"

static uint8_t read_rows(void) {
    return (readPin(C7) ? 0 : 1) |
           (readPin(B1) ? 0 : 2) |
           (readPin(B2) ? 0 : 4) |
           (readPin(C6) ? 0 : 8) |
           (readPin(B4) ? 0 : 16) |
           (readPin(B5) ? 0 : 32);
}

static void select_col(uint8_t col) {
    writePinLow(D3);

    writePin(D4, (col & 1));
    writePin(D5, (col & 2));
    writePin(D6, (col & 4));
    writePin(D7, (col & 8));
}

static void  unselect_cols(void) {
    writePinHigh(D3);
}

void matrix_init_custom(void) {
    /* 74HC154 col pin configuration
     * pin:     D3  D7  D6  D5  D4
     * row: off  0   x   x   x   x
     *      0    1   0   0   0   0
     *      1    1   0   0   0   1
     *      2    1   0   0   1   0
     *      3    1   0   0   1   1
     *      4    1   0   1   0   0
     *      5    1   0   1   0   1
     *      6    1   0   1   1   0
     *      7    1   0   1   1   1
     *      8    1   1   0   0   0
     *      9    1   1   0   0   1
     *      10   1   1   0   1   0
     *      11   1   1   0   1   1
     *      12   1   1   1   0   0
     *      13   1   1   1   0   1
     *      14   1   1   1   1   0
     *      15   1   1   1   1   1
     */
    setPinOutput(D3);
    writePinHigh(D3);

    setPinOutput(D4);
    setPinOutput(D5);
    setPinOutput(D6);
    setPinOutput(D7);


    /* Row pin configuration
     *
     * row:  0  1  2  3  4  5
     * pin: C7 B1 B2 C6 B4 B5
     *
     */
    setPinInputHigh(C7);
    setPinInputHigh(B1);
    setPinInputHigh(B2);
    setPinInputHigh(C6);
    setPinInputHigh(B4);
    setPinInputHigh(B5);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        select_col(col);
        matrix_io_delay();
        uint8_t rows = read_rows();

        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool prev_bit = current_matrix[row] & ((matrix_row_t)1 << col);
            bool curr_bit = rows & (1 << row);

            if (prev_bit != curr_bit) {
                current_matrix[row] ^= ((matrix_row_t)1 << col);
                changed = true;
            }
        }
        unselect_cols();
=======
/* Copyright 2022
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

#include "matrix.h"
#include "gpio.h"
#include "sn74x154.h"

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;

/* All columns use a 74HC154 4-to-16 demultiplexer.
 * D3 is the enable pin, must be set high to use it.
 *
 *     A3   A2   A1   A0
 *     D7   D6   D5   D4
 * 0:   0    0    0    0
 * 1:   0    0    0    1
 * 2:   0    0    1    0
 * 3:   0    0    1    1
 * 4:   0    1    0    0
 * 5:   0    1    0    1
 * 6:   0    1    1    0
 * 7:   0    1    1    1
 * 8:   1    0    0    0
 * 9:   1    0    0    1
 * 10:  1    0    1    0
 * 11:  1    0    1    1
 * 12:  1    1    0    0
 * 13:  1    1    0    1
 * 14:  1    1    1    0
 * 15:  1    1    1    1
 */
static void select_col(uint8_t col) {
    sn74x154_set_addr(col);
}

static void init_pins(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        gpio_set_pin_input_high(row_pins[x]);
    }
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    bool matrix_changed = false;

    // Select col and wait for col seleciton to stabilize
    select_col(current_col);
    matrix_io_delay();

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // Store last value of row prior to reading
        matrix_row_t last_row_value = current_matrix[row_index];

        // Check row pin state
        if (gpio_read_pin(row_pins[row_index]) == 0) {
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

    return matrix_changed;
}

void matrix_init_custom(void) {
    // initialize demultiplexer
    sn74x154_init();
    sn74x154_set_enabled(true);
    // initialize key pins
    init_pins();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    // Set col, read rows
    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
        changed |= read_rows_on_col(current_matrix, current_col);
>>>>>>> upstream/master
    }

    return changed;
}
