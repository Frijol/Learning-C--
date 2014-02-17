// Demonstrates function syntax, particulary prototypes

// Alias unsigned short to USHORT
typedef unsigned short USHORT;
// Set up, prototype function
#include <iostream>
USHORT findArea(USHORT width, USHORT length);

int main ()
{
	// Declare variables for length, width, area
	USHORT length;
	USHORT width;
	USHORT area;

	// Request user input for length and width
	std::cout << "Please enter length:\n";
	std::cin >> length;
	std::cout << "\nPlease enter width:\n";
	std::cin >> width;

	// Calculate area
	area = findArea(width, length);

	// Print all variables
	std::cout << "Length: " << length << " Width: " << width << " Area: " << area << std::endl;

	//Exit
	return 0;
}

// Define area function
USHORT findArea(USHORT width, USHORT length)
{
	return width * length;
}