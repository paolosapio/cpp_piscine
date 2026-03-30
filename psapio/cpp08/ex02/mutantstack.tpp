#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
{
	*this=other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) // rhs es el objeto del lado derecho
{
// falta aqui!
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}






template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}