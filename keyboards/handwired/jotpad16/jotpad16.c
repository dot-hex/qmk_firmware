#include "quantum.h"

<<<<<<< HEAD
void keyboard_pre_init_kb() {
    setPinOutput(JOTPAD16_LED1);
    setPinOutput(JOTPAD16_LED2);
=======
void keyboard_pre_init_kb(void) {
    gpio_set_pin_output(JOTPAD16_LED1);
    gpio_set_pin_output(JOTPAD16_LED2);
>>>>>>> upstream/master
    
    keyboard_pre_init_user();
}
