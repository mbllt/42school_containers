#include "test_map.hpp"

void test() {

	// std::cout << "_______\n";
	// std::cout << "constructor default\n";
	// map<int, std::string> mapp;
	// fillMapIntString(&mapp);
	// displayMap(mapp);

	// std::cout << "_______\n";
	// std::cout << "constructor range\n";
	// map<int, std::string> bis(mapp.begin(), mapp.end());
	// displayMap(bis);
	// mapp[70] = "test";
	// std::cout << "changing first map, second one should not change\n";
	// std::cout << "first ";
	// displayMap(mapp);
	// std::cout << "second ";
	// displayMap(bis);

	// std::cout << "_______\n";
	// std::cout << "constructor map(copy)\n";
	// map<int, std::string> tres(bis);
	// displayMap(tres);
	// bis[70] = "test";
	// std::cout << "changing first map, second one should not change\n";
	// std::cout << "first ";
	// displayMap(bis);
	// std::cout << "second ";
	// displayMap(tres);

	std::cout << "_______\n";
	std::cout << "operator =\n";
	map<int, std::string> weekend;
	// fillMapIntString(&weekend);
	std::cout << "first ";
	displayMap(weekend);
	map<int, std::string> fourth;
	fillMapIntString(&fourth);
	std::cout << "second ";
	displayMap(fourth);
	weekend = fourth;
	std::cout << "after 'first = second'\n";
	std::cout << "first == second : " << (weekend == fourth) << "\n\n";
	fourth[70] = "test";
	typename map<int, std::string>::iterator it = fourth.begin();
	it->second = "test";
	std::cout << "changing first map, second one should not change\n";
	displayMap(weekend);

	// std::cout << "_______\n";
	// std::cout << "operator = with empty map\n";
	// std::cout << "first ";
	// displayMap(fourth);
	// map<int, std::string> fifth;
	// std::cout << "second ";
	// displayMap(fifth);
	// fourth = fifth;
	// std::cout << "after 'first = second'\n";
	// std::cout << "first == second : " << (fourth == fifth) << "\n";

}

// try to use a valid map with items in it and then clear it
//	and then refill and use it. I fear that my _end is not going to work