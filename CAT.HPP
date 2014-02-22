// Header file for a cat

#include <iostream>

class Cat
{
public:
	Cat() {itsAge = 1; itsWeight = 5; }
	Cat(int initialAge);
	~Cat();
	int getAge() const {return itsAge; }
	int getWeight() const {return itsWeight; }
	void setAge(int age) {itsAge = age; }
private:
	int itsAge;
	int itsWeight;
};