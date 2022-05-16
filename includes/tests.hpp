#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>

void  vec_general();
void  vec_ope();

template<typename Container>
void displayCont(Container& vec) {
	std::cout << "{ ";
	for (typename Container::iterator it = vec.begin(); it != vec.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << "}\n";
}

#endif