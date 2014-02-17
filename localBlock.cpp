// Demonatrates the use of a block to create a very local var

// Setup
#include <iostream>

// Main function
int main ()
{
	int x = 2;
	std::cout << x << std::endl;
	{
		int x = 9230;
		std::cout << x << std::endl;
	}

	std::cout << x << std::endl;
	return 0;
}