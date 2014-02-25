// Static data members: shared among all members of the class
// (belongs more to the class than to the objects)

#include <iostream>

class Cat
{
public:
	Cat (int age):itsAge(age) {HowManyCats++; }
	virtual ~Cat() {HowManyCats--; }
	virtual int getAge() {return itsAge; }
	virtual void setAge(int age) {itsAge = age; }
	// static int HowManyCats; moved to private, but can be public
	static int getCats() {return HowManyCats; } //to access when private
	//originally just access in main through Cat::HowManyCats
private:
	int itsAge;
	static int HowManyCats;
};

int Cat::HowManyCats = 0;

int main()
{
	const int maxCats = 5; int i;
	Cat *CatHouse[maxCats];

	for (i = 0; i < maxCats; i++)
	{
		CatHouse[i] = new Cat(i);
	}

	for (i = 0; i < maxCats; i++)
	{
		std::cout << "There are " << Cat::getCats() << " cats.\n";
		std::cout << "Deleting youngest...\n";
		delete CatHouse[i];
		CatHouse[i] = 0;
	}

	return 0;
}