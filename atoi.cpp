// Using atoi (ascii to int) and related functions

// #include <stdlib> DON"T NEED THIS LINE; ALREADY INCLUDED
#include <iostream>

int main()
{
	char buffer[80];
	std::cout << "Enter a number: ";
	std::cin >> buffer;

	int number;
	number = atoi(buffer);
	std::cout << number << std::endl;

	int sum = atoi(buffer) + 5;
	std::cout << sum << std::endl;

	return 0;
}