#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "meta.hpp"
#include "utility.hpp"

#define NIL		NULL
#define BLACK	0
#define RED		1

namespace ft {

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> >
>
class map {

	public:

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const Key, T>					value_type;
		typedef size_t									size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef value_type&								reference;
		typedef value_type const&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		// typedef ft::iterator<ft::pair<const Key, T> >							iterator;
		// typedef ft::iterator<const ft::pair<const Key, T> >					const_iterator;
		// typedef ft::reverse_iterator<ft::pair<const Key, T> >					reverse_iterator;
		// typedef ft::reverse_iterator<const ft::pair<const Key, T> >			const_reverse_iterator;
		// typedef ft::iterator<T>							iterator;
		// typedef ft::iterator<const T>					const_iterator;
		// typedef ft::reverse_iterator<T>					reverse_iterator;
		// typedef ft::reverse_iterator<const T>			const_reverse_iterator;

	private :

		struct bst_node {
			struct bst_node		*child[2]; //left = 0 if key < parent->key | right = 1 if key > paretn->key
			value_type			key;
			bool				color;
			struct bst			*parent;
		};

		struct bst {
			struct bst_node		*root;
		};

		allocator_type	_alloc;
		bst				_bst;
		size_type		_size;
		size_type		_cap;

		// void _delete() {
		// 	if (_size) {
		// 		while (_size--) {
		// 			_alloc.destroy(&_tab[_size]);
		// 		}
		// 	}
		// 	_alloc.deallocate(_tab, _cap);
		// }

		// void _copy(map const & copy) {
		// 	_size = copy._size;
		// 	_cap = copy._cap;
		// 	_tab = _alloc.allocate(_cap);
		// 	for (size_type i = 0;i < _size;i++){
		// 		_alloc.construct(&_tab[i], copy._tab[i]);
		// 	}
		// }

	public :

//	--------------->> CONSTRUCTORS <<---------------

		explicit map( const Compare& comp,
						const Allocator& alloc = Allocator() ) :
						_alloc(alloc), _bst(NIL), _size(0), _cap(0) {(void)comp;}

		template< class InputIt >
		map(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last,
				const Compare& comp = Compare(),
				const Allocator& alloc = Allocator() );

		map( const map& other );

		~map() {}

//	------------------------------------------------


// //	---------------->> GENERAL <<-----------------

// 		map & operator=(map const &src) {
// 			_delete();
// 			_copy(src);
// 			return *this;
// 		}

// 		allocator_type get_allocator() const {
// 			return _alloc;
// 		}

// 		void assign(size_type count, const T& value) {
// 			map<T, Alloc> tmp(count, value);
// 			assign(tmp.begin(), tmp.end());
// 		}

// 		template<class InputIt>
// 			void assign(typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last) {
// 				clear();
// 				insert(begin(), first, last);
// 			}

// //	------------------------------------------------


// //	---------------->> ITERATORS <<-----------------

// 		iterator begin() {
// 			return iterator(_tab);
// 		}

// 		const_iterator begin() const {
// 			return const_iterator(_tab);
// 		}

// 		iterator end() {
// 			return _tab != NULL ? iterator(_tab + _size) : iterator();
// 		}

// 		const_iterator end() const {
// 			return _tab != NULL ? const_iterator(_tab + _size) : const_iterator();
// 		}

// 		reverse_iterator rbegin() {
// 			return _tab != NULL ? reverse_iterator(_tab + _size - 1) : reverse_iterator();
// 		}

// 		const_reverse_iterator rbegin() const {
// 			return _tab != NULL ? const_reverse_iterator(_tab + _size - 1) : const_reverse_iterator();
// 		}

// 		reverse_iterator rend() {
// 			return reverse_iterator(_tab - 1);
// 		}

// 		const_reverse_iterator rend() const {
// 			return const_reverse_iterator(_tab - 1);
// 		}

// //	------------------------------------------------


// //	---------------->> CAPACITY <<------------------

// 		size_type size() const {return _size;}

// 		bool empty() const {return begin() == end();}

// 		size_type max_size() const {return allocator_type().max_size();}

// 		size_type capacity() const {return _cap;}

// 		void reserve(size_type new_cap) {
// 			if (new_cap > max_size())
// 				throw std::length_error("map::reserve");
// 			else if (new_cap > capacity()) {
// 				value_type *tmp = _alloc.allocate(new_cap);
// 				if (_tab) {
// 					for (size_type i = 0;i < _size;i++){
// 						_alloc.construct(&tmp[i], _tab[i]);
// 					}
// 					for (size_type i = 0;i < _size;i++){
// 						_alloc.destroy(&_tab[i]);
// 					}
// 					_alloc.deallocate(_tab, _cap);
// 				}
// 				_tab = tmp;
// 				_cap = new_cap;
// 			}
// 		}

// //	------------------------------------------------


// //	----------------->> ACCESS <<-------------------

// 		value_type & operator[](const unsigned int n) {
// 			return _tab[n];
// 		}

// 		value_type const & operator[](const unsigned int n) const {
// 			value_type & ret = const_cast<map &>(*this).operator[](n);
// 			return const_cast<value_type const &>(ret);
// 		}

// 		reference at(size_type n) {
// 			if (n >= this->_size)
// 				throw std::out_of_range("map");
// 			return _tab[n];
			
// 		}
		
// 		const_reference at(size_type n) const {
// 			value_type & ret = const_cast<map &>(*this).at(n);
// 			return const_cast<value_type const &>(ret);

// 		}

// 		reference front() {
// 			return (*this)[0];
// 		}

// 		const_reference front() const { 
// 			value_type &ret = const_cast<map &>(*this).front();
// 			return const_cast<value_type const &>(ret);
// 		}

// 		reference back() {
// 			return _tab[_size - 1];
// 		}

// 		const_reference back() const { 
// 			value_type &ret = const_cast<map &>(*this).back();
// 			return const_cast<value_type const &>(ret);
// 		}

// //	------------------------------------------------


// //	--------------->> MODIFIERS <<------------------

// 		void clear() {
// 			while (_size)
// 				_alloc.destroy(&(_tab[--_size]));
// 		}

// 		iterator insert(iterator pos, const T& value) {
// 			insert(pos, 1, value);
// 			return pos++;
// 		}

// 		void insert(iterator pos, size_type count, const T& value) {
// 			map<T, Alloc> tmp(count, value);
// 			insert(pos, tmp.begin(), tmp.end());
// 		}

// 		template<class InputIt>
// 		void insert(iterator pos, typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last) {
// 			if (first == last)
// 				return ;
// 			size_type count = 0;
// 			while (first != last) {
// 				++count;
// 				++first;
// 			}
// 			for (size_type i = 0;i < count;++i)
// 				--first;

// 			size_type new_size = _size + count;
// 			size_type save_pos = 0;
// 			while (pos != end()) {
// 				++pos;
// 				++save_pos;
// 			}
// 			save_pos = _size - save_pos;

// 			if (new_size > _cap) {
// 				(new_size > _cap * 2) ? reserve(new_size) : reserve(_cap * 2);
// 			}
// 			map<value_type, Alloc> tmp = *this;

// 			for (size_type i = 0; i < count;++i) {
// 				_alloc.construct(_tab + save_pos, *first);
// 				++save_pos;
// 			}
// 			size_type i = save_pos;
// 			save_pos = save_pos - count;
// 			while (i < new_size) {
// 				_alloc.construct(&(_tab[i++]), tmp[save_pos++]);
// 			}
// 			_size = new_size;
// 		}

// 		iterator erase(iterator pos) {
// 			return erase(pos, pos + 1);
// 		}

// 		iterator erase(iterator first, iterator last) {
// 			if (first == last)
// 				return last;
// 			if (first == end())
// 				return end();

// 			iterator tmp = first;
// 			unsigned int deleted = dist_it(first, last);

// 			while (last != end()) {
// 				*first = *last;
// 				++first;
// 				++last;
// 			}
// 			while (deleted--) {
// 				_alloc.destroy(&(_tab[--_size]));
// 			}
// 			return tmp;
// 		}

// 		void push_back(const T& value) {
// 			if (_size + 1 > capacity())
// 				!_cap ? reserve(1) : reserve(_cap * 2);
// 			_alloc.construct(&(_tab[_size]), value);
// 			++_size;
// 		}

// 		void pop_back() {
// 			if (!_tab)
// 				return ;
// 			_alloc.destroy(&_tab[_size]);
// 			--_size;
// 		}

// 		void resize(size_type count, T value = T()) {
// 			if (_cap < count) {
// 				(count > _cap * 2) ? reserve(count) : reserve(_cap * 2);
// 				while (_size < count) {
// 					_alloc.construct(&(_tab[_size]), value);
// 					++_size;
// 				}
// 			}
// 			else if (_cap > count) {
// 				for (size_type i = count;i < _size;i++)
// 					_alloc.destroy(&_tab[i]);
// 			}
// 			_size = count;
// 		}

// 		void swap(map& other) {
// 			// if (this == &other)
// 			// 	return ;

// 			size_type tmp_size = _size;
// 			size_type tmp_cap = _cap;
// 			pointer tmp_tab = _tab;
// 			allocator_type tmp_alloc = _alloc;

// 			_size = other._size;
// 			_cap = other._cap;
// 			_tab = other._tab;
// 			_alloc = other._alloc;

// 			other._size = tmp_size;
// 			other._cap = tmp_cap;
// 			other._tab = tmp_tab;
// 			other._alloc = tmp_alloc;
// 		}


// //	------------------------------------------------

};

// //	---------------->> NON MEMBERS <<---------------
// // why use non members ? Because by default in a class,
// //	the first param is the instance of the class : this.
// //	Here we want the first element to be specifically something.

// template<typename T, class Alloc>
// bool		operator==(const ft::map<T, Alloc> & src, const ft::map<T, Alloc> & cmp) {
// 				if (src.size() != cmp.size())
// 					return false;
// 				typename ft::map<T>::const_iterator it = src.begin();
// 				typename ft::map<T>::const_iterator itbis = cmp.begin();
// 				while(it != src.end()) {
// 					if (itbis == cmp.end() || *it != *itbis)
// 						return false;
// 					++it;
// 					++itbis;
// 				}
// 				return true;
// 			}

// template<typename T, typename Y, class Alloc>
// bool		operator==(const ft::map<T, Alloc> & src, const ft::map<Y, Alloc> & cmp) {
// 				if (src.size() != cmp.size())
// 					return false;
// 				typename ft::map<T>::const_iterator it = src.begin();
// 				typename ft::map<Y>::const_iterator itbis = cmp.begin();
// 				while(it != src.end()) {
// 					if (itbis == cmp.end() || *it != *itbis)
// 						return false;
// 					++it;
// 					++itbis;
// 				}
// 				return true;
// 			}

// template<typename T, class Alloc>
// bool		operator!=(const ft::map<T, Alloc> & src, const ft::map<T, Alloc> & cmp) {
// 				return !(src == cmp);
// 			}

// template<typename T, typename Y, class Alloc>
// bool		operator!=(const ft::map<T, Alloc> & src, const ft::map<Y, Alloc> & cmp) {
// 				return !(src == cmp);
// 			}

// template<typename T, class Alloc>
// bool		operator<(const ft::map<T, Alloc> & src, const ft::map<T, Alloc> & cmp) {
// 				typename ft::map<T, Alloc>::const_iterator it1 = src.begin();
// 				typename ft::map<T, Alloc>::const_iterator ite1 = src.end();
// 				typename ft::map<T, Alloc>::const_iterator it2 = cmp.begin();
// 				typename ft::map<T, Alloc>::const_iterator ite2 = cmp.end();
// 				while (it1 != ite1) {
// 					if (it2 == ite2 || *it1 > *it2)
// 						return false;
// 					else if (*it1 < *it2)
// 						return true;
// 					++it1;
// 					++it2;
// 				}
// 				return it2 != ite2;
// 			}

// template<typename T, typename Y, class Alloc>
// bool		operator<(const ft::map<T, Alloc> & src, const ft::map<Y, Alloc> & cmp) {
// 				typename ft::map<T, Alloc>::const_iterator it1 = src.begin();
// 				typename ft::map<T, Alloc>::const_iterator ite1 = src.end();
// 				typename ft::map<Y, Alloc>::const_iterator it2 = cmp.begin();
// 				typename ft::map<Y, Alloc>::const_iterator ite2 = cmp.end();
// 				while (it1 != ite1) {
// 					if (it2 == ite2 || *it1 > *it2)
// 						return false;
// 					else if (*it1 < *it2)
// 						return true;
// 					++it1;
// 					++it2;
// 				}
// 				return it2 != ite2;
// 			}

// template<typename T, class Alloc>
// bool		operator<=(const ft::map<T, Alloc> & src, const ft::map<T, Alloc> & cmp) {
// 				if (src == cmp)
// 					return true;
// 				return src < cmp;
// 			}

// template<typename T, typename Y, class Alloc>
// bool		operator<=(const ft::map<T, Alloc> & src, const ft::map<Y, Alloc> & cmp) {
// 				if (src == cmp)
// 					return true;
// 				return src < cmp;
// 			}

// template<typename T, class Alloc>
// bool		operator>(const ft::map<T, Alloc> & src, const ft::map<T, Alloc> & cmp) {
// 				return cmp < src;
// 			}

// template<typename T, typename Y, class Alloc>
// bool		operator>(const ft::map<T, Alloc> & src, const ft::map<Y, Alloc> & cmp) {
// 				if (src == cmp)
// 					return false;
// 				return !(cmp < src);
// 			}

// template<typename T, class Alloc>
// bool		operator>=(const ft::map<T, Alloc> & src, const ft::map<T, Alloc> & cmp) {
// 				return !(src < cmp);
// 			}

// template<typename T, typename Y, class Alloc>
// bool		operator>=(const ft::map<T, Alloc> & src, const ft::map<Y, Alloc> & cmp) {
// 				if (src == cmp)
// 					return true;
// 				return !(src < cmp);
// 			}

// template<typename T, class Alloc>
// void		swap(ft::map<T,Alloc>& lhs,
// 				ft::map<T,Alloc>& rhs) {
// 				lhs.swap(rhs);
// 			}

}

#endif