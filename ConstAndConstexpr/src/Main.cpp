// ConstAndConstepr.cpp

// C++ supports two notions of immutability:
// const: meaning roughly " I promise not to change this value."...The compiler enforces the promise made by const....
// constexpr: meaning roughly "to be evaluated at compile time." This is used primarily to specify constants...

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int i;
    cout << "Enter an integer value for i: ";
    cin >> i;

    // j can be evaluated only at runtime
    // but cannot be changed once it's initialized
    //
    // const especially useful for the arguments passed by reference
    // to ensure the reference not getting changed
    const int j = i * 2;

    // k is evaluated at compile time and replaced with the actual value
    constexpr int k = 3;

    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";
        
    return 0;
}
