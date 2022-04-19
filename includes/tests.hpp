#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "vector.hpp"

#define X 5
#define Y 10
#define V std::vector<int>
#define MYV ft::vector<int>

template<typename T>
void displayVec(std::ofstream& out, T& vec) {

	typename T::iterator it;
	out << "display : ";
	for (it = vec.begin(); it != vec.end(); ++it){
		out << *it << " ";
	}
	out << "\n";
}

template<typename T>
void display(std::ofstream& of, V& vec, std::ofstream& myof, T& myvec) {

	displayVec(of, vec);
	displayVec(myof, myvec);
}

void testVector(void);
void test_constructors(std::ofstream& of, std::ofstream& myof);
void test_operators(std::ofstream& of, std::ofstream& myof);
void test_iterators(std::ofstream& of, std::ofstream& myof);
void printof(std::ofstream& of, std::ofstream& myof, std::string str);

#endif