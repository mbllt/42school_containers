#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

#include <functional>
#include <memory>
#include "utility.hpp"

namespace ft {

template< class T >
class iterator_map {

	public:
		typedef std::bidirectional_iterator_tag					iterator_category;
		typedef T												value_type;
		typedef std::ptrdiff_t									difference_type;
		typedef value_type*										pointer;
		typedef value_type&										reference;
		typedef typename GenerateNodeType<value_type>::type		node;
		typedef node*											node_pointer;

	private:
		node_pointer p;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		iterator_map() : p() {}
		iterator_map(const node_pointer new_node) : p(new_node) {}
		iterator_map(const iterator_map& copy) : p(copy.p) {}
		~iterator_map() {}

		node* getP() const { return p; }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator_map&		operator=(const iterator_map& src) {p = src.p; return *this;}
		reference			operator*() {return p->value;}
		pointer				operator->() {return &(p->value);}
		iterator_map&		operator++() {
			if (p->right) {
				p = p->right;
				while (p->left) {
					p = p->left;
				}
			}
			else if (p->parent) {
				node *tmp = p;
				while (tmp == tmp->parent->right)
					tmp = tmp->parent;
				p = tmp->parent;
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
				node *tmp = p;
				while (tmp == tmp->parent->left)
					tmp = tmp->parent;
				p = tmp->parent;
			}
			return *this;
		}

		iterator_map		operator--(const int n) {
			(void)n;
			iterator_map tmp(*this);
			operator--();
			return tmp;
		}

		template<class A>
		friend bool operator==(const iterator_map src, const iterator_map<A> cmp) {return (src.getP() == cmp.getP());}

		template<class A>
		friend bool operator!=(const iterator_map src, const iterator_map<A> cmp) {return !(src == cmp);}

};

}

#endif