// ForwardDeclarations.cpp
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

// 1. Forward Declaration of Wheel class to allow Car class to use it.
class Wheel;

class Car {
public:
    // Reference to undefined type Wheel which gets defined below; to solve this
    // we use Forward Declaration of Wheel class above.
    vector<Wheel> wheels;
};

class Wheel {
public:
    Car* car;
};

// 2. Forward declaration of InnerFunc; No argument name is needed.
void InnerFunc(string&);

void OuterFunc(string msg) {
    InnerFunc(msg);
}

// Definition of InnerFunc
void InnerFunc(string& msg) {
    cout << msg << "\n";
}

int main() {
    Car   car;
    Wheel wheel1;
    wheel1.car = &car;
    car.wheels.push_back(wheel1);

    OuterFunc("InnerFunc is an example of a Forward declaration.");
    return 0;
}
