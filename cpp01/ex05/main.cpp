#include "Harl.hpp"

int main()
{
	Harl H;

	H.complain("CACA");
	H.complain("CACA");
	H.complain("CACA");
	H.complain("DEBUG");
	H.complain("INFO");
	H.complain("WARNING");
	H.complain("ERROR");

	return (0);
}


// para el siguente exercicio:
/* int main(int argn, char *argv[])
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
} */