// Demonstrates storing pointers in an array instead of objects.
// This is better for memory; there is usually more memory on the
// free store than in the stack.

#include "CAT.HPP"

int main()
{
	// ARRAY OF POINTERS
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

	// // // EVERYTHING ON THE HEAP INSTEAD OF JUST THE OBJECTS
	// // BUT IT DOESN'T ACTUALLY WORK; CRASHES
	// Cat * Family = new Cat[500];
	// int i;
	// Cat * pCat = Family;
	// Cat * addr = pCat;
	// for (i = 0; i < 500; i++)
	// {
	// 	pCat = addr + i;
	// 	pCat->setAge(2*i+1);
	// }
	// for (i = 0; i < 500; i++)
	// {
	// 	pCat = addr + i;
	// 	std::cout << "Cat #" << i << " is " << pCat->getAge() << std::endl;
	// }
	return 0;
}