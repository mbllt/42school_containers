#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

#include <functional>
#include <memory>
#include "utility.hpp"

namespace ft {

template< class T >
class iterator_map {

	public:
		typedef T							value_type;
		typedef Node<value_type>			node;
		typedef node*						node_pointer;
		typedef std::ptrdiff_t				difference_type;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;

	private:

		node_pointer p;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		iterator_map() {p->value = value_type();p->left = 0;p->right = 0;p->parent = 0;}
		iterator_map(node_pointer new_node) : p(new_node) {}
		iterator_map(iterator_map const & copy) : p(copy.p) {}
		~iterator_map() {}

		pointer getP() const { return (p->value); }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator_map&					operator=(const iterator_map& src) {p = src.p; return *this;}

		reference						operator*() {return p->value;}
		const_reference					operator*() const {return p->value;}

		pointer							operator->() {return &(p->value);}
		const_pointer					operator->() const {return &(p->value);}

		iterator_map&					operator++() {++p;return *this;}

		iterator_map					operator++(const int n) {(void)n;iterator_map tmp(*this); operator++(); return tmp;}

		iterator_map&					operator--() {--p;return *this;}

		template <typename A, typename B>
			friend bool	operator==(const ft::iterator_map<A> src,
									const ft::iterator_map<B> cmp)
									{return (src.getP() == cmp.getP());}

		template <typename A, typename B>
			friend bool	operator!=(const ft::iterator_map<A> src,
									const ft::iterator_map<B> cmp)
									{return (src.getP() != cmp.getP());}

};

}

#endif