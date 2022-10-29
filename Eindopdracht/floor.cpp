#ifndef DEBUG
#define DEBUG false
#endif

#include "floor.hpp"
#include <math.h>

/* Create a floor specify the height and the size of a single square. */
Floor::Floor (float height, float squareSize) : Object(0, height, 0), squareSize(squareSize) {};

/**
 * We need a point on the plane and a (non normalized) normal to the plane. To achieve this, 
 * center is defined in such a way that is is both a point on the plane and at the same time
 * the normal to the plane.
 * 
 * dot = the dotproduct of the normal and the ray direction. This is used to later find the
 * point on the ray where the ray intersects. Because we test the ray before the formula we
 * can know this will happen.
 * 
 * w = the diff between the support and the point on the plane. we use it to only get the
 * component of the ray that we need
 * 
 * fac = the amount of ray.distance traveled on the ray where the ray hits the plane
 * 
 * u = the ray we get when using fac on the direction
 * 
 * P = ray u added to the support (the start of the ray)
 * 
 * If P.x < 0 we want to add 1 to the |P.x|/square calculation. This is to 
 * account for the fact that we want odd squares to be white in the negative x domain.
 * Otherwise the [0,1] and [-1,0] x values would be the same color on a given y
 * 
 * Taken from https://stackoverflow.com/questions/5666222/3d-line-plane-intersection
 * adapted for our specific usecase
*/

/* Returns true if the given ray hits a white square on the floor*/
bool Floor::hit(Ray &ray) {
    //the sceen is x,y depth = z
    if(ray.direction.y >=0 ) return false;
    //we don't want to show the floor up to the horizon which is halfway up the screen
    if(ray.bounces == 0 && ray.direction.y > -0.1) return false;

    auto dot = center ^ (ray.direction);
    auto w = ray.support - center;
    auto fac = - center ^ w / dot;
    auto u = ray.direction * fac;
    auto P = ray.support + u;

    auto hit = P.x > 0
        ? (int)floor(abs(P.z)/squareSize) % 2 == (int)floor(abs(P.x)/squareSize) % 2
        : (int)floor(abs(P.z)/squareSize) % 2 == (int)floor((abs(P.x)/squareSize) + 1) % 2;
    if(DEBUG) std::cout<< floor(P.x) <<  ' ' << floor(P.z) << ' '  << (hit? 'W' : 'B') << '|';
    if(hit) {
        // This is a quick way to make sure no other hits will happen for this ray.
        // We just make a ray pointing down from the floor.
        ray.support = center + Vec3D(0, -0.5, 0);
        ray.direction = Vec3D(0,-1,0);
        ray.intensity = 1;
    }
    return hit;
}