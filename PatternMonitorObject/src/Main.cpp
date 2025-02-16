// The Monitor Object pattern here ensures that:
// - All access to the vehicles vector is thread-safe
// - The mutex is automatically locked and unlocked
// - The shared resource is encapsulated and only accessible through synchronized
// methods
// - Multiple threads can safely interact with the queue without data races
#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Vehicle {
public:
    // Constructor
    Vehicle(int id) : _id(id) {}

    // getter/setter
    int getID() {
        return _id;
    }

private:
    int _id;
};

class WaitingVehicles {
public:
    WaitingVehicles() {}

    bool dataIsAvailable() {
        std::lock_guard<std::mutex> lock(_mutex);
        return !_vehicles.empty();
    }

    void printIDs() {
        std::lock_guard<std::mutex> lock(_mutex);  // synchronized

        for (auto& v : _vehicles) {
            std::cout << "   Vehicle #" << v.getID() << " is now waiting in the queue"
                      << '\n';
        }
    }

    Vehicle popBack() {
        std::lock_guard<std::mutex> lock(_mutex);  // synchronized

        // remove last vector element from queue
        Vehicle v = std::move(_vehicles.back());
        _vehicles.pop_back();

        return v;  // will not be copied due to return value optimization (RVO) in C++
    }

    void pushBack(Vehicle&& v) {
        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::lock_guard<std::mutex> lock(_mutex);  // synchronized

        // add vector to queue
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue"
                  << '\n';
        _vehicles.emplace_back(std::move(v));
    }

private:
    // list of all vehicles waiting to enter this intersection
    std::vector<Vehicle> _vehicles;  // the shared resourece
    std::mutex           _mutex;     // mutex for synchronization
};

int main() {
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<WaitingVehicles> queue_ptr(new WaitingVehicles);

    std::cout << "Spawning threads..." << '\n';
    std::vector<std::future<void>> futures;

    int nVehicles(0);

    for (int i = 0; i < 10; ++i) {
        // create a new Vehicle instance and move it into the queue
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack,
                                        queue_ptr, std::move(v)));
        nVehicles++;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "Collecting results..." << '\n';
    while (nVehicles > 0) {
        if (queue_ptr->dataIsAvailable()) {
            Vehicle v = queue_ptr->popBack();
            std::cout << "   Vehicle #" << v.getID()
                      << " has been removed from the queue" << '\n';
            nVehicles--;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::for_each(futures.begin(), futures.end(),
                  [](std::future<void>& ftr) { ftr.wait(); });

    std::cout << "Finished processing queue" << '\n';

    return 0;
}