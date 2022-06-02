#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

namespace ft {

template<typename T>
class iterator_map {

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

		iterator_map() : p(NULL) {}
		iterator_map(pointer p) : p(p) {}
		iterator_map(iterator_map const & copy) : p(copy.p) {}
		~iterator_map() {}

		pointer getP() const { return (this->p); }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator_map&			operator=(const iterator_map& src) {p = src.p; return *this;}

		reference			operator*() {return *p;}
		const_reference		operator*() const {return *p;}

		pointer				operator->() {return p;}
		const_pointer		operator->() const {return p;}

		reference			operator[](difference_type n) {return *(p + n);}
		const_reference		operator[](difference_type n) const {return *(p + n);}

		iterator_map&			operator++() {++p;return *this;}

		iterator_map			operator++(const int n) {(void)n;iterator_map tmp(*this); operator++(); return tmp;}

		iterator_map&			operator--() {--p;return *this;}

		iterator_map			operator--(const int n) {(void)n;iterator_map tmp(*this); operator--(); return tmp;}

		difference_type		operator-(const iterator_map & src) {return p - src.p;}

		iterator_map			operator+(difference_type n) {return p + n;}

		iterator_map			operator-(difference_type n) {return p - n;}

template<typename Class>
		friend iterator_map		operator+(difference_type n, const iterator_map& src);

template<typename Class>
		friend iterator_map		operator-(difference_type n, const iterator_map& src);

		iterator_map&			operator+=(difference_type n) {p += n; return *this;}

		iterator_map&			operator-=(difference_type n) {p -= n; return *this;}

};

template<typename Class>
ft::iterator_map<Class>					operator+(typename ft::iterator_map<Class>::difference_type n,
											typename ft::iterator_map<Class>& it)
											{return it + n;}

template<typename Class>
ft::iterator_map<Class>					operator-(typename ft::iterator_map<Class>::difference_type n,
											typename ft::iterator_map<Class>& it)
											{return it - n;}

template <typename T>
bool									operator==(const ft::iterator_map<T> src,
												const ft::iterator_map<T> cmp)
												{return (src.getP() == cmp.getP());}

template <typename A, typename B>
bool									operator==(const ft::iterator_map<A> src,
												const ft::iterator_map<B> cmp)
												{return (src.getP() == cmp.getP());}

template <typename T>
bool									operator!=(const ft::iterator_map<T> src,
												const ft::iterator_map<T> cmp)
												{return (src.getP() != cmp.getP());}

template <typename A, typename B>
bool									operator!=(const ft::iterator_map<A> src,
												const ft::iterator_map<B> cmp)
												{return (src.getP() != cmp.getP());}

template <typename T>
bool									operator<(const ft::iterator_map<T> src,
												const ft::iterator_map<T> cmp)
												{return (src.getP() < cmp.getP());}

template <typename A, typename B>
bool									operator<(const ft::iterator_map<A> src,
												const ft::iterator_map<B> cmp)
												{return (src.getP() < cmp.getP());}

template <typename T>
bool									operator<=(const ft::iterator_map<T> src,
												const ft::iterator_map<T> cmp)
												{return (src.getP() <= cmp.getP());}

template <typename A, typename B>
bool									operator<=(const ft::iterator_map<A> src,
												const ft::iterator_map<B> cmp)
												{return (src.getP() <= cmp.getP());}

template <typename T>
bool									operator>(const ft::iterator_map<T> src,
												const ft::iterator_map<T> cmp)
												{return (src.getP() > cmp.getP());}

template <typename A, typename B>
bool									operator>(const ft::iterator_map<A> src,
												const ft::iterator_map<B> cmp)
												{return (src.getP() > cmp.getP());}

template <typename T>
bool									operator>=(const ft::iterator_map<T> src,
												const ft::iterator_map<T> cmp)
												{return (src.getP() >= cmp.getP());}

template <typename A, typename B>
bool									operator>=(const ft::iterator_map<A> src,
												const ft::iterator_map<B> cmp)
												{return (src.getP() >= cmp.getP());}

}

#endif