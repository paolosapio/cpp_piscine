#include "whatever.hpp"

int main(void)
{
	int n_A = 7;
	int n_B = 5;
	
	std::cout << max(n_A, n_B) << " el max\n";
	std::cout << min(n_A, n_B) << " el min\n";

	std::string frasea = "viva la";
	std::string fraseb = " vida";

	std::cout << n_A << " " << n_B << " antes\n";
	swap(n_A, n_B);
	std::cout << n_A << " " << n_B << " despues\n\n";
	
	std::cout << frasea << fraseb << " antes\n";
	swap(frasea, fraseb);
	std::cout << frasea << " "  << fraseb << " despues\n\n";


	std::cout << "Contenido de la patata!\n";
	return (0);
}