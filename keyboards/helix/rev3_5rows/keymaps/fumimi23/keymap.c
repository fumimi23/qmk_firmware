/* Copyright 2020 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _MAC = 0,
    _WIN,
    _FUNC,
    _RGB
};

enum custom_keycodes {
    IME_SW_WIN = SAFE_RANGE
};

#define WIN TO(_WIN)
#define MAC TO(_MAC)
#define FUNC TO(_FUNC)
#define RGB TO(_RGB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Macintosh
    * ,-----------------------------------------.             ,-----------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   \  |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * | IME  |   ,  |   .  |   ;  |   =  |   '  |             |   L  |   R  |   D  |   Y  |   P  |   /  |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * | Shift|   A  |   O  |   E  |   I  |   U  |             |   G  |   N  |   T  |   S  |   K  |   F  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   V  |   X  |   C  |   W  |   Q  |   [  |   ]  |   J  |   H  |   M  |   B  |   Z  |   -  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | func | Ctrl | Opt  | Cmd  |  BS  |Space |Space | Esc  |Space |Enter | Left | Down |  Up  |Right |
    * `-------------------------------------------------------------------------------------------------'
    */
    [_MAC] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSLS,
        KC_CAPS, KC_COMM, KC_DOT,  KC_SCLN, KC_EQL,  KC_QUOTE,                  KC_L,    KC_R,    KC_D,    KC_Y,    KC_P,  KC_SLSH,
        KC_LSFT, KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                      KC_G,    KC_N,    KC_T,    KC_S,    KC_K,  KC_F,
        KC_TAB,  KC_V,    KC_X,    KC_C,    KC_W,    KC_Q,    KC_LBRC, KC_RBRC, KC_J,    KC_H,    KC_M,    KC_B,    KC_Z,  KC_MINS,
        FUNC,    KC_LCTL, KC_LOPT, KC_LCMD, KC_BSPC, KC_SPC,  KC_SPC,  KC_ESC,  KC_SPC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    /* Windows
    * ,-----------------------------------------.             ,-----------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   \  |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * | IME  |   ,  |   .  |   ;  |   =  |   '  |             |   L  |   R  |   D  |   Y  |   P  |   /  |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * | Shift|   A  |   O  |   E  |   I  |   U  |             |   G  |   N  |   T  |   S  |   K  |   F  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   V  |   X  |   C  |   W  |   Q  |   [  |   ]  |   J  |   H  |   M  |   B  |   Z  |   -  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | func | Alt  | Win  | Ctrl |  BS  |Space |Space | Esc  |Space |Enter | Left | Down |  Up  |Right |
    * `-------------------------------------------------------------------------------------------------'
    */
    [_WIN] = LAYOUT(
        _______,    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        IME_SW_WIN, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______,    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,    KC_LALT, KC_LWIN, KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Function
    * ,-----------------------------------------.             ,-----------------------------------------.
    * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * |      |      |      |      |      |      |             |      |      |  Up  |      |      |      |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |             |      | Left | Down |Right |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Ctrl | Opt  | Cmd  |  BS  |Space | mac  | win  |Space |Enter |      |      |      | rgb  |
    * `-------------------------------------------------------------------------------------------------'
    */
    [_FUNC] = LAYOUT(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, _______, _______, MAC,     WIN,     _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, RGB
    ),

    /* RGB Setting
    * ,-----------------------------------------.             ,-----------------------------------------.
    * |      |      |      |      |      |      |             |      |      |      |      |      |      |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * |      |      |      |      |      |      |             |      |      |      |      |      |      |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * |      |      |      |      |      |      |             |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ | EFF+ |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | func |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- | EFF- |      |
    * `-------------------------------------------------------------------------------------------------'
    */
    [_RGB] =  LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,
        FUNC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case IME_SW_WIN:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_CAPS);
            } else {
                unregister_code(KC_CAPS);
                unregister_code(KC_LSFT);
            }
            break;
    }
    return true;
}
