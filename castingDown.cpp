// dynamic_cast and rtti (real time type identification)

#include <iostream>

// enum TYPE {Horse, Pegasus};

class Horse
{
public:
	virtual void gallop() const {std::cout << "Galloping...\n"; }
private:
	int itsAge;
};

class Pegasus : public Horse
{
	public:
		virtual void fly() const {std::cout << "I can fly!\n"; }
};

const int numHorses = 5;

int main()
{
	Horse* Ranch[numHorses]; //array of pointers for horses
	Horse* pHorse; //declare pointer for horse
	int choice, i;
	for (i = 0; i < numHorses; i++)
	{
		std::cout << "(1) Horse (2) Pegasus:\n";
		std::cin >> choice;
		if (choice == 2) {
			pHorse = new Pegasus;
		} else {
			pHorse = new Horse;
		}
		Ranch[i] = pHorse;
	}

	for (i = 0; i < numHorses; i++)
	{
		Pegasus *pPeg =  dynamic_cast < Pegasus * > (Ranch[i]); //pointer pPeg isa dynamic cast of the current item as a pegasus object
		if (pPeg) //if the cast is possible
			pPeg->fly();
		else
			std::cout << "Just a horse.\n";

		delete Ranch[i];
	}

	return 0;
}