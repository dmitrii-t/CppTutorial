///
// * mutex: provides the core functions lock() and unlock() and the non-blocking try_lock() method that returns if the mutex is not available.
// * recursive_mutex: allows multiple acquisitions of the mutex from the same thread.
// * timed_mutex: similar to mutex, but it comes with two more methods try_lock_for() and try_lock_until() that try to acquire the mutex for a period of time or until a moment in time is reached.
// * recursive_timed_mutex: is a combination of timed_mutex and recursive_mutex.
#pragma once

#include <future>
#include <mutex>  // <- mutex header
#include <vector>

class Vehicle {
public:
    Vehicle(int id) : _id(id) {}

private:
    int _id;
};

class WaitingVehicles {
public:
    WaitingVehicles() : _nVehicles(0) {}

    // getters / setters
    void printSize();

    // typical behaviour methods
    void pushBack(Vehicle&& v);

private:
    std::vector<Vehicle>
               _vehicles;  // list of all vehicles waiting to enter this intersection
    std::mutex _mutex;
    int        _nVehicles;
};

void ShowcaseMutexes();