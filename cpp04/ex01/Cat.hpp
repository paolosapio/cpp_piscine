#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <iostream>

class Cat : public Animal
{
private:
	Brain* _brain;
public:
	Cat();
	Cat(const std::string name);
	Cat(const Cat& other);

	~Cat();

	Cat& operator=(const Cat& other);

	void makeSound() const;
};

#endif