﻿#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

template <class T>
class MessageQueue {
public:
    T receive() {
        // perform queue modification under the lock
        std::unique_lock<std::mutex> lock(_mutex);  // syncronized

        _cond.wait(lock, [this] {
            return !_messages.empty();
        });  // pass unique lock to condition variable

        // remove last vector element from queue
        T msg = std::move(_messages.back());
        _messages.pop_back();

        return msg;  // will not be copied due to return value optimization (RVO) in C++
    }

    void send(T&& msg) {
        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // perform vector modification under the lock
        std::lock_guard<std::mutex> lock(_mutex);  // synchronized

        // add vector to queue
        std::cout << "   Message " << msg << " has been sent to the queue" << '\n';
        _messages.push_back(std::move(msg));

        _cond.notify_one();  // notify client after pushing new Vehicle into vector
    }

private:
    std::mutex              _mutex;
    std::condition_variable _cond;
    std::deque<T>           _messages;
};

int main() {
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

    std::cout << "Spawning threads..." << '\n';
    std::vector<std::future<void>> futures;

    for (int i = 0; i < 10; ++i) {
        int message = i;
        futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send,
                                        queue, std::move(message)));
    }

    std::cout << "Collecting results..." << '\n';
    while (true) {
        int message = queue->receive();
        std::cout << "   Message #" << message << " has been removed from the queue"
                  << '\n';
    }

    std::for_each(futures.begin(), futures.end(),
                  [](std::future<void>& ftr) { ftr.wait(); });

    std::cout << "Finished!" << '\n';

    return 0;
}