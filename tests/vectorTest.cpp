#include "tests.hpp"
#include "test_vector.hpp"
#include <stdlib.h>
#include <time.h>

void print_str(std::ofstream& of, std::ofstream& myof, std::string str) {

	of << str << "\n";
	myof << str << "\n";
}

void print_line(std::ofstream& of, std::ofstream& myof, unsigned int n) {

	of << "---- l." << n << " ----" << "\n";
	myof << "---- l." << n << " ----" << "\n";
}

void testVector(void) {

//------my tests
	// std::vector<int> y(5, 4);

	// ft::vector<std::vector<int> > test;
	// // ft::vector<std::vector<int> > test(10, y);

	// test.push_back(y);
	// // int y = 5;

	// // ft::vector<int> test;
	// // // ft::vector<std::vector<int> > test(10, y);

	// // test.push_back(y);

//------


	std::ofstream of("res/res_vector.txt");
	std::ofstream myof("res/res_myvector.txt");

	srand (time(NULL));

	// TestVector<int> test_vec;
	TestVector<std::string> test_vec;

	srand (time(NULL));
	try {
		of << "------------------- TESTS VECTOR ------------------\n";
		myof << "------------------- TESTS VECTOR ------------------\n";
		test_vec.test_constructors(of, myof);
		test_vec.test_operators(of, myof);
		test_vec.test_iterators(of, myof);
		test_vec.test_accessors(of, myof);
		test_vec.test_capacity(of, myof);
		test_vec.test_modifiers(of, myof);
		test_vec.test_const(of, myof);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}
