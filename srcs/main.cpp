#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

#include <vector>
#include "vector.hpp"

int main(void) {

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

