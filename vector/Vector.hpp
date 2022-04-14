#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template<typename T, class Alloc = std::allocator<T> >
class vector {

	public:

		typedef ft::iterator<T> 			iterator;
		typedef ft::iterator<const T> 		const_iterator;
		typedef ft::iterator<T> 			reverse_iterator;
		typedef ft::iterator<const T> 		const_reverse_iterator;

		typedef Alloc allocator_type;
		typedef T value_type;
		typedef value_type * pointer;
		typedef value_type & reference;

	private :

		allocator_type	_alloc;
		value_type *	_tab;
		size_t			_size;

		void	_delete() {
			delete [] _tab;
		}

		void	_copy(vector const & copy) {
			_size = copy._size;
			_tab = _alloc.allocate(copy._size);
			for (size_t i = 0;i < copy._size;i++){
				_alloc.construct(&_tab[i], copy._tab[i]);
			}
		}

	public :

//	--------------->> CONSTRUCTORS <<---------------

		vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _tab(), _size(0) {}

		vector(size_t n, const T & val, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n) {
			_tab = _alloc.allocate(n);
			for(size_t i = 0;i < n;i++)
				_alloc.construct(&_tab[i], val);
		}

		// vector(input iterator first, input iterator last) : _size(first - last) {_tab = new T[_size]}

		vector(vector const & cpy) {_copy(cpy);}

		~vector() {_delete();}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		vector & operator=(vector const & src) {
			_delete();
			_copy(src);
			return *this;
		}

		T & operator[](const unsigned int index) {
			if (index >= this->_size)
				throw AccessorvectorInvalidExcpetion("Index to access vector is invalid.");
			return _tab[index];
		}

		T const & operator[](const unsigned int index) const {
			T & ret = const_cast<vector &>(*this).operator[](index);
			return const_cast<T const &>(ret);
		}

		vector& operator++() {
			return ++(*this);
		}

		vector operator++(int) {
			vector tmp(*this);
			++(*tmp); return tmp;
		}

		bool operator==(vector & cmp) {
			iterator it = begin();
			iterator it2 = cmp.begin();
			while (it++ != end() && it2++ != cmp.end())
				if (*it != *it2) 
					return false;
			return true;
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
			if (*_tab)
				return iterator(&(_tab[_size - 1]));
			else
				return iterator(&(_tab[_size]));
		}

		const_iterator end() const {
			if (*_tab)
				return const_iterator(&(_tab[_size - 1]));
			else
				return const_iterator(&(_tab[_size]));
		}

		reverse_iterator rbegin() {
			return reverse_iterator(&(_tab[_size - 1]));
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(&(_tab[_size - 1]));
		}

		reverse_iterator rend() {
			return reverse_iterator(_tab - 1);
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(_tab - 1);
		}

//	------------------------------------------------


//	---------------->> CAPACITY <<------------------

		size_t	size() const {return _size;}

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

		// front() const {return _tab[0];}
		// back() const {return _tab[_size - 1];}

//	------------------------------------------------


//	--------------->> MODIFIERS <<------------------

//		void assign(inputIterator first, inputIterator last);
//		void assign(size_t n, const T & val);

//	------------------------------------------------


//	---------------->> EXCEPTIONS <<----------------

		class AccessorvectorInvalidExcpetion : public std::exception {
		
			private :

				std::string		_messageErr;

			public :
		
				AccessorvectorInvalidExcpetion(std::string std) throw() : _messageErr(std) {};
				virtual ~AccessorvectorInvalidExcpetion() throw() {};
		
				virtual const char* what() const throw() {
					return _messageErr.c_str();
				}
		};

};

}
#endif