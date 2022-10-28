#include "vector3d.hpp"
#include "ray.hpp"
#include "object.hpp"


Ray::Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir, VPO &objects, int bounces):
    support(Vec3D(xSup, ySup, zSup)), direction(Vec3D(xDir, yDir, zDir)), objects(objects), bounces(bounces) { }

// Position of the eye is 3m back from the origin
auto EYE = Vec3D(0,0,-3);

// Create a ray from the eye to a defined point on the screen
Ray::Ray (float xStart, float yStart, VPO &objects) :
    objects(objects), support(EYE), direction(Vec3D(xStart, yStart, 0).sub(EYE).unit()), bounces(0), intensity(1) { }

/** 
 * Recursively scans the objects for hits.
 * If a bounce occurs trace the new ray that gets generated
 * returns true if a hit occurs
 */
bool Ray::scan() {
    for(auto object :objects) {
        if(object->hit(*this)) {
            this->bounces++;
            if(this->bounces > 2)
                return true;
            else
                return this->scan();
        }
    }
    return bounces > 0;
}

// Returns the color of the ray
float Ray::getWhite() { return bounces > 0 ? intensity/(float)bounces : 0; }
int Ray::getBounces() { return bounces; }