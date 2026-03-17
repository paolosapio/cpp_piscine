#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
    int n_A = 7;
    int n_B = 5;

	std::string frase_A = "<viva la>";
    std::string frase_B = "< vida>";

    std::cout << "valor inicial: " << n_A << "\n";
    std::cout << "valor inicial: " << n_B << "\n";
    std::cout << "valor inicial: " << frase_A << "\n";
    std::cout << "valor inicial: " << frase_B << "\n\n";


    std::cout << max(n_A, n_B) << " es el numero max\n";
    std::cout << min(n_A, n_B) << " es el numero min\n\n";

    std::cout << "antes SWAP: " << n_A << " | " << n_B << "\n";
    swap(n_A, n_B);
    std::cout << "despu SWAP: " << n_A << " | " << n_B << "\n\n";

    std::cout << "antes SWAP: " << frase_A << frase_B << "\n";
    swap(frase_A, frase_B);
    std::cout << "despu SWAP: " << frase_A << " " << frase_B << "\n\n";

    return (0);
}