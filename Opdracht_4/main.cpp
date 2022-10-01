/**
 * Requirements:
 *
 */

#include "rayscanner.hpp"
#include "floor.hpp"

const float far = 0.8;

int main() {
    auto scanner = RayScanner();

    scanner.AddObject(Floor(-0.5));
    scanner.scan();
}