#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

int main(void) {

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

