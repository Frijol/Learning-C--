// Demonstrates storing pointers in an array instead of objects.
// This is better for memory; there is usually more memory on the
// free store than in the stack.

#include "CAT.HPP"

int main()
{
	Cat * Family[500];
	int i;
	Cat * pCat;
	for (i = 0; i < 500; i++)
	{
		pCat = new Cat;
		pCat->setAge(2*i+1);
		Family[i] = pCat;
	}
	for (i = 0; i < 500; i++)
	{
		std::cout << "Cat #" << i << " is " << Family[i]->getAge() << std::endl;
	}
	return 0;
}