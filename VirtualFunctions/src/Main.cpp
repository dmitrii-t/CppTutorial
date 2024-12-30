// Example solution for Shape inheritance
#include <cassert>
#include <cmath>
#include <iostream>

// Define pi
#define PI 3.1415927

// Define the abstract class Shape
class Shape {
public:
    // Define public virtual functions Area() and Perimeter()
    // Append the declarations with = 0 to specify PURE virtual functions
    // (otherwise you'll get REGULAR virtual functions)

    // Regular virtual (virtual float Area() const;): "Derived classes can
    // override this" Pure virtual (virtual float Area() const = 0;): "Derived
    // classes must override this"

    virtual float Area() const      = 0;
    virtual float Perimeter() const = 0;
};

// Define Rectangle to inherit publicly from Shape
class Rectangle : Shape {
public:
    // Override virtual base class functions Area() and Perimeter()
    float Area() const override;
    float Perimeter() const override;

    // Declare public constructor
    Rectangle(float w, float h) : wigth(w), height(h) {};

private:
    // Declare private attributes width and height
    const float wigth;
    const float height;
};

float Rectangle::Area() const {
    return wigth * height;
}

float Rectangle::Perimeter() const {
    return 2 * wigth + 2 * height;
}

// Define Circle to inherit from Shape
class Circle : Shape {
public:
    // Override virtual base class functions Area() and Perimeter()
    float Area() const override;
    float Perimeter() const override;

    // Declare public constructor
    Circle(float r) : radius(r) {}

private:
    // Declare private member variable radius
    const float radius;
};

float Circle::Area() const {
    return PI * radius * radius;
}

float Circle::Perimeter() const {
    return 2.f * PI * radius;
}

// Test in main()
int main() {
    double epsilon = 0.1;  // useful for floating point equality

    // Tests that should not compile when PURE virtual functions are declared
    // Shape shape{};

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);

    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
