// Swaps some variables' values from within a function

#include <iostream>

void swap(int &x, int &y);

int main()
{
	int x = 5, y = 10;
	std::cout << "Main. Before swap x y " << x << " " << y << std::endl;
	swap(x, y);
	std::cout << "Main. After swap x y " << x << " " << y << std::endl;

	return 0;
}

void swap(int &rx, int &ry)
{
	int temp;
	std::cout << "Swap. Before swap rx ry " << rx << " " << ry << std::endl;
	temp = rx;
	rx = ry;
	ry = temp;

	std::cout << "Swap. After swap rx ry " << rx << " " << ry << std::endl;
}