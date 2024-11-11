#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels{0};
    int boot{300};
    string color = "blue";

    void Print() const
    {
        std::cout << "This " << color << " vehicle has boot size " << boot << " liters and " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
};

class Truck : public Vehicle
{
public:
    bool trailer = true;
};

int main()
{
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
    {
        std::cout << "And a sunroof!\n";
    }

    Truck truck;
    truck.wheels = 6;
    truck.boot = 3000;
    if(truck.trailer)
    {
        std::cout << "And a trailer!\n";
    }
    truck.Print();
};
