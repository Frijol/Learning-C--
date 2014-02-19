// Access data member of objects on the heap (free store)

#include <iostream>

class SimpleCat
{
public:
	SimpleCat() {itsAge = 2; }
	~SimpleCat() {}
	int getAge() const {return itsAge; }
	void setAge(int age) {itsAge = age; }
private:
	int itsAge;
};

int main()
{
	SimpleCat * Frisky = new SimpleCat;
	std::cout << "Frisky is " << Frisky->getAge() << std::endl;
	Frisky->setAge(5);
	std::cout<< "Frisky is " << Frisky ->getAge() << std::endl;
	delete Frisky;
	return 0;
}