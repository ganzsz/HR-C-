#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <math.h>
#include <algorithm>

typedef std::vector<float> Row;
typedef std::vector<Row> Screen;

Screen initScreen(int width, float aspect) {
    auto height = std::round((1.0/aspect) * width);
    auto screen = Screen(height);
    for (auto &row:screen) {
        row = Row(width, 1.0);
    }
    return screen;
}

void overlayCheckerOnScreen(Screen &screen) {
    auto width = screen.size();
    auto height = screen[0].size();

    auto squareSize = height < width ? height/10 : width/10;

    auto horCenter = width / 2;
    auto verCenter = height / 2;

    auto horOffset = horCenter % squareSize + 2;
    auto verOffset = verCenter % squareSize + 2;

    for (auto vPos = 0; vPos < width; vPos++) {
        for (auto hPos = 0; hPos < height; hPos++) {
            if( ((vPos + verOffset)/squareSize) % 2  == ((hPos + horOffset)/squareSize) % 2 ) {
                screen[vPos][hPos]/=2.0; // anything above 0.333 does the trick as we have a depth of 3
            }
        }
    }
}

void overlayCircleOnScreen(Screen &screen) {
    auto width = screen[0].size();
    auto height = screen.size();

    int innerDiameter = height < width ? height/5 : width/5;
    int outerDiameter = innerDiameter + innerDiameter;

    int horCenter = width / 2;
    int verCenter = height / 2;

    for (auto vPos = 0; vPos < screen.size(); vPos++) {
        for (auto hPos = 0; hPos < screen[vPos].size(); hPos++) {
            int horDist = std::abs(horCenter - hPos);
            int verDist = std::abs(verCenter - vPos);
            int absDist = std::sqrt(horDist * horDist + verDist * verDist);
            if( innerDiameter < absDist
            && absDist < outerDiameter) {
               screen[vPos][hPos]/=2;
            }
        }
    }
};


const auto CHARACTERS = std::vector<char> {'M', 'N', 'O', 'L', 'I', '\\', ':', ' '};
char getCharFromDepth(float f) {
    if (f == 1) return CHARACTERS.back();

    return CHARACTERS[std::floor((CHARACTERS.size() - 1) * (f))];

};

void displayScreen(Screen screen) {
    char pixelChar = 0;
    for (auto row:screen) {
        for (auto pixel:row) {
            pixelChar = getCharFromDepth(pixel);
            std::cout << pixelChar << pixelChar;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};
