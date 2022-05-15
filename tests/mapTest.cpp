#include "tests.hpp"
#include "test_map.hpp"
#include <stdlib.h>
#include <time.h>

void testMap(void) {

	std::ofstream of("res/res_map.txt");
	std::ofstream myof("res/res_mymap.txt");

	srand (time(NULL));

	// TestMap<int> test_vec;
	TestMap<std::string> test_vec;

	srand (time(NULL));
	try {
		of << "------------------- TESTS MAP ------------------\n";
		myof << "------------------- TESTS MAP ------------------\n";
		test_vec.test_general(of, myof);
		// test_vec.test_operators(of, myof);
		// test_vec.test_iterators(of, myof);
		// test_vec.test_reverse_iterators(of, myof);
		// test_vec.test_accessors(of, myof);
		// test_vec.test_capacity(of, myof);
		// test_vec.test_modifiers(of, myof);
		// test_vec.test_const(of, myof);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}
