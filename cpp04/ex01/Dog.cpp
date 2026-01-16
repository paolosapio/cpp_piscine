#include "Dog.hpp"

Dog::Dog() : Animal("DOG")
{
	std::cout << "DOG CONTRUIDO\n";
}


Dog::Dog(const std::string name) : Animal(name)
{
	std::cout << "DOG CONTRUIDO\n";
}


Dog::Dog(const Dog& other)
{
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	//! if (this != &other) verificar porque esta protecion es necesaria (Davida aviles te lo explica)
		_type = other._type;
	return (*this);
}



Dog::~Dog()
{
	std::cout << "DOG DESTRUIDO\n";

}



void Dog::makeSound() const
{
	std::cout << "DOG DICE: GUAUUUU\n";
}

