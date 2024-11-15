/*
 * MoveSemantics.cpp
 *
 * Move semantics is all about transferring ownership from one object to
 * another.
 *
 */
#include <cstring>
#include <iostream>
#include <utility>

class StringBuilder {
public:
  StringBuilder(size_t capacity = 16)
      : Size(0), Capacity(capacity), Data(new char[capacity]) {
    Data[0] = '\0';
  }

  // Ownership transfer
  StringBuilder(StringBuilder &&other) noexcept
      : Size(other.Size), Capacity(other.Capacity), Data(other.Data) {
    // Won't be able to reassign with StringBuilder& other
    other.Size = 0;
    other.Capacity = 0;
    other.Data = nullptr;
  }

  ~StringBuilder() { delete[] Data; }

  // Move Assignment Operator
  StringBuilder &operator=(StringBuilder &&other) noexcept {
    if (this != &other) {
      delete[] Data;

      Data = other.Data;
      Size = other.Size;
      Capacity = other.Capacity;

      other.Data = nullptr;
      other.Size = 0;
      other.Capacity = 0;
    }
    return *this;
  }

  void Append(const char *str) {
    size_t len = std::strlen(str);
    EnsureCapacity(Size + len + 1);
    std::memcpy(Data + Size, str, len + 1);
    Size += len;
  }

  const char *toString() const { return Data; }

private:
  size_t Size;
  size_t Capacity;
  char *Data;

  void EnsureCapacity(size_t minCapacity) {
    if (minCapacity > Capacity) {
      size_t newCapacity =
          (Capacity * 2) < minCapacity ? minCapacity : (Capacity * 2);
      char *newData = new char[newCapacity];

      std::memcpy(newData, Data, Size + 1);
      delete[] Data;

      Data = newData;
      Capacity = newCapacity;
    }
  }
};

int main() {
  StringBuilder sb;
  sb.Append("Ex4_");
  sb.Append("MoveSemantic");
  sb.Append("\n");

  StringBuilder other = std::move(sb);
  // at this point sb is no longer valid

  std::cout << other.toString();
  return 0;
}
