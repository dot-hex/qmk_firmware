#include "quantum.h"

<<<<<<< HEAD
void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
	DDRB |= (1<<6);
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
			// output low
			DDRB |= (1<<2);
			PORTB &= ~(1<<2);
		} else {
			// Hi-Z
			DDRB &= ~(1<<2);
			PORTB &= ~(1<<2);
		}
	// DDRB |= (1<<7);
	// DDRB |= (1<<1);
	// DDRB |= (1<<3);
	// DDRE |= (1<<6);
	if (usb_led == 0){
		PORTB |= (1<<6);
		// PORTB |= (1<<7);
		// PORTB |= (1<<1);
		// PORTB |= (1<<3);
		// PORTE |= (1<<6);
	}
	else{
		PORTB &= ~(1<<6);
		// PORTB &= ~(1<<7);
	}
    
	led_set_user(usb_led);
=======
void led_init_ports(void) {
    gpio_set_pin_output(B2);
    gpio_set_pin_output(B6);
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        gpio_write_pin(B2, !led_state.caps_lock);
        gpio_write_pin(B6, led_state.raw == 0);
    }
    return res;
>>>>>>> upstream/master
}
