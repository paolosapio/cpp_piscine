#include <iostream>
#include <cstring>

// a.out "VIVA LA VIDA"
int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		//cout significa console out (por terminal)
		std::string noise = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << noise << std::endl;
	}

	int i = 1;
	while (argv[i])
	{
		int j = 0;
		while(argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}

	std::cout << std::endl;

	return (0);
}
