#include "span.hpp"
#include <stdexcept>
#include <climits>
#include <iostream>


Span::Span() : n_(0)
{
}

Span::Span(unsigned int n) : n_(n)
{
}

Span::Span(Span &span) : n_(span.n_), int_vector(span.int_vector)
{
}

Span &Span::operator=(Span const &rhs)
{
	if (this == &rhs)
		return (*this);

	this->n_ = rhs.n_;

	this->int_vector = rhs.int_vector;
	return (*this);
}


Span::~Span()
{
}


/* ------------------METODOS-------------------- */

/* ADDERs */
void Span::addNumber(int n_to_add)
{
	if (this->int_vector.size() < this->n_)
		this->int_vector.push_back(n_to_add);
	else
		throw std::runtime_error("[ERROR]: demasidos numeroos!");
}

void Span::addRangereitor(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->n_ - int_vector.size() >= (unsigned int)(end - begin))
		this->int_vector.insert(this->int_vector.begin(), begin, end);
	else
		throw std::runtime_error("[ERROR]: demasidos numeros!");


}








/* longestSpan */
int Span::longestSpan()
{
	if (int_vector.size() < 2)
		throw std::length_error("[ERROR]: contenedor con meno de 2 numeros!");

	int min = *std::min_element(int_vector.begin(), int_vector.end());
	int max = *std::max_element(int_vector.begin(), int_vector.end());

	return (max - min);
}



/* shortestSpan */
int low_range_find(std::vector<int> int_vector)
{
	int lower_value = INT_MAX;
	
	int i = 0;
	while (i < static_cast<int>(int_vector.size()) - 1)
	{
		int j = i + 1;

		while (j != static_cast<int>(int_vector.size()))
		{
			if (std::abs(int_vector[i] - int_vector[j]) < lower_value)
				lower_value = std::abs(int_vector[i] - int_vector[j]);
			j++;
		}
		i++;
	}
	return (lower_value);
}

int Span::shortestSpan()
{
	if (int_vector.size() < 2)
		throw std::length_error("[ERROR]: contenedor con meno de 2 numeros!");

	return (low_range_find(int_vector));
}