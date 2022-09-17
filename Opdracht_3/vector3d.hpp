#pragma once

#include <iostream>

class Ray;

class Vec3D {
    friend Ray;

    public:
        Vec3D (float x, float y, float z);
        void show (std::string label);
        Vec3D minus () const;
        Vec3D add (Vec3D const &other) const;
        Vec3D sub (Vec3D const &other) const;
        Vec3D mul (float scalar) const;
        Vec3D div (float scalar) const;
        float norm () const;
        Vec3D unit () const;
        float dot (Vec3D const &other) const;
        Vec3D cross (Vec3D const &other) const;
    
    protected:
        float x, y, z;
};