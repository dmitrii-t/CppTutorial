#pragma once
#include <cassert>

// Variadic template function to calculate the average of a list of numbers
template <typename... Args> double Average(Args... args) {

  // The code below is a fold expression that sums up all the arguments
  return static_cast<double>((... + args)) / sizeof...(args);
}

inline void TestAverage() { assert(Average(2, 4, 6) == 4.); }
