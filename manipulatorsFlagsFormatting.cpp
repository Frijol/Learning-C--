#include <iostream>
// not needed for width and fill
#include <iomanip>

int main()
{
	// Adjusting the width of output
	std::cout << "Start >";
	std::cout.width(25);
	std::cout << 123 << "< End\n";

	std::cout << "Start >";
	std::cout.width(25);
	std::cout << 123 << "< Next >";
	std::cout << 456 << "< End\n";

	std::cout << "Start >";
	std::cout.width(4);
	std::cout << 123456 << "< End\n";

	// Fill
	std::cout << "Start >";
	std::cout.width(25);
	std::cout.fill('*');
	std::cout << 123 << "< End\n";

	// setf (set flag)
	const int number = 185;
	std::cout << "The number is " << number << std::endl;
	std::cout << "The number is " << std::hex << number << std::endl;

	std::cout.setf(std::ios::showbase);
	std::cout << "The number is " << std::hex << number << std::endl;

	std::cout << "The number is ";
	std::cout.width(10);
	std::cout << std::hex << number << std::endl;

	std::cout << "The number is ";
	std::cout.width(10);
	std::cout.setf(std::ios::left);
	std::cout << std::hex << number << std::endl;

	std::cout << "The number is ";
	std::cout.width(10);
	std::cout.setf(std::ios::internal);
	std::cout << std::hex << number << std::endl;

	// std::cout << "The number is " << setw(10) << std::hex << number << std::endl;

	return 0;
}