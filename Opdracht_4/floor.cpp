#include "floor.hpp"

Floor::Floor (float height) : Object(height, height, height) {};

bool Floor::hit(Ray &ray) {
    return ray.direction.z < center.z;
}