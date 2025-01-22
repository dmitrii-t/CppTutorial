#pragma once

#include <cassert>

// Define Point class
class Point {
public:
    // Define + operator overload
    Point operator+(const Point& other) const {
        return Point{x + other.x, y + other.y};
    }

    // Define public constructor
    Point(int xcoord, int ycoord) : x(xcoord), y(ycoord) {}

    // Declare attributes x and y
    const int x;
    const int y;
};

inline void TestPoint() {
    Point p1(10, 5), p2(2, 4);
    Point p3 = p1 + p2;  // An example call to "operator +";
    assert(p3.x == p1.x + p2.x);
    assert(p3.y == p1.y + p2.y);
}
