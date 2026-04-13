#include <iostream>
#include <vector>
#include "PmergeMe.hpp"



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


	void PmergeMe::setVector(const int value)
	{
		_vector.push_back(value);
	}


	void PmergeMe::printVector()
	{
		for (size_t i = 0; i < _vector.size(); i++)
		{
			std::cout << _vector[i] << " "; // se puede acder al dato asi tambien_vector.at(i)
		}
		std::cout << "\n";

	}
