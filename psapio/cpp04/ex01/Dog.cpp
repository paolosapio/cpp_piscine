#include "Dog.hpp"

Dog::Dog() //: Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog CONTRUIDO\n";
}

/* 
Dog::Dog(const std::string name) : Animal(name)
{
	_brain = new Brain();
	std::cout << "Dog CONTRUIDO\n";
}
 */

Dog::Dog(const Dog& other)
{
	*this = other;
}


Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = other._brain;
	}

	return (*this);
}


Dog::~Dog()
{
	std::cout << "Dog DESTRUIDO\n";
	delete _brain;
}


void Dog::makeSound() const
{
	std::cout << "Dog DICE: MIAOOOO\n";
}

