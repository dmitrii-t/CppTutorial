// Threads Example

#include <thread>
#include <vector>

using std::vector;

constexpr int                  THREAD_COUNT      = 10;
constexpr std::chrono::seconds THREAD_SPLEEP_SEC = std::chrono::seconds(5);

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads.emplace_back(std::thread([]() {
            while (true) {
                std::this_thread::sleep_for(THREAD_SPLEEP_SEC);
            }
        }));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
