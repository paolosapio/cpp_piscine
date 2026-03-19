#pragma once

#include <stddef.h>
#include <stdexcept>

template <typename T>
class ArrayRaul
{
public:
	ArrayRaul()
	{
		this->array_ = NULL;
		this->size_ = 0;
	}

	ArrayRaul(size_t size)
		: size_(size)
	{
		this->array_ = new T[size]();
	}

	ArrayRaul(const ArrayRaul& other)
	{
		if (this != &other)
		{
			this->clean(); //!?!?
			this->size_ = other.size_;
			this->array_ = other.array_;
		}
	}

	~ArrayRaul()
	{
		this->clean();
	}

	size_t size()
	{
		return this->size_;
	}

	//left hand shake (lhs) = right hand shake (rhs)
	ArrayRaul& operator=(const ArrayRaul& rhs)
	{
		if (this != &rhs)
		{
			this->clean();
			this->size_ = rhs.size_;
			this->array_ = rhs.array_;
		}
		return *this;
	}

	T& operator[](size_t index)
	{
		if (index < this->size_)
		{
			return this->array_[index];
		}
		throw std::exception("out of range");
	}

private:
	T		*array_;
	size_t 	size_;

	void clean()
	{
		delete this->array_[];
	}

};