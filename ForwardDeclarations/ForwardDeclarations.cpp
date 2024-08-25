// ForwardDeclarations.cpp
#include <vector>

// Forward Declaration of Wheel class to allow Car class to use it.
class Wheel;

class Car
{
    // Reference to undefined type Wheel which gets defined below; to solve this we use Forward Declaration of Wheel class above.
    std::vector<Wheel> Wheels;
};

class Wheel
{
    Car* Car;
};

int main()
{
    Car car;
    Wheel wheel;

    return 0;
}
