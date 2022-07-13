#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "test clear\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	std::cout << "clearing map\n";
	mapp.clear();
	displayMap(mapp);

	std::cout << "refilling map\n";
	mapp[9] = "test";

	std::cout << "clearing map\n";
	mapp.clear();
	displayMap(mapp);

	std::cout << "_______\n";
	std::cout << "test pair<iterator, bool> insert(value)\n";
	pair<map<int, std::string>::iterator, bool> ret = mapp.insert(pair<int,  std::string>(88, "heavy"));
	std::cout << "((ret.first)->value).first : " << (*(ret.first)).first << ";";
	std::cout << "((ret.first)->value).second : " << (*(ret.first)).second << " | ";
	std::cout << "ret.second : " << ret.second << "\n";


}