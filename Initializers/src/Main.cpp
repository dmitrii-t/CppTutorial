/*
 * Variable initialization
 *
 * There are few way to initialize a variable in C++
 *
 * default initializer- initializer that is automatically used to initialize a
 * variable if no other initializer is provided copy initializer - initializer
 * that copies the value of another variable functional-style initializer
 * initializer that uses parentheses brackets to initialize a variable uniform
 * initializer - (since C++11) initializer that uses figure brackets to
 * initialize a variable
 *
 */
#include <iostream>
#include <string>

int defaultInitializer;
int copyInitializer = 10;
int funcInitializer(20);
int uniformInitializer{30};

class Person {
public:
    // Constructor with uniform initializer (or initializer list)
    Person(std::string name, int age) : name{name}, age{age} {}

    // Constructor with function initializer
    Person(std::string name) : name(name), age(0) {}

private:
    std::string name;
    int         age;
};

// entry point
int main() {
    for (int i{0}; i < 5; ++i) {
        // Using uniform initialization with rvalue
        const int value{i * 2};
        std::cout << "Iteration " << i << ": " << value << std::endl;
    }

    return 0;
}
