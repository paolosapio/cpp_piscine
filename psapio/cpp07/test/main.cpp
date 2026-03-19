#include <iostream>
#include <string>

// c
void print(const char* str)
{
	std::cout << str << std::endl;
}

// c++
void print_str(std::string& str)
{
	std::cout << str << std::endl;
}

int main()
{
	// c++
	const std::string t = "Hola";
	// c
	char str[] = "hola";

	// c++
	print_str(t);

	// c
	print(str);

	return 0;
}
