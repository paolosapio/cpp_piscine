#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>      // std::istringstream
#include <string>
#include <cstdlib>
#include <limits>


bool check_if_more_two_args(int argc)
{
	if (argc < 2)
	{
		std::cerr << "ERROR: " << "Faltan argumentos\n";
		return (false);
	}
	return (true);
}


bool safe_convert(const std::string &token, int &number)
{
	std::istringstream iss(token);
	long long temp;

	iss >> temp; //automaticamente el stream se convierte en el valor

	//	no se puede leer un numero valido
	if (iss.fail())
	{
		std::cerr << "ERROR: " << token << " no es un numero valido\n";
		return (false);
	}

	// si el numero tiene basura tipo 42caca queda mierda en el stream
	if (!iss.eof())
	{
		std::cerr << "ERROR: " << token << " no es un numero\n";
		return (false);
	}

	// overflow
	if (temp < 0 || temp > std::numeric_limits<int>::max())
	{
		std::cerr << "ERROR: " << token << " overflow\n";
		return (false);
	}

	number = static_cast<int>(temp);
	return (true);
}


int main(int argc, char **argv)
{
	if (check_if_more_two_args(argc) == false)
		return (1);

for (int i = 1; i < argc; i++)
{
    std::istringstream iss(argv[i]);
    std::string token;

    while (iss >> token)
    {
        int number;
        if (!safe_convert(token, number))
            return (1);

        std::cout << number << " ";
    }
}
	std::cout <<  "\n";
	return (0);
}
