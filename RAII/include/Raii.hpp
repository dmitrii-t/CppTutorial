#pragma once

#include <iostream>

using std::cout;

class I {
public:
    // Constructor
    I(const int& p) : ptr_(new int(p)) {}

    // Destructor
    ~I() {
        cout << "resource " << *ptr_ << " deallocated" << '\n';
        delete ptr_;
    }

    // Copy constructor (Rule of Three)
    I(const I& other) : ptr_(new int(*other.ptr_)) {}

    // Copy assignment operator (Rule of Three)
    I& operator=(const I& other) {
        if (this == &other) {
            return *this;
        }

        int* new_ptr = new int(*other.ptr_);
        delete ptr_;
        ptr_ = new_ptr;

        return *this;
    }

    // Move constructor (Rule of Five)
    I(I&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    // Move assignment operator (Rule of Five)
    I& operator=(I&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete ptr_;
        ptr_       = other.ptr_;
        other.ptr_ = nullptr;

        return *this;
    }

    int& operator*() {
        return *ptr_;
    }
    const int& operator*() const {
        return *ptr_;
    }

private:
    int* ptr_;
};

void ExRaii() {
    cout << "\n-- RAII showcase" << '\n';

    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < std::size(den); ++i) {
        // allocate the resource on the stack
        I en(i);

        // use the resource
        cout << *en << "/" << den[i] << " = " << *en / den[i] << '\n';
    }
}