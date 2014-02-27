// demonstrates flushing std::cout, using put() and write()

#include <iostream>

int main()
{
	std::cout.put('h').put('i').put('\n');

	char One[] = "One if by land";

	int fullLength = strlen(One);
	int tooShort = fullLength - 4;
	int tooLong = fullLength + 6;

	std::cout.write(One, fullLength) << std::endl;
	std::cout.write(One, tooShort) << std::endl;
	std::cout.write(One, tooLong) << std::endl; //adds the next six bytes of contiguous memory

	return 0;
}