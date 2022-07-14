#ifndef REVERSE_ITERATOR_MAP_HPP
#define REVERSE_ITERATOR_MAP_HPP

#include "iterator_traits.hpp"

namespace ft {

template< class Iterator >
class reverse_iterator_map {

	public:
		typedef Iterator													iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename iterator_traits<Iterator>::value_type				value_type;
		typedef typename iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename iterator_traits<Iterator>::pointer					pointer;
		typedef typename iterator_traits<Iterator>::reference				reference;

	private:

		iterator_type _base;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		reverse_iterator_map() : _base() {}
		explicit reverse_iterator_map (iterator_type it) : _base(it) {}
		template <class Iter>
			reverse_iterator_map (const reverse_iterator_map<Iter>& rev_it) : _base(rev_it._base) {}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator_type base() const {return _base;}

		reference operator*() const {
			iterator_type tmp = _base;
			// return *--tmp;
			return *tmp;
		}

		reverse_iterator_map operator+ (difference_type n) const {
			return reverse_iterator(_base - n);
		}

		reverse_iterator_map& operator++() {
			--_base;
			return *this;
		}

		reverse_iterator_map  operator++(int) {
			reverse_iterator_map tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator_map& operator+= (difference_type n) {
			_base -= n;
			return *this;
		}

		reverse_iterator_map operator- (difference_type n) const {
			return reverse_iterator(_base + n);
		}

		reverse_iterator_map& operator--() {
			++_base;
			return *this;
		}

		reverse_iterator_map  operator--(int) {
			reverse_iterator_map tmp = *this;
			--*this;
			return tmp;
		}

		reverse_iterator_map& operator-= (difference_type n) {
			_base += n;
			return *this;
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return *(*this + n);
		}

//	--------------->> NON MEMBERS <<----------------

friend bool operator== (const reverse_iterator_map<Iterator>& lhs, const reverse_iterator_map<Iterator>& rhs) {return lhs._base == rhs._base;}
friend bool operator!= (const reverse_iterator_map<Iterator>& lhs, const reverse_iterator_map<Iterator>& rhs) {return !(lhs._base == rhs._base);}
friend bool operator<  (const reverse_iterator_map<Iterator>& lhs, const reverse_iterator_map<Iterator>& rhs) {return lhs._base > rhs._base;}
friend bool operator<= (const reverse_iterator_map<Iterator>& lhs, const reverse_iterator_map<Iterator>& rhs) {return lhs._base >= rhs._base;}
friend bool operator>  (const reverse_iterator_map<Iterator>& lhs, const reverse_iterator_map<Iterator>& rhs) {return lhs._base < rhs._base;}
friend bool operator>= (const reverse_iterator_map<Iterator>& lhs, const reverse_iterator_map<Iterator>& rhs) {return lhs._base <= rhs._base;}
friend reverse_iterator_map<Iterator> operator+ (typename reverse_iterator_map<Iterator>::difference_type n, const reverse_iterator_map<Iterator>& rev_it) {return rev_it._base+n;}
friend typename reverse_iterator_map<Iterator>::difference_type operator- (const reverse_iterator_map<Iterator>& lhs, const reverse_iterator_map<Iterator>& rhs) {return lhs._base - rhs._base;}

};

}

#endif