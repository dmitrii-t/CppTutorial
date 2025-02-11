#include "../include/Mutexes.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <thread>

void WaitingVehicles::printSize() {
    _mutex.lock();  // preventing concurrent threads overriding the value printed to
                    // stdout
    std::cout << "#vehicles = " << _nVehicles << '\n';
    _mutex.unlock();
};

void WaitingVehicles::pushBack(Vehicle&& v) {
    bool locked  = false;
    int  attempt = 0;

    for (; !(locked = _mutex.try_lock()) && attempt < 3; attempt++) {
        std::cout << "attempt: " << attempt << " failed to acquire lock" << '\n';
    }

    if (locked) {
        //_vehicles.push_back(std::move(v)); // data race would cause an exception
        int prevNum = _nVehicles;
        std::this_thread::sleep_for(
            std::chrono::microseconds(1));  // wait deliberately to expose the data race

        _nVehicles =
            prevNum + 1;  // <- data race is happening here as multiple threads writing
        // to the same member (overriding the stored value)
        _mutex.unlock();

    } else {
        std::ostringstream err;
        err << "failed to acquire a lock after " << attempt << " attempts " << '\n';
        throw std::runtime_error(err.str());
    }
}

void ShowcaseMutexes() {
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
    std::vector<std::future<void>>   futures;

    for (int i = 0; i < 1000; ++i) {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack,
                                        queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(),
                  [](std::future<void>& ftr) { ftr.wait(); });

    queue->printSize();
}
