// Allocate, use, and delete a pointer
// always check that a pointer is not null after allocating
// (if it is, the memory is full)

//Memory leaks:
// always delete pointers before they go out of scope
// 

// Crashing:
// set pointer to 0/null after deletion

#include <iostream>
int main()
{
	int localVar = 5;
	int * pLocal = &localVar;
	int * pHeap = new int;
	if (pHeap == NULL)
	{
		std::cout << "ERROR: No memory for pHeap!";
		return 0;
	}
	*pHeap = 7;
	std::cout << "localVarL " << localVar << std::endl;
	std::cout << "*pLocal: " << *pLocal << std::endl;
	std::cout << "*pHeap: " << *pHeap << std::endl;
	delete pHeap;
	pHeap = new int;
	if (pHeap == NULL)
	{
		std::cout << "ERROR: No memory for pHeap!";
		return 0;
	}
	*pHeap = 9;
	std::cout << "*pHeap: " << *pHeap << std::endl;
	delete pHeap;
	return 0;
}