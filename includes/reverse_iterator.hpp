#ifndef reverse_iterator_HPP
#define reverse_iterator_HPP

#include "iterator_traits.hpp"

namespace ft {

template< class Iterator >
class reverse_iterator {

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

		reverse_iterator() : _base() {}
		explicit reverse_iterator (iterator_type it) : _base(it) {}
		template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it.getBase()) {}

		iterator_type getBase() const { return _base; }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator_type base() const {return _base;}

		reference operator*() const {
			iterator_type tmp = _base;
			return *--tmp;
		}

		reverse_iterator operator+ (difference_type n) {
			return reverse_iterator((_base - n));
		}

		reverse_iterator& operator++() {
			--_base;
			return *this;
		}

		reverse_iterator  operator++(int) {
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator& operator+= (difference_type n) {
			_base -= n;
			return *this;
		}

		reverse_iterator operator- (difference_type n) {
			return reverse_iterator((_base + n));
		}

		reverse_iterator& operator--() {
			++_base;
			return *this;
		}

		reverse_iterator  operator--(int) {
			reverse_iterator tmp = *this;
			--*this;
			return tmp;
		}

		reverse_iterator& operator-= (difference_type n) {
			_base += n;
			return *this;
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			reverse_iterator tmp = *this;
			return *(tmp + n);
		}

//	--------------->> NON MEMBERS <<----------------

friend reverse_iterator operator+(difference_type n, reverse_iterator& it) {
	reverse_iterator tmp = it;
	return (tmp += n);
}

friend reverse_iterator operator-(difference_type n, reverse_iterator& it) {
	reverse_iterator tmp = it;
	return (tmp -= n);
}

friend bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return lhs._base == rhs._base;}
friend bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return !(lhs._base == rhs._base);}
friend bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return lhs._base > rhs._base;}
friend bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return lhs._base >= rhs._base;}
friend bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return lhs._base < rhs._base;}
friend bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return lhs._base <= rhs._base;}
friend reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
	Iterator p = rev_it._base;
	return reverse_iterator(p+n);
}
friend typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	Iterator l = lhs._base;
	Iterator r = rhs._base;
	return r - l;
}

};

}

#endif