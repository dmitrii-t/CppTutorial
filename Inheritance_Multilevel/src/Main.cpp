#include <cassert>
#include <iostream>

// Declare Vehicle as the base class
class Vehicle {
public:
    Vehicle(int s, int w, bool t) : seats(s), wheels(w), trunk(t) {}

    int  seats;
    int  wheels;
    bool trunk;
};

// Derive Car from Vehicle
class Car : public Vehicle {
public:
    Car(int seats, int trunk) : Vehicle(seats, 4, trunk) {}
};

// Derive Sedan from Car
class Sedan : public Car {
public:
    Sedan() : Car(4, true) {}
};

// Update main to pass the tests
int main() {
    Sedan sedan;
    assert(sedan.trunk == true);
    assert(sedan.seats == 4);
    assert(sedan.wheels == 4);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
