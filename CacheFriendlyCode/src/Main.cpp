#include <chrono>
#include <iostream>

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;
using std::cout;

int main() {
    // create array
    const int size = 1000;

    static int x[size][size];

    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // adjacent addresses access
            x[i][j] = i + j;  // took 1259700 nanoseconds

            // distant addresses access, note x[j][i] below
            // x[j][i] = i + j; // took 1414400 nanoseconds

            // std::cout << &x[j][i] << ": i=" << i << ", j=" << j << std::endl;
        }
    }

    // print execution time to console
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time).count();
    cout << "Execution time: " << duration << " nanoseconds" << '\n';

    return 0;
}
