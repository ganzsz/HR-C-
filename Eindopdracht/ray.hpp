#pragma once

#include <vector>
#include "vector3d.hpp"

class Sphere;
class Floor;
class RayScanner;

typedef std::vector<Object*> VPO;

class Ray {
    friend Sphere;
    friend Floor;
    friend RayScanner;
    
    public:
        Ray (float xStart, float yStart, VPO &objects);
        Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir, VPO &objects, int bounces);
        bool scan();
        float getWhite();
        int getBounces();

    private:
        Vec3D support, direction;
        VPO &objects;
        int bounces;
        float intensity;
        Object* lastBounce;
};