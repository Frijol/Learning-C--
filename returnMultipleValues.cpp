// Demonstrates use of references to
// return multiple values from a function
// Return is kind of a strong word; it changes values
// directly based on their 

#include <iostream>

typedef unsigned short USHORT;

short Factor(USHORT, USHORT*, USHORT*);

int main ()
{
	USHORT number, squared, cubed;
	short error;

	std::cout << "Enter a number: \n";
	std::cin >> number;

	error = Factor(number, &squared, &cubed); //pass addresses of squared & cubed

	if (!error)
	{
		std::cout << "Number: " << number << std::endl;
		std::cout << "Squared: " << squared << std::endl;
		std::cout << "Cubed: " << cubed << std::endl;
	} else {
		std::cout << "Error!\n";
	}

	return 0;
}

short Factor(USHORT n, USHORT *pSquared, USHORT *pCubed)
{
	short Value = 0;
	if (n > 20) //too big
	{
		Value = 1; //error
	} else {
		*pSquared = n*n; //change values at their addresses
		*pCubed = n*n*n;
	}
	return Value;
}