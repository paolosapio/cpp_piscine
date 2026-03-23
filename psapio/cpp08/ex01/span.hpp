#pragma once

#include  <exception>
#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int n_;
	std::vector<int> int_vector;

public:
	Span();
	Span(unsigned int n);
	Span(Span &other);
	Span &operator=(Span const &rhs); // rhs es el objeto del lado derecho
	~Span();

	void addNumber(int n_to_add);
	int longestSpan();
	int shortestSpan();
};
