// - ex02 → Clase template Array<T>.

#pragma once

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
private:
		T*				_array;
		unsigned int	_size;


public:
	Array();

	Array(int n);

	Array(const Array& other);

	~Array();

	Array& operator=(const Array& other);
	
	T& operator[](int i);
	
	unsigned int size() const;

	class OutOfRange : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#include "array.tpp"