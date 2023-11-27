//Alex Kaiser
//CIS 1202 801
//November 26, 2023

#include <cctype>
#include <iostream>


char character(const char start, int offset)
{
	if (!std::isalpha(start))
	{
		std::string e = "invalidCharacterException";
		throw e;
	}

	const char target = start + offset;
	if (std::isalpha(target) && std::isupper(target) == std::isupper(start))
	{
		return target;
	}

	std::string e = "invalidRangeException";
	throw e;
}

int main()
{
	character('a', 1);
	std::cout << "Offset a by 1 passed" << std::endl;

	try
	{
		character('a', -1);
	}
	catch (std::string exception)
	{
		std::cout << "Offsetting a by -1 failed: " << exception << std::endl;
	}

	character('Z', -1);
	std::cout << "Offset Z by -1 passed" << std::endl;

	try
	{
		character('?', 5);
	}
	catch (std::string exception)
	{
		std::cout << "Offsetting ? by 5 failed: " << exception << std::endl;
	}
}