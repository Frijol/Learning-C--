// main() is passed two params: the number of params (argc) and then the params (argv)
// argv[0] is the name of the program

#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "Received " << argc << " arguments.\n";
	for (int i = 0; i < argc ; i++)
	{
		std::cout << argv[i] << std::endl;
	}
	return 0;
}