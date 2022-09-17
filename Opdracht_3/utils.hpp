#pragma once

#include <iostream>

void show (std::string label, float scalar);

void show ();

/* Solve a quadratic abc formula put results in x0, x1 return true if there are results */
bool solveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1);