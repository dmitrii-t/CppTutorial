#pragma once

class NoCopyClass1 {
public:
    NoCopyClass1() = default;

private:
    NoCopyClass1(const NoCopyClass1&);
    NoCopyClass1& operator=(const NoCopyClass1&);
};

class NoCopyClass2 {
public:
    NoCopyClass2()                               = default;
    NoCopyClass2(const NoCopyClass2&)            = delete;
    NoCopyClass2& operator=(const NoCopyClass2&) = delete;
};

int NoCopyingTest() {
    [[maybe_unused]] NoCopyClass1 original1;
    // NoCopyClass1 copy1a(original1); // errors with 'NoCopyClass1::NoCopyClass1(const
    // NoCopyClass1&)' is private within this context 22

    // NoCopyClass1 copy1b = original1; // errors with 'NoCopyClass1::NoCopyClass1(const
    // NoCopyClass1&)' is private within this context 26

    [[maybe_unused]] NoCopyClass2 original2;
    // NoCopyClass2 copy2a(original2); // errors with use of deleted function
    // 'NoCopyClass2::NoCopyClass2(const NoCopyClass2&)' 32

    // NoCopyClass2 copy2b = original2; // errors with use of deleted function
    // 'NoCopyClass2::NoCopyClass2(const NoCopyClass2&)' 35

    return 0;
}