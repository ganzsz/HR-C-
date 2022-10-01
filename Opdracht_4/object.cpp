#include "object.hpp"
#include "ray.hpp"

Object::Object(float x, float y, float z): center (x, y, z) { }

bool Object::hit(Ray &ray) {return false;};