#pragma once

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void hslToRgb(float hue, float saturation, float light, int& red, int& green, int& blue);

void rainbowify(char text[], float saturation, float light);

void rainbowify(string text, float saturation, float light);