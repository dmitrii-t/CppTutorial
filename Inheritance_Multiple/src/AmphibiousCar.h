#pragma once

#include <iostream>
#include <string>

class Car {
public:
    std::string Drive() {
        return "i'm driving!";
    }
};

class Boat {
public:
    std::string Cruise() {
        return "i'm cruising!";
    }
};

class AmphibiousCar : public Car, public Boat {};
