#include "test_map.hpp"

void test() {

	std::cout << "map default\n";
	map<int, std::string> cont_map;
	fillMapIntString(&cont_map);
	displayMap(cont_map);

	std::cout << "map(it first, it last)\n";
	map<int, std::string> bis(cont_map.begin(), cont_map.end());
	displayMap(bis);

	std::cout << "map(copy)\n";
	map<int, std::string> tres(bis);
	displayMap(tres);
	std::cout << "map == copy : " << (tres == bis) << "\n";

}

// try to use a valid map with items in it and then clear it
//	and then refill and use it. I fear that my _end is not going to work