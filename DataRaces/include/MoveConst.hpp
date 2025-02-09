// VehicleMC class that has a Deep Copy constructor to avoid causing a race condition
// in multi-threaded programm
#pragma once

#include <future>
#include <iostream>
#include <string>
#include <thread>

class VehicleMC {
public:
    // default constructor
    VehicleMC() : _id(0), _name(new std::string("Default Name")) {
        std::cout << "Vehicle #" << _id << " Default constructor called" << '\n';
    }

    // initializing constructor
    VehicleMC(int id, std::string name) : _id(id), _name(new std::string(name)) {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << '\n';
    }

    // move constructor 
    VehicleMC(VehicleMC && src)
    {
        _id = src.getID();
        _name = new std::string(src.getName());

        src.setID(0);
        src.setName("Default Name");

        std::cout << "Vehicle #" << _id << " Move constructor called" << std::endl;
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

void TestMoveConstructor() {
    // create instances of class VehicleMC
    VehicleMC v0;                  // default constructor
    VehicleMC v1(1, "Vehicle 1");  // initializing constructor

    // launch a thread that modifies the VehicleMC name
    std::future<void> ftr = std::async(
        [](VehicleMC v) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(500));  // simulate work
            v.setName("Vehicle 2");
        },
        std::move(v0));

    // v0 cannot be used anymore 
    // v0.setName("Vehicle 3");

    ftr.wait();
    std::cout << v0.getName() << '\n';
}