#pragma once

#include "object.hpp"

class Floor : public Object {
    public:
        Floor (float height, float squareSize);
        virtual bool hit (Ray &ray);
    
    private:
        float squareSize;

};