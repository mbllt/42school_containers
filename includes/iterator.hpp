#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace ft {

template<typename T>
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
		iterator operator+(difference_type n) {return p + n;}
		iterator operator-(difference_type n) {return p - n;}
		template<typename Class>
			friend iterator operator+(difference_type n, const iterator& src);
		template<typename Class>
			friend iterator operator-(difference_type n, const iterator& src);
		iterator& operator+=(difference_type n) {p += n; return *this;}
		iterator& operator-=(difference_type n) {p -= n; return *this;}

friend ft::iterator<Class> operator+(typename ft::iterator<Class>::difference_type n, typename ft::iterator<Class>& it) {return it + n;}
friend ft::iterator<Class> operator-(typename ft::iterator<Class>::difference_type n, typename ft::iterator<Class>& it) {return it - n;}
friend bool operator==(const ft::iterator<T> src, const ft::iterator<T> cmp) {return (src.getP() == cmp.getP());}
friend bool operator==(const ft::iterator<A> src, const ft::iterator<B> cmp) {return (src.getP() == cmp.getP());}
friend bool operator!=(const ft::iterator<T> src, const ft::iterator<T> cmp) {return (src.getP() != cmp.getP());}
friend bool operator!=(const ft::iterator<A> src, const ft::iterator<B> cmp) {return (src.getP() != cmp.getP());}
friend bool operator<(const ft::iterator<T> src, const ft::iterator<T> cmp) {return (src.getP() < cmp.getP());}
friend bool operator<(const ft::iterator<A> src, const ft::iterator<B> cmp) {return (src.getP() < cmp.getP());}
friend bool operator<=(const ft::iterator<T> src, const ft::iterator<T> cmp) {return (src.getP() <= cmp.getP());}
friend bool operator<=(const ft::iterator<A> src, const ft::iterator<B> cmp) {return (src.getP() <= cmp.getP());}
friend bool operator>(const ft::iterator<T> src, const ft::iterator<T> cmp) {return (src.getP() > cmp.getP());}
friend bool operator>(const ft::iterator<A> src, const ft::iterator<B> cmp) {return (src.getP() > cmp.getP());}
friend bool operator>=(const ft::iterator<T> src, const ft::iterator<T> cmp) {return (src.getP() >= cmp.getP());}
friend bool operator>=(const ft::iterator<A> src, const ft::iterator<B> cmp) {return (src.getP() >= cmp.getP());}

};

}

#endif