#include "../include/DeepCopying.hpp"
#include "../include/ExclusiveOwnership.hpp"
#include "../include/NoCopying.hpp"
#include "../include/SharedCopying.hpp"

// Rule of Three:
// If a class needs to have an overloaded copy constructor, copy
// assignment operator, destructor, then it must also implement

int main() {
    // NoCopyingTest();
    ExclusiveCopyingTest();
    DeepCopyingTest();
    TestSharedCopy();
    return 0;
}
