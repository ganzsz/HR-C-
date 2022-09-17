/**
 * Requirements:
 * - Class Ray with two Vec3D (support, direction)
 * - Class Sphere with Vec3D center and float radius
 * -- Method distFromRay(Ray const &ray): distance between center and ray
 * -- Method hit(Ray const &ray): Does the ray intersect the sphere
 * -- Method hitPoint(Ray const &ray): Where does the ray hit the sphere 
 * 
 * TestSpec:
 * - std::vector<Ray> with rays that might intersect items in a std::vector<Sphere>
 * output:
 * dist:    0
 * intersect    -0.8    0.23    -1
 * 
 * Dist:    0.262
 * Intersect    0.254742        0.23    -1
 * 
 * Dist:    0.628
 * 
 * Dist:    1.164
 * 
 * Dist:    0.626
 * 
 * Dist:    0
 * Intersect    0.7     -0.15   -1.7
 * 
 * Dist:    0.825
 * 
 * Dist:    0
 * Intersect    0.4     0.1     -1.2
 * 
 * Dist:    0.424
 * 
 * Design:
 * 
 */

#include <vector>

#include "ray.hpp"
#include "sphere.hpp"
#include "utils.hpp"

const float far = 0.8;

int main() {
    auto spheres = std::vector<Sphere> ();
    spheres.push_back(Sphere (-0.4, 0.23,  -1,   0.4));
    spheres.push_back(Sphere (0.4,  0.4,   -1.2, 0.3));
    spheres.push_back(Sphere (0.7,  -0.15, -1.5, 0.2));

    auto rays = std::vector<Ray> ();
    rays.push_back(Ray(-far, 0.23,  -1,   far, 0,   0));
    rays.push_back(Ray (0.7, -0.15, -far, 0,   0,   far));
    rays.push_back(Ray (0.4, -far,  -1.2, 0,   far, 0));

    for(auto ray:rays) {
        for(auto sphere:spheres) {
            show("Dist", sphere.distFromRay(ray));
            if(sphere.hit(ray)) {
                sphere.hitPoint(ray).show("Intersect");
            }
            show();
        }
    }
}