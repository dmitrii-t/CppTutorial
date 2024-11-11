#include <cassert>
#include <complex>
#include <iostream>

// Define pi
#define PI 3.14159f

// Define Line Class
class LineSegment {
public:
  LineSegment(int l) : length(l) {}

  // Define public attribute length
  float length;
};

// Define Circle subclass
class Circle {
public:
  // Define public setRadius() and getArea()
  float Area();

  void Radius(LineSegment r) { radius = r; }

  Circle(LineSegment r) : radius(r) {};

private:
  LineSegment radius;
};

float Circle::Area() { return PI * std::pow(radius.length, 2); }

// Test in main()
int main() {
  LineSegment radius{3};
  Circle circle{radius};
  assert(int(circle.Area()) == 28);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
