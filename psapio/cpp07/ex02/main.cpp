#include <iostream>
#include "array.hpp"

int main() {
	// Test constructor por defecto
	Array<unsigned int> a;
	std::cout << "a.size() = " << a.size() << "\n";

	// Test constructor con tamaño
	Array<unsigned int> b(2);
	std::cout << "b.size() = " << b.size() << "\n";


    try
	{
        Array<int> k(-1);
    }
	catch (std::exception &e)
	{
        std::cerr << e.what() << "\n";

    }



	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i + 1;
	
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "] = " << b[i] << "\n";
	


	// Test copia
	Array<unsigned int> c(b);
	std::cout << "c.size() = " << c.size() << "\n";

	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << "c[" << i << "] = " << c[i] << "\n";


	// Modificar c no afecta b
	c[0] = 999;
	std::cout << "c[0] = " << c[0] << "\n";
	std::cout << "b[0] = " << b[0] << " (debe seguir igual)\n";


	// Test operador de asignación
	Array<unsigned int> d;
	d = b;


	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << "d[" << i << "] = " << d[i] << "\n";


	// Test excepción por índice fuera de rango
	try
	{
		std::cout << b[999] << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}


	return (0);
}