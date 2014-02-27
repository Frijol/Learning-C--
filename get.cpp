// get() can be used to obtain a single character
// it can be used with no params
// or with one param

#include <iostream>

int main()
{
	// get() with no params
	char ch;
	std::cout << "Enter some input; CTRL+D to exit.\n";
	while ((ch = std::cin.get()) != EOF)
	{
		std::cout << ch << std::endl;
	}
	std::cout << "Done!\n";

	// get() with params. Not really working here.
	char a[256], b[256], c[256];
	std::cout << "Enter three letters: ";
	std::cin.getline(a, 256);
	std::cin.get(b, 256);
	std::cin.get(c, 256);
	std::cout << a << b << c << std::endl;
	// return 0;
}