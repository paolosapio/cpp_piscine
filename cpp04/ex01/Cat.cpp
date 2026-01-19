#include "Cat.hpp"

Cat::Cat() //: Animal("CAT")
{
	_brain = new Brain();
	std::cout << "CAT CONTRUIDO\n";
}


Cat::Cat(const std::string name) : Animal(name)
{
	_brain = new Brain();
	std::cout << "CAT CONTRUIDO\n";
}


Cat::Cat(const Cat& other)
{
	*this = other;
}


Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = other._brain;
	}

	return (*this);
}


Cat::~Cat()
{
	std::cout << "CAT DESTRUIDO\n";
	delete _brain;
}


void Cat::makeSound() const
{
	std::cout << "CAT DICE: MIAOOOO\n";
}

