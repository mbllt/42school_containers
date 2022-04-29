#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tests.hpp"
#include "vector.hpp"

// default(int) and specialisation std::string vector<int>
template<typename Value>
class TestVector {

	public:

		TestVector() {}
		~TestVector() {}

		template<typename T>
		void displayVec(std::ofstream& out, T& vec) {

			typename T::iterator it;
			out << "display : ";
			for (it = vec.begin(); it != vec.end(); ++it){
				out << *it << " ";
			}
			out << "\n";
		}

		void display(std::ofstream& of, std::vector<Value>& vec, std::ofstream& myof, ft::vector<Value>& myvec) {

			TestVector<Value>::displayVec(of, vec);
			TestVector<Value>::displayVec(myof, myvec);
		}

		void test_constructors(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-constructors ✅\n";
			myof << "\ntest-constructors ✅\n";

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			std::vector<Value> bis;
			ft::vector<Value> mybis;
			TestVector<Value>::fill_vec(&bis, &mybis);
			std::vector<Value> quatre(bis);
			ft::vector<Value> myquatre(mybis);

			const std::vector<Value> vecconst(20, Value());
			const ft::vector<Value> myvecconst(20, Value());
			const std::vector<Value> bisconst;
			const ft::vector<Value> mybisconst;
			const std::vector<Value> quatreconst(vecconst);
			const ft::vector<Value> myquatreconst(myvecconst);
			//	----
			//	test constructor range


			TestVector<Value>::display(of, bis, myof, mybis);
			TestVector<Value>::display(of, quatre, myof, myquatre);
		}

		void test_operators(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-operators ✅\n";
			myof << "\ntest-operators ✅\n";
		
			for (int i = 0;i < 10;++i) {
		
				std::vector<Value> vec(20,  Value());
				ft::vector<Value> myvec(20,  Value());
				TestVector<Value>::fill_vec(&vec, &myvec);
				std::vector<Value> tmp(20,  Value());
				ft::vector<Value> mytmp(20,  Value());
				TestVector<Value>::fill_vec(&tmp, &mytmp);
		
			// !=
				if (myvec != mytmp) {
					printof(of, myof, "myvec != mytmp : ok", 24);
				}
				else if (vec != tmp) {
					of << "myvec != mytmp : ok\n";
					myof << "myvec != mytmp : koooo\n";
				}
		
			// <
				if (myvec < mytmp) {
					printof(of, myof, "myvec < mytmp : ok", 33);
				}
				else if (vec < tmp) {
					of << "myvec < mytmp : ok\n";
					myof << "myvec < mytmp : koooo\n";
				}
		
			// >
				if (myvec > mytmp) {
					printof(of, myof, "myvec > mytmp : ok", 42);
				}
				else if (vec > tmp) {
					of << "myvec > mytmp : ok\n";
					myof << "myvec > mytmp : koooo\n";
				}
			}
		}

		void test_it_arrow(std::ofstream& of, std::ofstream& myof) {(void)of;(void)myof;}

		void test_iterators(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-iterators ✅\n";
			myof << "\ntest-iterators ✅\n";

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			TestVector<Value>::fill_vec(&vec, &myvec);
			TestVector<Value>::display(of, vec, myof, myvec);

			typename std::vector<Value>::iterator it = vec.begin();
			typename ft::vector<Value>::iterator myit = myvec.begin();

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
			of << "it = it - 1 : " << *it << "\n";

			myit = myit - 1;
			myof << "it = it - 1 : " << *myit << "\n";

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

			of << "it[0] : " << it[0] << " | it[3] : " << it[3] << "\n";
			myof << "it[0] : " << myit[0] << " | it[3] : " << myit[3] << "\n";

			typename std::vector<Value>::iterator itit = vec.begin();
			typename std::vector<Value>::iterator tmp = itit + 3;
			typename ft::vector<Value>::iterator myitit = myvec.begin();
			typename ft::vector<Value>::iterator mytmp = myitit + 3;

			// -(it)
			int i = itit - tmp;
			of << "int i = itit - tmp : " << i << "\n";

			int myi = myitit - mytmp;
			myof << "int i = itit - tmp : " << myi << "\n";

			for (int i = 0; i < 5; ++i) {
			
				srand (time(NULL));
				size_t nbr = rand() % (vec.size() - 1);
				size_t nbrbis = rand() % (vec.size() - 1);
				typename std::vector<Value>::iterator ittest = vec.begin();
				*ittest = vec[nbr];
				typename std::vector<Value>::iterator ittestbis = vec.begin();
				*ittestbis = vec[nbrbis];

				size_t mynbr = rand() % (myvec.size() - 1);
				size_t mynbrbis = rand() % (myvec.size() - 1);
				typename ft::vector<Value>::iterator myittest = myvec.begin();
				*myittest = myvec[mynbr];
				typename ft::vector<Value>::iterator myittestbis = myvec.begin();
				*myittestbis = myvec[mynbrbis];

				//	==
				if (*ittest == *ittestbis && *myittest == *myittestbis)
					printof(of, myof, "*ittest == *ittestbis : ok", 131);
				else if (*ittest == *ittestbis) {
					of << "*ittest == *ittestbis : ok\n";
			 		myof << "*ittest == *ittestbis : koooo\n";}

				//	!=
				if (*ittest != *ittestbis && *myittest != *myittestbis)
					printof(of, myof, "*ittest != *ittestbis : ok", 138);
				else if (*ittest != *ittestbis) {
					of << "*ittest != *ittestbis : ok\n";
			 		myof << "*ittest != *ittestbis : koooo\n";}

				//	<
				if (*ittest < *ittestbis && *myittest < *myittestbis)
					printof(of, myof, "*ittest < *ittestbis : ok", 145);
				else if (*ittest < *ittestbis) {
					of << "*ittest < *ittestbis : ok\n";
			 		myof << "*ittest < *ittestbis : koooo\n";}

				//	<=
				if (*ittest <= *ittestbis && *myittest <= *myittestbis)
					printof(of, myof, "*ittest <= *ittestbis : ok", 152);
				else if (*ittest <= *ittestbis) {
					of << "*ittest <= *ittestbis : ok\n";
			 		myof << "*ittest <= *ittestbis : koooo\n";}

				//	>
				if (*ittest > *ittestbis && *myittest > *myittestbis)
					printof(of, myof, "*ittest > *ittestbis : ok", 159);
				else if (*ittest > *ittestbis) {
					of << "*ittest > *ittestbis : ok\n";
			 		myof << "*ittest > *ittestbis : koooo\n";}

				//	>=
				if (*ittest >= *ittestbis && *myittest >= *myittestbis)
					printof(of, myof, "*ittest >= *ittestbis : ok", 166);
				else if (*ittest >= *ittestbis) {
					of << "*ittest >= *ittestbis : ok\n";
					myof << "*ittest >= *ittestbis : koooo\n";}
			}
			test_it_arrow(of, myof);
		}

		void test_capacity(std::ofstream& of, std::ofstream& myof) {
			
			of << "\ntest-capacity ✅\n";
			myof << "\ntest-capacity ✅\n";

			//	empty size max_size reserve capacity

			std::vector<Value> emptyvec;
			ft::vector<Value> myemptyvec;

			// empty
			if (emptyvec.empty() == myemptyvec.empty())
				printof(of, myof, "emptyvec.empty() == myemptyvec.empty() : ok", 284);
			else {
				of << "emptyvec.empty() == myemptyvec.empty() : ok | l.300\n";
				myof << "emptyvec.empty() == myemptyvec.empty() : koooo work | l.300\n";
			}

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			TestVector<Value>::fill_vec(&vec, &myvec);

			// size
			if (vec.size() == myvec.size())
				printof(of, myof, "vec.size() == myvec.size() : ok", 284);
			else {
				of << "vec.size() == myvec.size() : ok | l.300\n";
				myof << "vec.size() == myvec.size() : koooo work | l.300\n";
			}

			// max_size
			if (vec.max_size() == myvec.max_size())
				printof(of, myof, "vec.max_size() == myvec.max_size() : ok", 284);
			else {
				of << "vec.max_size() == myvec.max_size() : ok | l.300\n";
				myof << "vec.max_size() == myvec.max_size() : koooo work | l.300\n";
			}

			// capacity
			if (vec.capacity() == myvec.capacity())
				printof(of, myof, "vec.capacity() == myvec.capacity() : ok", 284);
			else {
				of << "vec.capacity() == myvec.capacity() : ok | l.300\n";
				myof << "vec.capacity() == myvec.capacity() : koooo work | l.300\n";
			}
		}

		void test_accessors(std::ofstream& of, std::ofstream& myof) {
			
			of << "\ntest-accessors ✅\n";
			myof << "\ntest-accessors ✅\n";

			//	[] at front back data

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			TestVector<Value>::fill_vec(&vec, &myvec);
			TestVector<Value>::display(of, vec, myof, myvec);

			// []
			if (vec[0] == myvec[0])
				printof(of, myof, "vec[0] == myvec[0] : ok", 284);
			else {
				of << "vec[0] == myvec[0] : ok | l.300\n";
				myof << "vec[0] == myvec[0] : koooo | l.300\n";
			}
			
			// at
			if (vec.at(0) == myvec.at(0))
				printof(of, myof, "vec.at() == myvec.at() : ok", 290);
			else {
				of << "vec.at(0) == myvec.at(0) : ok | l.300\n";
				myof << "vec.at(0) == myvec.at(0) : koooo | l.300\n";
			}

			// front
			if (vec.front() == myvec.front())
				printof(of, myof, "vec.front() == myvec.front() : ok", 291);
			else {
				of << "vec.front() == myvec.front() : ok | l.300\n";
				myof << "vec.front() == myvec.front() : koooo | l.300\n";
			}

			// back
			if (vec.back() == myvec.back())
				printof(of, myof, "vec.back() == myvec.back() : ok", 290);
			else {
				of << "vec.back() == myvec.back() : ok | l.300\n";
				myof << "vec.back() == myvec.back() : koooo | l.300\n";
			}
		}

		void fill_vec(std::vector<Value>* vec, ft::vector<Value>* myvec) {	//int

			typename std::vector<Value>::iterator it =vec->begin();
			typename ft::vector<Value>::iterator myit = myvec->begin();

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

template<>		//function specilization
void TestVector<std::string>::fill_vec(std::vector<std::string>* vec, ft::vector<std::string>* myvec) {

	std::vector<std::string>::iterator it = vec->begin();
	ft::vector<std::string>::iterator myit = myvec->begin();

	std::string _tab[10] = { "test", "pop", "essay", "beeze", "youhou",
								"orange", "blue", "black", "sun", "best" };
	for (size_t i = 0; i < vec->size(); ++i) {
		int val = rand() % 10;
		*it = _tab[val];
		*myit = _tab[val];
		++it;
		++myit;
	}
}

template<>
void TestVector<std::string>::test_it_arrow(std::ofstream& of, std::ofstream& myof) {

	// ->
	std::vector<std::string> test(4, "pop");
	std::vector<std::string>::iterator ittest = test.begin();
	if (!strcmp(ittest->c_str(), "pop"))
		of << "test -> ok \n";
	else
		of << "test -> koooo \n";

	ft::vector<std::string> mytest(4, "pop");
	ft::vector<std::string>::iterator myittest = mytest.begin();
	if (!strcmp(myittest->c_str(), "pop"))
		myof << "test -> ok \n";
	else
		myof << "test -> koooo \n";
}

// template<>
// void TestVector<std::vector<int> >::fill_vec(std::vector<std::vector<int> >* vec, ft::vector<std::vector<int> >* myvec) {

// 	srand (time(NULL));

// 	for (size_t i = 0; i < vec->size(); ++i) {
// 		int val = rand() % 100;
		// vec.push_back(std::vector<int>(val, val + vec[i].size()));
		// myvec.push_back(std::vector<int>(val, val + myvec[i].size()));
	// }
// }

#endif