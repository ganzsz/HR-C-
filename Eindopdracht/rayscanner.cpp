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

void RayScanner::AddFloor(Floor object) {
    objects.push_back(&object);
}

void RayScanner::AddSphere(Sphere sphere) {
    objects.push_back(&sphere);
}

void RayScanner::scan() {
    auto screen = Screen(160, 2);
    auto centerRow = screen.numRows()/2;
    auto centerCol = screen.numCols()/2;
    float y,x,intensity = 0;

    for(int row= 0; row < screen.numRows(); row++) {
        y = (row - centerRow) / 40.0;
        if(DEBUG) std::cout << std::endl << row << '\t' << y << '\t' << x << std::endl;
        for(int col=0; col < screen.numCols(); col++) {
            x = (col - centerCol) / 50.0;
            intensity = 1.0;
            auto ray = Ray(x, y, objects);
            if(ray.scan()) intensity++;
            screen.updatePixelIntensity(col, row, intensity);
        }
    }

    screen.displayScreen();
}