// Demonstrates a class and public properties

#include <iostream>

class Cat
{
	public:
		int legs;
		int age;
		int weight;
};

int main ()
{
	Cat Frisky;
	Frisky.age = 7;
	Frisky.legs = 83;
	std::cout << "Age, Weight, Legs: " << Frisky.age << ", " << Frisky.weight << ", " << Frisky.legs << std::endl;
	return 0;
}