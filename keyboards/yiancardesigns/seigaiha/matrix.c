/*
Copyright 2012-2020 Jun Wako, Jack Humbert, Yiancar-Designs

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
#include "wait.h"
#include "quantum.h"
=======
#include "matrix.h"
#include "wait.h"
>>>>>>> upstream/master
#include "i2c_master.h"

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

static void unselect_rows(void) {
    for(uint8_t x = 0; x < MATRIX_ROWS; x++) {
<<<<<<< HEAD
        setPinInputHigh(row_pins[x]);
=======
        gpio_set_pin_input_high(row_pins[x]);
>>>>>>> upstream/master
    }
}

static void select_row(uint8_t row) {
<<<<<<< HEAD
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
}

static void unselect_row(uint8_t row) {
    setPinInputHigh(row_pins[row]);
=======
    gpio_set_pin_output(row_pins[row]);
    gpio_write_pin_low(row_pins[row]);
}

static void unselect_row(uint8_t row) {
    gpio_set_pin_input_high(row_pins[row]);
>>>>>>> upstream/master
}

static void init_pins(void) {
    unselect_rows();
    // Set I/O
    uint8_t send_data = 0x1F;
<<<<<<< HEAD
    i2c_writeReg((PORT_EXPANDER_ADDRESS << 1), 0x00, &send_data, 1, 20);
    // Set Pull-up
    i2c_writeReg((PORT_EXPANDER_ADDRESS << 1), 0x06, &send_data, 1, 20);

    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if ( x < 10 ) {
            setPinInputHigh(col_pins[x]);
=======
    i2c_write_register((PORT_EXPANDER_ADDRESS << 1), 0x00, &send_data, 1, 20);
    // Set Pull-up
    i2c_write_register((PORT_EXPANDER_ADDRESS << 1), 0x06, &send_data, 1, 20);

    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if ( x < 10 ) {
            gpio_set_pin_input_high(col_pins[x]);
>>>>>>> upstream/master
        }
    }
}

void matrix_init_custom(void) {
    // TODO: initialize hardware here
    // Initialize I2C
    i2c_init();

    // initialize key pins
    init_pins();
    wait_ms(50);
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    matrix_io_delay();

    uint8_t port_expander_col_buffer;
<<<<<<< HEAD
    i2c_readReg((PORT_EXPANDER_ADDRESS << 1), 0x09, &port_expander_col_buffer, 1, 20);
=======
    i2c_read_register((PORT_EXPANDER_ADDRESS << 1), 0x09, &port_expander_col_buffer, 1, 20);
>>>>>>> upstream/master

    // For each col...
    for(uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        uint8_t pin_state;
        // Select the col pin to read (active low)
        switch (col_index) {
            case 10 :
                pin_state = port_expander_col_buffer & (1 << 0);
                break;
            case 11 :
                pin_state = port_expander_col_buffer & (1 << 1);
                break;
            case 12 :
                pin_state = port_expander_col_buffer & (1 << 2);
                break;
            case 13 :
                pin_state = port_expander_col_buffer & (1 << 3);
                break;
            case 14 :
                pin_state = port_expander_col_buffer & (1 << 4);
                break;
            default :
<<<<<<< HEAD
                pin_state = readPin(col_pins[col_index]);
=======
                pin_state = gpio_read_pin(col_pins[col_index]);
>>>>>>> upstream/master
        }

        // Populate the matrix row with the state of the col pin
        current_matrix[current_row] |=  pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        matrix_has_changed |= read_cols_on_row(current_matrix, current_row);
    }

    return matrix_has_changed;
}
