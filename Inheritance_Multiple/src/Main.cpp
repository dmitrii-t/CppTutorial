#include "AmphibiousCar.h"
#include "CatPet.h"
#include <cassert>
#include <iostream>

int main() {
  Car car;
  Boat boat;
  AmphibiousCar duck;

  assert(duck.Drive() == car.Drive());
  assert(duck.Cruise() == boat.Cruise());

  Cat cat;
  cat.color = "black";
  cat.age = 10;
  cat.name = "Max";

  assert(cat.color == "black");
  assert(cat.age == 10);
  assert(cat.name == "Max");

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
