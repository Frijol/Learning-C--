// Demonstrates recursive functions by finding the nth
// number in the Fibonacci sequence

#include <iostream>

int Fibonacci(int n);

int main ()
{
	int n, answer;
	std::cout << "Where in the sequence would you like to go?\n";
	std::cin >> n;
	answer = Fibonacci(n);
	std::cout << "Answer: " << answer << std::endl;
	return 0;
}

int Fibonacci (int n)
{
	std::cout << "Processing Fibonacci(" << n << ")...";

	if (n < 3)
	{
		std::cout << 1 << " \n";
		return 1;
	} else {
		int temp = (Fibonacci(n - 2) + Fibonacci(n - 1));
		std::cout << "Fib(" << n - 2 <<") and Fib(" << n - 1 << ")\n";
		return temp;
	}
}