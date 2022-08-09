#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

// BUG
//	-clear
//	-erase
//	-it parfois, ca pourrait venir du insert ?
//	-jai pas tester les const

int main(void) {

	srand(time(NULL));

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

