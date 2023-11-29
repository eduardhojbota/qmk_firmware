/* Copyright 2021 eduardh (Eduard Hojbota - eduardh.com)
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

// Define ORYX translations
#define KC_BSPACE KC_BSPC
#define KC_SCOLON KC_SCLN
#define KC_LSHIFT KC_LSFT
#define KC_LCTRL KC_LCTL
#define KC_PGDOWN KC_PGDN
#define KC_LBRACKET KC_LBRC
#define KC_RBRACKET KC_RBRC
#define KC_NONUS_BSLASH KC_BSLS
#define KC_PSCREEN KC_PSCR
#define RESET QK_BOOT

#if defined(RGB_MATRIX_ENABLE)
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {20, 21, 22, 23, 24},
        {19, 6, 7, 8, 9},
        {18, 5, 0, 1, 10},
        {17, 4, 3, 2, 11},
        {16, 15, 14, 13, 12},
    }, {
        // LED Index to Physical Position
        {  0,  0}, { 20,  0}, { 40,  0}, {61,  0}, {81,  0},
        {  0, 21}, { 20, 21}, { 40, 21}, {61, 21}, {81, 21},
        {  0, 42}, { 20, 42}, { 40, 42}, {61, 42}, {81, 42},
        {  0, 64}, { 20, 64}, { 40, 64}, {61, 64}, {81, 64},
        {  0, 81}, { 20, 81}, { 40, 81}, {61, 81}, {81, 81},
        {220, 32}, {176, 32}, {132, 32}, {88, 32}, {44, 32}, {0, 32}, {0, 2}, {0, 1}
    }, {
        // LED Index to Flag
        4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,
        2, 2, 2, 2, 2, 2, 2, 2
    }
};

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif

enum my_layers {
    _BASE,
    _L1,
    _L2,
    _L3,
    _L4,
    _RAISE,
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRAVE,  KC_1,       KC_2,    KC_3,    KC_4,
        KC_TAB,    KC_Q,       KC_W,    KC_E,    KC_R,
        KC_ESCAPE, KC_A,       KC_S,    KC_D,    KC_F,
        KC_LSHIFT, KC_Z,       KC_X,    KC_C,    KC_V,
        KC_LCTRL,  MO(_RAISE), KC_LALT, KC_LGUI, KC_SPACE
    ),
    [_L1] = LAYOUT(
        _______, _______,    _______, _______,  _______,
        _______, _______,    KC_UP,   _______,  _______,
        _______, KC_LEFT,    KC_DOWN, KC_RIGHT, _______,
        _______, _______,    _______, _______,  _______,
        _______, MO(_RAISE), _______, _______, _______
    ),
    [_L2] = LAYOUT(
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, MO(_RAISE), _______, _______, _______
    ),
    [_L3] = LAYOUT(
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, MO(_RAISE), _______, _______, _______
    ),
    [_L4] = LAYOUT(
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, _______,    _______, _______, _______,
        _______, MO(_RAISE), _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        TO(_BASE), TO(_L1), TO(_L2),               TO(_L3),             TO(_L4),
        _______,   _______, KC_AUDIO_VOL_DOWN,     KC_AUDIO_VOL_UP,     _______,
        _______,   _______, KC_MEDIA_PREV_TRACK,   KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE,
        _______,   _______, RGB_VAD,               RGB_VAI,             _______,
        _______,   _______, _______,               _______,             RESET
    ),
};

// Colors

// Purple commands: {194,255,255}
// Blue Letters: {172,255,255}
// Blue 2 Letters: {149,255,255}
// Blue 3 Letters: {129,255,255}
// Spring Green Symbols: {108,255,255}
// Pink QMK commands: {236,255,255}
// Yellow media -: {43,255,255}
// Orange media +: {22,255,255}
// Yellow Numbers: {63,255,255}
// Red: {0,255,255}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][6] = {
    [0] = {
        {63,255,255}, {63,255,255}, {63,255,255}, {63,255,255}, {63,255,255},
        {194,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255},
        {194,255,255}, {149,255,255}, {149,255,255}, {149,255,255}, {149,255,255},
        {194,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255},
        {194,255,255}, {236,255,255}, {194,255,255}, {194,255,255}, {129,255,255},
    },
    [1] = {
        {0,0,0}, {63,255,255}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {194,255,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {194,255,255},  {194,255,255}, {194,255,255}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {236,255,255},  {0,0,0}, {0,0,0}, {0,0,0},
    },
    [2] = {
        {0,0,0}, {0,0,0}, {63,255,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {236,255,255},  {0,0,0}, {0,0,0}, {0,0,0},
    },
    [3] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {63,255,255}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {236,255,255},  {0,0,0}, {0,0,0}, {0,0,0},
    },
    [4] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {63,255,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {236,255,255},  {0,0,0}, {0,0,0}, {0,0,0},
    },
    [5] = {
        {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255},
        {0, 0, 0}, {0, 0, 0}, {43,255,255}, {22,255,255}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {43,255,255}, {22,255,255}, {22,255,255},
        {0, 0, 0}, {0, 0, 0}, {43,255,255}, {22,255,255}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0,255,255}
    },
};

const uint8_t PROGMEM convertion_table[RGB_MATRIX_LED_COUNT] = {20, 21, 22, 23, 24, 19, 6, 7, 8, 9, 18, 5, 0, 1, 10, 17, 4, 3, 2, 11, 16, 15, 14, 13, 12};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        int j;
        if(i < KEY_LED_COUNT){
            j = pgm_read_byte(&convertion_table[i]);
        } else {
            j = i;
        }
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(j, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(j, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return 0;
}
