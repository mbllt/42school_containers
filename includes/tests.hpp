#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "vector.hpp"
#include <vector>
#include "stack.hpp"
#include <stack>

template<typename Container>
void displayCont(Container& vec) {
		std::cout << "{ ";
		for (typename Container::iterator it = vec.begin(); it != vec.end(); ++it){
			std::cout << *it << " ";
		}
		std::cout << "}\n";
	}

// template<typename Vec>
// void fillVecInt(Vec* cont) {
// 	typename Vec::iterator it =cont->begin();

// 		for (size_t i = 0; i < cont->size(); ++i) {
// 			int val = rand() % 100;
// 			*it = val;
// 			++it;
// 		}
// 	}

// template<typename Vec>
// void fillVecString(Vec* cont) {

// 	typename Vec::iterator it = cont->begin();

// 	std::string str[10] = { "test", "pop", "essay", "beeze", "youhou",
// 								"orange", "blue", "black", "sun", "best" };
// 	for (size_t i = 0; i < cont->size(); ++i) {
// 		int val = rand() % 10;
// 		*it = str[val];
// 		++it;
// 	}
// }


#endif