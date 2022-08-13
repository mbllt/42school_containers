#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

// BUG
//	-vitesse
//	-change getP to p in iterator

int main(void) {

	srand(time(NULL));

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

