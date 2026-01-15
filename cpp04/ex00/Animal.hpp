#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(const std::string name);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);

	~Animal();


	std::string getType();

	void makeSound();
};

#endif