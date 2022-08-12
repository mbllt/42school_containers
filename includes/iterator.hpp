#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace ft {

template<class T>
class iterator {

	public:
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef value_type*							pointer;
		typedef value_type&							reference;

	private:

		pointer p;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		iterator() : p(NULL) {}
		iterator(pointer p) : p(p) {}
		iterator(iterator const & copy) : p(copy.p) {}
		~iterator() {}

		pointer getP() const { return (this->p); }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator& operator=(const iterator& src) {p = src.p; return *this;}
		reference operator*() {return *p;}
		pointer operator->() {return p;}
		reference operator[](difference_type n) {return *(p + n);}
		iterator& operator++() {++p;return *this;}
		iterator operator++(const int n) {(void)n;iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {--p;return *this;}
		iterator operator--(const int n) {(void)n;iterator tmp(*this); operator--(); return tmp;}
		difference_type	 operator-(const iterator & src) {return p - src.p;}
		difference_type	 operator+(const iterator & src) {return p + src.p;}
		iterator operator+(difference_type n) {return p + n;}
		iterator operator-(difference_type n) {return p - n;}
		iterator& operator+=(difference_type n) {p += n; return *this;}
		iterator& operator-=(difference_type n) {p -= n; return *this;}

//	------------------------------------------------


//	--------------->> NON MEMBERS <<----------------

		friend iterator operator+(difference_type n, iterator& it) {
			iterator tmp = it;
			return (tmp += n);
		}

		friend iterator operator-(difference_type n, iterator& it) {
			iterator tmp = it;
			return (tmp -= n);
		}

		template<class A>
		friend bool operator==(const iterator src, const iterator<A> cmp) {return (src.getP() == cmp.getP());}
		template<class A>
		friend bool operator!=(const iterator src, const iterator<A> cmp) {return (src.getP() != cmp.getP());}
		template<class A>
		friend bool operator<(const iterator src, const iterator<A> cmp) {return (src.getP() < cmp.getP());}
		template<class A>
		friend bool operator<=(const iterator src, const iterator<A> cmp) {return (src.getP() <= cmp.getP());}
		template<class A>
		friend bool operator>(const iterator src, const iterator<A> cmp) {return (src.getP() > cmp.getP());}
		template<class A>
		friend bool operator>=(const iterator src, const iterator<A> cmp) {return (src.getP() >= cmp.getP());}

};

}

#endif