#include "tests.hpp"

void print_str(std::ofstream& of, std::ofstream& myof, std::string str) {

	of << str << "\n";
	myof << str << "\n";
}

int	main(void) {

	testVector();
	testStack();
	return 0;
}
