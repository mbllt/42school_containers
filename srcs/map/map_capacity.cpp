#include "test_map.hpp"

void size() {

	std::cout << "_______\n";
	std::cout << "test size\n";
	map<int, std::string> mapp;
	std::cout << "size map empty : " << mapp.size() << "\n";

	fillMapIntString(&mapp);
	std::cout << "size map filled : " << mapp.size() << "\n";

	mapp[55] = "tester";
	mapp[-3] = "here we go";
	std::cout << "size map refilled : " << mapp.size() << "\n";

	mapp.clear();
	std::cout << "size map cleared : " << mapp.size() << "\n";
}

void empty() {

	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	mapp.clear();
	std::cout << "_______\n";
	std::cout << "test empty\n";
	std::cout << "map is empty : " << mapp.empty() << " - yes\n";

	mapp[90] = "youpi";
	mapp[91] = "youpi";
	mapp[92] = "youpi";
	std::cout << "map is empty : " << mapp.empty() << " - no\n";

	fillMapIntString(&mapp);
	std::cout << "map is empty : " << mapp.empty() << " - no\n";
	displayMap(mapp);
}
void test() {
	size();
	empty();
}