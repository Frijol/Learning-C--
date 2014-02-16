// Demonstrate the function of the ?: C++ ternary operator
// if ? true : false

#include <iostream>
int main()
{
	// Initialize x, y, z as ints
	int x, y, z;
	// Request user input for two numbers; assign to x & y
	std::cout << "Enter first int: \n";
	std::cin >> x;
	std::cout << "\nEnter second int: \n";
	std::cin >> y;
	// Assign the larger number to z using if/else
	if (x > y)
		z = x;
	else
		z = y;
	// Print x, y, z
	std::cout << "\nx: " << x << " y: " << y << " z: " << z << std::endl;
	// Use the ternary operator to reassign z to the greater of x & y
	z = (x > y) ? x : y;
	// Print x, y, z
	std::cout << "\nx: " << x << " y: " << y << " z: " << z << std::endl;
	// Exit
	return 0;
}