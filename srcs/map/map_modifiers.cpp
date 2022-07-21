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
	std::cout << "test insert\n";
	fillMapIntString(&mapp);
	displayMap(mapp);
	std::cout << "test pair<iterator, bool> insert(value)\n";
	pair<map<int, std::string>::iterator, bool> ret = mapp.insert(pair<int,  std::string>(88, "heavy"));
	std::cout << "Inserting pair(88, 'heavy)'" << std::endl;
	std::cout << "ret pair first : " << (*(ret.first)).first << ";";
	std::cout << "ret pair second : " << (*(ret.first)).second << " | ";
	std::cout << "ret bool : " << ret.second << "\n";
	mapp.insert(pair<int,  std::string>(99, "heavy"));
	mapp.insert(pair<int,  std::string>(54, "heavy"));
	mapp.insert(pair<int,  std::string>(104, "heavy"));
	mapp.insert(pair<int,  std::string>(0, "heavy"));

	std::cout << "test pair<iterator, bool> insert(it first, it last)\n";
	fillMapIntString(&mapp);
	map<int, std::string> mappbis(mapp.begin(), mapp.end());
	std::cout << "first ";
	displayMap(mapp);
	std::cout << "second created with it of the first ";
	displayMap(mappbis);



}

// #endif