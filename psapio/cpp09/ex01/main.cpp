#include "RPN.hpp"
#include <iostream>

int main(int argn, char **argv)
{
	if (argn != 2)
	{
		std::cout << "error args!\n";
		return (1);
	}

	Rpn stack;

	if (stack.StringStreaMeador(argv[1]) == true)
		std::cout << stack.getValueStack() << "\n";
	return (0);
}