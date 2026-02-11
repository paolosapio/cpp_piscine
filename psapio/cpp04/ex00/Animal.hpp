#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/*
NO OLVIDAR: Orthodox Canonical Form
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

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

		virtual ~Animal();

		std::string getType() const;

		virtual void makeSound() const;
};

#endif