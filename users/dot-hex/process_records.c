enum custom_keycodes {
    SSMac,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SSMac:
        if (record->event.pressed) {
            // when keycode SSMac is pressed
            SEND_STRING(SS_RGUI(SS_LSFT(KC_S)));
        } else {
            // when keycode SSMac is released
        }
        break;
    }
    return true;
};
