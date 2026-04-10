#include <iostream>
#include <sstream>      // std::istringstream
#include <string>
#include <cstdlib>



/*
./PmergeMe "1 2 3"
./PmergeMe "1 2" "3"
./PmergeMe 1 2 3
*/








bool check_if_more_two_args(int argc)
{
	if (argc < 2)
	{
		std::cerr << "Falta argumentos\n";
		return (false);
	}
	return (true);
}


bool check_token_is_digit(std::string token)
{
	int i = 0;

	while (token[i])
	{
		if (std::isdigit(token[i]) == false)
		{
		std::cerr << token << " not a number\n";
		return (false);
		}
		i++;
	}
	return (true);
}


int main(int argc, char **argv)
{
	(void)argv;
	if (check_if_more_two_args(argc) == false)
	{
		return (1);
	}
	argv++;
	
	while (*argv)
	{
		int number;
		std::istringstream iss(*argv++);
		std::string token;
		
		while (iss >> token)
		{
			if (!check_token_is_digit(token))
				return (1);

			number = std::atoi(token.c_str());
			std::cout << number << " NUMBER\n";
		}
	}
	return (0);
}





/* 
	check_if_more_two_args(argn);

	if (argn == 2)
	{
		int size = sizeof(argv) / sizeof(argv[0]);
		std::cout << size << " size";
		check_if_more_two_args(size);
	}
	std::istringstream iss(argv[1]);
	std::string token;

	int count = 0;

	while (iss >> token)
	{
		count ++;
	}
	std::cout << count << " count\n";
	return (0);
	 */