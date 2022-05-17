#include <exception>
#include <iostream>
#include "tests.hpp"

int main(void) {

	try {
		vec_general();
		vec_ope();
		vec_it();
		vec_rev_it();
		vec_capacity();
		vec_accessors();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
