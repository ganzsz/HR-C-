#include <iostream>
#include <math.h>

struct Vec3D {float x, y, z;};

Vec3D vec3D (float x, float y, float z) {
    return {x, y, z};
}

void show (std::string label, Vec3D const &self) {
    std::cout << label << "\t " << self.x << "\t "<< self.y << "\t " << self.z << std::endl;
}

void show (std::string label, float scalar) {
    std::cout << label << "\t " << scalar << std::endl;
}

void show () {
    std::cout << std::endl;
}

/* Creates the negative vector from a vector returns a vector*/
Vec3D minus (Vec3D const &self) {
    return {-self.x, -self.y, -self.z};
}

/* Add two vectors returns a vector*/
Vec3D add (Vec3D const &self, Vec3D const &other) {
    return {
        self.x + other.x,
        self.y + other.y,
        self.z + other.z
    };
}

/* Subtract two vectors returns a vector*/
Vec3D sub (Vec3D const &self, Vec3D const &other) {
    return add(self, minus(other));
}

/* Multiply a vector with a scalar, returns a vector*/
Vec3D mul (Vec3D const &self, float scalar) {
    return {
        self.x * scalar,
        self.y * scalar,
        self.z * scalar
    };
}

/* Divide a vector by a scalar returns a vector */
Vec3D div (Vec3D const &self, float scalar) {
    return {
        self.x / scalar,
        self.y / scalar,
        self.z / scalar
    };
}

/* returns the length of a vector (a scalar) */
float norm (Vec3D const &self) {
    return sqrt(self.x*self.x + self.y*self.y + self.z*self.z);
}

/* Returns 1 length vector thet points in the same direction */
Vec3D unit (Vec3D const &self) {
    auto len = norm(self);
    if(len != 0) {
        return {
            self.x / len,
            self.y / len,
            self.z / len
        };
    }
    throw std::invalid_argument("The length of the vector can't be 0 in Vec3D unit(Vec3d const &self");
}

/* Returns the inproduct of two vecors (a scalar)*/
float dot (Vec3D const &self, Vec3D const &other) {
    return self.x*other.x + self.y*other.y + self.z*other.z;
}

/* Returns the exproduct of two vectors (a vector)*/
Vec3D cross (Vec3D const &self, Vec3D const &other) {
    return vec3D(
        self.y*other.z - self.z*other.y,
        self.z*other.x - self.x*other.z,
        self.x*other.y - self.y*other.x
    );
}