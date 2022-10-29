#pragma once

#include <iostream>

class Object;
class Floor;
class Ray;

class Vec3D {
    friend Ray;
    friend Floor;
    friend Object;

    public:
        Vec3D ();
        Vec3D (const Vec3D &cp);
        Vec3D (float x, float y, float z);
        void show (std::string label);
        Vec3D negate () const;
        Vec3D add (Vec3D const &other) const; //
        Vec3D sub (Vec3D const &other) const; //
        Vec3D mul (float scalar) const; //
        Vec3D div (float scalar) const;
        float norm () const;
        Vec3D unit () const;
        float dot (Vec3D const &other) const;
        Vec3D cross (Vec3D const &other) const; //

        Vec3D operator + (Vec3D const &other) const { return this->add(other); };
        Vec3D operator - (Vec3D const &other) const { return this->sub(other); };
        Vec3D operator * (float const &other) const { return this->mul(other); };
        Vec3D operator * (Vec3D const &other) const { return this->cross(other); };
        Vec3D operator / (float const &other) const { return this->div(other); };
    
    protected:
        float x, y, z;
};