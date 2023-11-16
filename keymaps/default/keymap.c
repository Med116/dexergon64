// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define HSV_VAL 145
#define HSV_NORTHERN_LIGHTS_PURPLE 189,56,145
#define HSV_NORTHERN_LIGHTS_GREEN 70,40,145
#define HSV_NORTHERN_LIGHTS_BLUE 189,56,145
#define HSV_NORTHERN_LIGHTS_YELLOW 123,67,145
#define HSV_DNKN_ORANGE 22,249,155
#define HSV_DNKN_MAJENTA 234,193,155


enum layer_names {
    _BASE,
    _FN_KEY,
	_FN_NUMS
};

//default light layer
const rgblight_segment_t PROGMEM base_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    
	{0,1, HSV_MAGENTA },
	{16,1, HSV_MAGENTA },
	{32,1, HSV_MAGENTA },
	{48,8, HSV_MAGENTA },
	{13,1, HSV_MAGENTA },
	{28,1, HSV_MAGENTA },
	{43,1, HSV_MAGENTA },
	{1,12, 54, 255,145 },
	{17,11, 87, 255,145 },
	{33,10, 174, 255,145 },
	{56, 3, HSV_RED},
	{44, 1, HSV_RED},
    {14,2, HSV_GREEN},
	{45,3, HSV_GREEN},
	{29,3, HSV_GREEN},
	{59,5, HSV_GREEN}
);

//caps lock layer
const rgblight_segment_t PROGMEM caps_lock_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{16,2, HSV_MAGENTA },
	{1,10, HSV_RED },
	{23,9, HSV_RED},
	{34,7, HSV_RED},
	{48,2, HSV_MAGENTA} 
	
);

//FN keys layer
const rgblight_segment_t PROGMEM fn_keys_light_layer[] = RGBLIGHT_LAYER_SEGMENTS( 
    {14,6, HSV_RED},
	{46,5, HSV_RED}
	
);

//      LEFT TO RIGHT LIGHT LAYER COLOR CHANGE keys layer
const rgblight_segment_t PROGMEM dnkn_segment_colors_light_layer[] = RGBLIGHT_LAYER_SEGMENTS( 
  {0,6, HSV_DNKN_MAJENTA},
	{6,5, HSV_DNKN_ORANGE},
	{11,3, HSV_GREEN},
	{14,6, HSV_DNKN_MAJENTA},
	{20,2, HSV_GREEN},
	{22,5, HSV_DNKN_ORANGE},
	{27,13, HSV_DNKN_MAJENTA},
	{39,5, HSV_DNKN_ORANGE},
	{44,1, HSV_GREEN},
	{45,9, HSV_DNKN_MAJENTA},
	{54,1, HSV_GREEN},
	{55,3, HSV_DNKN_ORANGE},
	{58,6, HSV_DNKN_MAJENTA}
	
	
	
);

const rgblight_segment_t PROGMEM dnkn_colors_layer_keys_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0,16, HSV_DNKN_ORANGE },
	{20,13, HSV_DNKN_ORANGE },
	{33,12, HSV_DNKN_MAJENTA },
	{54,10, HSV_DNKN_MAJENTA },
	// ARROWS
  {51, 3, HSV_CYAN},
	{45, 1, HSV_CYAN},
	// ALL RIGHT SIDE NUM PAD PLUS MINUS PLUS DEL
	{14,3, HSV_GREEN},
	{17,3, HSV_GREEN},
	{46,5, HSV_GREEN},
	{49,2, HSV_GREEN}
	
	
);

const rgblight_segment_t PROGMEM dnkn_magenta_all[] = RGBLIGHT_LAYER_SEGMENTS(
	{0,63, HSV_DNKN_MAJENTA} // All majenta, remove if want dunkin
	
	
);

// // Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM user_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	dnkn_segment_colors_light_layer,
	fn_keys_light_layer,
	caps_lock_light_layer
	);
	


void keyboard_post_init_user(void) {
    rgblight_layers = user_rgb_layers;
    rgblight_set_layer_state(0, true);

}

enum custom_keycodes {
  SEMI_COLON_RETURN,
  LBRACK,
  RBRACK,
  LPAR,
  RPAR,
  CAPS_TAB,
  ACTIVATE_DNKN_COLOR_LAYER,
  RGB_DNKN_COLORS,
  UP_SAT,
  DOWN_SAT,
  UP_HUE,
  DOWN_HUE,
  RGB_SET_ALL,
  RGB_PURPLE_ALL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LPAR, RPAR, KC_BSPC, KC_7, KC_8, KC_9, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_4, KC_5, KC_6,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,KC_RSFT,   KC_UP,        KC_1, KC_2, KC_3, 
		KC_LCTL,KC_LALT, KC_LCMD,KC_HOME,KC_END, MO(_FN_KEY), KC_SPC, KC_MINS, KC_EQL, KC_BSLS,KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, KC_0
    ),
    [_FN_KEY] = LAYOUT(
        KC_GRAVE, KC_Q, KC_W, KC_E, RGB_MODE_RAINBOW, RGB_MODE_TWINKLE, KC_Y, KC_U,  KC_I, KC_O, KC_P,KC_LBRC, KC_RBRC, KC_BSPC, KC_F7, KC_F8, KC_F9, 
		KC_CAPS, KC_A, RGB_MODE_SNAKE, RGB_TOG, KC_F, KC_G, KC_H, KC_J, RGB_MODE_KNIGHT, KC_L, KC_SCLN, KC_QUOT,  TG(_FN_NUMS), KC_F4, KC_F5, KC_F6,
		KC_LSFT, KC_Z, RGB_MODE_XMAS, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,KC_RSFT,   RGB_SAI,        KC_F1, KC_F2, KC_F3, 
		KC_LCTL,KC_LALT, KC_LCMD,KC_HOME,KC_END, KC_END, RGB_DNKN_COLORS, RGB_SET_ALL, RGB_PURPLE_ALL, RGB_MODE_PLAIN,RGB_HUI, RGB_SAD, RGB_HUD, KC_DEL, KC_0
    ),
    [_FN_NUMS] = LAYOUT(
        QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LPAR, RPAR, KC_BSPC, KC_F7, KC_F8, KC_F9, 
		KC_TAB, KC_A, KC_S, RGB_TOG, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, TG(_FN_NUMS), KC_F4, KC_F5, KC_F6,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,KC_RSFT,   RGB_SAI,        KC_F1, KC_F2, KC_F3, 
		KC_LCTL,KC_LALT, KC_LCMD,KC_HOME,KC_END, KC_END, RGB_DNKN_COLORS, RGB_SET_ALL, RGB_PURPLE_ALL, KC_BSLS,RGB_HUI, RGB_SAD, KC_F12, KC_F11, KC_F10
    ),

};

bool led_update_user(led_t led_state) {
    
	rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}



layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN_NUMS));
    
	
	
	return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
  
   	case LPAR: 
	if (record->event.pressed) {
		 if (get_mods() & MOD_MASK_SHIFT) {
		  SEND_STRING("{");
		  return false;
        } else {
		  SEND_STRING("(");
		  return false;
        }
	}
	break;
	case RPAR: 
	if (record->event.pressed) {
		 if (get_mods() & MOD_MASK_SHIFT) {
		 SEND_STRING("}");
		 return false;              
        } else {
		  SEND_STRING(")");
		  return false;
        }
	}
	break;
    case RGB_DNKN_COLORS: 
	if (record->event.pressed) {
		rgblight_set_layer_state(0, false);
        rgblight_set_layer_state(1, false);
        rgblight_set_layer_state(2, false);
        return false;

	}
	break;
    case RGB_SET_ALL: 
	if (record->event.pressed) {
        rgblight_set_layer_state(0, true);
        rgblight_set_layer_state(1, false);
	    rgblight_set_layer_state(2, false);
        return false;

	}
	break;
    case RGB_PURPLE_ALL: 
		
        rgblight_sethsv_range(HSV_DNKN_MAJENTA,0,63);
        return false;
	
	break;
  return true;

}
return true;
}
