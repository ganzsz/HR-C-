#pragma once

#include "vector3d.hpp"

class Sphere;

class Ray {
    friend Sphere;
    
    public:
        Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir);

    private:
        Vec3D support, direction;
};