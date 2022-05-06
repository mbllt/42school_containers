#include "tests.hpp"
#include "test_vector.hpp"
#include <stdlib.h>
#include <time.h>

void print_str(std::ofstream& of, std::ofstream& myof, std::string str) {

	of << str << "\n";
	myof << str << "\n";
}

void testVector(void) {

//------my tests
	// std::vector<std::string> y(5, "pep");

	// std::cout << "{ ";
	// for (std::vector<std::string>::iterator it = y.begin(); it != y.end(); ++it){
	// 	std::cout << *it << " ";
	// }
	// std::cout << "}\n";
	// y.insert(y.begin(), "test");
	// std::cout << "{ ";
	// for (std::vector<std::string>::iterator it = y.begin(); it != y.end(); ++it){
	// 	std::cout << *it << " ";
	// }
	// std::cout << "}\n";

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

	TestVector<int> test_vec;
	// TestVector<std::string> test_vec;

	srand (time(NULL));
	try {
		of << "------------------- TESTS VECTOR ------------------\n";
		myof << "------------------- TESTS VECTOR ------------------\n";
		// test_vec.test_constructors(of, myof);
		// test_vec.test_operators(of, myof);
		// test_vec.test_iterators(of, myof);
		// test_vec.test_accessors(of, myof);
		// test_vec.test_capacity(of, myof);
		test_vec.test_modifiers(of, myof);
		// test_vec.test_const(of, myof);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}
