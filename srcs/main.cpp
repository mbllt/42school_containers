#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

// BUG
//	-balance faut que je check mon mes valeurs de height_l

// -test size de lucas, comprends pas
//	-insert et tout le reste marche pas avec int, int or int, double...
//	-clear marche pas car iterator() par defaut marche pas
//	-vitesse

int main(void) {

	srand(time(NULL));

	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

