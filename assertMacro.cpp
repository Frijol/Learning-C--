//Assert is really useful for making a compiler, because it performs tests as
// you compile code.
//Since it is defined only if DEBUG is defined, it is removed automatically
// from production code.
//Also good to use with ASSERT(INVARIANTS()), to check that specific parameters are filled 

#define DEBUG
#include <iostream>

#ifndef DEBUG
	#define ASSERT(x)
#else
	#define ASSERT(x) \
		if (!(x)) \
		{ \
			std::cout << "Error! Assert(" << #x << ") failed\n"; \
			std::cout << " on line " << __LINE__ << std::endl; \
			std::cout << " in file " << __FILE__ << std::endl; \
		}
#endif

int main()
{
	int x = 5;
	std::cout << "First assert: \n";
	ASSERT(x==5);
	std::cout << "\nSecond assert: \n";
	ASSERT(x != 5);
	std::cout << std::endl;

	return 0;
}