/*
 * Arrays.cpp
 *
 */
#include <iostream>

#ifndef FORMAT_ARRAY_END
#define ARRAY_COMPLETION_COUT std::cout << "}" << std::endl;
#endif

constexpr int LENGTH{6};

int main() {
    // zero-initialized array
    int zeroes[6]{};

    std::cout << "zeroes[" << LENGTH << "] { ";

    // get number of elements via sizeof(zeroes)/sizeof(zeroes[0]) or
    // _countof(zeroes);
    for (int i = 0, len = sizeof(zeroes) / sizeof(zeroes[0]); i < len; i++) {
        std::cout << zeroes[i] << " ";
    }
    ARRAY_COMPLETION_COUT

    // Array can have initialization within declaration
    int hundreds[LENGTH]{100, 200, 300, 400, 500, 600};

    std::cout << "hundreds[" << LENGTH << "] { ";

    // Array supports range-based for loop
    for (int h : hundreds) {
        std::cout << h << " ";
    }
    ARRAY_COMPLETION_COUT

    // multi-dimensional array with 2 rows and 4 columns in the example and some
    // element have no initializing values
    long multi[2][4]{{
                         1,
                         2,
                         3,
                     },
                     {
                         7,
                         11,
                     }};
    std::cout << "multi=" << multi << std::endl;

    // c-style string including terminating '\0'
    char c_string[15]{"C-style string"};
    std::cout << "c_string=" << c_string << std::endl;

    // wide string where each character takes 2 bytes
    wchar_t wide_c_string[]{L"Wide string"};
    std::cout << "wide_c_string=" << wide_c_string << std::endl;

    return 0;
}
