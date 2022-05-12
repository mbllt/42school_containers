#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {

template<typename T>
class reverse_iterator {

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

		reverse_iterator() : p(NULL) {}
		reverse_iterator(pointer p) : p(p) {}
		reverse_iterator(reverse_iterator const & copy) : p(copy.p) {}
		~reverse_iterator() {}

		pointer getP() const { return (this->p); }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		reverse_iterator&			operator=(const reverse_iterator& src) {p = src.p;return *this;}

		reference					operator*() {return *p;}
		const_reference				operator*() const {return *p;}

		pointer						operator->() {return p;}
		const_pointer				operator->() const {return p;}

		reference					operator[](difference_type n) {return *(p - n);}
		const_reference				operator[](difference_type n) const {return *(p - n);}

		reverse_iterator&			operator++() {--p;return *this;}

		reverse_iterator			operator++(const int n) {reverse_iterator tmp(*this); operator++(); return tmp - n;}

		reverse_iterator&			operator--() {++p;return *this;}

		reverse_iterator			operator--(const int n) {reverse_iterator tmp(*this); operator--();return tmp + n;}

		difference_type				operator-(const reverse_iterator & src) {return p - src.p;}

		reverse_iterator			operator+(difference_type n) {return p - n;}

		reverse_iterator			operator-(difference_type n) {return p + n;}

template<typename Class>
		friend reverse_iterator		operator+(difference_type n, const reverse_iterator& src);

template<typename Class>
		friend reverse_iterator		operator-(difference_type n, const reverse_iterator& src);

		reverse_iterator&			operator+=(difference_type n) {p -= n;return *this;}

		reverse_iterator&			operator-=(difference_type n) {p += n;return *this;}

};

template<typename Class>
ft::reverse_iterator<Class>					operator+(typename ft::reverse_iterator<Class>::difference_type n,
											typename ft::reverse_iterator<Class>& it)
											{return it + n;}

template<typename Class>
ft::reverse_iterator<Class>					operator-(typename ft::reverse_iterator<Class>::difference_type n,
											typename ft::reverse_iterator<Class>& it)
											{return it - n;}

template <typename T>
bool									operator==(const ft::reverse_iterator<T> src,
												const ft::reverse_iterator<T> cmp)
												{return (src.getP() == cmp.getP());}

template <typename A, typename B>
bool									operator==(const ft::reverse_iterator<A> src,
												const ft::reverse_iterator<B> cmp)
												{return (src.getP() == cmp.getP());}

template <typename T>
bool									operator!=(const ft::reverse_iterator<T> src,
												const ft::reverse_iterator<T> cmp)
												{return (src.getP() != cmp.getP());}

template <typename A, typename B>
bool									operator!=(const ft::reverse_iterator<A> src,
												const ft::reverse_iterator<B> cmp)
												{return (src.getP() != cmp.getP());}

template <typename T>
bool									operator<(const ft::reverse_iterator<T> src,
												const ft::reverse_iterator<T> cmp)
												{return (src.getP() < cmp.getP());}

template <typename A, typename B>
bool									operator<(const ft::reverse_iterator<A> src,
												const ft::reverse_iterator<B> cmp)
												{return (src.getP() < cmp.getP());}

template <typename T>
bool									operator<=(const ft::reverse_iterator<T> src,
												const ft::reverse_iterator<T> cmp)
												{return (src.getP() <= cmp.getP());}

template <typename A, typename B>
bool									operator<=(const ft::reverse_iterator<A> src,
												const ft::reverse_iterator<B> cmp)
												{return (src.getP() <= cmp.getP());}

template <typename T>
bool									operator>(const ft::reverse_iterator<T> src,
												const ft::reverse_iterator<T> cmp)
												{return (src.getP() > cmp.getP());}

template <typename A, typename B>
bool									operator>(const ft::reverse_iterator<A> src,
												const ft::reverse_iterator<B> cmp)
												{return (src.getP() > cmp.getP());}

template <typename T>
bool									operator>=(const ft::reverse_iterator<T> src,
												const ft::reverse_iterator<T> cmp)
												{return (src.getP() >= cmp.getP());}

template <typename A, typename B>
bool									operator>=(const ft::reverse_iterator<A> src,
												const ft::reverse_iterator<B> cmp)
												{return (src.getP() >= cmp.getP());}

}

#endif