#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

/*
NO OLVIDAR: Orthodox Canonical Form
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

class Dog : public Animal
{
protected:

public:
	Dog();
	// Dog(const std::string name);
	Dog(const Dog& other);

	~Dog();

	Dog& operator=(const Dog& other);

	void makeSound() const;
};

#endif