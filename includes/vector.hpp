#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template<typename T, class Alloc = std::allocator<T> >
class vector {

	public:

		typedef ft::iterator<T>				iterator;
		typedef ft::iterator<const T>		const_iterator;
		typedef ft::iterator<T>				reverse_iterator;
		typedef ft::iterator<const T>		const_reverse_iterator;

		typedef size_t						size_type;
		typedef Alloc						allocator_type;
		typedef T 							value_type;
		typedef value_type *				pointer;
		typedef value_type const *			const_pointer;
		typedef value_type &				reference;
		typedef value_type const &			const_reference;

	private :

		allocator_type	_alloc;
		pointer			_tab;
		size_t			_size;

		void	_delete() {
			for (size_type i = 0;i < _size;i++){
				_alloc.destroy(&_tab[i]);
			}
			_alloc.deallocate(_tab, _size);
		}

		void	_copy(vector const & copy) {
			_size = copy._size;
			_tab = _alloc.allocate(copy._size);
			for (size_type i = 0;i < copy._size;i++){
				_alloc.construct(&_tab[i], copy._tab[i]);
			}
		}

	public :

//	--------------->> CONSTRUCTORS <<---------------

		explicit vector(const allocator_type& alloc = allocator_type()) :
						_alloc(alloc), _tab(), _size(0) {}

		explicit vector(size_type n, const value_type& val,
						const allocator_type& alloc = allocator_type()) :
						_alloc(alloc), _tab(), _size(n)
		{
			_tab = _alloc.allocate(n);
			for (size_type i = 0;i < n;i++)
				_alloc.construct(&_tab[i], val);
		}

//	enable_if InuputIterator ft::is_iterator_traits
		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last,
		// 		const allocator_type& alloc = allocator_type()) :
		// 		_alloc(alloc), _tab(), _size(0)
		// {
		// 	InputIterator tmp = first;
		// 	while (first++ != last)
		// 		++_size;
		// 	_tab = alloc.allocate(_size);
		// 	for (size_type i = 0;i < _size;i++)
		// 		_alloc.construct(&_tab[i], *tmp++);
		// }

		vector(const vector& x) {_copy(x);}

		~vector() {_delete();}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		vector & operator=(vector const &src) {
			_delete();
			_copy(src);
			return *this;
		}

//	------------------------------------------------


//	---------------->> ITERATORS <<-----------------

		iterator begin() {
			return iterator(_tab);
		}

		const_iterator begin() const {
			return const_iterator(_tab);
		}

		iterator end() {
			return iterator(&(_tab[_size]));
		}

		const_iterator end() const {
			return const_iterator(&(_tab[_size]));
		}

		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		reverse_iterator rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}

//	------------------------------------------------


//	---------------->> CAPACITY <<------------------

		size_t size() const {return _size;}

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

		T & operator[](const unsigned int n) {
			return _tab[n];
		}

		T const & operator[](const unsigned int n) const {
			T & ret = const_cast<vector &>(*this).operator[](n);
			return const_cast<T const &>(ret);
		}

		reference at(size_type n) {
			if (n >= this->_size)
				throw std::out_of_range("Index to access vector is invalid.");
			return _tab[n];
			
		}
		
		const_reference at(size_type n) const {
			T & ret = const_cast<vector &>(*this).at(n);
			return const_cast<T const &>(ret);

		}

		// front() const {return _tab[0];}
		// back() const {return _tab[_size - 1];}
		// data()

//	------------------------------------------------


//	--------------->> MODIFIERS <<------------------

//		void assign(inputIterator first, inputIterator last);
//		void assign(size_type n, const T & val);

//	------------------------------------------------


//	---------------->> EXCEPTIONS <<----------------

		// class AccessorvectorInvalidExcpetion : public std::exception {
		
		// 	private :

		// 		std::string		_messageErr;

		// 	public :
		
		// 		AccessorvectorInvalidExcpetion(std::string std) throw() : _messageErr(std) {};
		// 		virtual ~AccessorvectorInvalidExcpetion() throw() {};
		
		// 		virtual const char* what() const throw() {
		// 			return _messageErr.c_str();
		// 		}
		// };

//	------------------------------------------------

};

//	---------------->> NON MEMBERS <<---------------

template<typename T, class Alloc>
bool		operator==(const ft::vector<T, Alloc> & src, const ft::vector<T, Alloc> & cmp) {
				if (src.size() != cmp.size())
					return false;
				typename ft::vector<T>::const_iterator it = src.begin();
				typename ft::vector<T>::const_iterator itbis = cmp.begin();
				while(it != src.end()) {
					if (itbis == cmp.end() || *it != *itbis)
						return false;
					++it;
					++itbis;
				}
				return true;
			}

template<typename T, class Alloc>
bool		operator!=(const ft::vector<T, Alloc> & src, const ft::vector<T, Alloc> & cmp) {
				return !(src == cmp);
			}


template<typename T, class Alloc>
bool		operator<(const ft::vector<T, Alloc> & src, const ft::vector<T, Alloc> & cmp) {
				typename ft::vector<T, Alloc>::const_iterator it1 = src.begin();
				typename ft::vector<T, Alloc>::const_iterator ite1 = src.end();
				typename ft::vector<T, Alloc>::const_iterator it2 = cmp.begin();
				typename ft::vector<T, Alloc>::const_iterator ite2 = cmp.end();
				while (it1 != ite1) {
					if (it2 == ite2 || *it1 > *it2)
						return false;
					else if (*it1 < *it2)
						return true;
					++it1;
					++it2;
				}
				return it2 != ite2;
			}

template<typename T, class Alloc>
bool		operator<=(const ft::vector<T, Alloc> & src, const ft::vector<T, Alloc> & cmp) {
				return !(src < cmp);
			}

template<typename T, class Alloc>
bool		operator>(const ft::vector<T, Alloc> & src, const ft::vector<T, Alloc> & cmp) {
				return cmp < src;
			}

template<typename T, class Alloc>
bool		operator>=(const ft::vector<T, Alloc> & src, const ft::vector<T, Alloc> & cmp) {
				return !(src < cmp);
			}

}

#endif