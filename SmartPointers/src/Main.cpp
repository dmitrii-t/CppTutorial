#include <iostream>
#include <memory>

using std::cout;
using std::shared_ptr;
using std::unique_ptr;

class A {
public:
    A(int number) : number_(number) {}
    void print_number() {
        cout << ", managed object " << this << " with number_=" << number_ << '\n';
    }

private:
    int number_;
};

void RawPointer() {
    int* raw = new int;  // create a raw pointer on the heap
    *raw     = 1;        // assign a value
    delete raw;          // delete the resource again
}

void UniquePointer() {
    unique_ptr<int> unique(new int);  // create a unique pointer on the stack
    *unique = 2;                      // assign a value
    // delete is not neccessary
}

void SharedPointer() {
    shared_ptr<int> shared1(new int);
    cout << "shared pointer count = " << shared1.use_count() << '\n';

    {
        shared_ptr<int> shared2 = shared1;
        cout << "shared pointer count = " << shared1.use_count() << '\n';
    }

    cout << "shared pointer count = " << shared1.use_count() << '\n';
}

void WeakPointer() {
    shared_ptr<int> mySharedPtr(new int);
    cout << "shared pointer count = " << mySharedPtr.use_count() << '\n';

    std::weak_ptr<int> myWeakPtr1(mySharedPtr);
    std::weak_ptr<int> myWeakPtr2(myWeakPtr1);
    cout << "shared pointer count = " << mySharedPtr.use_count() << '\n';
}

void ConvertingSmartPointer() {
    // construct a unique pointer
    unique_ptr<int> uniquePtr(new int);

    // (1) shared pointer from unique pointer
    shared_ptr<int> sharedPtr1 = std::move(uniquePtr);

    // (2) shared pointer from weak pointer
    std::weak_ptr<int> weakPtr(sharedPtr1);
    shared_ptr<int>    sharedPtr2 = weakPtr.lock();

    // (3) raw pointer from shared (or unique) pointer
    int* rawPtr = sharedPtr2.get();
    delete rawPtr;
}

void func(unique_ptr<A> ptr) {
    cout << "func.&ptr=" << &ptr;
    ptr->print_number();
}

void func(shared_ptr<A> ptr) {
    cout << "func.&ptr(ref_cnt=" << ptr.use_count() << ")=" << &ptr;
    ptr->print_number();
}

void PassignUniquePointer() {
    cout << "-- Unique Pointer Example" << '\n';
    unique_ptr<A> uniquePtr = std::make_unique<A>(23);
    cout << "uniquePtr=" << &uniquePtr;
    uniquePtr->print_number();

    // move semantic is needed when using Unique Pointers
    func(std::move(uniquePtr));
    if (uniquePtr) {
        uniquePtr->print_number();
    }

    cout << "-- Shared Pointer Example" << '\n';
    shared_ptr<A> sharedPtr = std::make_shared<A>(23);
    cout << "shared_ptr(ref_cnt=" << sharedPtr.use_count() << ")=" << &sharedPtr;
    sharedPtr->print_number();

    // copy constructor is used using Shared Pointers
    func(sharedPtr);

    cout << "shared_ptr(ref_cnt=" << sharedPtr.use_count() << ")=" << &sharedPtr;
    sharedPtr->print_number();
}

int main() {
    PassignUniquePointer();
    return 0;
}
