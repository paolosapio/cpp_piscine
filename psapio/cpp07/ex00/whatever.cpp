#include "whatever.hpp"

int main(void)
{
	int alago = 7;
	int blago = 5;
	
	std::cout << maxaolo(alago, blago) << " el max aolo\n";
	std::cout << minaolo(alago, blago) << " el min aolo\n";
	
	Patata <int, float> frita;


	Hola<int, std::string> caca;
	
	Hola<int, std::string> pis;


	caca.mafio = 7;
	pis.mafio = 1;

	caca.dana = 5;
	pis.dana = 0;

	caca.bebe = "mucha";
	pis.bebe = " pocaa";


	std::string frasea = "viva la";
	std::string fraseb = " vida";

	std::cout << alago << blago << " antes\n";
	swaPaolo(alago, blago);
	std::cout << alago << blago << " despues\n\n";
	
	std::cout << frasea << fraseb << " antes\n";
	swaPaolo(frasea, fraseb);
	std::cout << frasea << fraseb << " despues\n\n";

	std::cout << caca.mafio << pis.mafio << " antes\n";
	std::cout << caca.dana << pis.dana << " antes\n";
	std::cout << caca.bebe << pis.bebe << " antes\n";

	swaPaolo<Hola<int, std::string>>(caca, pis);
	std::cout << &caca << " &caca\n";
	std::cout << &pis << " &pis\n";

	std::cout << caca.mafio << pis.mafio << " despues\n";
	std::cout << caca.dana << pis.dana << " despues\n";
	std::cout << caca.bebe << pis.bebe << " despues\n";
	return (0);
}