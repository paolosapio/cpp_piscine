#include "span.hpp"
#include <iostream>
#include <stdexcept>

#define SIZE 100000

int main()
{
	std::srand(time(NULL));

	Span container(SIZE);

	int	arr[SIZE];

	int i = 0;
	while (i < SIZE)
	{
		arr[i] = std::rand() % SIZE;
		i++;
	}
	
	
	std::vector<int> range(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try
	{
		container.addRangereitor(range.begin(), range.end());
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	
	// test1.addNumber();
	// test1.addNumber();
	// test1.addNumber();

	std::cout << container.longestSpan() << ": longestSpan\n";
	std::cout << container.shortestSpan() << ": shortestSpan\n";


	return (0);
}
