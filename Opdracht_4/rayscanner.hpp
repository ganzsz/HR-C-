#pragma once

#include <vector>

#include "object.hpp"

class RayScanner {
    public:
        void AddObject(Object object);
        void scan();

    private:
        std::vector<Object> objects;
};