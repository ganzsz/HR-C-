#include "utils.hpp"

#include <iostream>

void show (std::string label, float scalar) {
    std::cout << label << "\t " << scalar << std::endl;
}

void show () {
    std::cout << std::endl;
}
