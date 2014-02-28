// illustrates use of #define with #ifdef #ifndef #else #endif
// You can also do #undef to undefine

#include <iostream>
#define DemoVersion
#define DOS_VERSION 5

int main()
{
	std::cout << "Checking on the definitions of DemoVersion, DOS_VERSION and WINDOWS_VERSION...\n";
	#ifdef DemoVersion
		std::cout << "DemoVersion defined\n";
	#else
		std::cout << "DemoVersion not defined\n";
	#endif

	#ifndef DOS_VERSION
		std::cout << "DOS_VERSION not defined\n";
	#else
		std::cout << "DOS_VERSION defined\n";
	#endif

	#ifdef WINDOWS_VERSION
		std::cout << "WINDOWS_VERSION defined\n";
	#else
		std::cout << "WINDOWS_VERSION not defined\n";
	#endif
	return 0;
}