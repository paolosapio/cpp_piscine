#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

// using std::string;

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(const std::string name);
	AAnimal(const AAnimal& other);
	
	virtual ~AAnimal();
	
	std::string getType() const;
	
	virtual void makeSound() const = 0;
	AAnimal& operator=(const AAnimal& other);
};

#endif