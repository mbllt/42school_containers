#include "test_map.hpp"

void test() {

	map<int, int> cont_map;

	std::cout << "test size : " << cont_map.size() << std::endl;
	std::cout << "print first element : ";
	displayMap(cont_map);
	cont_map[10] = 69;
	std::cout << "print first element : ";
	displayMap(cont_map);
}
