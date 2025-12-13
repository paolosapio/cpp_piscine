#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::ifstream file(argv[1]);
	std::ofstream file2((std::string(argv[1]) + ".replace").c_str());
	
	if (!file || !file2)
	{
		std::cerr << "FILE Error" << std::endl;
		return (1);
	}

	std::string palabra_original = std::string(argv[2]);

	if (palabra_original.empty())
	{
		std::cerr << "Empty arg Error" << std::endl;
		return (1);
	}
	std::string palabra_nueva = std::string(argv[3]);

	std::string frase;
	size_t pos_inicial_palabra = 0;
	std::getline(file, frase, '\0');

buscar_la_palabra:
	pos_inicial_palabra = frase.find(palabra_original, pos_inicial_palabra);
	if (pos_inicial_palabra == std::string::npos) /* si no se encuentra la palabra inicial return 0*/
		goto escribe_frase_entera;

	frase.erase(pos_inicial_palabra, palabra_original.length());
	frase.insert(pos_inicial_palabra, palabra_nueva);

	pos_inicial_palabra = pos_inicial_palabra + palabra_nueva.length();
	goto buscar_la_palabra;

escribe_frase_entera:
	file2 << frase;
	return (0);
}