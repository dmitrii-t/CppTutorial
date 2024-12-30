#pragma once

#include <cassert>
#include <vector>

class Matrix {
public:
    // !returning a reference to an element within a vector
    // allows assigning value to that element
    int& operator()(int row, int column) {
        return values[row * columns + column];
    }

    // !const is a part of method signature
    // it's the only difference in signature with the method above
    int operator()(int row, int column) const {
        return values[row * columns + column];
    }

    // Changed parameter to const reference
    Matrix operator+(const Matrix& other) const {
        // Create new matrix with same dimensions
        Matrix result(rows, columns);

        // Fixed loop syntax using normal for loops
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                result(r, c) = (*this)(r, c) + other(r, c);
            }
        }
        return result;
    }

    Matrix(int r, int c) : rows(r), columns(c), values(r * c) {}

private:
    int rows;
    int columns;

    // linear storage
    std::vector<int> values;
};

inline void TestMatrix() {
    Matrix matrix{2, 2};
    // !The example below returns a reference to an element within vector
    // which we use to assign a value
    matrix(0, 0) = 4;
    assert(matrix(0, 0) == 4);

    Matrix m1{2, 2};
    m1(0, 0) = 1;
    m1(0, 1) = 0;
    m1(1, 0) = 0;
    m1(1, 1) = 1;

    Matrix m2{2, 2};
    m2(0, 0) = 1;
    m2(0, 1) = 0;
    m2(1, 0) = 0;
    m2(1, 1) = 1;

    Matrix m3 = m1 + m2;
    assert(m3(0, 0) == 2);
    assert(m3(1, 1) == 2);
}
