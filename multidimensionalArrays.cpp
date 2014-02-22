// Demonstrates multidimensional arrays

#include <iostream>

int main()
{
	int someArray[5][2] = {{0,0}, {3,5}, {5,1}, {9,7}, {1,5}};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << someArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}