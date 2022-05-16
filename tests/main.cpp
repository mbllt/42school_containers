#include "tests.hpp"
#include <exception>
#include <iostream>

void test();

int main(void) {

	try {
		test();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
