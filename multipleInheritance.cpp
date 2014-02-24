// Demonstrates multiple inheritance

#include <iostream>

class Horse
{
public:
	Horse() {std::cout << "Horse constructor...\n";}
	virtual ~Horse() {std::cout << "Horse destructor...\n";}
	virtual void Whinny() const {std::cout << "Whinnying...\n";}
private:
	int itsAge;
};

class Bird
{
public:
	Bird() {std::cout << "Bird constructor...\n";}
	virtual ~Bird() {std::cout << "Bird destructor...\n";}
	virtual void Chirp() const {std::cout << "Chirping...\n";}
	virtual void Fly() const {std::cout << "Flying...\n";}
private:
	int itsWeight;
};

class Pegasus : public Horse, public Bird
{
public:
	void Chirp() const {Whinny();} //whinny when a bird would chirp
	Pegasus() {std::cout << "Pegasus constructor...\n";}
	~Pegasus() {std::cout << "Pegasus destructor...\n";}
};

const int magicNumber = 2;

int main()
{
	Horse* Ranch[magicNumber];
	Bird* Aviary[magicNumber];
	Horse* pHorse;
	Bird* pBird;
	int choice, i;
	for (i = 0; i < magicNumber; i++)
	{
		std::cout << "(1) Horse (2) Pegasus:\n";
		std::cin >> choice;
		if (choice == 2)
		{
			pHorse = new Pegasus;
		} else {
			pHorse = new Horse;
		}
		Ranch[i] = pHorse;
	}
	for (i = 0; i < magicNumber; i++)
	{
		std::cout << "(1) Bird (2) Pegasus:\n";
		std::cin >> choice;
		if (choice == 2)
		{
			pBird = new Pegasus;
		} else {
			pBird = new Bird;
		}
		Aviary[i] = pBird;
	}
	for (i = 0; i < magicNumber; i++)
	{
		std::cout << "Ranch " << i << " ";
		Ranch[i]->Whinny();
		delete Ranch[i];
	}
	for (i = 0; i < magicNumber; i++)
	{
		std::cout << "Aviary " << i << " ";
		Aviary[i]->Chirp();
		delete Aviary[i];
	}
	return 0;
}