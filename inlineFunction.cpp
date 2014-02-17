// Demonstrates inline function

#include <iostream>

inline int Double(int);

int main ()
{
	int target;
	std::cout << "Give me an int: \n";
	std::cin >> target;
	std::cout << Double(target) << std::endl;
	return 0;
}

int Double(int x)
{
	return 2 * x;
}