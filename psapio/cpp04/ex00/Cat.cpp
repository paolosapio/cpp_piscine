#include "Cat.hpp"

Cat::Cat() : Animal("CAT")
{
	std::cout << "CAT CONTRUIDO\n";
}


/*
Cat::Cat(const std::string name) : Animal(name)
{
	std::cout << "CAT CONTRUIDO\n";
} */


Cat::Cat(const Cat& other)
{
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}



Cat::~Cat()
{
	std::cout << "CAT DESTRUIDO\n";

}




void Cat::makeSound() const
{
	std::cout << "CAT DICE: MIAOOOO\n";
}

