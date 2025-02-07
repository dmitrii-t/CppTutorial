#pragma once

#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

void workerFunction(int n) {
    // print system id of worker thread
    std::cout << "Worker thread id = " << std::this_thread::get_id() << '\n';

    // perform work
    for (int i = 0; i < n; ++i) {
        sqrt(12345.6789);
    }
}

void TestTasks() {
    // print system id of worker thread
    std::cout << "Main thread id = " << std::this_thread::get_id() << '\n';

    // start time measurement
    std::chrono::high_resolution_clock::time_point t1 =
        std::chrono::high_resolution_clock::now();

    // launch various tasks
    std::vector<std::future<void>> futures;
    int                            nLoops = 10, nThreads = 2;
    for (int i = 0; i < nThreads; ++i) {
        futures.emplace_back(std::async(workerFunction, nLoops));
    }

    // wait for tasks to complete
    for (const std::future<void>& ftr : futures) {
        ftr.wait();
    }

    // stop time measurement and print execution time
    std::chrono::high_resolution_clock::time_point t2 =
        std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Execution finished after " << duration << " microseconds"
              << '\n';
}