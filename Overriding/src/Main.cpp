#include "Animal.h"
#include "Vehicle.h"
#include <cassert>
#include <iostream>

int main() {
  // Test Animal talks
  Dog dog;
  assert(dog.Talk() == "Woof");

  // Test VehicleModel moves
  ParticleModel particle;
  BicycleModel bicycle;

  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);

  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
