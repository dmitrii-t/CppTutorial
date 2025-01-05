#pragma once

#include <iostream>

using std::cout;

class SharedCopy {
public:
    SharedCopy(int val);
    ~SharedCopy();
    SharedCopy(SharedCopy& source);
    SharedCopy& operator=(SharedCopy& source);

private:
    int*       numberptr_;
    static int instancecnt_;
};

int SharedCopy::instancecnt_ = 0;

SharedCopy::SharedCopy(int val) {
    numberptr_  = (int*)malloc(sizeof(int));
    *numberptr_ = val;
    ++instancecnt_;
    cout << "resource allocated at address " << numberptr_ << '\n';
}

SharedCopy::~SharedCopy() {
    --instancecnt_;
    if (instancecnt_ == 0) {
        free(numberptr_);
        cout << "resource freed at address " << numberptr_ << '\n';
    } else {
        cout << "instance at address " << this
             << " goes out of scope with instancecnt_ = " << instancecnt_ << '\n';
    }
}

SharedCopy::SharedCopy(SharedCopy& source) {
    numberptr_ = source.numberptr_;
    ++instancecnt_;
    cout << instancecnt_ << " instances with handles to address " << numberptr_
         << " with *numberptr_ = " << *numberptr_ << '\n';
}

SharedCopy& SharedCopy::operator=(SharedCopy& source) {
    numberptr_ = source.numberptr_;
    ++instancecnt_;
    cout << instancecnt_ << " instances with handles to address " << numberptr_
         << " with *numberptr_ = " << *numberptr_ << '\n';
    return *this;
}

void TestSharedCopy() {
    cout << "-- Shared copying\n";
    SharedCopy source(42);
    SharedCopy destination1 = source;
    SharedCopy destination2(source);
    SharedCopy destination3(source);
}