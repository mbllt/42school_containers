#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


template<typename Vec>
void displayVec(Vec& vec) {
	std::cout << "{ ";
	for (typename Vec::iterator it = vec.begin(); it != vec.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << "}\n";
}

template<typename Vec>
void fillVecInt(Vec* cont) {

	srand (time(NULL));

	typename Vec::iterator it =cont->begin();

	for (size_t i = 0; i < cont->size(); ++i) {
		int val = rand() % 100;
		*it = val;
		++it;
	}
}

template<typename Vec>
void fillVecString(Vec* cont) {

	srand (time(NULL));

	typename Vec::iterator it = cont->begin();

	std::string str[10] = { "test", "pop", "essay", "beeze", "youhou",
								"orange", "blue", "black", "sun", "best" };
	for (size_t i = 0; i < cont->size(); ++i) {
		int val = rand() % 10;
		*it = str[val];
		++it;
	}
}

template<typename Map>
void displayMap(Map& map) {

	if (map.empty()) {
		std::cout << "\n";
		return ;
	}

	// std::cout << "end :" << (map.end())->first << std::endl;

	// typename Map::iterator it = map.begin();

	// for (int i = 0;i < 5;++i) {
	std::cout << "{ ";
	for (typename Map::iterator it = map.begin(); it != map.end();++it) {
		std::cout << "(" << it->first << ";" << it->second << ")" << " ";
		// ++it;
	}
	std::cout << "}\n";
}

#endif