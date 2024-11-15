#include "Matrix.cpp"
#include "Point.cpp"
#include <cassert>
#include <iostream>

int main() {
  Matrix matrix{2, 2};
  // !The example below returns a reference to an element within vector
  // which we use to assign a value
  matrix(0, 0) = 4;
  assert(matrix(0, 0) == 4);

  Matrix m1{2, 2};
  m1(0, 0) = 1;
  m1(0, 1) = 0;
  m1(1, 0) = 0;
  m1(1, 1) = 1;

  Matrix m2{2, 2};
  m2(0, 0) = 1;
  m2(0, 1) = 0;
  m2(1, 0) = 0;
  m2(1, 1) = 1;

  Matrix m3 = m1 + m2;
  assert(m3(0, 0) == 2);
  assert(m3(1, 1) == 2);

  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
