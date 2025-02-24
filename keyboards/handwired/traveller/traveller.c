<<<<<<< HEAD
#include "traveller.h"
=======
#include "quantum.h"
>>>>>>> upstream/master

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

#ifdef RGBLIGHT_ENABLE
    rgblight_init();
    rgblight_mode(1); // solid, no timer
    rgblight_setrgb(0,20,0);// dim green, happens to be same as _QW
#endif

    // Turn status LED on
<<<<<<< HEAD
    setPinOutput(C7);
    writePinHigh(C7);
=======
    gpio_set_pin_output(C7);
    gpio_write_pin_high(C7);
>>>>>>> upstream/master

    matrix_init_user();
}
