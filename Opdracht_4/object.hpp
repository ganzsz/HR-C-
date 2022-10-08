#pragma once

#include "vector3d.hpp"
#include "ray.hpp"

class Object {

    public:
        Object (float x, float y, float z);
        virtual bool hit (Ray &ray) = 0;
    
    protected:
        Vec3D center;
};