#include <math.h>

#include "vector3d.hpp"

Vec3D::Vec3D (): x(0), y(0), z(0) { }

Vec3D::Vec3D (const Vec3D &cp): x(cp.x), y(cp.y), z(cp.z) { }

Vec3D::Vec3D (float x, float y, float z): x(x), y(y), z(z) { }

void Vec3D::show (std::string label) {
    std::cout << label << "\t " << x << "\t "<< y << "\t " << z << std::endl;
}


/* returns a new negative vector */
Vec3D Vec3D::negate () const {
    return Vec3D(-x, -y, -z);
}

/* returns this+other as a new vector*/
Vec3D Vec3D::add (Vec3D const &other) const {
    return Vec3D ( 
        x + other.x,
        y + other.y,
        z + other.z
    );
}

/* returns this-other as a new vector */
Vec3D Vec3D::sub (Vec3D const &other) const {
    return add(other.negate());
}

/* returns this*scalar as a new vector */
Vec3D Vec3D::mul (float scalar) const {
    return Vec3D(
        x * scalar,
        y * scalar,
        z * scalar
    );
}

/* returns this/scalar as a new vector */
Vec3D Vec3D::div (float scalar) const {
    return Vec3D(
        x / scalar,
        y / scalar,
        z / scalar
    );
}

/* returns the length this (a scalar) */
float Vec3D::norm () const {
    return sqrt(x*x + y*y + z*z);
}

/* Returns new 1 length vector thet points in the same direction */
Vec3D Vec3D::unit () const {
    auto len = norm();
    if(len != 0) {
        return {
            x / len,
            y / len,
            z / len
        };
    }
    throw std::invalid_argument("The length of the vector can't be 0 in Vec3D unit(Vec3d const &self");
}

/* Returns the inproduct this.other (a scalar)*/
float Vec3D::dot (Vec3D const &other) const {
    return (x*other.x + y*other.y + z*other.z);
}

/* Returns the exproduct of two vectors (a vector)*/
Vec3D Vec3D::cross (Vec3D const &other) const {
    return Vec3D(
        y*other.z - z*other.y,
        z*other.x - x*other.z,
        x*other.y - y*other.x
    );
}