#include <cassert>
#include <sstream>
#include <string>

// Genetic class template
template <typename KeyType, typename ValueType> class Mapping {
public:
  Mapping(const KeyType key, const ValueType value) : key(key), value(value) {}

  std::string Print() const {
    std::ostringstream stream;
    stream << key << ": " << value;
    return stream.str();
  }

private:
  KeyType key;
  ValueType value;
};

inline void TestMapping() {
  Mapping<std::string, int> mapping("age", 20);
  assert(mapping.Print() == "age: 20");
}
