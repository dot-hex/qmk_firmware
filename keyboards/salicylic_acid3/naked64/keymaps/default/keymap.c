#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FLOCK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
      KC_PGUP,  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
      KC_PGDN,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LCBR, KC_RCBR,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
<<<<<<< HEAD:keyboards/salicylic_acid3/naked64/keymaps/default/keymap.c
              KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
=======
              KC_LCTL,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
>>>>>>> upstream/master:keyboards/naked64/keymaps/default/keymap.c
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_UP, KC_RSFT,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
           MO(_ADJUST),          KC_LALT,           KC_SPC,MO(_LOWER),          MO(_RAISE),           KC_SPC, KC_LGUI, KC_LEFT, KC_DOWN,KC_RIGHT
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_FLOCK] = LAYOUT(
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
   TG(_FLOCK),  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,          _______,          _______, _______,               _______,          _______, _______, _______, _______, _______
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
      _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                KC_F12,S(KC_NUHS),S(KC_NUBS),_______,_______,KC_VOLU,_______,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,          _______,          _______, _______,               _______,          _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
      _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
      _______,  KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                KC_F12, KC_NUHS, KC_NUBS, _______, _______, _______, _______,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,          _______,          _______, _______,               _______,          _______, _______, _______, _______, _______
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
<<<<<<< HEAD:keyboards/salicylic_acid3/naked64/keymaps/default/keymap.c
   TG(_FLOCK),   RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_TOG, RGB_MOD, XXXXXXX,LCA(KC_DEL),LALT(KC_PSCR),KC_PSCR,XXXXXXX,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
=======
   TG(_FLOCK), QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               UG_TOGG, UG_NEXT, XXXXXXX,LCA(KC_DEL),LALT(KC_PSCR),KC_PSCR,XXXXXXX,
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               UG_VALD, UG_VALU, UG_HUED, UG_HUEU, UG_SATD, UG_SATU, XXXXXXX,
>>>>>>> upstream/master:keyboards/naked64/keymaps/default/keymap.c
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______,          _______,          _______, _______,               _______,          _______, _______, _______, _______, _______
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  )
};


//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _FLOCK:
      rgblight_sethsv_range(HSV_YELLOW, 0, 2);
      break;
    case _LOWER:
      rgblight_sethsv_range(HSV_BLUE, 0, 2);
      break;
    case _RAISE:
      rgblight_sethsv_range(HSV_RED, 0, 2);
      break;
    case _ADJUST:
      rgblight_sethsv_range(HSV_PURPLE, 0, 2);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_range( 0, 0, 0, 0, 2);
      break;
    }
    rgblight_set_effect_range( 2, 6);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case QK_UNDERGLOW_MODE_NEXT:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}
