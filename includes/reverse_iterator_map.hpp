#ifndef REVERSE_ITERATOR_MAP_HPP
#define REVERSE_ITERATOR_MAP_HPP

#include <functional>
#include <memory>
#include "utility.hpp"

namespace ft {

template< class T >
class reverse_iterator_map {

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

		reverse_iterator_map() : p() {}
		reverse_iterator_map(node_pointer new_node) : p(new_node) {}
		reverse_iterator_map(reverse_iterator_map const & copy) : p(copy.p) {}
		~reverse_iterator_map() {}

		value_type getP() const { return (p->value); }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		reverse_iterator_map&		operator=(const reverse_iterator_map& src) {p = src.p; return *this;}

		reference			operator*() {return p->value;}
		const_reference		operator*() const {return p->value;}

		pointer				operator->() {return &(p->value);}
		const_pointer		operator->() const {return &(p->value);}

		reverse_iterator_map&		operator++() {

			if (p->left) {
				p = p->left;
				while (p->right) {
					p = p->right;
				}
			}
			else if (p->parent) {
				while (p->parent && (p->value).first < (p->parent->value).first)
					p = p->parent;
			}
			return *this;
		}

		reverse_iterator_map		operator++(const int n) {
			(void)n;
			reverse_iterator_map tmp(*this);
			operator++();
			return tmp;
		}

		reverse_iterator_map&		operator--() {
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

		reverse_iterator_map		operator--(const int n) {
			(void)n;
			reverse_iterator_map tmp(*this);
			operator--();
			return tmp;
		}

		template <typename A, typename B>
			friend bool		operator==(const ft::reverse_iterator_map<A> src,
										const ft::reverse_iterator_map<B> cmp)
			{return (src.getP() == cmp.getP());}

		template <typename A, typename B>
			friend bool		operator!=(const ft::reverse_iterator_map<A> src,
										const ft::reverse_iterator_map<B> cmp)
			{return !(src == cmp);}

};

}

#endif