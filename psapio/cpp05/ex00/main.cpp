#include <iostream>

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- 1. Pruebas de instanciación válida ---" << std::endl;
    try {
        Bureaucrat boss("El Jefe", 1);
        Bureaucrat intern("Becario", 150);
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- 2. Pruebas de GradeTooHigh (Constructor) ---" << std::endl;
    try {
        Bureaucrat god("Zeus", 0);
    } catch (std::exception &e) {
        std::cerr << "Error capturado: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. Pruebas de GradeTooLow (Constructor) ---" << std::endl;
    try {
        Bureaucrat ghost("Casper", 151);
    } catch (std::exception &e) {
        std::cerr << "Error capturado: " << e.what() << std::endl;
    }

    std::cout << "\n--- 4. Pruebas de Incremento/Decremento ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << "Antes: " << bob << std::endl;
        bob.increment();
        std::cout << "Después de subir: " << bob << std::endl;
        bob.increment(); // Esto debería lanzar excepción (grado 0)
    } catch (std::exception &e) {
        std::cerr << "Error capturado: " << e.what() << std::endl;
    }

    std::cout << "\n--- 5. Prueba de Forma Canónica (Copia y Asignación) ---" << std::endl;
    Bureaucrat original("Original", 42);
    Bureaucrat copia(original); // Constructor de copia
    Bureaucrat asignado("Temp", 100);
    
    asignado = original; // Operador de asignación

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copia:    " << copia << std::endl;
    std::cout << "Asignado: " << asignado << " (Solo cambió la nota, el nombre 'Temp' es const)" << std::endl;
    std::cout << original.getGrade() << "\n";
    int i = original.getGrade();
    i++;
    original.increment();
    std::cout << original.getGrade() << "\n";

    return 0;
}