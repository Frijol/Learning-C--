// Demonstrates creation of references
// References are aliases.
// References cannot be reassigned.

#include <iostream>

int main()
{
	int intOne;
	int &rRef = intOne; //assigns rRef as alias of intOne

	// Assign intOne, print its value, print rRef, print both of their addresses
	intOne = 5;
	std::cout << "intOne: " << intOne << std::endl;
	std::cout << "rRef: " << rRef << std::endl;
	std::cout << "&intOne: " << &intOne << std::endl;
	std::cout << "&rRef: " << &rRef << std::endl;

	// Try to reassign rRef, see results
	std::cout << "Assigning rRef to intTwo...\n";
	int intTwo = 8;
	rRef = intTwo;
	std::cout << "intOne: " << intOne << std::endl;
	std::cout << "intTwo: " << intTwo << std::endl;
	std::cout << "rRef: " << rRef << std::endl;
	std::cout << "&intOne: " << &intOne << std::endl;
	std::cout << "&intTwo: " << &intTwo << std::endl;
	std::cout << "&rRef: " << &rRef << std::endl;

	return 0;
}