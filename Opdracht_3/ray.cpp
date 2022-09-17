#include "vector3d.hpp"
#include "ray.hpp"


Ray::Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir):
    support(Vec3D(xSup, ySup, zSup)), direction(Vec3D(xDir, yDir, zDir)) { }

