#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x4(KC_P7, KC_P8, KC_P9, MO(1), KC_P4, KC_P5, KC_P6, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_P0, KC_PDOT, KC_PCMM, KC_PENT),
	[1] = LAYOUT_ortho_4x4(QK_BOOT, BL_STEP, KC_TRNS, KC_VOLU, BL_TOGG, BL_DOWN, BL_UP, KC_VOLD, RGB_TOG, RGB_MOD, RGB_HUI, KC_MUTE, RGB_SAI, RGB_SAD, RGB_HUD, KC_TRNS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



