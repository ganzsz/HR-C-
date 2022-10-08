#ifndef DEBUG
#define DEBUG false
#endif

#include "screen.hpp"

#include <vector>
#include <map>
#include <iostream>
#include <math.h>
#include <algorithm>


Screen::Screen(int width, float aspect) {
    int height = std::round((1.0/aspect) * width);
    screen = std::vector<std::vector<float>>(height);
    for (auto &row:screen) {
        row = std::vector<float>(width, 1.0);
    }
}

void Screen::updatePixelIntensity(int x, int y, float fraction) {
    if (y >= screen.size()) throw std::invalid_argument("x is too high in Screen::updatePixelIntensity value:"+x);
    if (x >= screen[0].size()) throw std::invalid_argument("y is too high in Screen::updatePixelIntensity value:"+y);

    screen[y][x] /= fraction;
}

const auto CHARACTERS = std::vector<char> {'M', 'N', 'O', 'L', 'I', '\\', ':', ' '};
char getCharFromDepth(float f) {
    if (f == 1) return CHARACTERS.back();

    return CHARACTERS[std::floor((CHARACTERS.size() - 1) * (f))];

};

void Screen::displayScreen() {
    char pixelChar = 0;
    auto row = std::vector<float>(screen[0].size());
    for (int y = screen.size() -1; y >= 0; y --) {
    if(DEBUG) std::cout << (y<10 ? "00" : "0") << y;
        row = screen [y];
        for (auto pixel:row) {
            pixelChar = getCharFromDepth(pixel);
            std::cout << pixelChar << pixelChar;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

int Screen::numRows() {
    return screen.size();
}

int Screen::numCols() {
    return screen[0].size();
}