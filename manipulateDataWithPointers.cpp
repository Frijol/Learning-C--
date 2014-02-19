// Using pointers

#include <iostream>

typedef unsigned short int USHORT;
int main ()
{
	USHORT myAge; //declares variable
	USHORT * pAge = 0; //declares pointer, assigns null
	myAge = 5; //assigns variable
	std::cout << "myAge: " << myAge << std::endl;

	pAge = &myAge; //assigns pointer

	std::cout << "pAge: " << pAge << std::endl;
	std::cout << "*pAge: " << *pAge << std::endl;

	std::cout << "*pAge = 7\n";

	*pAge = 7; //sets myAge to 7

	std::cout << "myAge: " << myAge << std::endl;
	std::cout << "pAge: " << pAge << std::endl;
	std::cout << "*pAge: " << *pAge << std::endl;

	return 0;
}