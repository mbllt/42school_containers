#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

#include <vector>
#include "vector.hpp"

int main(void) {

	srand(time(NULL));

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

