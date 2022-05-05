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
		typedef std::ptrdiff_t				difference_type;
		typedef T 							value_type;
		typedef value_type *				pointer;
		typedef value_type const *			const_pointer;
		typedef value_type &				reference;
		typedef value_type const &			const_reference;

	private :

		allocator_type	_alloc;
		pointer			_tab;
		size_type		_size;
		size_type		_cap;

		void _delete() {
			for (size_type i = 0;i < _size;i++){
				_alloc.destroy(&_tab[i]);
			}
			_alloc.deallocate(_tab, _size);
		}

		void _copy(vector const & copy) {
			_size = copy._size;
			_cap = copy._cap;
			try {
				_tab = _alloc.allocate(_cap);
			} catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			for (size_type i = 0;i < _size;i++){
				_alloc.construct(&_tab[i], copy._tab[i]);
			}
		}

		void ft_realloc_tab(size_type new_cap) {
			if (new_cap <= _cap)
				return ;
			pointer tmp = _tab;
			for (size_type i = 0;i < _size;i++){
				_alloc.destroy(&_tab[i]);
			}
			_alloc.deallocate(_tab, _size);
			try {
				_tab = _alloc.allocate(new_cap);
			} catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			for (size_type i = 0;i < _size;i++){
				_alloc.construct(&_tab[i], tmp[i]);
			}
		}

//	why do I need to reset first if I receptionated it as a reference ?
		unsigned int dist_it(iterator first, iterator last) {
			unsigned int n = 0;
			while (first++ != last)
				++n;
			return n;
		}

	public :

//	--------------->> CONSTRUCTORS <<---------------

		explicit vector(const allocator_type& alloc = allocator_type()) :
						_alloc(alloc), _tab(), _size(0), _cap(0) {}

		explicit vector(size_type n, const value_type& val,
						const allocator_type& alloc = allocator_type()) :
						_alloc(alloc), _tab(), _size(n), _cap()
		{
			reserve(n);
			for (size_type i = 0;i < _size;i++)
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

		size_type size() const {return _size;}

		bool empty() const {return begin() == end();}

		size_type max_size() const {return allocator_type().max_size();}

		size_type capacity() const {return _cap;}

		void reserve(size_type new_cap) {
			if (new_cap >  max_size())
				throw std::length_error("New cap is to big."); // check error message
			if (new_cap > capacity() && !_cap) {
				try {
					_tab = _alloc.allocate(_size);
				}
				catch (const std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
			}
			else
				ft_realloc_tab(new_cap);
			_cap = new_cap;
		}

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

		value_type & operator[](const unsigned int n) {
			return _tab[n];
		}

		value_type const & operator[](const unsigned int n) const {
			value_type & ret = const_cast<vector &>(*this).operator[](n);
			return const_cast<value_type const &>(ret);
		}

		reference at(size_type n) {
			if (n >= this->_size)
				throw std::out_of_range("Index to access vector is invalid."); // check error message
			return _tab[n];
			
		}
		
		const_reference at(size_type n) const {
			value_type & ret = const_cast<vector &>(*this).at(n);
			return const_cast<value_type const &>(ret);

		}

		reference front() {
			return (*this)[0];
		}

		const_reference front() const { 
			value_type &ret = const_cast<vector &>(*this).front();
			return const_cast<value_type const &>(ret);
		}

		reference back() {
			return _tab[_size - 1];
		}

		const_reference back() const { 
			value_type &ret = const_cast<vector &>(*this).back();
			return const_cast<value_type const &>(ret);
		}

//	------------------------------------------------


//	--------------->> MODIFIERS <<------------------

		void clear() {
			while (_size)
				_alloc.destroy(&(_tab[--_size]));
		}

		// iterator insert( iterator pos, const T& value ) {}
		// void insert( iterator pos, size_type count, const T& value ) {}
		// template< class InputIt >
		// 	void insert( iterator pos, InputIt first, InputIt last ) {}

		iterator erase(iterator pos) {
			// iterator tmp = pos;
			// iterator cpy = pos + 1;
			// if (pos == end())
			// 	return end();
			// while (pos != end()) {
			// 	*pos = *cpy;
			// 	++pos;
			// 	++cpy;
			// }
			// --_size;
			// _alloc.destroy(&_tab[_size]);
			// return tmp;
			return erase(pos, pos + 1);
		}

		iterator erase(iterator first, iterator last) {
			if (first == last)
				return last;
			if (first == end())
				return end();

			iterator tmp = first;
			unsigned int deleted = dist_it(first, last);

			while (last != end()) {
				*first = *last;
				++first;
				++last;
			}
			while (deleted--) {
				_alloc.destroy(&(_tab[--_size]));
			}
			return tmp;
		}

// Problem with string
		void push_back(const T& value) {
			if (_size + 1 > capacity())
				reserve(_cap * 2);
			_tab[_size] = value;
			++_size;
		}

		void pop_back() {
			_alloc.destroy(&_tab[_size]);
			--_size;
		}

// Problem with string
		void resize(size_type count, T value = T()) {
			if (_cap < count) {
				reserve(_cap * 2);
				--_size;
				while (_size++ < count)
					_tab[_size] = value;
			}
			else if (_cap > count) {
				for (size_type i = count;i < _cap;i++)
				_alloc.destroy(&_tab[i]);
			}
			_size = count;
		}

		void swap(vector& other) {
			if (*this == other)
				return ;
			
			size_type tmp_size = _size;
			size_type tmp_cap = _cap;
			pointer tmp_tab = _tab;
			allocator_type tmp_alloc = _alloc;

			_size = other._size;
			_cap = other._cap;
			_tab = other._tab;
			_alloc = other._alloc;

			other._size = tmp_size;
			other._cap = tmp_cap;
			other._tab = tmp_tab;
			other._alloc = tmp_alloc;
		}


//	------------------------------------------------

};

//	---------------->> NON MEMBERS <<---------------
// why use non members ? Because by default in a class,
//	the first param is the instance of the class : this.
//	Here we want the first element to be specifically something else.

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