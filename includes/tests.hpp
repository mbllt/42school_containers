#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utility.hpp"


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


template<typename It>
void displayMapNode(It& it) {
	std::cout << "(" << it->first << ";" << it->second << ") ";
}
template<typename Map>
void displayMap(Map& map) {
	if (map.empty()) {
		std::cout << "map is empty\n";
		return ;
	}
	std::cout << "map : { ";
	for (typename Map::iterator it = map.begin(); it != map.end();++it) {
		displayMapNode(it);
	}
	std::cout << "}\n";
}

#ifdef MINE
  using namespace ft;
#else
  using namespace std;
#endif

template<typename Map>
void fillMapIntString(Map *map) {

	std::string str[20] = { "test", "pop", "essay", "beeze", "youhou",
							"orange", "blue", "black", "sun", "best",
							"yes", "nine", "kakao", "lione", "search",
							"biking", "mont-blanc", "testing", "ring", "marvelous"};
	// for (int i = 1; i < 11; ++i) {
	// 	int val = rand() % 20;
	// 	int integer = rand() % 100;
	// 	map->insert(pair<const int, std::string>(integer, str[val]));
	// }
	map->insert(pair<const int, std::string>(50, "test"));
	map->insert(pair<const int, std::string>(86, "test"));
	map->insert(pair<const int, std::string>(90, "test"));
	map->insert(pair<const int, std::string>(100, "test"));
	map->insert(pair<const int, std::string>(70, "test"));
	map->insert(pair<const int, std::string>(76, "test"));
}


#endif