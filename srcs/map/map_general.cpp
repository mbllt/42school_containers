#include "test_map.hpp"
#include <list>

void test() {

	std::list<int> test;

	map<int, int> cont_map;

	std::cout << "size bf :" << cont_map.size() << std::endl;
	std::cout << "print bf :";
	displayMap(cont_map);
	cont_map[4] = 40;
	cont_map[1] = 10;
	cont_map[5] = 50;
	cont_map[6] = 60;
	cont_map[2] = 20;
	cont_map[3] = 30;
	std::cout << "size af :" << cont_map.size() << std::endl;
	std::cout << "print af :";
	displayMap(cont_map);

	cont_map.clear();

	std::cout << "test clear and print after :\n";
	std::cout << "print :";
	displayMap(cont_map);
}

// try to use a valid map with items in it and then clear it
//	and then refill and use it. I fear that my _end is not going to work