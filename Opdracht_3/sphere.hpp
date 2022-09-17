#pragma once

#include "ray.hpp"
#include "vector3d.hpp"

class Sphere {
    public:
        Sphere (float x, float y, float z, float radius);
        float distFromRay (Ray const &ray) const;
        bool hit (Ray const &ray) const;
        Vec3D hitPoint (Ray const &ray) const;
        Vec3D getCenter() const;
        float getRadius() const;

    protected:
        Vec3D center;
        float radius;
};