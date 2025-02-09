// VehicleDC class that has a Deep Copy constructor to avoid causing a race condition
// in multi-threaded programm
#pragma once

#include <future>
#include <iostream>
#include <string>
#include <thread>

class VehicleDC {
public:
    // default constructor
    VehicleDC() : _id(0), _name(new std::string("Default Name")) {
        std::cout << "Vehicle #" << _id << " Default constructor called" << '\n';
    }

    // initializing constructor
    VehicleDC(int id, std::string name) : _id(id), _name(new std::string(name)) {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << '\n';
    }

    // copy constructor
    VehicleDC(VehicleDC const& src) {
        // QUIZ: Student code STARTS here
        _id   = src._id;
        _name = new std::string(*src._name);

        std::cout << "Vehicle #" << _id << " Copy constructor called" << '\n';
    };

    // setter and getter
    void setID(int id) {
        _id = id;
    }
    int getID() {
        return _id;
    }
    void setName(std::string name) {
        *_name = name;
    }
    std::string getName() {
        return *_name;
    }

private:
    int          _id;
    std::string* _name;
};

void TestDeepCopy() {
    // create instances of class VehicleDC
    VehicleDC v0;                  // default constructor
    VehicleDC v1(1, "Vehicle 1");  // initializing constructor

    // launch a thread that modifies the VehicleDC name
    std::future<void> ftr = std::async(
        [](VehicleDC v) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(500));  // simulate work
            v.setName("Vehicle 2");
        },
        v0);

    v0.setName("Vehicle 3");

    ftr.wait();
    std::cout << v0.getName() << '\n';
}