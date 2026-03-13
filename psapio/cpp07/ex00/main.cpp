#include "whatever.hpp"

int main(void)
{
	int alago = 7;
	int blago = 5;
	
	std::cout << maxaolo(alago, blago) << " el max aolo\n";
	std::cout << minaolo(alago, blago) << " el min aolo\n";
	
	Patata<int, float> frita;


	Hola<int, std::string> caca;
	
	Hola<int, std::string> pis;


	caca.mafio = 7;
	pis.mafio = 1;

	caca.dana = 5;
	pis.dana = 0;

	caca.bebe = "mucha";
	pis.bebe = " pocaa";

	frita.h.mafio = 7;
	frita.h.dana = 8;
	frita.h.bebe = 7.7;

	std::string frasea = "viva la";
	std::string fraseb = " vida";

	std::cout << alago << " " << blago << " antes\n";
	swaPaolo(alago, blago);
	std::cout << alago << " " << blago << " despues\n\n";
	
	std::cout << frasea << fraseb << " antes\n";
	swaPaolo(frasea, fraseb);
	std::cout << frasea << " "  << fraseb << " despues\n\n";

	std::cout << caca.mafio << " "  << pis.mafio << " antes\n";
	std::cout << caca.dana << " "  << pis.dana << " antes\n";
	std::cout << caca.bebe << " "  << pis.bebe << " antes\n";

	swaPaolo(caca, pis);
	std::cout << &caca << " &caca\n";
	std::cout << &pis << " &pis\n";

	std::cout << caca.mafio << " "  << pis.mafio << " despues\n";
	std::cout << caca.dana << " "  << pis.dana << " despues\n";
	std::cout << caca.bebe << " "  << pis.bebe << " despues\n";


	std::cout << "Contenido de la patata!\n";
	std::cout << frita.h.mafio << " " << frita.h.dana << " " << frita.h.bebe << "\n";
	return (0);
}