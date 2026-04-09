#include <iostream>

int main(int argn, char **argv)
{
	if (argn < 3)
	{
		std::cerr << "argumentos invalidos\n";
		std::cerr << argv << "\n";
	}

	return (0);
}
