#include "span.hpp"
#include <stdexcept>


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
}


Span::~Span()
{
}


/* ------------------METODOS-------------------- */


void Span::addNumber(int n_to_add)
{
	if (this->int_vector.size() < this->n_)
		this->int_vector.push_back(n_to_add);
	else
		throw std::runtime_error("[ERROR]: demasidos numeroos!");
}

int Span::longestSpan()
{
	if (int_vector.size() < 2)
		throw std::length_error("[ERROR]: contenedor con meno de 2 numeros!");

	int min = *std::min_element(int_vector.begin(), int_vector.end());
	int max = *std::max_element(int_vector.begin(), int_vector.end());

	return (max - min);
}

// 7 3 9 6 10 1
int low_range_find(std::vector<int> int_vector, int index_contenedor)
{
	int lower_value;
	int i = 0;

	while (i != int_vector.size())
	{
		int j = 0;
		while (j != int_vector.size())
		{
			if (int_vector[i] < int_vector[j])
				lower_value = int_vector[i];
			else
				lower_value = int_vector[j];
			j++;
		}
		i++;
	}
	return (lower_value);
}

int Span::shortestSpan()
{
	int low_n_find;

	if (int_vector.size() < 2)
		throw std::length_error("[ERROR]: contenedor con meno de 2 numeros!");

	
	for (int index_contenedor = *int_vector.begin(); index_contenedor > 0; index_contenedor--)
	{
		low_n_find = low_range_find(int_vector, index_contenedor);
	}
}