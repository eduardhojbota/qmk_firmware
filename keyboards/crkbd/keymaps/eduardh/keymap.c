/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define PURPLE {194,255,255}
#define BLUE_1 {172,255,255}
#define BLUE_2 {149,255,255}
#define BLUE_3 {129,255,255}
#define PINK {236,255,255}
#define CYAN {107,255,255}
#define LIME {63,255,255}
#define YELLOW {43,255,255}
#define ORANGE {22,255,255}
#define RED {0,255,255}
#define TRANSPARENT {0,0,0}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,                         XXXXXXX,    KC_4,    KC_5, KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_MEDIA_PREV_TRACK,   KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE,XXXXXXX, XXXXXXX,    KC_1,    KC_2, KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_0,   MO(3), KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRAVE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX,                      XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCRL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  )
};

const uint8_t PROGMEM ledmap[][KEY_LED_COUNT*2][3] = {
    [0] = {
        PURPLE, BLUE_1, BLUE_1, BLUE_1, BLUE_1, BLUE_1, BLUE_1, BLUE_1, BLUE_1, BLUE_1, BLUE_1, PURPLE,
        PURPLE, BLUE_2, BLUE_2, BLUE_2, BLUE_2, BLUE_2, BLUE_2, BLUE_2, BLUE_2, BLUE_2, CYAN, CYAN,
        PURPLE, BLUE_3, BLUE_3, BLUE_3, BLUE_3, BLUE_3, BLUE_3, BLUE_3, CYAN, CYAN, CYAN, PURPLE,
        PURPLE, PINK, CYAN, PURPLE, PINK, PURPLE
    },

    [1] = {
        TRANSPARENT, LIME, LIME, LIME, LIME, LIME, LIME, LIME, LIME, LIME, LIME, PURPLE,
        TRANSPARENT, PURPLE, PURPLE, PURPLE, PURPLE, TRANSPARENT, TRANSPARENT, LIME, LIME, LIME, TRANSPARENT, TRANSPARENT,
        TRANSPARENT, TRANSPARENT, YELLOW, ORANGE, ORANGE, TRANSPARENT, TRANSPARENT, LIME, LIME, LIME, TRANSPARENT, TRANSPARENT,
        TRANSPARENT, PINK, TRANSPARENT, LIME, TRANSPARENT, TRANSPARENT
    },

    [2] = {
        CYAN, CYAN, CYAN, CYAN, CYAN, CYAN, CYAN, CYAN, CYAN, CYAN, CYAN, PURPLE,
        TRANSPARENT, PURPLE, PURPLE, PURPLE, PURPLE, TRANSPARENT, TRANSPARENT, CYAN, CYAN, CYAN, CYAN, CYAN,
        TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT,
        TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, PINK, TRANSPARENT,
    },

    [3] = {
        TRANSPARENT, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,
        TRANSPARENT, PURPLE, PURPLE, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, PURPLE, TRANSPARENT,
        TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, TRANSPARENT, RED,
        TRANSPARENT, PINK, TRANSPARENT, TRANSPARENT, PINK, TRANSPARENT,
    }
};

const uint8_t PROGMEM led_convertion_table[KEY_LED_COUNT*2] = {
   24,23,18,17,10,9,36,37,44,45,50,51,
   25,22,19,16,11,8,35,38,43,46,49,52,
   26,21,20,15,12,7,34,39,42,47,48,53,
            14,13,6,33,40,41
};
const uint8_t PROGMEM underglow_convertion_table[UNDERGLOW_LED_COUNT*2] = {
   2, 1, 0, 27, 28, 29,
   3, 4, 5, 32, 31, 30
};

void set_layer_color(int layer) {
    for (int i = 0; i < KEY_LED_COUNT*2; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        int j = pgm_read_byte(&led_convertion_table[i]);
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
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE)
            rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return 0;
}
