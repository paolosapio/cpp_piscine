#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

# include <iostream>

class Dog : public AAnimal
{
private:
	Brain*	_brain;

public:
	Dog();
	Dog(const std::string name);
	Dog(const Dog& other);

	~Dog();

	Dog& operator=(const Dog& other);


	void makeSound() const;
};

#endif