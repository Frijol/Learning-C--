// Demonstrates use of deep copy

#include <iostream>

class CAT
{
public:
	CAT(); //Default constructor
	CAT(const CAT&); //Copy constructor
	~CAT(); //Default destructor

	int getAge() const {return *itsAge; }
	int getWeight() const {return *itsWeight; }
	void setAge(int age) {*itsAge = age; }
private:
	int *itsAge;
	int *itsWeight;
};

CAT::CAT()
{
	itsAge = new int;
	itsWeight = new int;
	*itsAge = 5;
	*itsWeight = 9;
}

CAT::CAT(const CAT & rhs)
{
	itsAge = new int;
	itsWeight = new int;
	*itsAge = rhs.getAge();
	*itsWeight = rhs.getWeight();
}

CAT::~CAT()
{
	delete itsAge;
	itsAge = 0;
	delete itsWeight;
	itsWeight = 0;
}

int main()
{
	// Make Frisky
	CAT Frisky;
	//Print Frisky's age
	std::cout << "Frisky's age: " << Frisky.getAge() << std::endl;
	//Change Frisky's age
	std::cout << "Setting age to 6\n";
	Frisky.setAge(6);
	//Make Boots from Frisky
	std::cout << "Making Boots from Frisky\n";
	CAT Boots(Frisky);
	//Print their ages
	std::cout << "Frisky's age: " << Frisky.getAge() << std::endl;
	std::cout << "Boots's age: " << Boots.getAge() << std::endl;
	//Change Frisky's age
	std::cout << "Changing Frisky's age.\n";
	Frisky.setAge(12);
	//Print both their ages
	std::cout << "Frisky's age: " << Frisky.getAge() << std::endl;
	std::cout << "Boots's age: " << Boots.getAge() << std::endl;
	//Return
	return 0;
}