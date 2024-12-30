#pragma once

#include <cassert>
#include <iostream>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
  // public class members
public:
  // constructor
  Pyramid(int l, int w, int h) {
    Length(l);
    Width(w);
    Height(h);
  }

  // accessors
  int Length() { return length; }
  int Width() { return width; }
  int Height() { return height; }

  // mutators
  void Length(int l);
  void Width(int w);
  void Height(int h);

  // public Volume() function
  int Volume() { return Base() * height / 3; }

  int Base() { return length * width; }

  // private class members
private:
  int length;
  int width;
  int height;
};

void Pyramid::Length(int l) {
  if (l < 0) {
    throw std::out_of_range("Length");
  }
  length = l;
}

void Pyramid::Width(int w) {
  if (w < 0) {
    throw std::out_of_range("Width");
  }
  width = w;
}

void Pyramid::Height(int h) {
  if (h < 0) {
    throw std::out_of_range("Height");
  }
  height = h;
}

// Test
int TestPyramid() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
