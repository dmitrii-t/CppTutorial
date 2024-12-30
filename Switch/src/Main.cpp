/*
 *
 *
 */
#include <iostream>

int main() {
    char letter{};

    std::cout << std::endl << "Enter a small letter: ";

    // reads the input
    std::cin >> letter;

    // (letter >= 'a' && letter <= 'z') zeroes out the expression it the input was
    // outside of a-z range
    switch (letter * (letter >= 'a' && letter <= 'z')) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            std::cout << std::endl << "You entered a vowel.";
            break;
        case 0:
            std::cout << std::endl << "That is not a small letter.";
            break;
        default:
            std::cout << std::endl << "You entered a consonant.";
    }
    std::cout << std::endl;
    return 0;
}
