#pragma once

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;

class Student {
public:
    // constructor
    Student(string name, int grade, float gpa);

    // accessors
    string Name() {
        return name;
    }
    float Gpa() {
        return gpa;
    }
    int Grade() {
        return grade;
    }

    // mutators
    void Name(string);
    void Grade(int);
    void Gpa(float);

private:
    string name;
    float  gpa;
    int    grade;
};

Student::Student(string name, int grade, float gpa) : name(name) {
    Grade(grade);
    Gpa(gpa);
}

void Student::Grade(int grade) {
    if (grade < 0) {
        throw std::out_of_range("Grade");
    }
    if (grade > 12) {
        throw std::out_of_range("Grade");
    }
    this->grade = grade;
}

void Student::Gpa(float gpa) {
    if (gpa < 0) {
        throw std::out_of_range("Gpa");
    }
    if (gpa > 4.0) {
        throw std::out_of_range("Gpa");
    }
    this->gpa = gpa;
}

void Student::Name(string name) {
    this->name = name;
}

void TestStudent() {
    // Test valid constructor and accessors
    Student bob{"Bob", 4, 1.0};
    assert(bob.Name() == "Bob");
    assert(bob.Grade() == 4);
    assert(bob.Gpa() == 1.0);

    // Test mutators with valid values};
    Student bobby{"Bobby", 6, 3.0};
    bobby.Name("Bobby");
    assert(bobby.Name() == "Bobby");
    bobby.Grade(5);
    assert(bobby.Grade() == 5);
    bobby.Gpa(3.5);
    assert(bobby.Gpa() == 3.5);

    // Test invalid grade (negative)
    bool caught = false;
    try {
        Student invalid{"bob", -1, 2.0};
    } catch (const out_of_range& e) {
        caught = true;
        assert(string(e.what()) == "Grade");
    }
    assert(caught);

    // Test invalid grade (too high)
    caught = false;
    try {
        Student invalid{"bob", 13, 2.0};
    } catch (const out_of_range& e) {
        caught = true;
        assert(string(e.what()) == "Grade");
    }
    assert(caught);

    // Test invalid GPA (negative)
    caught = false;
    try {
        Student invalid{"bob", 5, -0.1};
    } catch (const out_of_range& e) {
        caught = true;
        assert(string(e.what()) == "Gpa");
    }
    assert(caught);

    // Test invalid GPA (too high)
    caught = false;
    try {
        Student invalid{"bob", 5, 4.1f};
    } catch (const out_of_range& e) {
        caught = true;
        assert(string(e.what()) == "Gpa");
    }
    assert(caught);

    // Test mutator for invalid grade
    caught = false;
    try {
        bobby.Grade(-1);
    } catch (const out_of_range& e) {
        caught = true;
        assert(string(e.what()) == "Grade");
    }
    assert(caught);

    // Test mutator for invalid GPA
    caught = false;
    try {
        bobby.Gpa(5.0);
    } catch (const out_of_range& e) {
        caught = true;
        assert(string(e.what()) == "Gpa");
    }
    assert(caught);

    // Verify original object wasn't modified by failed mutations
    assert(bobby.Grade() == 5);
    assert(bobby.Gpa() == 3.5);

    cout << "All tests passed!" << '\n';
}
