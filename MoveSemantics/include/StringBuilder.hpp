/*
 * Move semantics is all about transferring ownership from one object to
 * another.
 *
 */

#pragma once

#include <cassert>
#include <cstring>
#include <iostream>
#include <utility>

using std::string;

class StringBuilder {
public:
    // Custom constructor
    StringBuilder(size_t capacity = 16)
        : Size(0), Capacity(capacity), Data(new char[capacity]) {
        Data[0] = '\0';
    }

    // Destructor
    ~StringBuilder() {
        delete[] Data;
    }

    // Move constructor
    StringBuilder(StringBuilder&& source) noexcept
        : Size(source.Size), Capacity(source.Capacity), Data(source.Data) {
        // IMPORTANT
        // Won't be able to assign new values with lvalue reference StringBuilder&
        // source
        source.Size     = 0;        // transferring ownership to the copy
        source.Capacity = 0;        // transferring ownership to the copy
        source.Data     = nullptr;  // transferring ownership to the copy
    }

    // Move Assignment Operator
    StringBuilder& operator=(StringBuilder&& source) noexcept {
        if (this != &source) {
            delete[] Data;

            Data     = source.Data;
            Size     = source.Size;
            Capacity = source.Capacity;

            source.Data     = nullptr;  // transferring ownership to the copy
            source.Size     = 0;
            source.Capacity = 0;
        }
        return *this;
    }

    void Append(const char* str) {
        size_t len = std::strlen(str);
        EnsureCapacity(Size + len + 1);
        std::memcpy(Data + Size, str, len + 1);
        Size += len;
    }

    const char* toString() const {
        return Data;
    }

private:
    void EnsureCapacity(size_t minCapacity) {
        if (minCapacity > Capacity) {
            size_t newCapacity =
                (Capacity * 2) < minCapacity ? minCapacity : (Capacity * 2);
            char* newData = new char[newCapacity];

            std::memcpy(newData, Data, Size + 1);
            delete[] Data;

            Data     = newData;
            Capacity = newCapacity;
        }
    }

    size_t Size;
    size_t Capacity;
    char*  Data;
};

void TestStringBuilder() {
    StringBuilder sb;
    sb.Append("Ex4_");
    sb.Append("MoveSemantic");
    sb.Append("\n");

    StringBuilder copy = std::move(sb);  // explicit invocation of Move COnstructor
    // at this point sb is no longer valid

    assert(string("Ex4_MoveSemantic\n") == copy.toString());
}
