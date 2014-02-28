// stringizing operator #, concatenation operator ##
#include <iostream>

#define WRITESTRING(x) std::cout << #x
#define fPRINT(x) f ## x ## Print

void fOnePrint() {std::cout << "We're in fOnePrint\n";}

int main ()
{
	WRITESTRING(This is a string);
	fPRINT(One)();
}