#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

# include <iostream>

class Cat : public AAnimal
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