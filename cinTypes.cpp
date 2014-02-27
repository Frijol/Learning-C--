// Demonstrates use of cin with various data types
// Note that cin treats a space as a separator

#include <iostream>

int main()
{
	int myInt;
	long myLong;
	float myFloat;
	double myDouble;
	unsigned short myUnsigned;
	char YourName[50]; // creates buffer
	int varOne, varTwo, varThree;

	std::cout << "Int: ";
	std::cin >> myInt;
	std::cout << "Long: ";
	std:: cin >> myLong;
	std::cout << "Float: ";
	std::cin >> myFloat;
	std::cout << "Double: ";
	std::cin >> myDouble;
	std::cout << "Unsigned Short: ";
	std::cin >> myUnsigned;

	std::cout << "Your name: ";
	std::cin >> YourName;

	std::cout << "Enter three numbers: ";
	std::cin >> varOne >> varTwo >> varThree; //three cin assignments at once

	std::cout << "All in a row: " << myInt << ", " << myLong << ", " << myFloat << ", " << myDouble << ", " << myUnsigned << std::endl;
	std::cout << YourName << std::endl;
	std::cout << varOne << varTwo << varThree << std::endl;
}