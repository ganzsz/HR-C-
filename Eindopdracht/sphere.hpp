#pragma once

#include "ray.hpp"
#include "vector3d.hpp"
#include "object.hpp"

class Sphere : public Object {
    public:
        Sphere (float x, float y, float z, float radius);
        float distFromRay (Ray const &ray) const;
        bool hit(Ray &ray);
        Vec3D hitPoint (Ray const &ray) const;
        bool hitPointTest (Ray const &ray, Vec3D *out);
        Vec3D getCenter() const;
        float getRadius() const;

    protected:
        float radius;
};