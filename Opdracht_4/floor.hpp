#pragma once

#include "object.hpp"
#include "vector3d.hpp"

class Floor : public Object {
    public:
        Floor (float height, float squareSize);
        virtual bool hit (Ray &ray);
    
    private:
        Vec3D normal;
        float squareSize;

};