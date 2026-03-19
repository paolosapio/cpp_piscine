#include "array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}


template <typename T>
Array<T>::Array(int n)
{
	if (n < 0)
		throw OutOfRange();

	_array = new T[n];
	_size = n;
}



template <typename T>
Array<T>::Array(const Array& other)
{
	if (this == &other)
		return ;

	this->_size = other._size;
	this->_array = new T[_size];

	for (unsigned int i = 0; i < _size; i++)
	{
		this->_array[i] = other._array[i];
	}
}



template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}


//left hand shake (lhs) = right hand shake (rhs)
template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this == &rhs)
		return (*this);


	delete[] _array;
	_size = rhs._size;
	
	this->_array = (_size > 0) ? new T[_size] : NULL;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
	return (*this);
}




// COMO ACEDEMOS AL INDICE DEL ARRAY!
template <typename T>
T& Array<T>::operator[](int i)
{
	if (i >= (int)_size || i < 0)
		throw OutOfRange();
	return (_array[i]);
}

/* 
template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Index fuera de rango");
	return _array[i];
}
 */

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfRange::what() const throw()
{
	return ("Out Of Range!");
}

