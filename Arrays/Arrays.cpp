/* 
 * Arrays.cpp
 *
 */
#include <iostream>

#ifndef FORMAT_ARRAY_END
#define ARRAY_COMPLETION_COUT std::cout << "}" << std::endl;
#endif

int main()
{
	constexpr int length{6};

	// zero-initialized array
	int zeroes[6]{};

	std::cout << "zeroes[" << length << "] { ";

	// get number of elements via sizeof(zeroes)/sizeof(zeroes[0]) or _countof(zeroes);
	for(int i = 0, len = sizeof(zeroes) / sizeof(zeroes[0]); i < len; i++)
	{
		std::cout << zeroes[i] << " ";
	}
	ARRAY_COMPLETION_COUT


	// array initialization within declaration
	int hundreds[length]{100, 200, 300, 400, 500, 600};

	std::cout << "hundreds[" << length << "] { ";

	// range-based for loop
	for(int h : hundreds)
	{
		std::cout << h << " ";
	}
	ARRAY_COMPLETION_COUT

	// multi-dimensional array with 2 rows and 4 columns in the example and some element have no initializing values
	long multi[2][4]{
		{1, 2, 3, },
		{7, 11, }
	};

	// c-style string including terminating '\0'
	char c_string[15]{"C-style string"};

	// wide string where each character takes 2 bytes
	wchar_t wide_c_string[]{L"Wide string"};
	
	return 0;
}
