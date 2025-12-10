#include <iostream>

int main(void)
{
	std::string frase = "HI THIS IS BRAIN";

	std::string *stringPTR = &frase;
	std::string &stringREF = frase;
	
	std::cout << "frase      " << &frase << std::endl;
	std::cout << "puntero    " << stringPTR << std::endl;
	std::cout << "referencia " << &stringREF << std::endl;

	std::cout << "frase      " << frase << std::endl;
	std::cout << "puntero    " << *stringPTR << std::endl;
	std::cout << "referencia " << stringREF << std::endl;


	std::string stringCPY = frase;
	stringCPY[2] = 'A';
	frase = "viva la vida";
	std::cout << stringCPY << std::endl;
	std::cout << frase << std::endl;

	std::cout << "puntero    " << *stringPTR << std::endl;
	std::cout << "referencia " << stringREF << std::endl;
	
	return  (0);
}