#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "test lower/upper bound\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);
	mapp[80] = "test";
	mapp[90] = "test";
	mapp[50] = "test";
	std::cout << "lower_bound(7) :" << (mapp.lower_bound(7))->first << "\n";
	std::cout << "lower_bound(55) :" << (mapp.lower_bound(55))->first << "\n";
	std::cout << "upper_bound(5) :" << (mapp.upper_bound(5))->first << "\n";
	std::cout << "upper_bound(80) :" << (mapp.upper_bound(80))->first << "\n";
	std::cout << "upper_bound(50) :" << (mapp.upper_bound(50))->first << "\n";
}