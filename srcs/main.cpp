// #include <iostream>
// #include <string>
// #include <iomanip>
// #include <map>
// #include <vector>
#include "tests.hpp"

void test();

int main(void) {

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

