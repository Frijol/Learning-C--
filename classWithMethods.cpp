// Implements methods in a class 

#include <iostream>

class Cat
{
public:
	Cat(int initialAge);
	~Cat();
	int getAge() const;
	void setAge(int age);
	void Meow() const;

private:
	int itsAge;
};

// constructor
Cat::Cat(int initialAge)
{
	itsAge = initialAge;
}

// destructor
Cat::~Cat()
{}

// Accessor functions
int Cat::getAge() const
{
	return itsAge;
}

void Cat::setAge(int age)
{
	itsAge = age;
}

void Cat::Meow() const
{
	std::cout << "Meow.\n";
}

int main()
{
	Cat Frisky(5);
	Frisky.Meow();
	std::cout << "Frisky is a cat who is ";
	std::cout << Frisky.getAge() << " years old.\n";
	Frisky.setAge(7);
	Frisky.Meow();
	std::cout << "Frisky is a cat who is ";
	std::cout << Frisky.getAge() << " years old.\n";
	Frisky.Meow();
	return 0;
}