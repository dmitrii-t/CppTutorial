// Referencies.cpp
#include <iostream>

using namespace std;

void DoubleString(string& value) {
    // Concatenates the string with a space and itself.
    // When the value is passed by reference this will update the value outside
    // off this function as well. Stack:
    // +--------------------------+
    // | main()                   |
    // |  string s = "Hello"      | <--- Original variable
    // |  &s (reference)          | <--- Reference to x
    // +--------------------------+
    // | function(string& value)  |
    // |  value (alias for s)     |
    // +--------------------------+
    value = value + " " + value;
}

int main() {
    string s = "Hello";
    cout << "The string s is: " << s << "\n";

    DoubleString(s);
    cout << "The string s is now: " << s << "\n";
}
