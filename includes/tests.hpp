#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <type_traits>
#include "vector.hpp"

#define X 5
#define Y 10
#define TYPE int // int float std::string myclass bool array
#define V std::vector<TYPE>
#define MYV ft::vector<TYPE>

void testVector(void);
void printof(std::ofstream& of, std::ofstream& myof, std::string str, size_t n);

#endif