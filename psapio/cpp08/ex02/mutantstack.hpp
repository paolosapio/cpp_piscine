#pragma once

#include <exception>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	unsigned int n_;
	std::vector<int> int_vector;

public:
	MutantStack();
	MutantStack(unsigned int n);
	MutantStack(MutantStack &other);
	MutantStack &operator=(MutantStack const &rhs); // rhs es el objeto del lado derecho
	~MutantStack();

	// iterators(?); NO ES UN METODO! OJO!

};
