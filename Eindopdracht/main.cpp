/**
 * Requirements:
 *  Display a pleasing scene with three spheres and a checkerd floor.
 *  The screen is placed 3m from the observer.
 * 
 * The screen is placed on the x, y plane with z=0. The 'eye' is placed at z-3
 *  (this is mostly bc it confirms with the MineCraft playing field and anything
 *   else kept messing with my brain)
 * 
 * Testign: 
 *  We add a few spheres at different positions. The goal is to have at least one
 *  sphere reflected in another one.
 */

#include "rayscanner.hpp"
#include "floor.hpp"
#include "sphere.hpp"

const float far = 0.8;

int main() {
    auto objects = VPO();
    auto floor = Floor(-1.0, 0.75);
    objects.push_back(&floor);
    auto sphere2 = Sphere(-0.75, 0.5, 0.5, 0.4);
    objects.push_back(&sphere2);
    auto sphere1 = Sphere(-0.25, 0.1, 1.25, 0.5);
    objects.push_back(&sphere1);
    auto sphere3 = Sphere(1, 1.25, 5, 1);
    objects.push_back(&sphere3);
    auto scanner = RayScanner(objects);
    scanner.scan();
}