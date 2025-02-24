#include <stdbool.h>
#include "ps2_io.h"
#include "gpio.h"
#include "wait.h"

/* Check port settings for clock and data line */
#if !(defined(PS2_CLOCK_PIN))
#    error "PS/2 clock setting is required in config.h"
#endif

#if !(defined(PS2_DATA_PIN))
#    error "PS/2 data setting is required in config.h"
#endif

/*
 * Clock
 */
void clock_init(void) {}

void clock_lo(void) {
    // Transition from input with pull-up to output low via Hi-Z instead of output high
<<<<<<< HEAD
    writePinLow(PS2_CLOCK_PIN);
    setPinOutput(PS2_CLOCK_PIN);
}

void clock_hi(void) {
    setPinInputHigh(PS2_CLOCK_PIN);
}

bool clock_in(void) {
    setPinInputHigh(PS2_CLOCK_PIN);
    wait_us(1);
    return readPin(PS2_CLOCK_PIN);
=======
    gpio_write_pin_low(PS2_CLOCK_PIN);
    gpio_set_pin_output(PS2_CLOCK_PIN);
}

void clock_hi(void) {
    gpio_set_pin_input_high(PS2_CLOCK_PIN);
}

bool clock_in(void) {
    gpio_set_pin_input_high(PS2_CLOCK_PIN);
    wait_us(1);
    return gpio_read_pin(PS2_CLOCK_PIN);
>>>>>>> upstream/master
}

/*
 * Data
 */
void data_init(void) {}

void data_lo(void) {
    // Transition from input with pull-up to output low via Hi-Z instead of output high
<<<<<<< HEAD
    writePinLow(PS2_DATA_PIN);
    setPinOutput(PS2_DATA_PIN);
}

void data_hi(void) {
    setPinInputHigh(PS2_DATA_PIN);
}

bool data_in(void) {
    setPinInputHigh(PS2_DATA_PIN);
    wait_us(1);
    return readPin(PS2_DATA_PIN);
=======
    gpio_write_pin_low(PS2_DATA_PIN);
    gpio_set_pin_output(PS2_DATA_PIN);
}

void data_hi(void) {
    gpio_set_pin_input_high(PS2_DATA_PIN);
}

bool data_in(void) {
    gpio_set_pin_input_high(PS2_DATA_PIN);
    wait_us(1);
    return gpio_read_pin(PS2_DATA_PIN);
>>>>>>> upstream/master
}
