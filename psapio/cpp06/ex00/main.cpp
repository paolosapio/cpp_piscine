#include "ScalarConverter.hpp"

int main(int argn, char *argv[])
{
    std::stringstream stringConversor;

    int aInt;
    std::string stringo = "7";

    stringConversor << stringo;
    stringConversor >> aInt;
    std::cout << aInt << "\n";

    ScalarConverter::convert(argv[1]);
    return (0);
}