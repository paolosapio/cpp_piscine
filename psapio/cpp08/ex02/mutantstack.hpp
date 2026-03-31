#pragma once

# include <iostream>
# include <stack>
# include <vector>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &rhs);// rhs es el objeto del lado derecho
	~MutantStack();



	typedef typename std::deque<T>::iterator iterator;

	iterator begin();
	iterator end();



	typedef typename std::deque<T>::const_iterator const_iterator;

	const_iterator begin() const;
	const_iterator end() const;
};

# include "mutantstack.tpp"
