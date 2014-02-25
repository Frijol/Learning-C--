// Using function pointers

#include <iostream>

void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);
enum BOOL {FALSE, TRUE};

int main()
{
	void (* pFunc) (int&, int&);
	BOOL fQuit = FALSE;

	int valOne = 1; int valTwo = 2;
	int choice;
	while (fQuit == FALSE)
	{
		std::cout << "(0) Quit (1) Change Vals (2) Square (3) Cube (4) Swap:\n";
		std::cin >> choice;
		switch(choice)
		{
			case 1: pFunc = GetVals; break;
			case 2: pFunc = Square; break;
			case 3: pFunc = Cube; break;
			case 4: pFunc = Swap; break;
			default: fQuit = TRUE; break;
		}

		if (fQuit)
		{
			break;
		}

		PrintVals(valOne, valTwo);
		pFunc(valOne, valTwo);
		PrintVals(valOne, valTwo);
	}
	return 0;
}

void PrintVals (int x, int y)
{
	std::cout << "x, y: " << x << ", " << y << std::endl;
}

void Square (int & rX, int & rY)
{
	rX *= rX;
	rY *= rY;
}

void Cube (int & rX, int & rY)
{
	rX *= rX*rX;
	rY *= rY*rY;
}

void Swap (int & rX, int & rY)
{
	int tmp;
	tmp = rX;
	rX = rY;
	rY = tmp;
}

void GetVals (int & rX, int & rY)
{
	std::cout << "New valOne: ";
	std::cin >> rX;
	std::cout << "New valTwo: ";
	std::cin >> rY;
}