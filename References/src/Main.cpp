// References.cpp
#include <iostream>

using namespace std;

void PassByValue(string value) {
    value = value + " " + value;
}

void UpdateByReference(string& value) {
    // Concatenates the string with a space and the string itself.
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
    cout << "1: s=" << s << "\n";

    PassByValue(s);
    cout << "2: passing by value s=" << s << "\n";

    UpdateByReference(s);
    cout << "3: passing by ref s=" << s << "\n";
}
