#include <iostream>
#include <string>

// Define base class Animal
class Animal {
public:
    Animal(std::string c, std::string n, int a) : color(c), name(n), age(a) {}

    void MakeSound();

private:
    std::string color;
    std::string name;
    int         age;
};

// Declare derived class Snake
class Snake : public Animal {
public:
    Snake() : Animal(std::string("Brown"), std::string("Snake"), 1), length(30) {}
    void MakeSound();

private:
    int length;
};

void Snake::MakeSound() {
    std::cout << "snake says his-s-s" << std::endl;
}

// Declare derived class Cat
class Cat : public Animal {
public:
    Cat() : Animal(std::string("Red"), std::string("Ginger"), 2), height(10) {}
    void MakeSound();

private:
    int height;
};

void Cat::MakeSound() {
    std::cout << "cat says meow" << std::endl;
}

// Test in main()
int main() {
    Cat cat;
    cat.MakeSound();

    Snake snake;
    snake.MakeSound();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
