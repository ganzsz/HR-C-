#pragma once

#include <vector>
#include "vector3d.hpp"

class Sphere;
class Floor;

typedef std::vector<Object*> VPO;

class Ray {
    friend Sphere;
    friend Floor;
    
    public:
        Ray (float xStart, float yStart, VPO &objects);
        Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir, VPO &objects);
        bool scan();

    private:
        Vec3D support, direction;
        VPO &objects;

};