#include <iostream>
#include <cassert>
#define _USE_MATH_DEFINES // Must come before cmath to get M_PI
#include <cmath>

class Sphere
{
public:
    Sphere(float radius);

    static float V(float radius)
    {
        return (4.0/3.0) * M_PI * pow(radius, 3);
    }

    float Volume() const;

    void Radius(float radius);
    float Radius(){ return radius; }

private:
    float radius;
};

Sphere::Sphere(float radius)
{
    Radius(radius);
}

void Sphere::Radius(float r)
{
    if (r < 0) { throw std::out_of_range("Radius"); }
    radius = r;
}

float Sphere::Volume() const
{
    return (4.0/3.0) * M_PI * pow(radius, 3);
}

int main()
{
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
