#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

// BUG
//	-op= 1 leak
//	-erase : dans mon swap : mon erase bug completement !

//	-erase le cas de root
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

