#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "accessor []\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	mapp[23] = "new twenty three";
	mapp[5] = "reset five";
	mapp[-70] = "new minus seventy";
	mapp[8] = "reset height";
	std::cout << "map[23] = 'new twenty three'\n";
	std::cout << "map[5] = 'reset five'\n";
	std::cout << "map[-70] = 'new minus seventy'\n";
	std::cout << "map[8] = 'reset height'\n";
	displayMap(mapp);

	std::cout << "_______\n";
	std::cout << "accessor at()\n";
	std::cout << "map.at(1) : " << mapp.at(1) << "\n";
	std::cout << "map.at(23) : " << mapp.at(23) << "\n";
// std::out_of_range exception
	// std::cout << "map.at(29) : " << mapp.at(29) << "\n";
	// std::cout << "map.at(-42) : " << mapp.at(-42) << "\n";

}