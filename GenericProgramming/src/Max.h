#pragma once

#include <cassert>
#include <string>

// Generic function template to calculate the maximum of two values
template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

inline void TestMax() {
    assert(Max<int>(2, 4) == 4);
    assert(Max<double>(-1.0, -2.0) == -1.0);
    assert(Max<char>('a', 'b') == 'b');
    // works on char type
    assert(Max<bool>(true, false) == true);
    // even works on std::string type as no type traits were specified for the
    // function
    assert(Max<std::string>("hello", "world") == "world");
}
