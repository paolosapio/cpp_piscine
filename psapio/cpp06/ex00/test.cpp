#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <limits>
#include <cfloat>
#include <math.h>

int main(int argc, char **argv) {
	if (argc != 2) return 1;

	
	float f = std::atof(argv[1]);
	if (f != f) {
		std::cout << "Number is a nan" << std::endl;
	}
	if (f > FLT_MAX) {
		std::cout << "Number is +inf" << std::endl;
	}
	if (f < FLT_MIN) {
		std::cout << "Number is -inf" << std::endl;
	}
}
