#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

// BUG
//	-op= 1 leak
//	-erase dans node_two_children
//	-erase _root two_children
//	-faut que je teste ma fonction balance
//	-test lucas

int main(void) {

	srand(time(NULL));

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

