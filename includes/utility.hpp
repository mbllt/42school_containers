#pragma once

#include "iterator_traits.hpp"
#include <uchar.h>

#define IS_INTEGRAL(TYPE)	  \
	template <>			    \
	struct is_integral<TYPE> { \
		enum { value = true }; \
	}

namespace ft {

template <typename A, typename B>
	struct is_same {
		enum { value = false };
	};

template <typename T>
	struct is_same<T, T> {
		enum { value = true };
	};

template <typename T>
	struct is_integral {
		enum { value = false };
	};

	IS_INTEGRAL(bool);
	IS_INTEGRAL(char);
	IS_INTEGRAL(char16_t);
	IS_INTEGRAL(char32_t);
	IS_INTEGRAL(wchar_t);
	IS_INTEGRAL(short);
	IS_INTEGRAL(int);
	IS_INTEGRAL(long);
	IS_INTEGRAL(long long);

template <bool cond, typename T>		// declaration de ma structure
	struct enable_if;

template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

template <typename T>
	struct enable_if<false, T> {		// compile time : no error if tries to
	};									// read a type that is not there -> SFINAE
										// Substitution Failure Is Not An Error

template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

template< class T1, class T2 >
	struct pair {

			typedef T1 first_type;
			typedef T2 second_type;

			first_type first;
			second_type second;

			pair() : first(T1()), second(T2()) {}

		template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

			pair (const first_type& a, const second_type& b) : first(a), second(b) {}

			pair & operator=(const pair& src) {first = src.first; second = src.second; return *this;}

	};


template< class T1, class T2 >
	bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

template< class T1, class T2 >
	bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		return !(lhs == rhs);
	}

template< class T1, class T2 >
	bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if (lhs.first < rhs.first)
				return true;
		else if (lhs.first == rhs.first)
			if (lhs.second < rhs.second)
				return true;
		return false;
	}

template< class T1, class T2 >
	bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if (lhs == rhs)
			return true;
		return lhs < rhs;
	}

template< class T1, class T2 >
	bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if (lhs == rhs)
			return false;
		return !(lhs < rhs);
	}

template< class T1, class T2 >
	bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		return !(lhs < rhs);
	}

template< class T1, class T2 >
	ft::pair<T1,T2> make_pair( T1 t, T2 u ) {
		return ft::pair<T1, T2>(t, u);
	}

template< class Arg1, class Arg2, class Result >
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

template<class T>
	struct Node {
		Node() :
			value(T()), left(NULL), right(NULL), parent(NULL), root(NULL) {}
		Node(T val) :
			value(val), left(NULL), right(NULL), parent(NULL), root(NULL) {}
		template< class A>
		Node(const Node<A>& copy) :
			value(copy.value), left(copy.left), right(copy.right), parent(copy.parent), root(NULL) {}

		Node& operator=(const Node& src) {
			value = src.value;
			left = src.left;
			right = src.right;
			parent = src.parent;
			root = src.root;
			return *this;
		}
		T			value;
		Node*		left;
		Node*		right;
		Node*		parent;
		Node*		root;
	};


template <class Pair>
	struct GenerateNodeType {
		typedef Node<Pair> type;
	};

template <class Pair>
	struct GenerateNodeType<const Pair> {
		typedef const Node<Pair> type;
	};

template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2) 
	{
		while (first1!=last1)
		{
			if (first2==last2)
				return false;
			else if (*first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, Compare comp) 
	{
		while (first1!=last1)
		{
			if (first2==last2)
				return false;
			else if ((comp(*first2, *first1)))
				return false;
			else if ((comp(*first1, *first2)))
				return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

}

#undef IS_INTEGRAL