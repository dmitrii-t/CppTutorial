#pragma once

#include <iostream>

using std::cout;

class DeepCopy {
public:
    DeepCopy(int val);
    ~DeepCopy();
    DeepCopy(DeepCopy& source);
    DeepCopy& operator=(DeepCopy& source);

private:
    int* numberptr_;
};

DeepCopy::DeepCopy(int val) {
    numberptr_  = (int*)malloc(sizeof(int));
    *numberptr_ = val;
    cout << "resource allocated at address " << numberptr_ << std::endl;
}
DeepCopy::~DeepCopy() {
    free(numberptr_);
    cout << "resource freed at address " << numberptr_ << std::endl;
}
DeepCopy::DeepCopy(DeepCopy& source) {
    numberptr_  = (int*)malloc(sizeof(numberptr_));
    *numberptr_ = *source.numberptr_;
    cout << "resource allocated at address " << numberptr_
         << " with *numberptr_ = " << *numberptr_ << '\n';
}
DeepCopy& DeepCopy::operator=(DeepCopy& source) {
    numberptr_ = (int*)malloc(sizeof(numberptr_));
    cout << "resource allocated at address " << numberptr_
         << " with *numberptr_=" << *numberptr_ << '\n';
    *numberptr_ = *source.numberptr_;
    return *this;
}

void DeepCopyingTest() {
    cout << "-- Deep copying\n";
    DeepCopy source(42);
    DeepCopy dest1(source);
    DeepCopy dest2 = dest1;
}
