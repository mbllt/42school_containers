#include <iostream>
#include <string>
#include <iomanip>
#include "tests.hpp"

void test();

int main(void) {

	// std::map<int, int> map;

	// map.insert(std::pair<int, int>(5, 40));
	// map.insert(std::pair<int, int>(3, 100));
	// map.insert(std::pair<int, int>(4, 1));

	// for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
	// 	std::cout << "key :" << it->first << "| value :" << it->second << std::endl;


	try {

		test();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

