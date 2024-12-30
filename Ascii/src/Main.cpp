/* Ascii.cpp
 *
 * Exercise 2: The ASCII character set.
 *
 * ASCII codes for 'A'-'Z' and 'a'-'z' are two groups of consecutive
 * numerical codes, decimal 65-90 (A-Z) and 97-122 (a-z), respectively,
 * so the expression 'a' - 'A' represents the value to be added to an uppercase
 * letter to get the equivalent lowercase letter, which is 32. Thus, if you add
 * 32 to the code value for 'K', which is 75, you get 107, which is the code
 * value for 'k'.
 */
#include <iostream>

constexpr int CASE_DISTANCE = 32;

int main() {
    for (char i{65}, j{static_cast<char>(i + CASE_DISTANCE)}; i <= 90;
         i++, j = i + CASE_DISTANCE) {
        std::cout << i << " = char(" << static_cast<int>(i)
                  << ")"  // printing out capital letter
                  << ", " << j << " = char(" << static_cast<int>(j)
                  << ")"  // printing out lowercase letter
                  << std::endl;
    }

    return 0;
}
