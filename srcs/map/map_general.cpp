#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "constructor default\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	std::cout << "_______\n";
	std::cout << "constructor range\n";
	map<int, std::string> bis(mapp.begin(), mapp.end());
	displayMap(bis);

	std::cout << "_______\n";
	std::cout << "constructor map(copy)\n";
	map<int, std::string> tres(bis);
	displayMap(tres);

	std::cout << "_______\n";
	std::cout << "operator =\n";
	std::cout << "first ";
	displayMap(mapp);
	map<int, std::string> fourth;
	fillMapIntString(&fourth);
	std::cout << "second ";
	displayMap(fourth);
	mapp = fourth;
	std::cout << "after 'first = second'\n";
	std::cout << "first == second : " << (mapp == fourth) << "\n\n";

	std::cout << "_______\n";
	std::cout << "operator = with empty map\n";
	std::cout << "first ";
	displayMap(fourth);
	map<int, std::string> fifth;
	std::cout << "second ";
	displayMap(fifth);
	fourth = fifth;
	std::cout << "after 'first = second'\n";
	std::cout << "first == second : " << (fourth == fifth) << "\n";

}

// try to use a valid map with items in it and then clear it
//	and then refill and use it. I fear that my _end is not going to work