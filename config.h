// custom keyboard firmware configuration file
// it contains keymap, rgb effects, and macros for a custom keyboard firmware
// this is a fully custom settings i made for my keyboard to suit my needs
// my keyboard is akko 5075b plus blue on white (akko switch v3 cream yellow) if anyone ever wonder

#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 15

enum custom_keycodes {
    MC_LEAVE = 0xF0,
    MC_INC,
    MC_VOLUP,
    MC_VOLDOWN,
    MC_MUTE,
    MC_COPYDISCORD,
    MC_PASTEEMAIL
};

const uint16_t keymap[MATRIX_ROWS][MATRIX_COLS] = {
    { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', ';', '[', ']', '\\', MC_VOLUP },
    { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', '\'', MC_VOLDOWN, MC_MUTE, MC_COPYDISCORD, MC_PASTEEMAIL, 0 },
    { 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', MC_LEAVE, MC_INC, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// macro
bool process_record_user(uint16_t keycode, bool pressed, bool shift_held, bool ctrl_held) {
    if (!pressed) return true;

    if (shift_held && keycode == ';') {
        send_string("/leave\n");
        return false;
    }
    if (shift_held && keycode == 'I') {
        send_string("inc\n");
        return false;
    }
    if (keycode == MC_VOLUP) {
        media_key_press(VOLUME_UP);
        return false;
    }
    if (keycode == MC_VOLDOWN) {
        media_key_press(VOLUME_DOWN);
        return false;
    }
    if (keycode == MC_MUTE) {
        media_key_press(MUTE);
        return false;
    }
    if (keycode == MC_PASTEEMAIL) {
        send_string("whatdoyouexpect@gmail.com");
        return false;
    }
    return true;
}

// rgb
#define RGB_ENABLE true
#define RGB_NUM_LEDS 68
#define RGB_BRIGHTNESS_MAX 255
#define RGB_BREATH_SPEED 4

typedef struct {
    uint8_t r, g, b;
} rgb_t;

typedef enum {
    RGB_MODE_RAINBOW_WAVE,
    RGB_MODE_BREATHING,
    RGB_MODE_REACTIVE,
    RGB_MODE_SOLID
} rgb_mode_t;

typedef struct {
    rgb_mode_t mode;
    uint8_t brightness;
    uint8_t speed;
    rgb_t solid_color;
} rgb_config_t;

rgb_config_t rgb_config = {
    .mode = RGB_MODE_RAINBOW_WAVE,
    .brightness = 200,
    .speed = 3,
    .solid_color = {0, 255, 128}
};

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
            break;
        case RGB_MODE_SOLID:
            for (uint8_t i = 0; i < num_leds; i++) {
                leds[i] = rgb_config.solid_color;
            }
            break;
    }
}

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

// breathing effect (just some rgb effects on keyboard iykyk)
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

void send_string(const char* str);
void media_key_press(uint8_t media_key);

#endif