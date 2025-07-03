// custom keyboard firmware configuration file
// it contains keymap, rgb effects, and macros for a custom keyboard firmware
// this is a fully custom settings i made for my keyboard to suit my needs
// my keyboard is akko 5075b plus blue on white (akko switch v3 cream yellow) if anyone ever wonder

#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

// hardware configuration
#define MATRIX_ROWS 6
#define MATRIX_COLS 16
#define DEBOUNCE 5

// rotary encoder (volume knob)
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
#define ENCODER_RESOLUTION 4

// USB configuration
#define VENDOR_ID 0x0483
#define PRODUCT_ID 0x5075
#define DEVICE_VER 0x0001
#define MANUFACTURER "Akko"
#define PRODUCT "5075B Plus"

// standard key definitions
#define KC_NO 0x00
#define KC_ESC 0x29
#define KC_1 0x1E
#define KC_2 0x1F
#define KC_3 0x20
#define KC_4 0x21
#define KC_5 0x22
#define KC_6 0x23
#define KC_7 0x24
#define KC_8 0x25
#define KC_9 0x26
#define KC_0 0x27
#define KC_MINS 0x2D
#define KC_EQL 0x2E
#define KC_BSPC 0x2A
#define KC_TAB 0x2B
#define KC_Q 0x14
#define KC_W 0x1A
#define KC_E 0x08
#define KC_R 0x15
#define KC_T 0x17
#define KC_Y 0x1C
#define KC_U 0x18
#define KC_I 0x0C
#define KC_O 0x12
#define KC_P 0x13
#define KC_LBRC 0x2F
#define KC_RBRC 0x30
#define KC_BSLS 0x31
#define KC_CAPS 0x39
#define KC_A 0x04
#define KC_S 0x16
#define KC_D 0x07
#define KC_F 0x09
#define KC_G 0x0A
#define KC_H 0x0B
#define KC_J 0x0D
#define KC_K 0x0E
#define KC_L 0x0F
#define KC_SCLN 0x33
#define KC_QUOT 0x34
#define KC_ENT 0x28
#define KC_LSFT 0xE1
#define KC_Z 0x1D
#define KC_X 0x1B
#define KC_C 0x06
#define KC_V 0x19
#define KC_B 0x05
#define KC_N 0x11
#define KC_M 0x10
#define KC_COMM 0x36
#define KC_DOT 0x37
#define KC_SLSH 0x38
#define KC_RSFT 0xE5
#define KC_LCTL 0xE0
#define KC_LGUI 0xE3
#define KC_LALT 0xE2
#define KC_SPC 0x2C
#define KC_RALT 0xE6
#define KC_RCTL 0xE4
#define KC_LEFT 0x50
#define KC_DOWN 0x51
#define KC_UP 0x52
#define KC_RGHT 0x4F
#define KC_F1 0x3A
#define KC_F2 0x3B
#define KC_F3 0x3C
#define KC_F4 0x3D
#define KC_F5 0x3E
#define KC_F6 0x3F
#define KC_F7 0x40
#define KC_F8 0x41
#define KC_F9 0x42
#define KC_F10 0x43
#define KC_F11 0x44
#define KC_F12 0x45
#define KC_PSCR 0x46
#define KC_DEL 0x4C
#define KC_HOME 0x4A
#define KC_END 0x4D
#define KC_PGUP 0x4B
#define KC_PGDN 0x4E

// media keys
#define KC_MUTE 0x7F
#define KC_VOLU 0x80
#define KC_VOLD 0x81
#define KC_MPLY 0x82
#define KC_MSTP 0x83
#define KC_MPRV 0x84
#define KC_MNXT 0x85

// layer keys
#define MO(layer) (0x5000 | (layer))
#define LT(layer, kc) (0x6000 | ((layer) << 8) | (kc))

// custom keycodes
enum custom_keycodes {
    MC_LEAVE = 0x7000,
    MC_INC,
    MC_PASTEEMAIL,
    MC_GAMING_MODE,
    MC_RGB_TOG,
    MC_RGB_MOD,
    MC_RGB_HUI,
    MC_RGB_HUD,
    MC_RGB_SAI,
    MC_RGB_SAD,
    MC_RGB_VAI,
    MC_RGB_VAD
};

// layer definitions
#define _BASE 0
#define _FN 1
#define _GAMING 2

// keymap for the keyboard
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* base layer (QWERTY) - from arduino
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Hom│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgU│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │Ctrl│GUI │Alt │         Space          │Alt │Fn  │ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
    [_BASE] = {
        {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  KC_NO},
        {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_NO},
        {KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,  KC_PGUP, KC_NO},
        {KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, KC_NO},
        {KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_RALT, MO(_FN), KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT},
        {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}
    },

    /* function yayer - from arduino
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │RGB│RGB│RGB│RGB│   │   │   │Inc│   │Psc│   │   │     │End│
     * │     │Tog│Mod│H+ │H- │   │   │   │   │   │   │   │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │RGB│RGB│   │   │Gam│   │   │   │Lev│   │Eml│        │   │
     * │      │S+ │S- │   │   │ing│   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │RGB│RGB│Cpy│   │   │   │Mut│V- │V+ │   │      │   │   │
     * │        │V+ │V- │Dsc│   │   │   │   │   │   │   │      │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │                        │    │    │ │   │   │   │
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
    [_FN] = {
        {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO},
        {KC_NO,   MC_RGB_TOG, MC_RGB_MOD, MC_RGB_HUI, MC_RGB_HUD, KC_NO, KC_NO, KC_NO, MC_INC, KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_END, KC_NO},
        {KC_NO,   MC_RGB_SAI, MC_RGB_SAD, KC_NO, KC_NO, MC_GAMING_MODE, KC_NO, KC_NO, KC_NO, MC_LEAVE, KC_NO, MC_PASTEEMAIL, KC_NO, KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   MC_RGB_VAI, MC_RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO},
        {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}
    },

    /* gaming layer (WASD optimized) - from arduino
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Hom│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgU│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │Alt │    │         Space          │    │Fn  │ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
    [_GAMING] = {
        {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  KC_NO},
        {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_NO},
        {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,  KC_PGUP, KC_NO},
        {KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, KC_NO},
        {KC_NO,   KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   MO(_FN), KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT},
        {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}
    }
};

// global variables
static bool gaming_mode = false;
static uint8_t current_layer = _BASE;

// rotary encoder support
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Volume knob
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

// enhanced macro processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case MC_LEAVE:
            send_string("/leave");
            tap_code(KC_ENT);
            return false;

        case MC_INC:
            send_string("inc");
            tap_code(KC_ENT);
            return false;

        case MC_PASTEEMAIL:
            send_string("vutung7709@gmail.com");
            return false;

        case MC_GAMING_MODE:
            gaming_mode = !gaming_mode;
            if (gaming_mode) {
                layer_on(_GAMING);
                rgb_matrix_set_color_all(255, 0, 0);
            } else {
                layer_off(_GAMING);
                rgb_matrix_reload_from_eeprom();
            }
            return false;

        case MC_RGB_TOG:
            rgb_matrix_toggle();
            return false;

        case MC_RGB_MOD:
            rgb_matrix_step();
            return false;

        case MC_RGB_HUI:
            rgb_matrix_increase_hue();
            return false;

        case MC_RGB_HUD:
            rgb_matrix_decrease_hue();
            return false;

        case MC_RGB_SAI:
            rgb_matrix_increase_sat();
            return false;

        case MC_RGB_SAD:
            rgb_matrix_decrease_sat();
            return false;

        case MC_RGB_VAI:
            rgb_matrix_increase_val();
            return false;

        case MC_RGB_VAD:
            rgb_matrix_decrease_val();
            return false;
    }

    return true;
}

// RGB matrix configuration - from sadekbaroudi
#define RGB_MATRIX_ENABLE
#define RGB_MATRIX_LED_COUNT 68
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_DEFAULT_BRIGHTNESS 150
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 16
#define RGB_MATRIX_VAL_STEP 16
#define RGB_MATRIX_SPD_STEP 10

// RGB matrix effects - from sadekbaroudi
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN

// reactive effects - from sadekbaroudi
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

typedef struct {
    uint8_t r, g, b;
} rgb_t;

typedef enum {
    RGB_MODE_RAINBOW_WAVE,
    RGB_MODE_BREATHING,
    RGB_MODE_REACTIVE,
    RGB_MODE_SOLID,
    RGB_MODE_TYPING_HEATMAP,
    RGB_MODE_DIGITAL_RAIN,
    RGB_MODE_GAMING
} rgb_mode_t;

typedef struct {
    rgb_mode_t mode;
    uint8_t brightness;
    uint8_t speed;
    rgb_t solid_color;
    bool reactive_enabled;
} rgb_config_t;

rgb_config_t rgb_config = {
    .mode = RGB_MODE_RAINBOW_WAVE,
    .brightness = 150,
    .speed = 3,
    .solid_color = {0, 255, 128},
    .reactive_enabled = true
};

// RGB effects - from sadekbaroudi
void set_rgb_effect(rgb_t* leds, uint8_t num_leds, uint32_t tick) {
    switch (rgb_config.mode) {
        case RGB_MODE_RAINBOW_WAVE:
            for (uint8_t i = 0; i < num_leds; i++) {
                uint8_t hue = (i * 256 / num_leds + tick * rgb_config.speed) % 256;
                leds[i] = hsv_to_rgb(hue, 255, rgb_config.brightness);
            }
            break;

        case RGB_MODE_BREATHING: {
            uint8_t breath = (sin_wave(tick * rgb_config.speed) * rgb_config.brightness) / 255;
            for (uint8_t i = 0; i < num_leds; i++) {
                leds[i].r = (rgb_config.solid_color.r * breath) / 255;
                leds[i].g = (rgb_config.solid_color.g * breath) / 255;
                leds[i].b = (rgb_config.solid_color.b * breath) / 255;
            }
            break;
        }

        case RGB_MODE_REACTIVE:
            // reactive typing effect (keys light up when pressed)
            for (uint8_t i = 0; i < num_leds; i++) {
                if (key_pressed_time[i] > 0) {
                    uint8_t fade = 255 - ((tick - key_pressed_time[i]) * 8);
                    if (fade > 0) {
                        leds[i] = hsv_to_rgb((i * 8) % 256, 255, fade);
                    } else {
                        leds[i] = (rgb_t){0, 0, 0};
                        key_pressed_time[i] = 0;
                    }
                } else {
                    leds[i] = (rgb_t){0, 0, 0};
                }
            }
            break;

        case RGB_MODE_SOLID:
            for (uint8_t i = 0; i < num_leds; i++) {
                leds[i] = rgb_config.solid_color;
            }
            break;

        case RGB_MODE_TYPING_HEATMAP:
            // heatmap based on typing frequency
            for (uint8_t i = 0; i < num_leds; i++) {
                uint8_t heat = key_heat_map[i];
                if (heat > 0) {
                    leds[i] = hsv_to_rgb(240 - (heat * 2), 255, rgb_config.brightness);
                    key_heat_map[i] = (heat > 2) ? heat - 2 : 0;
                } else {
                    leds[i] = (rgb_t){0, 0, 0};
                }
            }
            break;

        case RGB_MODE_DIGITAL_RAIN:
            // matrix-style digital rain effect
            for (uint8_t i = 0; i < num_leds; i++) {
                uint8_t col = i % 16; // Assuming 16 columns
                uint8_t rain_pos = (tick + col * 13) % (num_leds / 16 * 3);
                if (rain_pos < num_leds / 16) {
                    uint8_t brightness = 255 - (rain_pos * 40);
                    leds[i] = hsv_to_rgb(120, 255, brightness);
                } else {
                    leds[i] = (rgb_t){0, 0, 0};
                }
            }
            break;

        case RGB_MODE_GAMING:
            // gaming mode - WASD highlighted
            for (uint8_t i = 0; i < num_leds; i++) {
                leds[i] = (rgb_t){50, 0, 0}; // Dim red background
            }
            if (gaming_mode) {
                leds[17] = (rgb_t){255, 0, 0}; // W
                leds[30] = (rgb_t){255, 0, 0}; // A
                leds[31] = (rgb_t){255, 0, 0}; // S
                leds[32] = (rgb_t){255, 0, 0}; // D
            }
            break;
    }
}

// key press tracking for reactive effects
static uint32_t key_pressed_time[RGB_MATRIX_LED_COUNT] = {0};
static uint8_t key_heat_map[RGB_MATRIX_LED_COUNT] = {0};

void rgb_matrix_indicators_user(void) {
    // layer indicators
    if (layer_state_is(_FN)) {
        rgb_matrix_set_color(60, 0, 0, 255); // blue for function layer
    }
    if (gaming_mode) {
        rgb_matrix_set_color(61, 255, 0, 0); // red indicator for gaming mode
    }

    // Caps Lock indicator
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, 255, 255, 255); // white for caps lock
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // update key press times for reactive effects
    for (uint8_t i = led_min; i < led_max; i++) {
        if (rgb_config.reactive_enabled && rgb_config.mode == RGB_MODE_REACTIVE) {
            // this would be called when a key is pressed
            // implementation depends on the specific firmware
        }
    }
    return false;
}

// optimized HSV to RGB conversion - https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
rgb_t hsv_to_rgb(uint8_t h, uint8_t s, uint8_t v) {
    uint8_t region, remainder, p, q, t;
    rgb_t rgb = {0, 0, 0};

    if (s == 0) {
        rgb.r = v;
        rgb.g = v;
        rgb.b = v;
        return rgb;
    }

    region = h / 43;
    remainder = (h - (region * 43)) * 6;
    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    switch (region) {
        case 0:
            rgb.r = v; rgb.g = t; rgb.b = p; break;
        case 1:
            rgb.r = q; rgb.g = v; rgb.b = p; break;
        case 2:
            rgb.r = p; rgb.g = v; rgb.b = t; break;
        case 3:
            rgb.r = p; rgb.g = q; rgb.b = v; break;
        case 4:
            rgb.r = t; rgb.g = p; rgb.b = v; break;
        default:
            rgb.r = v; rgb.g = p; rgb.b = q; break;
    }
    return rgb;
}

// custom breathing effect
uint8_t sin_wave(uint32_t t) {
    static const uint8_t lut[256] = {
        128,131,134,137,140,143,146,149,152,155,158,162,165,168,171,174,
        177,180,183,186,189,192,195,198,201,204,207,210,213,216,219,222,
        224,227,230,233,235,238,241,243,246,248,251,253,255,258,260,262,
        264,266,268,270,272,274,276,278,279,281,283,284,286,287,289,290,
        291,293,294,295,296,297,298,299,300,301,302,302,303,304,304,305,
        305,306,306,306,307,307,307,307,307,307,307,307,307,307,306,306,
        306,305,305,304,304,303,302,302,301,300,299,298,297,296,295,294,
        293,291,290,289,287,286,284,283,281,279,278,276,274,272,270,268,
        266,264,262,260,258,255,253,251,248,246,243,241,238,235,233,230,
        227,224,222,219,216,213,210,207,204,201,198,195,192,189,186,183,
        180,177,174,171,168,165,162,158,155,152,149,146,143,140,137,134,
        131,128,124,121,118,115,112,109,106,103,100,97,93,90,87,84,81,
        78,75,72,69,66,63,60,57,54,51,48,45,42,39,36,33,31,28,25,23,
        20,18,15,13,10,8,5,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    return lut[(t >> 2) & 0xFF];
}

// random features
void keyboard_post_init_user(void) {
    // initialize RGB matrix
    rgb_matrix_enable();
    rgb_matrix_set_color_all(0, 255, 128); // initial green color

    // set default layer
    layer_on(_BASE);
}

void matrix_scan_user(void) {
    // custom matrix scan
    static uint32_t last_tick = 0;
    uint32_t current_tick = timer_read32();

    if (current_tick - last_tick > 50) { // update every 50ms
        // update RGB effects
        if (rgb_matrix_is_enabled()) {
            rgb_t leds[RGB_MATRIX_LED_COUNT];
            set_rgb_effect(leds, RGB_MATRIX_LED_COUNT, current_tick);

            // apply the effect to the matrix
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
                rgb_matrix_set_color(i, leds[i].r, leds[i].g, leds[i].b);
            }
        }
        last_tick = current_tick;
    }
}

// layer state management
layer_state_t layer_state_set_user(layer_state_t state) {
    current_layer = get_highest_layer(state);

    // update RGB based on layer
    switch (current_layer) {
        case _BASE:
            rgb_config.mode = RGB_MODE_RAINBOW_WAVE;
            break;
        case _FN:
            rgb_config.mode = RGB_MODE_BREATHING;
            rgb_config.solid_color = (rgb_t){0, 0, 255}; // blue for function layer
            break;
        case _GAMING:
            rgb_config.mode = RGB_MODE_GAMING;
            break;
    }

    return state;
}

// function declarations
void send_string(const char* str);
void tap_code(uint8_t code);
void layer_on(uint8_t layer);
void layer_off(uint8_t layer);
bool layer_state_is(uint8_t layer);
uint8_t get_highest_layer(layer_state_t state);
uint32_t timer_read32(void);
void rgb_matrix_enable(void);
void rgb_matrix_disable(void);
void rgb_matrix_toggle(void);
void rgb_matrix_step(void);
void rgb_matrix_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
void rgb_matrix_set_color_all(uint8_t r, uint8_t g, uint8_t b);
void rgb_matrix_increase_hue(void);
void rgb_matrix_decrease_hue(void);
void rgb_matrix_increase_sat(void);
void rgb_matrix_decrease_sat(void);
void rgb_matrix_increase_val(void);
void rgb_matrix_decrease_val(void);
void rgb_matrix_reload_from_eeprom(void);
bool rgb_matrix_is_enabled(void);

#endif
