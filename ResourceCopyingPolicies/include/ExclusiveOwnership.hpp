#pragma once

#include <iostream>

using std::cout;

class ExclusiveCopy {
public:
    ExclusiveCopy();
    ~ExclusiveCopy();
    ExclusiveCopy(ExclusiveCopy& source);
    ExclusiveCopy& operator=(ExclusiveCopy& source);

private:
    int* numberptr_;
};

ExclusiveCopy::ExclusiveCopy() {
    numberptr_ = (int*)malloc(sizeof(int));
    cout << "resource allocated" << '\n';
}
ExclusiveCopy::~ExclusiveCopy() {
    if (numberptr_ != nullptr) {
        free(numberptr_);
        cout << "resource freed" << '\n';
    }
}
ExclusiveCopy::ExclusiveCopy(ExclusiveCopy& source) {
    numberptr_ = source.numberptr_;  // transfers ownership from the source to the copy
    source.numberptr_ = nullptr;     // the source pointer gets set to nullptr
    printf(
        "transferred ownership of the resource %p to the copy %p from the source "
        "%p\n",
        this->numberptr_, this, &source);
}
ExclusiveCopy& ExclusiveCopy::operator=(ExclusiveCopy& source) {
    numberptr_        = source.numberptr_;
    source.numberptr_ = nullptr;
    printf(
        "transferred ownership of the resource %p to the copy %p from the source "
        "%p\n",
        this->numberptr_, this, &source);

    return *this;
}

void ExclusiveCopyingTest() {
    cout << "-- Exclusive copying\n";
    ExclusiveCopy source;
    ExclusiveCopy copy1(source);
    ExclusiveCopy copy2 = source;
}