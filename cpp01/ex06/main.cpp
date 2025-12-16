#include "Harl.hpp"

int main(int argn, char *argv[])
{
	if (argn == 2)
	{
		Harl H;
		std::string string = argv[1];
		H.complain(string);
	}
	else
		std::cerr << "err arg" << std::endl;
	return (0);
}