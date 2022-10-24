/**
 * Requirements:
 * Display a pleasing scene with three spheres and a checkerd floor.
 * The screen is placed 3m from the observer
 */

#include "rayscanner.hpp"
#include "floor.hpp"
#include "sphere.hpp"

const float far = 0.8;

int main() {
    auto objects = VPO(4);
    auto floor = Floor(-0.5, 0.25);
    objects[0] = &floor;
    auto sphere1 = Sphere(-0, 0, 3.5, 0.5);
    objects[1] = &sphere1;
    auto sphere2 = Sphere(-0.75, 0.5, 3.1, 1.7);
    objects[2] = &sphere2;
    auto sphere3 = Sphere(2.2, 0.5, 8, 5);
    objects[3] = &sphere3;
    auto scanner = RayScanner(objects);
    scanner.scan();
}