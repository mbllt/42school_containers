#include "tests.hpp"
#include "test_vector.hpp"
#include <stdlib.h>
#include <time.h>

void print_str(std::ofstream& of, std::ofstream& myof, std::string str) {

	of << str << "\n";
	myof << str << "\n";
}

template<typename T>
void printVector(std::ofstream& out, T& vec) {

	out << "{ ";
	for (typename T::iterator it = vec.begin(); it != vec.end(); ++it){
		out << *it << " ";
		}
	out << "}\n";
}

template<typename T>
void displayVectors(std::ofstream& of, std::vector<T>& vec, std::ofstream& myof, ft::vector<T>& myvec) {

	printVector(of, vec);
	printVector(myof, myvec);
}

void testVector(void) {

	std::ofstream of("res/res_vector.txt");
	std::ofstream myof("res/res_myvector.txt");

//------my tests



//------


	srand (time(NULL));

	TestVector<int> test_vec;
	// TestVector<std::string> test_vec;

	srand (time(NULL));
	try {
		of << "------------------- TESTS VECTOR ------------------\n";
		myof << "------------------- TESTS VECTOR ------------------\n";
		test_vec.test_general(of, myof);
		test_vec.test_operators(of, myof);
		test_vec.test_iterators(of, myof);
		test_vec.test_reverse_iterators(of, myof);
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
