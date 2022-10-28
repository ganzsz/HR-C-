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
    auto objects = VPO();
    auto floor = Floor(-1.0, 0.75);
    objects.push_back(&floor);
    auto sphere1 = Sphere(-0, 0.1, 1.25, 0.5);
    objects.push_back(&sphere1);
    auto sphere2 = Sphere(-0.75, 0.5, 1, 0.4);
    objects.push_back(&sphere2);
    // auto sphere3 = Sphere(1, 0.75, 8, 3);
    // objects[3] = &sphere3;
    auto scanner = RayScanner(objects);
    scanner.scan();
}