// Demonstration of classes derived from other classes
// Constructors and destructors made explicit to show order.
// Note on overriding: if you override an overloaded function,
// you hide all of the other overloaded functionalities of
// the original, even if you only override one.
// Get around this with virtual functions.
// If a class has any virtual functions, the destructor should be virtual too

#include <iostream>

enum BREED {YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
public:
	Mammal(): itsAge(2), itsWeight(5) {std::cout << "Mammal constructor...\n"; }
	virtual ~Mammal(){std::cout << "Mammal destructor...\n"; }

	int getAge() const {return itsAge; }
	void setAge(int age) {itsAge = age; }
	int getWeight() const {return itsWeight; }
	void setWeight(int weight) {itsWeight = weight; }

	void speak() const {std::cout << "Mammal sound!\n"; } //virtual
	void sleep() const {std::cout << "sshhh, I'm sleeping.\n"; }
	virtual void move() const {std::cout << "Mammal move one step.\n"; }

protected:				// protected: private not avail. to derived classes
	int itsAge;
	int itsWeight;
};

class Dog : public Mammal
{
public:
	Dog(): itsBreed(YORKIE){std::cout << "Dog constructor...\n"; }
	~Dog(){std::cout << "Dog destructor...\n"; }

	BREED getBreed() const {return itsBreed; }
	void setBreed(BREED breed) {itsBreed = breed; }

	void wagTail() const {std::cout << "Wagging tail...\n"; }
	void begForFood() const {std::cout << "Begging for food...\n"; }
	void speak() const {std::cout << "Woof!\n"; } //overrides mammal speak
	void move() const {std::cout << "Dog move one step.\n"; }

protected:
	BREED itsBreed;
};

int main()
{
	Dog fido;
	fido.speak(); //calls dog speak
	fido.Mammal::speak(); //specifically calls mammal speak
	fido.wagTail();
	fido.sleep();
	std::cout << "Fido is " << fido.getAge() << std::endl;

	// Weird virtual function thing
	Mammal *pDog = new Dog;
	pDog->move(); //virtual function, so looks for dog version
	pDog->speak();
	// pDog->begForFood(); // This cannot be done because there is no virtual function for it in Mammal.

	return 0;
}