# include "Brain.hpp"
// Constructors and destructors of each class must display specific messages.

Brain::Brain()
{
	std::cout << "Cerebro construido\n";
}


Brain::Brain(const Brain& other)
{
	for(int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];

	std::cout << "Ideas copiadas\n";
}


Brain::~Brain()
{
	std::cout << "Cerebro destruido!\n";
}


Brain& Brain::operator=(const Brain& other)
{
	for(int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];

	std::cout << "Operador = llamado (Brain)\n";
	return (*this);
}

