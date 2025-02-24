#include QMK_KEYBOARD_H
#include "rgblite.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKURL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    UG_HUEU,  QMKURL
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
<<<<<<< HEAD:keyboards/xiudi/xd002/keymaps/rgb_lite/keymap.c
      case RGB_HUI:
=======
      case QK_UNDERGLOW_HUE_UP:
>>>>>>> upstream/master:keyboards/xd002/keymaps/rgb_lite/keymap.c
        rgblite_increase_hue();
        break;
      case QMKURL:
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
        break;
    }
  }
  return true;
}

void keyboard_post_init_user(void) {
<<<<<<< HEAD:keyboards/xiudi/xd002/keymaps/rgb_lite/keymap.c
=======
  rgblite_init();
>>>>>>> upstream/master:keyboards/xd002/keymaps/rgb_lite/keymap.c
  rgblite_increase_hue();
}
