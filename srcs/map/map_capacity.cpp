#include "test_map.hpp"

void test() {
	
	std::cout << "_______\n";
	std::cout << "test size\n";
	map<int, std::string> mapp;
	std::cout << "size map empty : " << mapp.size() << "\n";

	fillMapIntString(&mapp);
	std::cout << "size map filled : " << mapp.size() << "\n";

	mapp[55] = "tester";
	mapp[-3] = "here we go";
	std::cout << "size map refilled : " << mapp.size() << "\n";

// test erase and check size after
	// mapp.erase(it);

	mapp.clear();
	std::cout << "size map cleared : " << mapp.size() << "\n";

	
	std::cout << "_______\n";
	std::cout << "test empty\n";
	std::cout << "";

}