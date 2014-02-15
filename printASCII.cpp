#include <iostream>

int main()
{
	for (int i = 32; i < 128; i++)
		std::cout << i << ": " << (char) i <<std::endl;
    
  return 0;
}