// Vectors are similar to array lists or dynamic lists in other languages.
// They have dynamic size and provide random constant time O(1) access to the
// elements.
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

constexpr char SPACE[] = " ";

int main() {
    // Declaration
    vector<int> vec1{10, 20, 30};

    // Element Access
    std::cout << "Vector allows constant time O(1) access to the elements; vec1: "
              << SPACE;
    for (size_t i = 0; i < vec1.size(); i++)  // NOLINT(modernize-loop-convert)
    {
        // Vectors allow constant time O(1) access
        std::cout << vec1[i] << SPACE;
    }
    std::cout << std::endl;

    // Modern C++ Loop
    std::cout << "Vector allows modern C++ loop; vec1: " << SPACE;
    for (auto v : vec1) {
        std::cout << v << SPACE;
    }
    std::cout << std::endl;

    // Dynamic Size
    std::cout << "Vector has dynamic size, vec1.push_back(40); vec1: " << SPACE;
    vec1.push_back(40);
    for (auto v : vec1) {
        std::cout << v << SPACE;
    }
    std::cout << std::endl;

    // Vector gets stored in heap
    std::cout << "Vector gets stored in HEAP; vec1.data() // address of the data "
                 "on heap: "
              << vec1.data() << std::endl;

    // Iterator Support
    std::cout << "Vector supports Iterator; auto i = vec1.begin(); i != "
                 "vec1.end(); i++ { *i += 1 }: ";
    for (auto i = vec1.begin(); i != vec1.end(); i++) {
        *i += 1;  // Modifies the element
    }
    for (auto i = vec1.begin(); i != vec1.end(); i++) {
        std::cout << *i << SPACE;
    }
    std::cout << std::endl;

    // STL Functions
    std::cout << "Vector is compatible with STL functions; "
                 "std::reverse(vec1.begin(), vec1.end()): "
              << SPACE;
    std::reverse(vec1.begin(), vec1.end());
    for (auto v : vec1) {
        std::cout << v << SPACE;
    }
    std::cout << std::endl;

    // Move Semantics
    vector<int> vec2 = std::move(vec1);
    std::cout << "Vector allows move semantics, vector<int> vec2 = std::move(vec1), "
                 "all elements moved to vec2 leaving vec1 empty, vec1.size(): "
              << vec1.size() << std::endl;

    return 0;
}
