
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ,---------------------------------------------------------------.
     * |Esc|▓▓▓|F1 |F2 |F3 |F4 |▓|F5 |F6 |F7 |F8 |▓|F9 |F10|F11|F12|▓▓▓|
     * |---------------------------------------------------------------|
     * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Del|Bsp|Hm |
     * |---------------------------------------------------------------|
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\    |End|
     * |---------------------------------------------------------------|
     * |Caps  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Enter   |PgU|
     * |---------------------------------------------------------------|
     * |Shft|\  |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|GUI |Alt |Space                   |Alt |Fn  |▓|Lt |Dn |Rt |
     * `---------------------------------------------------------------'
    */
    LAYOUT(
        KC_ESC,                KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,  KC_F12,
        KC_GRV,  KC_1,         KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,      KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,      KC_RBRC,          KC_BSLS, KC_END,
        KC_CAPS, KC_A,         KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                        KC_ENT,  KC_PGUP,
        KC_LSFT, LT(1, KC_NO), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      KC_LSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI,      KC_LALT,                            KC_SPC,                             KC_LALT, LT(1, KC_NO),          KC_LEFT, KC_DOWN, KC_RGHT
        ),

    /*
     * ,---------------------------------------------------------------.
     * |RST|▓▓▓|   |   |   |   |▓|   |   |   |   |▓|   |   |   |   |▓▓▓|
     * |---------------------------------------------------------------|
     * |`  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |Tog|
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |Stp|
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |BL+|
     * |---------------------------------------------------------------|
     * |    |   |   |   |   |   |   |   |   |   |   |   |      |   |BL-|
     * |---------------------------------------------------------------|
     * |    |    |    |                        |    |    |▓|   |   |   |
     * `---------------------------------------------------------------'
    */
    LAYOUT(
        QK_BOOT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_TOGG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, BL_STEP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, BL_UP, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, BL_DOWN,
        _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______
        )
};

<<<<<<< HEAD
void led_set_user(uint8_t usb_led) {

    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        setPinOutput(B0);
        writePinLow(B0);
    } else {
        setPinInput(B0);
        writePinLow(B0);
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        setPinOutput(B1);
        writePinLow(B1);
    } else {
        setPinInput(B1);
        writePinLow(B1);
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        setPinOutput(B2);
        writePinLow(B2);
    } else {
        setPinInput(B2);
        writePinLow(B2);
    }
=======
bool led_update_user(led_t led_state) {

    if (led_state.num_lock) {
        gpio_set_pin_output(B0);
        gpio_write_pin_low(B0);
    } else {
        gpio_set_pin_input(B0);
        gpio_write_pin_low(B0);
    }

    if (led_state.caps_lock) {
        gpio_set_pin_output(B1);
        gpio_write_pin_low(B1);
    } else {
        gpio_set_pin_input(B1);
        gpio_write_pin_low(B1);
    }

    if (led_state.scroll_lock) {
        gpio_set_pin_output(B2);
        gpio_write_pin_low(B2);
    } else {
        gpio_set_pin_input(B2);
        gpio_write_pin_low(B2);
    }
    return false;
>>>>>>> upstream/master
}
