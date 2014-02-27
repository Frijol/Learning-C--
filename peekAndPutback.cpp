// functions peek() and putback() on std::cin

#include <iostream>

int main()
{
	char ch;
	std::cout << "Enter a phrase: ";
	while (std::cin.get(ch))
	{
		if (ch == '!')
		{
			std::cin.putback('$'); //sub in $ for !
		} else {
			std::cout << ch;
		}
		while (std::cin.peek() == '#')
		{
			std::cin.ignore(1, '#'); //ignore #
		}
	}
	return 0;
}