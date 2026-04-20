#include <iostream>
#include <vector>
#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}


PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque)
{
}


PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return (*this);
}


PmergeMe::~PmergeMe()
{
}


void PmergeMe::setContainers(const int value)
{
	_vector.push_back(value);
	_deque.push_back(value);
}


std::vector<int> PmergeMe::pairingVector(	const std::vector<int> &input,
											std::vector<int> &pending,
											bool &haySobrante,
											int &sobrante )
{
	std::vector<int> mainChain;
	pending.clear();
	haySobrante = false;

	size_t i = 0;
	while (i + 1 < input.size())
	{
		int a = input[i];
		int b = input[i + 1];

		if (a < b)
		{
			pending.push_back(a);
			mainChain.push_back(b);
		}
		else
		{
			pending.push_back(b);
			mainChain.push_back(a);
		}
		i += 2;
	}

	// Si queda un número suelto está, te d (Soltero)
	if (i < input.size())
	{
		haySobrante = true;
		sobrante = input[i];
	}

	return (mainChain);
}


/* mainChain = mayores de cada pareja
	pending	= menores
	straggler = último si hay impar */
void PmergeMe::sortVector()
{
	_vector = fordJohnson(_vector);
}


std::vector<int> PmergeMe::fordJohnson(const std::vector<int> &input)
{
	// Caso base: 0, 1 o 2 elementos
	if (input.size() <= 1)
		return input;

	if (input.size() == 2)
	{
		std::vector<int> res = input;
		if (res[0] > res[1])
			std::swap(res[0], res[1]);
		return res;
	}

	// 1. Pairing
	std::vector<int> pending;
	bool haySobrante = false;
	int sobrante = 0;

	std::vector<int> mainChain =
		pairingVector(input, pending, haySobrante, sobrante);

	// 2. Ordenar mainChain RECURSIVAMENTE
	mainChain = fordJohnson(mainChain);

	// 3. Insertar pending usando Jacobsthal
	std::vector<size_t> seq = generateJacobsthal(pending.size());
	insertPending(mainChain, pending, seq);

	// 4. Insertar sobrante
	if (haySobrante)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), sobrante);
		mainChain.insert(pos, sobrante);
	}

	return mainChain;
}


std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> seq;

	if (n == 0)
		return (seq);

	size_t j0 = 0;
	size_t j1 = 1;

	while (j1 <= n)
	{
		seq.push_back(j1);
		size_t j2 = j1 + 2 * j0;
		j0 = j1;
		j1 = j2;
	}

	return (seq);
}



void PmergeMe::printVector() const
{
	for (size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i] << " "; // se puede acder al dato asi tambien_vector.at(i)
	}
	std::cout << "\n";
}



void PmergeMe::printDeque() const
{
	for (size_t i = 0; i < _deque.size(); i++)
	{
		std::cout << _deque[i] << " ";
	}
	std::cout << "\n";
}


void PmergeMe::insertPending(std::vector<int> &mainChain,
							 const std::vector<int> &pending,
							 const std::vector<size_t> &seq)
{
	std::vector<bool> inserted(pending.size(), false);

	// Vamos a insertar siguiendo Jacobsthal
	for (size_t k = 0; k < seq.size(); k++)
	{
		size_t i = seq[k] - 1;
		if (i >= pending.size() || inserted[i])
			continue;

		int value = pending[i];

		// 🔥 LIMITAMOS EL RANGO
		size_t limit = std::min(i + 1, mainChain.size());

		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.begin() + limit, value);

		mainChain.insert(pos, value);
		inserted[i] = true;
	}

	// Insertar los que faltan
	for (size_t i = 0; i < pending.size(); i++)
	{
		if (inserted[i])
			continue;

		int value = pending[i];

		size_t limit = std::min(i + 1, mainChain.size());

		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.begin() + limit, value);

		mainChain.insert(pos, value);
	}
}
