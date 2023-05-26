#include "blackpill_mini.h"

extern keymap_config_t keymap_config;

// tap dance layers
enum {
 TD_CLN = 0, // ; or : or tap/dbl
 TD_CP = 3, // copy/paste/get last clipboard item/clipboard manager for tap/dbl/trpl/hold
 TD_DASH = 4, // - or _ for tap/dbl
 TD_QUOTE = 5, // ' or '' for tap/dbl
 TD_NUMTERM = 6, // hold for num layer, dbl tap toggle num layer, or tap for term
};

#define _QWERTY 0
#define _COLEMAK 1
#define _NAV 2
#define _SYMBOLS 3
#define _COMMAND 4
#define _NUMBERS 5

#define _CODE MO(_COMMAND)
#define _FSYM LT(_SYMBOLS,KC_F)
#define _ZCTL LCTL_T(KC_Z)
#define _XALT LALT_T(KC_X)
#define _CGUI LGUI_T(KC_C)
#define _TERM LGUI(KC_GRAVE)
#define _COMGUI RGUI_T(KC_COMM)
#define _DOTALT LALT_T(KC_DOT)
#define _SLSHCTL RCTL_T(KC_SLSH)
#define _ENTGUI LGUI_T(KC_ENT)
#define _SPCNAV LT(_NAV,KC_SPC)
#define _LINE_DOWN LALT(LSFT(KC_DOWN))
#define _LINE_UP LALT(LSFT(KC_UP))
#define _PREV_TAB LGUI(LSFT(KC_LBRC))
#define _NEXT_TAB LGUI(LSFT(KC_RBRC))
#define _TD_CLN TD(TD_CLN)
#define _TD_CP TD(TD_CP)
#define _TD_DASH TD(TD_DASH)
#define _TD_QUOTE TD(TD_QUOTE)
#define _TD_NUMTERM TD(TD_NUMTERM)
#define _WINMODE MAGIC_TOGGLE_CTL_GUI
#define ____ KC_NO
#define _QWERTY 0


// Combos
enum combos {
	WE,WF
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	// Horizontal Chords
  [WE] = COMBO(we_combo, KC_ESC),
  [WF] = COMBO(wf_combo, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        _CODE,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,   _TD_CLN, _TD_QUOTE,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,  _ZCTL,   _XALT,   _CGUI,   KC_V,    KC_B,                KC_N,    KC_M,   _COMGUI, _DOTALT, _SLSHCTL, KC_RSFT,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                           MO(_NUMBERS),  _TD_CP, KC_DEL,  _ENTGUI,            _SPCNAV, KC_BSPC,MO(_SYMBOLS),MO(_NUMBERS),
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                    _TD_NUMTERM,        MO(_SYMBOLS)
    //                                             └────────┘           └────────┘
    ),

    [_COLEMAK] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                KC_J,    KC_L,    KC_U,    KC_Y,    _TD_CLN, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        _CODE,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   _TD_QUOTE,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,  _ZCTL,   _XALT,   _CGUI,   KC_V,    KC_B,                KC_K,    KC_M,   _COMGUI, _DOTALT, _SLSHCTL, KC_RSFT,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                           MO(_NUMBERS),  _TD_CP, KC_DEL,  _ENTGUI,            _SPCNAV, KC_BSPC,MO(_SYMBOLS), MO(_NUMBERS),
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                    _TD_NUMTERM,        MO(_SYMBOLS)
    //                                             └────────┘           └────────┘
    ),


    [_NAV] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        ____, TO(_QWERTY),_WINMODE, ____,   RESET,    ____,               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  ____,   ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,     ____,    ____,   KC_MUTE, KC_VOLU,KC_BTN1,             KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,   ____,   ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_LALT,   ____, TO(_COLEMAK),KC_VOLD,KC_BTN2,         _PREV_TAB,_LINE_DOWN,_LINE_UP,_NEXT_TAB, ____,   ____,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                         _______, _______, _______, _______,             _______, _______, _______,  _______,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                     _______,            _______
    //                                             └────────┘           └────────┘
    ),
	[_SYMBOLS] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        ____,    ____,    ____,    ____,    ____,    ____,               KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, LSFT(KC_MINUS), ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    ____,    ____,    ____,    ____,    ____,               KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN,  KC_MINUS, ____,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    ____,    ____,    ____,    ____,    ____,               KC_TILDE, KC_GRV,   KC_LT,   KC_GT,    ____,    ____,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                         _______, _______, _______, _______,             _______, _______, _______,  _______,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                     _______,            _______
    //                                             └────────┘           └────────┘
    ),
   	[_NUMBERS] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        ____,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),   LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),LSFT(KC_MINUS),
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINUS,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ┌────────┼────────┼────────┼────────┼────────┼────────┤
        ____,    ____,    ____,    ____,    ____,    ____,                 ____,    ____,    ____,    ____,    ____,    ____,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                         _______, _______, _______, _______,             _______, _______, _______,  _______,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                     _______,            _______
    //                                             └────────┘           └────────┘
    )

};

