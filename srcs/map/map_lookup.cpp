#include "test_map.hpp"

void count() {
	
	std::cout << "_______\n";
	std::cout << "test count\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	mapp[80] = "test";
	mapp[90] = "test";
	mapp[50] = "test";
	displayMap(mapp);

	std::cout << "count(50) :" << mapp.count(50) << "\n";
	std::cout << "count(-15) :" << mapp.count(-15) << "\n";
	std::cout << "count(78) :" << mapp.count(78) << "\n";
	std::cout << "count(13) :" << mapp.count(13) << "\n";
	std::cout << "count(3) :" << mapp.count(3) << "\n";
}

void find() {

	std::cout << "\n_______\n";
	std::cout << "test find\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	mapp[80] = "test";
	mapp[90] = "test";
	mapp[50] = "test";
	displayMap(mapp);

	typename map<int, std::string>::iterator it1 = mapp.find(50);
	typename map<int, std::string>::iterator it2 = mapp.find(-14);
	typename map<int, std::string>::iterator it3 = mapp.find(78);
	typename map<int, std::string>::iterator it4 = mapp.find(13);
	typename map<int, std::string>::iterator it5 = mapp.find(3);

	if (it1 != mapp.end())
		std::cout << "find(50) :1\n";
	else
		std::cout << "find(50) :0\n";
	if (it2 != mapp.end())
		std::cout << "find(-14) :1\n";
	else
		std::cout << "find(-14) :0\n";
	if (it3 != mapp.end())
		std::cout << "find(78) :1\n";
	else
		std::cout << "find(78) :0\n";
	if (it4 != mapp.end())
		std::cout << "find(13) :1\n";
	else
		std::cout << "find(13) :0\n";
	if (it5 != mapp.end())
		std::cout << "find(3) :1\n";
	else
		std::cout << "find(3) :0\n";
}

void bound_range() {

	std::cout << "\n_______\n";
	std::cout << "test lower/upper bound/equal_range\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	mapp[80] = "test";
	mapp[90] = "test";
	mapp[50] = "test";
	typename map<int, std::string>::iterator it1 = mapp.lower_bound(7);
	typename map<int, std::string>::iterator it2 = mapp.lower_bound(55);
	typename map<int, std::string>::iterator it3 = mapp.upper_bound(5);
	typename map<int, std::string>::iterator it4 = mapp.upper_bound(80);
	typename map<int, std::string>::iterator it5 = mapp.upper_bound(50);
	std::cout << "lower_bound(7) :" << it1->first << "\n";
	std::cout << "lower_bound(55) :" << it2->first << "\n";
	std::cout << "upper_bound(5) :" << it3->first << "\n";
	std::cout << "upper_bound(80) :" << it4->first << "\n";
	std::cout << "upper_bound(50) :" << it5->first << "\n";
	displayMap(mapp);

	pair<typename map<int, std::string>::iterator, \
		typename map<int, std::string>::iterator> \
		equal = mapp.equal_range(8);

	std::cout << "return equal_range(8)->first_it->first :" << (equal.first)->first << "\n";
	std::cout << "return equal_range(8)->second_it->first :" << (equal.second)->first << "\n";
}

void test() {

	// count();
	// find();
	bound_range();
}