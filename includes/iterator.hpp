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

//	++() ++(int) == != * --() --(int) -> [] < <= > >= +(it) -(it) += -=  +(int) -(int)


//	diff pointer reference : pointer je peux modifier la valeure de base et reference non ?
		reference			operator*() {return *p;}
		const_reference		operator*() const {return *p;}

		pointer				operator->() {return *p;}
		const_pointer		operator->() const {return *p;}

		reference			operator[](int val) {return *(p + val);}
		const_reference		operator[](int val) const {return *(p + val);}

		iterator&			operator++() {++p;return *this;}

		iterator			operator++(int val) {(void)val;iterator tmp(*this); operator++(); return tmp;}

		iterator&			operator--() {--p;return *this;}

		iterator			operator--(int val) {(void)val;iterator tmp(*this); operator++(); return tmp;}

		reference			operator+(const reference src) {return *p + *(src.p);}
		const_reference		operator+(const reference src) const {return *p + *(src.p);}

		reference			operator-(const reference src) {return *p - *(src.p);}
		const_reference		operator-(const reference src) const {return *p - *(src.p);}

		reference			operator+=(const reference src) {return *p + *(src.p);}
		const_reference		operator+=(const reference src) const {return *p + *(src.p);}

		reference			operator-=(const reference src) {return *p - *(src.p);}
		const_reference		operator-=(const reference src) const {return *p - *(src.p);}

		iterator&			operator+(int val) {p + val;return *this;}

		iterator&			operator-(int val) {p - val;return *this;}

		bool				operator==(const iterator& src) const {return p==src.p;}
		
		bool				operator!=(const iterator& src) const {return p!=src.p;}

		bool				operator<(const iterator& src) const {return p<src.p;}

		bool				operator<=(const iterator& src) const {return p<=src.p;}

		bool				operator>(const iterator& src) const {return p>src.p;}

		bool				operator>=(const iterator& src) const {return p>=src.p;}



};

}
#endif