#include <iostream>
#include <vector>
#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}


PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector)
{
}


PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		this->_vector = other._vector;
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
											bool &estaSoltero,
											int &Soltero )
{
    std::vector<int> mainChain;
    pending.clear();
    estaSoltero = false;

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

    // Si queda un número suelto (Soltero)
    if (i < input.size())
    {
        estaSoltero = true;
        Soltero = input[i];
    }

    return (mainChain);
}


/* mainChain = mayores de cada pareja
	pending	= menores
	straggler = último si hay impar */
void PmergeMe::sortVector()
{
    std::vector<int> pending;
    bool haySobrante = false;
    int sobrante = 0;

    std::vector<int> mainChain = pairingVector(_vector, pending, haySobrante, sobrante);

    // ORDENAMOS mainChain
    std::sort(mainChain.begin(), mainChain.end());

    std::cout << "MainChain sorted: ";
    for (size_t i = 0; i < mainChain.size(); i++)
        std::cout << mainChain[i] << " ";
    std::cout << "\n";

    std::cout << "Pending: ";
    for (size_t i = 0; i < pending.size(); i++)
        std::cout << pending[i] << " ";
    std::cout << "\n";

    if (haySobrante)
        std::cout << "Sobrante: " << sobrante << "\n";
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
