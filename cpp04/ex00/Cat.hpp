#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

# include <iostream>

class Cat : public Animal
{
protected:

public:
	Cat();
	Cat(const std::string name);
	Cat(const Cat& other);

	~Cat();

	Cat& operator=(const Cat& other);

	std::string getType();

	void makeSound();
};

#endif