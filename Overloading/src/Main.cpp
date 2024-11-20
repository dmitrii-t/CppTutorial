// Polymorphism describes a paradigm in which a function may behave differently
// depending on how it is called.
#include <cassert>
#include <iostream>
#include <string>

class Dad {};
class Mom {};
class Sis {};
class Bro {};

// Write hello() function
std::string hello([[maybe_unused]] Dad d) { return "hello dad"; }

// Overload hello() three times
std::string hello([[maybe_unused]] Mom m) { return "hello mom"; }

std::string hello([[maybe_unused]] Sis s) { return "hello sis"; }

std::string hello([[maybe_unused]] Bro b) { return "hello brother"; }

// Call hello() from main()
int main() {
  assert(hello(Dad{}) == "hello dad");
  assert(hello(Mom{}) == "hello mom");
  assert(hello(Sis{}) == "hello sis");
  assert(hello(Bro{}) == "hello brother");

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
