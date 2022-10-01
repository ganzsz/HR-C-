#pragma once

#include "object.hpp"

class Floor : public Object {
    public:
        Floor (float height);
        virtual bool hit (Ray &ray);
};