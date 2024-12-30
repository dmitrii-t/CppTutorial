// Example solution for Rectangle and Square friend classes
#include <cassert>
#include <iostream>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
public:
    // Add public constructor to Square, initialize side
    Square(int s) : side(s) {};

private:
    // Add friend class Rectangle
    friend class Rectangle;
    // Add private attribute side to Square
    int side;
};

// Define class Rectangle
class Rectangle {
public:
    // Add public declarations of the class constructor and Area() method
    Rectangle(const Square& s);
    int Area() const;

private:
    // Add private attributes width, height
    int width;
    int height;
};

// Outside class Rectangle and using class scope of resolution (::)
// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(const Square& s) : width(s.side), height(s.side) {};

// Define Area() to compute area of Rectangle
int Rectangle::Area() const {
    return width * height;
}

//  Update main() to pass the tests
int main() {
    Square    square{4};
    Rectangle rectangle{square};
    assert(rectangle.Area() == 16);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
