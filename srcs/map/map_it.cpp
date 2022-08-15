#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "iterators\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	map<int, std::string>::iterator it = mapp.begin();

	//	it++
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	it++;
	std::cout << "it++ : ";
	displayMapNode(it);
	std::cout << "\n";

	//	it--
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	it--;
	std::cout << "it-- : ";
	displayMapNode(it);
	std::cout << "\n";

	//	++it
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	++it;
	std::cout << "++it : ";
	displayMapNode(it);
	std::cout << "\n";

	//	--it
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	--it;
	std::cout << "--it : ";
	displayMapNode(it);
	std::cout << "\n";

	std::cout << "_______\n";
	std::cout << "const iterators\n";
	map<int, std::string> bis;
	fillMapIntString(&bis);
	displayMap(bis);

	map<int, std::string>::iterator itbis = bis.begin();

	//	it++
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	itbis++;
	std::cout << "itbis++ : ";
	displayMapNode(itbis);
	std::cout << "\n";

	//	it--
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	itbis--;
	std::cout << "itbis-- : ";
	displayMapNode(itbis);
	std::cout << "\n";

	//	++it
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	++itbis;
	std::cout << "++itbis : ";
	displayMapNode(itbis);
	std::cout << "\n";

	//	--it
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	--itbis;
	std::cout << "--itbis : ";
	displayMapNode(itbis);
	std::cout << "\n";

	mapp.clear();
	std::cout << "clearing map\n";
	std::cout << "--itbis : ";
	displayMapNode(itbis);
	std::cout << "\n";
}