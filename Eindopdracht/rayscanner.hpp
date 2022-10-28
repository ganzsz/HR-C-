#pragma once

#include <vector>

#include "floor.hpp"
#include "sphere.hpp"
#include "ray.hpp"

class RayScanner {
    public:
        RayScanner(VPO ojb);
        void scan();

    private:
        VPO objects;
};