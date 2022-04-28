#include "tests.hpp"
#include "test_vector.hpp"

void printof(std::ofstream& of, std::ofstream& myof, std::string str, size_t n) {

	of << str << " | l." << n << "\n";
	myof << str << " | l." << n << "\n";
}

void testVector(void) {

	std::ofstream of("res_vector.txt");
	std::ofstream myof("res_myvector.txt");

	srand (time(NULL));


	Test_vector<int> test_vec;
	// Test_vector<std::string> test_vec;

	try {
		printof(of, myof, "------------------- TESTS VECTOR ------------------\n", 17);
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