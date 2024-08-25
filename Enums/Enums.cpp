/* 
 * Enums in C++
 *
 * There are two ways to declare an enum
 *
 * The old fashion way where enums are declared as constants and
 * the type-safe enums (C++11 and later) where enums are declared as classes
 *
 */
#include <iostream>

// Old fashion way to declare an enum
enum Weekdays { Mon, Tues = 10, Wed, Thurs, Fri, Sat, Sun } today;
// enum Weekends { Sat = 10, Sun }; // This won't compile as the names clash 

// Old fashion way to declare an enum with an initializer
enum Punctuation { Comma = ',', Exclamation = '!', Question = '?' } things;


// Type-safe Eunums (C++11 an later)
enum class Suit { Clubs, Diamonds, Hearts, Spades };

enum class Jewels { Clubs, Diamonds, Hearts, Spades }; // Names don't clash as they are different types

enum class Genstones : unsigned long { Diamonds, Emeralds, Opals, Rubies, Sapphires }; // The enumerator values can be changed (see parent type unsigned long), but are of type int by default

Suit suit{Suit::Diamonds}; // You must always qualify them using the type name


int main()
{
	today = Weekdays::Mon; // you can qualify an enumeration constant with the name of the enumeration
	today = Mon;           // although it is not necessary
	std::cout << "today is an integer: " << today << std::endl;

	Weekdays tomorrow { Weekdays::Tues }; // this is 10
	std::cout << "tomorrow is an integer: " << tomorrow << std::endl;

	Weekdays day_after_tomorrow { Weekdays::Wed }; // subsequent enumerators start from 10 and are incremented by 1
	std::cout << "day_after_tomorrow is an integer: " << day_after_tomorrow << std::endl;
	
	int integer = Tues; // Enumerators and variables of an enumeration type will be implicitly converted to type int when required
	std::cout << "integer is: " << integer << std::endl;

	int number = Comma;
	std::cout << "number is: " << number << std::endl;

	return 0;
}
