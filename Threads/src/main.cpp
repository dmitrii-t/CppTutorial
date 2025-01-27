// Threads Example

#include <iostream>
#include <thread>
#include <vector>

using std::vector;

constexpr int                       THREAD_COUNT      = 10;
constexpr std::chrono::milliseconds THREAD_SPLEEP_SEC = std::chrono::milliseconds(5);

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < THREAD_COUNT; ++i) {
        // emplace_back() instead of push_back() as
        // emplace_back() uses move semantics to move a thread object instead of copying
        // it
        threads.emplace_back(std::thread([i]() {
            std::this_thread::sleep_for(THREAD_SPLEEP_SEC * i);
            // std::cout << "worker thread " <<  std::this_thread::get_id() << "\n";
            std::cout << "worker thread " << i << "\n";
        }));
    }

    std::cout << "main thread" << '\n';

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
