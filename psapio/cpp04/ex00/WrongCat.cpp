#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WRONG_CAT")
{
	std::cout << "WRONG CAT CONTRUIDO\n";
}


WrongCat::WrongCat(const std::string name) : WrongAnimal(name)
{
	std::cout << "WRONG CAT CONTRUIDO\n";
}


WrongCat::WrongCat(const WrongCat& other)
{
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}



WrongCat::~WrongCat()
{
	std::cout << "WRONG CAT DESTRUIDO\n";

}




void WrongCat::makeSound() const
{
	std::cout << "WRONG CAT DICE: MIAOOOO\n";
}

