#include <cassert>
#include <exception>
#include <iostream>

using std::cout;
using std::string;

class A {
public:
    A() {
        number_ = (int*)malloc(sizeof(int));
    }

    ~A() {
        free(number_);
    }

    void printOwnAddress(string prefix) {
        cout << prefix << " own address on the stack is " << this << '\n';
    }
    void printMemberAddress(string prefix) {
        cout << prefix << " managing memory block on the heap at " << number_ << '\n';
    }

    int* number_;
};

int main() {
    // instantiate object 1
    A a1;
    a1.printOwnAddress("orig");
    a1.printMemberAddress("orig");

    // copy object 1 into object 2
    A a2(a1);  // copy constructor
    a2.printOwnAddress("copy");
    a2.printMemberAddress("copy");

    assert(a1.number_ != a2.number_);
    // the program will crash at exit as a1.number_ == a2.number_ which means
    // when the destructor of a2 called the address at number_ has been freed already
}