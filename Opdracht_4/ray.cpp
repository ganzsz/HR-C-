#include "vector3d.hpp"
#include "ray.hpp"
#include "object.hpp"


Ray::Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir, VPO &objects):
    support(Vec3D(xSup, ySup, zSup)), direction(Vec3D(xDir, yDir, zDir)), objects(objects) { }

Ray::Ray (float xStart, float yStart, VPO &objects) :
    objects(objects), support(Vec3D(0, 0, 0)), direction(Vec3D(xStart, yStart, 3)) { }

bool Ray::scan() {
    for(auto object :objects) {
        if(object->hit(*this)) return true;
    }
    return false;
}