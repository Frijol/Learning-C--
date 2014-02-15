// Demo of prefix and postfix in increment/decrement

#include <iostream>
int main()
{
	int myAge = 39;
	int yourAge = 39;
	std::cout << "I am: " << myAge << " years old.\n";
	std::cout << "You are: " << yourAge << " years old.\n";
	myAge++;
	++yourAge;
	std::cout << "A year passes...\n";
	std::cout << "I am: " << myAge << " years old.\n";
	std::cout << "You are: " << yourAge << " years old.\n";
	std::cout << "Another year...\n";
	std::cout << "I am: " << myAge++ << " years old.\n";
	std::cout << "You are: " << ++yourAge << " years old.\n";
	std::cout << "Final ages of both\n";
	std::cout << "I am: " << myAge << " years old.\n";
	std::cout << "You are: " << yourAge << " years old.\n";
		return 0;
}