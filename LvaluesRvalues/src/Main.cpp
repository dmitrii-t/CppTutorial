/*
 * LvaluesRvalues.cpp
 */

#include <iostream>

void func(int& lvalue) { std::cout << "lvalue reference" << '\n'; }
void func(int&& rvalue) { std::cout << "rvalue reference" << '\n'; }

class MyClass
{
public:
    MyClass() { std::cout << "Constructor" << '\n'; }
    ~MyClass() { std::cout << "Destructor" << '\n'; }
    MyClass(const MyClass&) { std::cout << "Copy Constructor" << '\n'; }
    MyClass(MyClass&&) noexcept { std::cout << "Move Constructor" << '\n'; }
};


int main(int argc, char* argv[])
{
    std::cout << "LvaluesRvalues.cpp" << '\n';

    //  Lvalue (locator value) refers to an object that occupies a specific location in memory
    //  (i.e., it has an identifiable address).
    int x = 10; // 'x' is an lvalue
    x = 20; // 'x' is an lvalue
    int* p = &x; // 'x' has a memory address, so '&x' is valid

    //  Rvalue (right value) is a temporary value that does not persist beyond the expression that uses it.
    //  Rvalues are typically literals, temporary objects, or the results of expressions.
    int y = 10; // '10' is an rvalue
    int z = x + y; // 'x + y' is an rvalue
    // int* q = &(x + y); // Error! 'x + y' is an rvalue and doesn't have a memory address


    // Examples

    // 1. Function Overloading with References:
    int a = 5;
    func(a); // Calls lvalue reference version
    func(5); // Calls rvalue reference version

    // 2. Move semantics
    MyClass obj1;
    MyClass obj2 = std::move(obj1); // Calls move constructor

    return 0;
}
