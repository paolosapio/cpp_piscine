#include <iostream>
#include "array.hpp"

int main() {
    // Test constructor por defecto
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    // Test constructor con tamaño
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;

    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;

    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    // Test copia
    Array<int> c(b);
    std::cout << "c.size() = " << c.size() << std::endl;

    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << "c[" << i << "] = " << c[i] << std::endl;

    // Modificar c no afecta b
    c[0] = 999;
    std::cout << "c[0] = " << c[0] << std::endl;
    std::cout << "b[0] = " << b[0] << " (debe seguir igual)" << std::endl;

    // Test operador de asignación
    Array<int> d;
    d = b;

    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << "d[" << i << "] = " << d[i] << std::endl;

    // Test excepción por índice fuera de rango
    try {
        std::cout << b[999] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Excepción capturada: índice fuera de rango" << std::endl;
    }

	return (0);
}