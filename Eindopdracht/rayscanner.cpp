#ifndef DEBUG
#define DEBUG false
#endif

#include "rayscanner.hpp"

#include <vector>

#include "object.hpp"
#include "screen.hpp"
RayScanner::RayScanner(VPO objs) {
    this->objects = objs;
}

// scan all the rays and display the screen afterwards
void RayScanner::scan() {
    auto screen = Screen(250, 2);
    auto centerRow = screen.numRows()/2;
    auto centerCol = screen.numCols()/2;
    float y,x = 0;

    for(int row= 0; row < screen.numRows(); row++) {
        // To keep the fov sensible we divide the x,y. These values were found by trial and error
        y = (row - centerRow) / 63.0;
        if(DEBUG) std::cout << std::endl << row << '\t' << y << '\t' << x << std::endl;
        for(int col=0; col < screen.numCols(); col++) {
            x = (col - centerCol) / 100.0;
            auto ray = Ray(x, y, objects);
            ray.scan();
            screen.updatePixelIntensity(col, row, ray.getWhite());
        }
    }

    screen.displayScreen();
}