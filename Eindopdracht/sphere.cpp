#include "sphere.hpp"
#include "utils.hpp"

Sphere::Sphere (float x, float y, float z, float radius):
    Object(x, y, z), radius(radius) {}

/* Return a scalar with the minimum distance that a ray has from the center of the sphere */
float Sphere::distFromRay (Ray const &ray) const {
    return ((ray.support - center) * ray.direction).norm();
}

/* Return true if a ray intercepts a sphere */
bool Sphere::hit (Ray &ray) {
    if(distFromRay(ray) < radius) {
        Vec3D hitPoint;
        if(!hitPointTest(ray, &hitPoint)) return false;

        // Using the theory found on
        // https://www.fabrizioduroni.it/2017/08/25/how-to-calculate-reflection-vector/
        auto normal = (hitPoint - center).unit();
        auto reflection = (normal * (normal.dot(ray.direction)) * 2 - ray.direction).negate().unit();
        ray.direction=reflection;
        ray.support=hitPoint;

        return true;
    }
    else
        return false;
}

/**
 * To know hitpoints we have the following functions:
 * - ray:    S + tD =  with Support and Direction aka the points on the ray
 *           and t, wich is a time component how far we are along the ray
 * - sphere: |P^2 - C^2| - R^2 = 0 with Points on the circle centered in C and Radius
 * These combined form |S + tD − C|^2 − R^2 = 0
 * 
 * Letting the internet do magic for us we get a quadratic formula
 * wich can be written as ax^2 + bx + c = 0 with:
 *  a = D^2
 *  b = 2D(S - C)
 *  c = |S - C|^2 - R^2
 * What we are basically doing is translating the ray - C so we can pretend the
 * sphere is around the origin
 * 
 * We then check whether t0 is positive. If it is negative this means that the ray
 * only has a backwards hit. This usually means that the support for a bounced off ray
 * is juuust inside the sphere, so it will keep bouncing off itself then.
 */

/** out becomes the point as a vector where a ray hits the outside of a sphere 
 * returns whether t0 is positive
 */
bool Sphere::hitPointTest (Ray const &ray, Vec3D *out) {
    // L is the pretend ray moved relative with the sphere
    auto L = ray.support - center;
    auto a = ray.direction.dot(ray.direction);
    auto b = 2 * ray.direction.dot(L);
    auto c = L.dot(L) - radius*radius;

    float t0, t1;
    if(!solveQuadratic(a, b, c, t0, t1))
        throw std::logic_error("The ray and sphere don't intersect in Sphere::hitPoint");

    if(ray.bounces == 0 && t0 < 0) throw std::logic_error("The object is behind the person. This should not be the case. in Sphere::hitPoint");

    // Fill in the point we found in the ray equation to find the intersection point
    *out = ray.direction * t0 + ray.support;
    return t0 > 0;
}

// Getters for debugging mainly 
Vec3D Sphere::getCenter() const { return center; }
float Sphere::getRadius() const { return radius; }