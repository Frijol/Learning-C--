// Implements methods in a class 

#include <iostream>

class Cat
{
public:
	int getAge();
	void setAge(int age);
	void Meow();

private:
	int itsAge;
};

int Cat::getAge()
{
	return itsAge;
}

void Cat::setAge(int age)
{
	itsAge = age;
}

void Cat::Meow()
{
	std::cout << "Meow.\n";
}

int main()
{
	Cat Frisky;
	Frisky.setAge(5);
	Frisky.Meow();
	std::cout << "Frisky is a cat who is ";
	std::cout << Frisky.getAge() << " years old.\n";
	Frisky.Meow();
	return 0;
}