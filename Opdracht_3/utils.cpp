#include "utils.hpp"

#include <iostream>
#include <math.h>

void show (std::string label, float scalar) {
    std::cout << label << "\t " << scalar << std::endl;
}

void show () {
    std::cout << std::endl;
}

/**
 * First calc disc to see if there are 0, 1 or 2 solutions.
 * - with 0 solutions return false since it won't work
 * - with 1 solutions run simplified formula since sqrt(0) = 0 
 * - with 2 solutions run formula and make sure x0 is the smallest result
 */
bool solveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1) 
{ 
    float discr = b * b - 4 * a * c; 
    if (discr < 0) return false; 
    else if (discr == 0) x0 = x1 = - 0.5 * b / a; 
    else {
        x0 = (-b + sqrt(discr)) / (2*a);
        x1 = (-b - sqrt(discr)) / (2*a);
    } 
    if (x0 > x1) std::swap(x0, x1); 
 
    return true; 
} 
