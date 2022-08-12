#include "test_map.hpp"

void clear() {
	std::cout << "_______\n";
	std::cout << "test clear\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	std::cout << "clearing map\n";
	mapp.clear();
	displayMap(mapp);

	std::cout << "refilling map with []\n";
	mapp[9] = "test";

	std::cout << "clearing map\n";
	mapp.clear();
	displayMap(mapp);

	std::cout << "clearing map\n";
	mapp.clear();
	displayMap(mapp);

	std::cout << "\ntest with cleared and refilled map\n";
	map<int, std::string> test;
	// // iterator() par defaut marche pas
	// std::cout << "begin on empty map : " << test.begin()->first << "\n";
	// test[8] = "you";
	// test.clear();
	// std::cout << "inserting a value and clearing\n";
	// std::cout << "begin on empty map : " << test.begin()->first << "\n";
	// map<int, std::string> empty(test.begin(), test.end());
}

void insert() {
	std::cout << "_______\n";
	std::cout << "test insert\n";
	map<int, std::string> mapp;
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

	std::cout << "\ntest iterator insert(it hint, value)\n";
	displayMap(mapp);
	typename map<int, std::string>::iterator it = mapp.find(54);
	typename map<int, std::string>::iterator returnn = mapp.insert(it, pair<int, std::string>(85, "HERE"));
	displayMap(mapp);
	std::cout << "Ret de insert(hint, value) :" << returnn->first << "\n";
	it = mapp.find(99);
	returnn = mapp.insert(it, pair<int, std::string>(150, "HERE"));
	displayMap(mapp);
	it = mapp.find(0);
	returnn = mapp.insert(it, pair<int, std::string>(-4, "HERE"));
	displayMap(mapp);
	std::cout << "Ret de insert(hint, value) :" << returnn->first << "\n";

	map<int, std::string> l;
	l[3] = "8";
	l[0] = "0";
	l[4] = "4";
	l[2] = "2";
	l[1] = "1";
	std::cout << "Should be ordered : ";
	displayMap(l);

// // operator sur T (value_type.second) ne marche pas avec des int...
// 	map<int, int> m;
	// m[3] = 3;
	// m[0] = 0;
	// m[4] = 4;
	// m[2] = 2;
	// m[1] = 1;
	// std::cout << "Should be ordered : ";
	// displayMap(m);
}

void erase() {
	std::cout << "_______\n";
	std::cout << "test erase\n";
	map<int, std::string> test_erase;
	fillMapIntString(&test_erase);
	displayMap(test_erase);

	typename map<int, std::string>::iterator it = test_erase.begin();
	++it;
	++it;
	++it;
	std::cout << "erasing " << it->first << "\n";
	test_erase.erase(it);
	typename map<int, std::string>::iterator ite = test_erase.end();
	--ite;
	--ite;
	--ite;
	std::cout << "erasing " << ite->first << "\n";
	test_erase.erase(ite);
	typename map<int, std::string>::iterator itbis = test_erase.begin();
	std::cout << "erasing " << itbis->first << "\n";
	test_erase.erase(itbis);
	displayMap(test_erase);
}

void swap() {
	std::cout << "_______\n";
	std::cout << "test swap\n";
	map<int, std::string> src;
	map<int, std::string> other;
	fillMapIntString(&src);
	fillMapIntString(&other);

	typename map<int, std::string>::iterator it = src.begin();
	++it;
	typename map<int, std::string>::reference ref = *(src.begin());

	std::cout << "before swap :\n";
	std::cout << "src";
	displayMap(src);
	std::cout << "other";
	displayMap(other);
	std::cout << "iter of src :" << it->first << "\n";
	std::cout << "ref of src :" << ref.first << "\n";

	src.swap(other);

	std::cout << "after swap :\n";
	std::cout << "src";
	displayMap(src);
	std::cout << "other";
	displayMap(other);
	std::cout << "iter of src :" << it->first << "\n";
	std::cout << "ref of src :" << ref.first << "\n";

}

void test()
{
	clear();
	insert();
	erase();
	swap();
}