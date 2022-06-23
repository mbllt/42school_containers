#include "test_map.hpp"

void test() {

	map<int, int> cont_map;

	std::cout << "size bf :" << cont_map.size() << std::endl;
	std::cout << "print bf :";
	displayMap(cont_map);
	cont_map[4] = 40;
	cont_map[1] = 10;
	cont_map[5] = 50;
	cont_map[0] = 00;
	cont_map[2] = 20;
	cont_map[3] = 30;
	std::cout << "size af :" << cont_map.size() << std::endl;
	std::cout << "print af :";
	displayMap(cont_map);
}
