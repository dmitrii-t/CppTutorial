#include <chrono>
#include <iostream>

// This brings ALL the names (functions, vars, classes, etc) from the namespace into the current scope
using namespace std;

/// This brings a SPECIFIC NAME (like function, variable, class, etc) into the scope
using std::chrono::system_clock;

int main()
{
    // uses namespace std
    cout << "Example of brining ALL names with using namespace to output a text" << endl;

    cout << "Example of brining a SPECIFIC system_clock name into the scope to format time: " << system_clock::to_time_t(
        system_clock::now()) << endl;

    return 0;
}
