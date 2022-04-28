#include "tests.hpp"
#include "test_vector.hpp"
#include <stdlib.h>
#include <time.h>

void printof(std::ofstream& of, std::ofstream& myof, std::string str, size_t n) {

	of << str << " | l." << n << "\n";
	myof << str << " | l." << n << "\n";
}

void testVector(void) {

	std::ofstream of("res/res_vector.txt");
	std::ofstream myof("res/res_myvector.txt");

	srand (time(NULL));


	TestVector<int> test_vec;
	// TestVector<std::string> test_vec;
	// TestVector<std::vector<int> > test_vec;

	srand (time(NULL));
	try {
		of << "------------------- TESTS VECTOR ------------------\n";
		myof << "------------------- TESTS VECTOR ------------------\n";
		test_vec.test_constructors(of, myof);
		test_vec.test_operators(of, myof);
		test_vec.test_iterators(of, myof);
		test_vec.test_accessors(of, myof);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}