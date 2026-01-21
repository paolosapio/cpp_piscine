#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

/*
NO OLVIDAR: Orthodox Canonical Form
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

class Cat : public Animal
{
protected:

public:
	Cat();
	// Cat(const std::string name);
	Cat(const Cat& other);

	~Cat();

	Cat& operator=(const Cat& other);

	void makeSound() const;
};

#endif