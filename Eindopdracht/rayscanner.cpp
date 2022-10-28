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
    float y,x = 0;

    for(int row= 0; row < screen.numRows(); row++) {
        y = (row - centerRow) / 40.0;
        if(DEBUG) std::cout << std::endl << row << '\t' << y << '\t' << x << std::endl;
        std::cout << row << ' ';
        for(int col=0; col < screen.numCols(); col++) {
            x = (col - centerCol) / 50.0;
            auto ray = Ray(x, y, objects);
            ray.scan();
            std::cout<<ray.bounces<<std::flush;
            screen.updatePixelIntensity(col, row, ray.getWhite());
        }
        std::cout<<std::endl;
    }

    screen.displayScreen();
}