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
	// std::vector<int> test(20, 0);
	// std::cout << "capacity bf : " << test.capacity() << std::endl;
	// test.push_back(5);
	// std::cout << "capacity af : " << test.capacity() << std::endl;
	
	// for (int i = 0; i < 20;++i)
	// 	test.push_back(5);
	// std::cout << "capacity af : " << test.capacity() << std::endl;
	// const std::vector<int>::const_iterator ittest = test.begin();
	// std::vector<const int> test(20, 0);
	// std::vector<int>::iterator ittest = test.begin();
	// *ittest = 1;
	// test.push_back(5);

	// (void)ittest;
//------


	std::ofstream of("res/res_vector.txt");
	std::ofstream myof("res/res_myvector.txt");

	srand (time(NULL));

	TestVector<int> test_vec;
	// TestVector<const int> test_vec;

	// TestVector<std::string> test_vec;
	// TestVector<const std::string> test_vec;

	// TestVector<std::vector<int> > test_vec;

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
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}
