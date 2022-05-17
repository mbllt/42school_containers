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
		vec_resize();
		vec_push_back();
		vec_pop_back();
		vec_swap();
		vec_clear();
		vec_erase();
		vec_insert();

		stack_all();

		map_general();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
