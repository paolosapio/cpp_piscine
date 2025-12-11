#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::string palabra1AKitar;
	std::string frase;
	std::ifstream file(argv[1]);
	std::ofstream file2((std::string(argv[1]) + ".replace").c_str());
	std::string newFrase;

	size_t pos1;
	size_t pos2;

	palabra1AKitar = std::string(argv[2]);

	while (std::getline(file, frase))
	{
		pos1 = frase.find(palabra1AKitar);
		if (pos1 != std::string::npos) /* std::string::npos significa <-1 unsigned> */
		{
			pos2 = pos1 + palabra1AKitar.length();
			if (pos1 != 0)
			{
				newFrase = frase.substr(0, pos1) + argv[3] + frase.substr(pos2);
			}
			else
			{
				newFrase = argv[3] + frase.substr(pos2);
			}
			file2 << newFrase << std::endl;
		}
		else
			file2 << frase << std::endl;
	}
	return (0);
}