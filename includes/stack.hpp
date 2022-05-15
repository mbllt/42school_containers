#ifndef stack_HPP
#define stack_HPP

#include <iostream>
#include <deque>

namespace ft {

template<typename T, class Container = std::deque<T> >
class stack {

	public:

		typedef Container 								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;

	protected :

		container_type	c;

	public :

//	--------------->> CONSTRUCTORS <<---------------

		explicit stack( const Container& cont = Container() ) : c(cont) {}

		~stack() {}

//	------------------------------------------------


//	----------------->> GENERAL <<------------------

		stack & operator=(const stack &other) {
			c = other.c;
			return *this;
		}

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

	reference top() {return c.back();}

	const_reference top() const {return c.back();}


//	------------------------------------------------


//	---------------->> CAPACITY <<------------------

	bool empty() const {return c.empty();}

	size_type size() const {return c.size();}

//	------------------------------------------------


//	--------------->> MODIFIERS <<------------------

	void push( const value_type& value ) {c.push_back(value);}

	void pop() {c.pop_back();}

//	------------------------------------------------


//	--------------->> OPERATORS <<------------------

	friend bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {return lhs.c == rhs.c;}

	friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {return lhs.c != rhs.c;}

	friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {return lhs.c < rhs.c;}

	friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {return lhs.c <= rhs.c;}

	friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {return lhs.c > rhs.c;}

	friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {return lhs.c >= rhs.c;}

};

}

#endif