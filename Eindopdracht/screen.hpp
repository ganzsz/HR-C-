#pragma once

#pragma once

#include <vector>

class Screen {
    public:
        Screen (int widht, float aspect);
        void updatePixelIntensity(int x, int y, float fraction);
        void displayScreen();
        int numRows();
        int numCols();
    
    private:
        std::vector<std::vector<float>> screen;
};