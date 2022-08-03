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
	std::cout << "\ntest pair<iterator, bool> insert(value)\n";
	pair<map<int, std::string>::iterator, bool> ret = mapp.insert(pair<int, std::string>(88, "heavy"));
	std::cout << "Inserting pair(88, 'heavy')" << std::endl;
	std::cout << "ret pair first : " << (*(ret.first)).first << ";";
	std::cout << "ret pair second : " << (*(ret.first)).second << " | ";
	std::cout << "ret bool : " << ret.second << "\n";
	displayMap(mapp);
	mapp.insert(pair<int, std::string>(99, "heavy"));
	mapp.insert(pair<int, std::string>(74, "heavy"));
	mapp.insert(pair<int, std::string>(54, "heavy"));
	mapp.insert(pair<int, std::string>(104, "heavy"));
	mapp.insert(pair<int, std::string>(0, "heavy"));

	std::cout << "\ntest void insert(it first, it last)\n";
	std::cout << "first ";
	displayMap(mapp);
	map<int, std::string> mappbis(mapp.begin(), mapp.end());
	std::cout << "second created with it of the first ";
	displayMap(mappbis);

	// std::cout << "\ntest iterator insert(it hint, value)\n";


// test dans clear
	std::cout << "\ntest with cleared and refilled map\n";
	map<int, std::string> test;
	std::cout << "begin on empty map : " << (*(test.begin())).first << "\n";
	test[8] = "you";
	test.clear();
	std::cout << "inserting a value and clearing\n";
// bug sur loperator = de ft::pair qui est appele dans begin() dans iterator() par defaut.
	// std::cout << "begin on empty map : " << (*(test.begin())).first << "\n";
	// map<int, std::string> empty(test.begin(), test.end());

	std::cout << "_______\n";
	std::cout << "test erase\n";
	map<int, std::string> test_erase;
	fillMapIntString(&test_erase);
	displayMap(test_erase);
	typename map<int, std::string>::iterator it = test_erase.find(7);
	test_erase.erase(it);
	it = test_erase.find(4);
	test_erase.erase(it);
	it = test_erase.find(10);
	test_erase.erase(it);
	it = test_erase.find(1);
	test_erase.erase(it);
	std::cout << "erasing pos 7 4 10 1\n";
	displayMap(test_erase);

}