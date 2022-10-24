#pragma once

#include <vector>

#include "floor.hpp"
#include "sphere.hpp"
#include "ray.hpp"

class RayScanner {
    public:
        RayScanner(VPO ojb);
        void AddFloor(Floor floor);
        void AddSphere(Sphere Sphere);
        void scan();

    private:
        VPO objects;
};