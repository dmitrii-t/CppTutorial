#include <cassert>
#include <cmath>
#include <iostream>

#define PI 3.1415927

class Sphere {
public:
  Sphere(double radius);

  static double V(float radius) {
    return (4.0 / 3.0) * PI * std::pow(radius, 3);
  }

  double Volume() const;

  void Radius(double radius);
  double Radius() { return radius; }

private:
  double radius;
};

Sphere::Sphere(double radius) { Radius(radius); }

void Sphere::Radius(double r) {
  if (r < 0) {
    throw std::out_of_range("Radius");
  }
  radius = r;
}

double Sphere::Volume() const { return (4.0 / 3.0) * PI * std::pow(radius, 3); }

int main() {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
