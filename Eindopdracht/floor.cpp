#ifndef DEBUG
#define DEBUG false
#endif

#include "floor.hpp"
#include <math.h>

/* Create a floor specify the height and the size of a single square */
Floor::Floor (float height, float squareSize) : Object(0, height, 0), squareSize(squareSize) {};
/**
 * 
*/
/* Returns true if the given ray hits a white square on the floor*/
bool Floor::hit(Ray &ray) {
    //the sceen is x,y depth = z
    if(ray.direction.y >=0 ) return false;
    //we don't want to show the floor up to the horizon which is halfway up the screen
    if(ray.support.x == 0.0 && ray.support.y ==0.0 && ray.support.z == -3.0 && ray.direction.y > -0.1) return false;

    // Taken from https://stackoverflow.com/questions/5666222/3d-line-plane-intersection
    // adapted to use c++
    auto dot = center.dot(ray.direction);
    auto w = ray.support.sub(center);
    auto fac = -center.dot(w)/dot;
    auto u = ray.direction.mul(fac);
    auto P = ray.support.add(u);
    /**
     * If P.x < 0 we want to add 1 to the |P.x|/square calculation. This is to 
     * account for the fact that we want odd squares to be white in the negative x domain.
     * Otherwise the [0,1] and [-1,0] x values would be the same color on a given y
    */
    auto hit = P.x > 0
        ? (int)floor(abs(P.z)/squareSize) % 2 == (int)floor(abs(P.x)/squareSize) % 2
        : (int)floor(abs(P.z)/squareSize) % 2 == (int)floor((abs(P.x)/squareSize) + 1) % 2;
    if(DEBUG) std::cout<< floor(P.x) <<  ' ' << floor(P.z) << ' '  << (hit? 'W' : 'B') << '|';
    if(hit) {
        // This is a quick way to make sure no other hits will happen for this ray.
        // We just make a ray pointing down from the floor.
        ray.support = center.add(Vec3D(0, -0.5, 0));
        ray.direction = Vec3D(0,-1,0);
        ray.intensity = 1;
    }
    return hit;
}