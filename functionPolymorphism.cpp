// Demonstrates function polymorphism/overloaded functions
// Can overload as long as function params differ in # or type

#include <iostream>

float Average(int x, int y);
float Average(float x, float y);

int main ()
{
	int x = 4;
	int y = 3;
	float c = 5.6;
	float d = 9.6;
	std::cout << Average(x, y) << std::endl;
	std::cout << Average(c, d) << std::endl;
	return 0;
}

float Average(int x, int y)
{
	return ((float) x + (float) y)/2;
}

float Average(float x, float y)
{
	return (x + y)/2;
}