#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void	vec_general();
// void	vec_ope();
// void	vec_it();
// void	vec_rev_it();
// void	vec_capacity();
// void	vec_accessors();
// void	vec_resize();
// void	vec_push_back();
// void	vec_pop_back();
// void	vec_swap();
// void	vec_clear();
// void	vec_erase();
// void	vec_insert();

// void	stack_all();

// void	map_general();

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

#endif