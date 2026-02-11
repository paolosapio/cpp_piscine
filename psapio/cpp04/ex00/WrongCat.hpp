#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

# include <iostream>

class WrongCat : public WrongAnimal
{
protected:

public:
	WrongCat();
	WrongCat(const std::string name);
	WrongCat(const WrongCat& other);

	~WrongCat();

	WrongCat& operator=(const WrongCat& other);

	void makeSound() const;
};

#endif