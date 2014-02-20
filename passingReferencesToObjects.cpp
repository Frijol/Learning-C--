// Demonstrates passing references to objects into functions
// Objective:  performance > passing objects,
// security > passing pointers

#include <iostream>

class SimpleCat
{
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();

	int getAge() const {return itsAge; }
	void setAge(int age) {itsAge = age; }
private:
	int itsAge;
};

SimpleCat::SimpleCat()
{
	std::cout << "SimpleCat constructor...\n";
	itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&)
{
	std::cout << "Copy constructor...\n";
}

SimpleCat::~SimpleCat()
{
	std::cout << "SimpleCat destructor...\n";
}

const SimpleCat & FunctionTwo (const SimpleCat& theCat);

int main ()
{
	std::cout << "Making a cat.\n";
	SimpleCat Frisky;
	std::cout << "Frisky is " << Frisky.getAge() << std::endl;

	int age = 5;
	Frisky.setAge(age);
	std::cout << "Frisky is " << Frisky.getAge() << std::endl;

	std::cout << "Calling FunctionTwo...\n";
	FunctionTwo(Frisky);
	std::cout << "Frisky is " << Frisky.getAge() << std::endl;

	return 0;
}

// FunctionTwo passes a ref to a const object
const SimpleCat& FunctionTwo(const SimpleCat& theCat)
{
	std::cout << "Returning FunctionTwo\n";
	std::cout << "Frisky is " << theCat.getAge() << std::endl;
}