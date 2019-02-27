#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1
#define _SF 2

#define S_INSRT S(KC_INSERT)

#define S_ESC LT(1, KC_ESC)

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 0: qwerty */
  [_BL] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,
    KC_LSFT, TG(2),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(1),   KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_BSLS, KC_RGUI, KC_RALT, KC_APP,  KC_RCTL
  ),
  /* 1: fn */
  [_FL] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    S_INSRT, _______, KC_MS_U, _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______, _______, _______,
    MO(_SF), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_SF),
    _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______
  ),

    /* 2: arrows */
  [_SF] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______
  ),

};

enum function_id {
        SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
      [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    static uint8_t shift_esc_shift_mask;
    switch (id) {
        case SHIFT_ESC:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                    add_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    add_key(KC_ESC);
                    send_keyboard_report();
                }
            } else {
            if (shift_esc_shift_mask) {
                del_key(KC_GRV);
                send_keyboard_report();
            } else {
                del_key(KC_ESC);
                send_keyboard_report();
            }
        }
    break;
    }
}

void matrix_scan_user(void) {

//Layer LED indicators
    uint32_t layer = layer_state;

    if (layer & (1<<1)) {
        gh60_wasd_leds_on();
        gh60_fn_led_on();
    } else {
        gh60_wasd_leds_off();
        gh60_fn_led_off();
    }

    if (layer & (1<<2)) {
        gh60_poker_leds_on();
        gh60_esc_led_on();
    } else {
        gh60_poker_leds_off();
        gh60_esc_led_off();
    }

};
