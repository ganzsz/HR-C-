#include "sphere.hpp"
#include "utils.hpp"

Sphere::Sphere (float x, float y, float z, float radius):
    center(Vec3D(x, y, z)), radius(radius) {}

/* Return a scalar with the minimum distance that a ray has from the center of the sphere */
float Sphere::distFromRay (Ray const &ray) const {
    return ray.support.sub(center).cross(ray.direction).norm();
}

/* Return true if a ray intercepts a sphere */
bool Sphere::hit (Ray const &ray) const {
    return distFromRay(ray) < radius;
}

/**
 * To know hitpoints we have the following functions:
 * - ray:    S + tD = P with Support and Direction aka the points on the ray
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
 */

/* Return the point as a vector where a ray hits the outside of a sphere */
Vec3D Sphere::hitPoint (const Ray &ray) const
{
    // L is the pretend ray moved relative with the sphere
    auto L = ray.support.sub(center);
    auto a = ray.direction.dot(ray.direction);
    auto b = 2 * ray.direction.dot(L);
    auto c = L.dot(L) - radius*radius;

    float t0, t1;
    if(!solveQuadratic(a, b, c, t0, t1))
        throw std::logic_error("The ray and sphere don't intersect in Sphere::hitPoint");

    // if(t0 < 0) throw std::logic_error("The object is behind the person. This should not be the case in Sphere::hitPoint");

    // Fill in the point we found in the ray equation to find the intersection point
    return ray.support.add(ray.direction.mul(t0));
};

// Getters for debugging mainly 
Vec3D Sphere::getCenter() const { return center; }
float Sphere::getRadius() const { return radius; }