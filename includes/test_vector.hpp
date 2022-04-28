#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <type_traits>
#include "vector.hpp"
#include "tests.hpp"


// default(int) and specialisation float std::string myclass bool array
template<typename Vec, typename MyVec>
class Test_vector {

	public:

		Test_vector() {}
		~Test_vector() {}

		template<typename T>
		void displayVec(std::ofstream& out, T& vec) {

			typename T::iterator it;
			out << "display : ";
			for (it = vec.begin(); it != vec.end(); ++it){
				out << *it << " ";
			}
			out << "\n";
		}

		void display(std::ofstream& of, Vec& vec, std::ofstream& myof, MyVec& myvec) {

			Test_vector<Vec, MyVec>::displayVec(of, vec);
			Test_vector<Vec, MyVec>::displayVec(myof, myvec);
		}

		void test_constructors(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-constructors ✅\n";
			myof << "\ntest-constructors ✅\n";

			V vec;
			V bis(X, Y);
			V quatre(bis);

			//	----
			//	test constructor range

			//	->->->->->->->->->->-> CHANGE TYPE
			MYV myvec;
			MYV mybis(X, Y);
			MYV myquatre(mybis);
			//	->->->->->->->->->->-> CHANGE TYPE

			Test_vector<Vec, MyVec>::display(of, bis, myof, mybis);
			Test_vector<Vec, MyVec>::display(of, quatre, myof, myquatre);
		}

		void test_operators(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-operators ✅\n";
			myof << "\ntest-operators ✅\n";
		
			for (int i = 0;i < 10;++i) {
			
				srand (time(NULL));
				size_t nbr = rand() % 100;
				size_t val = rand() % 100;
				size_t nbr_tmp = rand() % 100;
				size_t val_tmp = rand() % 100;
		
				Vec vec(nbr, val);
				Vec tmp(nbr_tmp, val_tmp);
			//	->->->->->->->->->->-> CHANGE TYPE
				MyVec myvec(nbr, val);
				MyVec mytmp(nbr_tmp, val_tmp);
			//	->->->->->->->->->->-> CHANGE TYPE
		
			// !=
				if (myvec != mytmp) {
					printof(of, myof, "myvec != mytmp : true", 24);
				}
				else if (vec != tmp) {
					of << "myvec != mytmp : true\n";
					myof << "myvec != mytmp : false\n";
				}
		
			// <
				if (myvec < mytmp) {
					printof(of, myof, "myvec < mytmp : true", 33);
				}
				else if (vec < tmp) {
					of << "myvec < mytmp : true\n";
					myof << "myvec < mytmp : false\n";
				}
		
			// >
				if (myvec > mytmp) {
					printof(of, myof, "myvec > mytmp : true", 42);
				}
				else if (vec > tmp) {
					of << "myvec > mytmp : true\n";
					myof << "myvec > mytmp : false\n";
				}
			}
		}

		void test_it_arrow(std::ofstream& of, std::ofstream& myof) {(void)of;(void)myof;}

		void test_iterators(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-iterators ✅\n";
			myof << "\ntest-iterators ✅\n";

			//	->->->->->->->->->->-> CHANGE TYPE
			Vec vec(X, Y);
			typename Vec::iterator it = vec.begin();
			typename Vec::iterator ite = vec.end();
			MyVec myvec(X, Y);
			typename MyVec::iterator myit = myvec.begin();
			typename MyVec::iterator myite = myvec.end();
			//	->->->->->->->->->->-> CHANGE TYPE

			for (int i = 1; it != ite; ++it) {
				*it = i++;
			}
			Test_vector<Vec, MyVec>::displayVec(of, vec);
			for (int i = 1; myit != myite; ++myit) {
				*myit = i++;
			}
			Test_vector<Vec, MyVec>::displayVec(myof, myvec);

			it = vec.begin(); // to avoid reading vec.end() -> undefined behavior
			myit = myvec.begin();

			//	++(int)
			of << "it : " << *it << " | ";
			myof << "it : " << *myit << " | ";
			it++;
			myit++;
			of << "it++ : " << *it << "\n";
			myof << "it++ : " << *myit << "\n";

			//	--(int)
			of << "it : " << *it << " | ";
			myof << "it : " << *myit << " | ";
			it--;
			myit--;
			of << "it-- : " << *it << "\n";
			myof << "it-- : " << *myit << "\n";

			//	++()
			of << "it : " << *it << " | ";
			myof << "it : " << *myit << " | ";
			++it;
			++myit;
			of << "++it : " << *it << "\n";
			myof << "++it : " << *myit << "\n";

			//	--()
			of << "it : " << *it << " | ";
			myof << "it : " << *myit << " | ";
			--it;
			--myit;
			of << "--it : " << *it << "\n";
			myof << "--it : " << *myit << "\n";

			// +(int)
			it = it + 1;
			it = 1 + it;
			of << "it = it + 1 : " << *it << "\n";

			myit = myit + 1;
			myit = 1 + myit;
			myof << "it = it + 1 : " << *myit << "\n";

			// -(int)
			it = it - 1;
			of << "it = it + 1 : " << *it << "\n";

			myit = myit - 1;
			myof << "it = it + 1 : " << *myit << "\n";

			// +=(it)
			it += 2;
			of << "it += 2 : " << *it << "\n";

			myit += 2;
			myof << "it += 2 : " << *myit << "\n";

			// -=(int)
			it -= 2;
			of << "it -= 2 : " << *it << "\n";

			myit -= 2;
			myof << "it -= 2 : " << *myit << "\n";

			// []
			it = vec.begin();
			myit = myvec.begin();
			Test_vector<Vec, MyVec>::display(of, vec, myof, myvec);

			of << "it[0] : " << it[0] << " | it[3] : " << it[3] << "\n";
			myof << "it[0] : " << myit[0] << " | it[3] : " << myit[3] << "\n";

			//	->->->->->->->->->->-> CHANGE TYPE
			typename Vec::iterator itit = vec.begin();
			typename Vec::iterator tmp = itit + 3;
			typename MyVec::iterator myitit = myvec.begin();
			typename MyVec::iterator mytmp = myitit + 3;
			//	->->->->->->->->->->-> CHANGE TYPE

			// -(it)
			int i = itit - tmp;
			of << "int i = itit - tmp : " << i << "\n";

			int myi = myitit - mytmp;
			myof << "int i = itit - tmp : " << myi << "\n";

			for (int i = 0; i < 5; ++i) {
			
				srand (time(NULL));
				size_t nbr = rand() % (vec.size() - 1);
				size_t nbrbis = rand() % (vec.size() - 1);
				typename Vec::iterator ittest = vec.begin();
				*ittest = vec[nbr];
				typename Vec::iterator ittestbis = vec.begin();
				*ittestbis = vec[nbrbis];

				size_t mynbr = rand() % (myvec.size() - 1);
				size_t mynbrbis = rand() % (myvec.size() - 1);
				typename MyVec::iterator myittest = myvec.begin();
				*myittest = myvec[mynbr];
				typename MyVec::iterator myittestbis = myvec.begin();
				*myittestbis = myvec[mynbrbis];

				//	==
				if (*ittest == *ittestbis && *myittest == *myittestbis)
					printof(of, myof, "*ittest == *ittestbis : true", 131);
				else if (*ittest == *ittestbis) {
					of << "*ittest == *ittestbis : true\n";
			 		myof << "*ittest == *ittestbis : false\n";}

				//	!=
				if (*ittest != *ittestbis && *myittest != *myittestbis)
					printof(of, myof, "*ittest != *ittestbis : true", 138);
				else if (*ittest != *ittestbis) {
					of << "*ittest != *ittestbis : true\n";
			 		myof << "*ittest != *ittestbis : false\n";}

				//	<
				if (*ittest < *ittestbis && *myittest < *myittestbis)
					printof(of, myof, "*ittest < *ittestbis : true", 145);
				else if (*ittest < *ittestbis) {
					of << "*ittest < *ittestbis : true\n";
			 		myof << "*ittest < *ittestbis : false\n";}

				//	<=
				if (*ittest <= *ittestbis && *myittest <= *myittestbis)
					printof(of, myof, "*ittest <= *ittestbis : true", 152);
				else if (*ittest <= *ittestbis) {
					of << "*ittest <= *ittestbis : true\n";
			 		myof << "*ittest <= *ittestbis : false\n";}

				//	>
				if (*ittest > *ittestbis && *myittest > *myittestbis)
					printof(of, myof, "*ittest > *ittestbis : true", 159);
				else if (*ittest > *ittestbis) {
					of << "*ittest > *ittestbis : true\n";
			 		myof << "*ittest > *ittestbis : false\n";}

				//	>=
				if (*ittest >= *ittestbis && *myittest >= *myittestbis)
					printof(of, myof, "*ittest >= *ittestbis : true", 166);
				else if (*ittest >= *ittestbis) {
					of << "*ittest >= *ittestbis : true\n";
					myof << "*ittest >= *ittestbis : false\n";}
			}
			test_it_arrow(of, myof);
		}

		void test_accessors(std::ofstream& of, std::ofstream& myof) {
			
			of << "\ntest-accessors ✅\n";
			myof << "\ntest-accessors ✅\n";

			//	[] at front back data

			//	->->->->->->->->->->-> CHANGE TYPE
			V vec(20, 0);
			MYV myvec(20, 0);
			//	->->->->->->->->->->-> CHANGE TYPE
			// fill_vec(&vec, &myvec);
			// Test_vector<Vec, MyVec>::display(of, vec, myof, myvec);
		}



		void fill_vec(Vec* vec, MyVec* myvec) {	//int

			V::iterator it =vec->begin();
			MYV::iterator myit = myvec->begin();

			srand (time(NULL));

			for (size_t i = 0; i < vec->size(); ++i) {
				int val = rand() % 100;
				*it = val;
				*myit = val;
				++it;
				++myit;
			}
		}

	private:
};

// template<>		//function specilization
// void Test_vector<std::vector<std::string, ft::vector<std::string> >::fill_vec(Vec* vec, MyVec* myvec) {

// 	V::iterator it =vec->begin();
// 	MYV::iterator myit = myvec->begin();

// 	srand (time(NULL));

// 	std::string _tab[10] = { "test", "pop", "essay", "beeze", "youhou",
// 								"orange", "blue", "black", "sun", "best" };
// 	for (size_t i = 0; i < vec->size(); ++i) {
// 		int val = rand() % 10;
// 		*it = _tab[val];
// 		*myit = _tab[val];
// 		++it;
// 		++myit;
// 	}
// }

// template<>
// void Test_vector::<std::vector<std::string, ft::vector<std::string> >::test_it_arrow(std::ofstream& of, std::ofstream& myof) {

// 	// ->
// 	std::vector<std::string> test(4, "pop");
// 	std::vector<std::string>::iterator ittest = test.begin();
// 	if (!strcmp(ittest->c_str(), "pop"))
// 		of << "test operator -> ok \n";
// 	else
// 		of << "test operator -> ko \n";

// 	ft::vector<std::string> mytest(4, "pop");
// 	ft::vector<std::string>::iterator myittest = mytest.begin();
// 	if (!strcmp(myittest->c_str(), "pop"))
// 		myof << "test operator -> ok \n";
// 	else
// 		myof << "test operator -> ko \n";
// }

#endif