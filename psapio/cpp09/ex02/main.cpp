#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>      // std::istringstream
#include <string>
#include <cstdlib>
#include <limits>
#include <set>

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


bool tieneDuplicados(std::istream& in)
{
	std::set<int> enteros;
	int n;

	while (in >> n)
	{
		if (enteros.count(n))
		{
			std::cerr << "numero duplicado encontrato: " << n << "\n";
			return true; // duplicado encontrado
		}
		enteros.insert(n);
	}
	return false;
}



void PmergeMe::sortDeque()
{
	std::vector<int> tmp(_deque.begin(), _deque.end());

	tmp = fordJohnson(tmp);

	_deque.clear();
	_deque.insert(_deque.end(), tmp.begin(), tmp.end());
}


int main(int argc, char **argv)
{
	if (check_if_more_two_args(argc) == false)
		return (1);

	PmergeMe mem;

	std::stringstream ss;

	// Primero metemos TODOS los números en un solo flujo
	for (int i = 1; i < argc; i++)
		ss << argv[i] << " ";

	// Ahora sí: detectamos duplicados una sola vez
	if (tieneDuplicados(ss))
		return (1);

	// Reiniciamos el flujo para volver a leerlo
	ss.clear();
	ss.seekg(0);

	// Ahora convertimos y guardamos
	std::string token;
	while (ss >> token)
	{
		int number;
		if (!safe_convert(token, number))
			return (1);
		mem.setContainers(number);
	}
	
	mem.sortVector();
	mem.sortDeque();

	mem.printVector();
	mem.printDeque();
	std::cout << "\n";
	return 0;
}
