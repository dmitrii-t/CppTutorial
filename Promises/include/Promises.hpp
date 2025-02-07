#pragma once

#include <future>
#include <iostream>
#include <thread>

// promise is a producer side which sets the value
void modifyMessage(std::promise<std::string>&& promise, std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));  // simulate work
    promise.set_value(message + " has been modified");
}

void TestPromises() {
    // the message
    std::string input_msg = "My Message";

    // create promise and future
    std::promise<std::string> promise;
    std::future<std::string>  future = promise.get_future();

    // start a new thread
    // NOTE since promise is moved the local var is no longer valid
    std::thread t(modifyMessage, std::move(promise), input_msg);
    
    // print original message to console
    std::cout << "input message from main(): " << input_msg << '\n';
    
    // std::chrono::milliseconds delay(1000);
    // if (future.wait_for(delay) == std::future_status::ready) {
        std::cout << "output message from thread(): " << future.get() << '\n';
    // } else {
    //    std::cout << "the result is not ready after " << delay.count() << "mills" << '\n';
    // }

    // thread barrier
    t.join();
}