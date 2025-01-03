#include <stdlib.h>

#include <iostream>

using std::cout;

class A {
public:
    A() {
        cout << "constructor is called\n";
        number_ = new int(0);
    }

    ~A() {
        cout << "destructor is called\n";
        delete number_;
    }

    void* operator new(size_t size) {
        cout << "operator new: allocating " << size << " bytes of memory" << '\n';
        void* p = malloc(size);
        return p;
    }

    void operator delete(void* p) {
        cout << "operator delete: memory is freed again " << '\n';
        free(p);
    }

    void* operator new[](size_t size) {
        std::cout << "operator new: allocating " << size << " bytes of memory"
                  << std::endl;
        void* p = malloc(size);
        return p;
    }

    void operator delete[](void* p) {
        std::cout << "operator delete: memory is freed again " << std::endl;
        free(p);
    }

    int* number_;
};

int main() {
    A* a1 = new A();
    delete a1;
    // prints out
    // operator new: allocating 8 bytes of memory
    // constructor is called
    // destructor is called
    // operator delete: memory is freed again

    A* a2 = new A[3]();
    delete[] a2;
    // prints out
    // operator new: allocating 32 bytes of memory
    // constructor is called
    // constructor is called
    // constructor is called
    // destructor is called
    // destructor is called
    // destructor is called
    // operator delete: memory is freed again

    return 0;
}
