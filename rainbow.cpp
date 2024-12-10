#include "rainbow.h"



void rainbowify(char text[], float saturation, float light) {
    saturation /= 100;
    light /= 100;

    int textLength = 0;
    int nonWhiteSpaceChars = 0;

    while (text[textLength] != '\0') {
        textLength++;
        if (text[textLength - 1] != ' ') {
            nonWhiteSpaceChars++;
        }
    }

    int whitespaceCount = 0;

    for (int i = 0; i < textLength; ++i) {
        char c = text[i];

        if (c == ' ') {
            cout << c;
            whitespaceCount++;
        } else {
            float hue = (float)(i - whitespaceCount) / nonWhiteSpaceChars;
            int red, green, blue;
            hslToRgb(hue, saturation, light, red, green, blue);

            cout << "\033[38;2;" << red << ";" << green << ";" << blue << "m" << c;
        }
    }
    cout << "\033[0m" << endl;
}

void rainbowify(string text, float saturation, float light) {
    saturation /= 100;
    light /= 100;

    int textLength = text.length();
    int nonWhiteSpaceChars = 0;

    for (char c : text) {
        if (c != ' ') {
            nonWhiteSpaceChars++;
        }
    }

    int whitespaceCount = 0;

    for (int i = 0; i < textLength; ++i) {
        char c = text[i];

        if (c == ' ') {
            cout << c;
            whitespaceCount++;
        } else {
            float hue = (float)(i - whitespaceCount) / nonWhiteSpaceChars;
            int red, green, blue;
            hslToRgb(hue, saturation, light, red, green, blue);

            cout << "\033[38;2;" << red << ";" << green << ";" << blue << "m" << c;
        }
    }
    cout << "\033[0m" << endl;
}

