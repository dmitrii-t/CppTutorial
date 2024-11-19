#pragma once
#include <cassert>
#include <type_traits>

// Generic function template to calculate the product of two values
template <typename T>

// the code below restricts the function to only accept arithmetic types via
// using type_traits
std::enable_if_t<std::is_arithmetic<T>::value &&
                     !std::is_same<T, bool>::value &&
                     !std::is_same<T, char>::value,
                 T>
Product(T a, T b) {
  return a * b;
}

inline void TestProduct() {
  // type can be deducted by the compiler
  assert(Product(0, 2) == 0);

  assert(Product<int>(1, 2) == 2);
  assert(Product<float>(10., 10.) == 100.);
  assert(Product<double>(0.0, 3.14) == 0.);

  // the code below is tot allowed because the function template only accepts
  // arithmetic types
  // assert(Product<bool>(true, false) == false);
}
