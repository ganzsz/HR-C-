/**
 * Eisen:
 * - Screen with vector<vector<float>>
 * - Aspect ratio as const
 * - Width as const
 * 
 * TestSpec:
 * - Height approx Width + Aspect
 * - output matches 3 different intensities using ' ', 'L', 'N'
 * 
 * Design:
 * I have a screen that consists of std::vector<std::vector<float>>
 * the float tells the brightness. 0 is black, and 1 is white.
 * 
 * The program uses a nested for loop to overlay a checker pattern on the sceen.
 * For this it finds the center and the offset that is needed to get a nice 
 * checkerboard centered on the screen. Then it adds this offset to the position
 * in the loop. to up the brightness it is simply increased by one
 */
#include <iostream>
#include "screen.cpp"

const auto WIDTH = 160;
const auto ASPECT = 16.0/9.0;

int main() {
    Screen s = initScreen(WIDTH, ASPECT);

    overlayCheckerOnScreen(s);
    overlayCircleOnScreen(s);

    displayScreen(s);
}