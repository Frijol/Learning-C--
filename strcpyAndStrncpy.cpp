// Demonstrates the use of strcpy() and strncpy() on char arrays
// Strcpy copies the entire contents of a string into a designated buffer.
// This can be dangerous; buffer overflow possible.
// Strncpy copies until null or until specified max chars reached.

#include <iostream>
#include <string>

int main()
{
	const int maxLength = 80;
	char string1[] = "Some texfakdfkjahsdk\n"; // [] automatically makes it the right size (statically)
	char string2[maxLength];
	char string3[maxLength + 1];

	strcpy(string2, string1);
	strncpy(string3, string2, maxLength);

	std::cout << string1;
	std::cout << string2;
	std::cout << string3;

	return 0;
}