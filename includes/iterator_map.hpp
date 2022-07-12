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

		iterator_map() : p() {}
		iterator_map(node_pointer new_node) : p(new_node) {}
		iterator_map(const iterator_map& copy) : p(copy.p) {}
		~iterator_map() {}

		value_type getP() const { return (p->value); }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator_map&		operator=(const iterator_map& src) {p = src.p; return *this;}

		reference			operator*() {return p->value;}
		const_reference		operator*() const {return p->value;}

		pointer				operator->() {return &(p->value);}
		const_pointer		operator->() const {return &(p->value);}

		iterator_map&		operator++() {

			if (!(p->right) && !(p->left)) {
				node *tmp = p->parent;
				while (tmp && (p->value).first < (tmp->value).first)
					tmp = tmp->parent;
				if (!tmp) {
					p = p->parent;
					return *this;
				}
			}
			if (p->right) {
				p = p->right;
				while (p->left) {
					p = p->left;
				}
			}
			else if (p->parent) {
				node *tmp = p->parent;
				while (tmp && (p->value).first > (tmp->value).first)
					tmp = tmp->parent;
				p = tmp;
			}
			return *this;
		}

		iterator_map		operator++(const int n) {
			(void)n;
			iterator_map tmp(*this);
			operator++();
			return tmp;
		}

		iterator_map&		operator--() {
			if (p->left) {
				p = p->left;
				while (p->right) {
					p = p->right;
				}
			}
			else if (p->parent) {
				node *tmp = p->parent;
				while (tmp && (p->value).first < (tmp->value).first)
					tmp = tmp->parent;
				p = tmp;
			}
			return *this;
		}

		iterator_map		operator--(const int n) {
			(void)n;
			iterator_map tmp(*this);
			operator--();
			return tmp;
		}

		template <typename A, typename B>
			friend bool		operator==(const ft::iterator_map<A> src,
										const ft::iterator_map<B> cmp)
			{return (src.getP() == cmp.getP());}

		template <typename A, typename B>
			friend bool		operator!=(const ft::iterator_map<A> src,
										const ft::iterator_map<B> cmp)
			{return !(src == cmp);}

};

}

#endif