// ForwardDeclarations.cpp
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

// 1. Forward Declaration of Wheel class to allow Car class to use it.
class Wheel;

class Car
{
    // Reference to undefined type Wheel which gets defined below; to solve this we use Forward Declaration of Wheel class above.
    vector<Wheel> Wheels;
};

class Wheel
{
    Car* Car;
};


// 2. Forward declaration of InnerFunc; No argument name is needed. 
void InnerFunc(string&);

void OuterFunc(string msg)
{
    InnerFunc(msg);
}

// Definition of InnerFunc  
void InnerFunc(string& msg)
{
    cout << msg << "\n";
}

int main()
{
    Car car;
    Wheel wheel1;

    OuterFunc("InnerFunc is an example of a Forward declaration.");
    return 0;
}
