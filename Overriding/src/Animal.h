#pragma once

#include <cassert>
#include <string>

class Animal {
public:
    virtual std::string Talk() const = 0;
};

// Declares a class Dog that inherits from Animal
class Dog : Animal {
public:
    std::string Talk() const override;
};

std::string Dog::Talk() const {
    return "Woof";
}

inline void TestAnimalTalks() {
    Dog dog;
    assert(dog.Talk() == "Woof");
}
