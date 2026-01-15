#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# include <iostream>

class Dog : public Animal
{
protected:

public:
	Dog();
	Dog(const std::string name);
	Dog(const Dog& other);

	~Dog();

	Dog& operator=(const Dog& other);

	std::string getType();

	void makeSound();
};

#endif