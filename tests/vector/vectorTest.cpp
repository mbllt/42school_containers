#include "tests.hpp"

void printof(std::ofstream& of, std::ofstream& myof, std::string str) {

	of << str << "\n";
	myof << str << "\n";
}

void testVector(void) {

	std::ofstream of("res_vector.txt");
	std::ofstream myof("res_myvector.txt");


	srand (time(NULL));
	try {
		printof(of, myof, "------------------- TESTS VECTOR ------------------\n");
		test_constructors(of, myof);
		test_operators(of, myof);
		test_iterators(of, myof);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}