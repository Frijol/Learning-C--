// Related to strcpy and strncpy.
// Strcat appends second param to first
// Strncat appends the first n chars of one string to the other

#include <iostream>
#include <string>

int main()
{
	char stringOne[255];
	char stringTwo[255];

	stringOne[0] = '\0';
	stringTwo[0] = '\0';

	std::cout << "Enter a string:\n";
	std::cin >> stringOne;

	std::cout << "Enter another string:\n";
	std::cin >> stringTwo;

	std::cout << "String One: " << stringOne << std::endl;
	std::cout << "String Two: " << stringTwo << std::endl;

	strcat(stringOne, " ");
	strncat(stringOne, stringTwo, 10);

	std::cout << "String One: " << stringOne << std::endl;
	std::cout << "String Two: " << stringTwo << std::endl;

	return 0;
}