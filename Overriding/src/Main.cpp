#include <iostream>

#include "../include/Animal.h"
#include "../include/Vehicle.h"

int main() {
    TestAnimalTalks();
    TestVehicleModelMoves();
    std::cout << "All tests passed!" << '\n';
    return 0;
}
