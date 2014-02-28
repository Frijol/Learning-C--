// a macro is the precompiler version of a function.
// Problems with macros:
// 	must be defined on one line
// 	expanded inline when used
// 	hard to debug (compiler doesn't see them)
// 	not type safe
// Inline functions can be subbed in

#include <iostream>

#define CUBE(a) ((a) * (a) * (a))
#define THREE(a) a * a * a

inline unsigned long Square(unsigned long a) { return a * a;}
inline unsigned long Cube(unsigned long a) { return a * a * a; }

int main()
{
	// macros demo
	long x = 5;
	long y = CUBE(x);
	long z = THREE(x);

	std::cout << "cube: " << y << std::endl;
	std::cout << "three: " << z << std::endl;

	long a = 5, b = 7;
	y = CUBE(a+b);
	z = THREE(a+b);

	std::cout << "cube: " << y << std::endl;
	std::cout << "three: " << z << std::endl;

	// inline demo
	unsigned long r = 1;
	for (;;)
	{
		std::cout << "Enter a number (0 to quit): ";
		std::cin >> r;
		if (r == 0)
			break;
		std::cout << "You entered: " << r << std::endl;
		std::cout << "square: " << Square(r) << std::endl;
		std::cout << "cube: " << Cube(r) << std::endl;
	}

	return 0;
}