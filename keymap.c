#include QMK_KEYBOARD_H


#define _AA 0
#define _BB 1
#define _CC 2
#define _DD 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    /* LAYER 0
     * ┌───────┬───────┬───────┐ // general
     * | TG(1) |   1   |  F13  |
     * ├───────┼───────┼───────┤ // purple
     * | Space | alt<  | alt>  | 
     * ├───────┼───────┼───────┤
     * |  F13  |L arrow|R arrow| 
     * └───────┴───────┴───────┘
     */
    [_AA] = LAYOUT( \
      TG(_BB),    KC_1,             KC_F13,       \
      KC_SPC,    A(S(KC_COMM)),    A(S(KC_DOT)),       \
      KC_F13,     KC_LEFT,          KC_RGHT \
    ),

    /* LAYER 1
     * ┌───────┬───────┬───────┐ // read aloud edit
     * |       |   2   |   A   |
     * ├───────┼───────┼───────┤ // blue
     * |ctr l+z|   .   | Enter |
     * ├───────┼───────┼───────┤
     * |bkSpace| Space |Delete |
     * └───────┴───────┴───────┘
     */
    [_BB] = LAYOUT( \
      TG(_CC),     KC_2,    KC_A, \
      LCTL(KC_Z),  KC_DOT,  KC_ENT, \
      KC_BSPC,     KC_SPC,  KC_DEL  \
    ),

    /* LAYER 2
     * ┌───────┬───────┬───────┐ // 
     * |       |   7   |   8   |
     * ├───────┼───────┼───────┤ // gold
     * |   4   |   5   |   6   |
     * ├───────┼───────┼───────┤
     * |   1   |   2   |   3   |
     * └───────┴───────┴───────┘
     */
    [_CC] = LAYOUT( \
      TG(_DD),  KC_7,  KC_8, \
      KC_4,     KC_5,  KC_6, \
      KC_1,     KC_2,  KC_3  \
    ),

    /* LAYER 3
     * ┌───────┬───────┬───────┐ // 
     * |       |   Z   | ONOFF |
     * ├───────┼───────┼───────┤ // 
     * |   4   |   5   |   6   |
     * ├───────┼───────┼───────┤
     * |   1   |   2   |   3   |
     * └───────┴───────┴───────┘
     */
    [_DD] = LAYOUT( \
      TO(_AA),  KC_Z,  RGB_TOG, \
      KC_4,     KC_5,  KC_6, \
      KC_1,     KC_2,  KC_3  \
    )

};/////////



void matrix_scan_user(void) {

}


void matrix_init_user(void) {
  rgblight_enable();
  rgblight_setrgb(0x00,  0x00,  0x00);
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _AA:
        rgblight_setrgb (0x7A, 0x00, 0xFF);// purple
        break;
    case _BB:
        rgblight_setrgb (0x00, 0x00, 0xFF); // blue
        break;
    case _CC:
        rgblight_setrgb (0xFF, 0xD9, 0x00); // gold
        break;
    case _DD:
        rgblight_setrgb (0, 204, 0);        // green
        break;
    }
  return state;
}



    //┌────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┐
    //│    │    │    │    │    │              │    │    │    │    │    │
    //├────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┤
    //│    │    │    │    │    │              │    │    │    │    │    │
    //├────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┤
    //│    │    │    │    │    ├────┐    ┌────┤    │    │    │    │    │
    //├────┼────┼────┼────┼────┤    │    │    ├────┼────┼────┼────┼────┤
    //│OSML│OSML│OSML│NADA│    │    │    │    │    │    │    │    │    │
    //└────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘


//#define RGB_WHITE 0xFF, 0xFF, 0xFF
//#define RGB_RED 0xFF, 0x00, 0x00
//#define RGB_CORAL 0xFF, 0x7C, 0x4D
//#define RGB_ORANGE 0xFF, 0x80, 0x00
//#define RGB_GOLDENROD 0xD9, 0xA5, 0x21
//#define RGB_GOLD 0xFF, 0xD9, 0x00
//#define RGB_YELLOW 0xFF, 0xFF, 0x00
//#define RGB_CHARTREUSE 0x80, 0xFF, 0x00
//#define RGB_GREEN 0x00, 0xFF, 0x00
//#define RGB_SPRINGGREEN 0x00, 0xFF, 0x80
//#define RGB_TURQUOISE 0x47, 0x6E, 0x6A
//#define RGB_TEAL 0x00, 0x80, 0x80
//#define RGB_CYAN 0x00, 0xFF, 0xFF
//#define RGB_AZURE 0x99, 0xf5, 0xFF
//#define RGB_BLUE 0x00, 0x00, 0xFF
//#define RGB_PURPLE 0x7A, 0x00, 0xFF
//#define RGB_MAGENTA 0xFF, 0x00, 0xFF
//#define RGB_PINK 0xFF, 0x80, 0xBF
