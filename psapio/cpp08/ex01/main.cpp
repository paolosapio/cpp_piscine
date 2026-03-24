#include "span.hpp"
#include <iostream>
int main()
{
	Span test1(7);

	test1.addNumber(-01);
	test1.addNumber(-10);
	test1.addNumber(-11);


	std::cout << test1.longestSpan() << "\n";
	std::cout << test1.shortestSpan() << "\n";



	return (0);
}