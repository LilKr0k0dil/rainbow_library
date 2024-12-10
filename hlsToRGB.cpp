#include "rainbow.h"

void hslToRgb(float hue, float saturation, float light, int& red, int& green, int& blue) {
    float chroma = (1 - fabs(2 * light - 1)) * saturation;
    float intermediateValueRGB = chroma * (1 - fabs(fmod(hue * 6, 2) - 1));
    float offset = light - chroma / 2;

    float red1, green1, blue1;
    if (hue < 1.0 / 6) {
        red1 = chroma; green1 = intermediateValueRGB; blue1 = 0;
    } else if (hue < 2.0 / 6) {
        red1 = intermediateValueRGB; green1 = chroma; blue1 = 0;
    } else if (hue < 3.0 / 6) {
        red1 = 0; green1 = chroma; blue1 = intermediateValueRGB;
    } else if (hue < 4.0 / 6) {
        red1 = 0; green1 = intermediateValueRGB; blue1 = chroma;
    } else if (hue < 5.0 / 6) {
        red1 = intermediateValueRGB; green1 = 0; blue1 = chroma;
    } else {
        red1 = chroma; green1 = 0; blue1 = intermediateValueRGB;
    }

    red = (int)((red1 + offset) * 255);
    green = (int)((green1 + offset) * 255);
    blue = (int)((blue1 + offset) * 255);
}