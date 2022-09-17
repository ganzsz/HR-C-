/**
 * Requirements:
 * - Vec3D as {x, y, z}
 * - Ways to visualize the vector
 * - Vec3D minus (Vec3D const &self)                    Create negative vector
 * - Vec3D add (Vec3D const &self, Vec3D const &other)  Add two vectors
 * - Vec3D sub (Vec3D const &self, Vec3D const &other)  Subtract two vectors
 * - Vec3D mul (Vec3D const &self, float scalar)        Multiply a vector with a scalar
 * - Vec3D div (Vec3D const &self, float scalar)        Divide a vector by a scalar
 * - float norm (Vec3D const &self)                     Return the length of a vector
 * - Vec3D unit (Vec3D const &self)                     Create a vector w/ length 1 that points in same direction
 * - float dot (Vec3D const &self, Vec3D const &other)  Return dotproduct of two vectors
 * - Vec3D cross (Vec3D const &self, Vec3D const &other)Return crossproduct of two vectors
 * 
 * TestSpec:
 * - we take two vectors: a: {1,2,3} b: {4,5,6} and we use all the operators on it
 *   to expected input and output values are below
 * +
 * | input       | output
 * +-------------+--------------------------------
 * | minus(a)    | {-1, -2, -3}
 * +-------------+--------------------------------
 * | add(a, b)   | {5, 7, 9}
 * +-------------+--------------------------------
 * | sub(b, a)   | {3, 3, 3}
 * +-------------+--------------------------------
 * | mul(a, 7)   | {7, 14, 21}
 * +-------------+--------------------------------
 * | div(a, 7)   | {0.142857, 0.285714, 0.428571}
 * +-------------+--------------------------------
 * | norm(a)     | 3.74166
 * +-------------+--------------------------------
 * | unit(a)     | {0.267261, 0.534522, 0.801784}
 * +-------------+--------------------------------
 * | dot(a, b)   | 32
 * +-------------+--------------------------------
 * | cross(a, b) | {-3, 6, -3}
 * +-------------+--------------------------------
 * 
 * - Failure contdition on unit with length 0 because it points to itself.
 * zero: {0, 0, 0}
 * | input       | output
 * +-------------+--------------------------------
 * | unit(zero)  | throw error
 * 
 * Design:
 * We have three show() functions.
 * show(label, &Vec3D)  show the label and the vector
 * show(label, &float)  show the label and the scalar
 * show()               show a empty line
 * 
 * and we have implemented te above functions
 */

#include "vector3d.cpp"

int main() {
    auto a = vec3D(1, 2, 3);
    auto b = vec3D(4, 5, 6);
    show("minus",   minus(a));
    show("add",     add(a, b));
    show("sub",     sub(b, a));
    show("mul",     mul(a, 7));
    show("div",     div(a, 7));
    show("norm",    norm(a));
    show("unit",    unit(a));
    show("dot",     dot(a, b));
    show("cross",   cross(a, b));

    auto zero = vec3D(0, 0, 0);
    show("zero",    unit(zero));
}