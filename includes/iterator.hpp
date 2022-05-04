#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

template<typename T>
class iterator {

	public:
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;

	private:

		pointer p;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		iterator() : p(NULL) {}
		iterator(pointer p) : p(p) {}
		iterator(iterator const & copy) : p(copy.p) {}
		~iterator() {}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator&			operator=(const iterator& src) {p = src.p; return *this;}

		reference			operator*() {return *p;}
		const_reference		operator*() const {return *p;}

		pointer				operator->() {return p;}
		const_pointer		operator->() const {return p;}

		reference			operator[](difference_type n) {return *(p + n);}
		const_reference		operator[](difference_type n) const {return *(p + n);}

		iterator&			operator++() {++p;return *this;}

		iterator			operator++(const int n) {(void)n;iterator tmp(*this); operator++(); return tmp;}

		iterator&			operator--() {--p;return *this;}

		iterator			operator--(const int n) {(void)n;iterator tmp(*this); operator--(); return tmp;}

		difference_type		operator-(const iterator& src) {return p - src.p;}

		iterator			operator+(difference_type n) {return p + n;}

		iterator			operator-(difference_type n) {return p - n;}

template<typename Class>
		friend iterator		operator+(difference_type n, const iterator& src);

template<typename Class>
		friend iterator		operator-(difference_type n, const iterator& src);

		iterator&			operator+=(difference_type n) {p += n; return *this;}

		iterator&			operator-=(difference_type n) {p -= n; return *this;}

		bool				operator==(const iterator& src) const {return p==src.p;}
		
		bool				operator!=(const iterator& src) const {return p!=src.p;}

		bool				operator<(const iterator& src) const {return p<src.p;}

		bool				operator<=(const iterator& src) const {return p<=src.p;}

		bool				operator>(const iterator& src) const {return p>src.p;}

		bool				operator>=(const iterator& src) const {return p>=src.p;}

};

template<typename Class>
ft::iterator<Class>					operator+(typename ft::iterator<Class>::difference_type n,
											typename ft::iterator<Class>& it)
											{return it + n;}

template<typename T>
ft::iterator<T>					operator-(typename ft::iterator<T>::difference_type n,
											typename ft::iterator<T>& it)
											{return it - n;}

}

#endif