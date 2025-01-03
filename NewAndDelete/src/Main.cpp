#include <stdlib.h>

#include <iostream>

using std::cout;

class A {
public:
    A() {
        cout << "constructor is called\n";
        // number_ = (int*)malloc(sizeof(int));
        number_ = new int(0);
    }
    ~A() {
        cout << "destructor is called\n";
        // free(number_);
        delete number_;
    }
    void setNumber(int number) {
        *number_ = number;
        cout << "Number: " << *number_ << "\n";
    }

    int* number_;
};

int main() {
    cout << "1: allocate memory using malloc" << '\n';
    A* a1 = (A*)malloc(
        sizeof(A));  // allocates memory for the number_ at a different address
                     // a1=000001ca905b1a80, a1.number_=000001ca905d6090 does not call a
                     // constructor returns unsafe void pointer
    printf("a1=%p, a1.number_=%p\n", a1, a1->number_);
    a1->setNumber(42);
    free(a1);
    // prints out
    // 1: allocate memory using malloc
    // a1=000001fa607c2a90, a1.number_=000001fa607c6ff0
    // Number: 42
    cout << '\n';

    cout << "2: allocate memory using new" << '\n';
    A* a2 = new A();  // allocates contiguous memory a2=000001ca905b1a80,
                      // a2.number_=000001ca905b1aa0 executes the constructor return a
                      // correct pointer type A* automatically
    printf("a2=%p, a2.number_=%p\n", a2, a2->number_);
    a2->setNumber(42);
    delete a2;
    // prints out
    // 2: allocate memory using new
    // constructor is called
    // a2=000001fa607c2a90, a2.number_=000001fa607c2ab0
    // Number: 42
    // destructor is called
    cout << '\n';

    cout << "3: placement new constructor" << '\n';
    void* memory = malloc(sizeof(A));  // pre-allocates memory
    A* a3 = new (memory) A;  // calls the constructor at a pre-allocated memory location
    printf("a3=%p, a3.number_=%p\n", a3, a3->number_);
    a3->~A();
    free(memory);            // fees memory at *memory pointer,
    // prints out
    // 3: placement new constructor
    // constructor is called
    // a3=000001fa607c2a90, a3.number_=000001fa607c2ab0
    // destructor is called
    // make: *** [Makefile:24: exec] Segmentation fault

    return 0;
}
