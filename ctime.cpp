// Demonstrates use of standard library ctime

#include <ctime>
#include <iostream>

int main()
{
	time_t currentTime;

	//get and print the current time
	time (&currentTime); //fill with current time
	std::cout << ctime(&currentTime) << std::endl;

	struct tm * ptm = localtime(&currentTime);

	std::cout << "Today is " << ((ptm->tm_mon)+1) << "/";
	std::cout << ptm->tm_mday << "/";
	std::cout << ptm->tm_year << std::endl;

	return 0;
}