#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"

namespace ft {

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> >
>
class map {

	public:

		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const Key, T>									value_type;
		typedef size_t													size_type;
		typedef std::ptrdiff_t											difference_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef value_type&												reference;
		typedef value_type const&										const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef ft::iterator<ft::pair<const Key, T> >					iterator;
		typedef ft::iterator<const ft::pair<const Key, T> >				const_iterator;
		typedef ft::reverse_iterator<ft::pair<const Key, T> >			reverse_iterator;
		typedef ft::reverse_iterator<const ft::pair<const Key, T> >		const_reverse_iterator;

	private :

		struct node {
			value_type	pair;
			node*		left;
			node*		right;
			node*		parent;
		};

		allocator_type	_alloc;
		Compare			_comp;
		node			_tree;
		size_type		_size;
		size_type		_height;
		node			_begin;
		node			_end;

		void _copy(map const &copy) {
			_size = copy._size();
			_height = copy._height();
			_begin = copy._begin;
			_end = copy._end;
			insert(copy._begin, copy._end);
		}


	public :

//	----------------->> CLASSES <<-----------------

	class value_compare : ft::binary_function<value_type, value_type, bool> {
		public:

			bool operator()( const value_type& lhs, const value_type& rhs ) const { return comp(lhs.first, rhs.first);}

		protected:
			value_compare(Compare C) : comp(C) {}
			Compare comp;
	};

//	------------------------------------------------


//	--------------->> CONSTRUCTORS <<---------------

		explicit map( const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type() ) :
						_alloc(alloc), _comp(comp), _tree(), _size(0), _height(0), _begin(), _end() {}

		template< class InputIt >
		map(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type() ) :
				_alloc(alloc), _comp(comp), _tree(), _size(0), _height(0), _begin(), _end() {
			insert(first, last);
		}

		map( const map& other ) {
			insert(other.begin(), other.end());
		}

		~map() {clear();}

//	------------------------------------------------


//	---------------->> GENERAL <<-----------------

		map & operator=(map const& other) {clear(); _copy(other); return *this;}

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

		T& operator[]( const Key& key );

		T& at( const Key& key );
		
		const T& at( const Key& key ) const;

//	------------------------------------------------


//	---------------->> ITERATORS <<-----------------

		iterator begin() {return _begin != NULL ? _begin : iterator();}

		const_iterator begin() const {return _begin != NULL ? _begin : const_iterator();}

		iterator end() {return _end != NULL ? _end : iterator();}

		const_iterator end() const {return _end != NULL ? _end : const_iterator();}

		reverse_iterator rbegin();

		const_reverse_iterator rbegin() const;

		reverse_iterator rend();

		const_reverse_iterator rend() const;

//	------------------------------------------------


//	---------------->> CAPACITY <<------------------

		size_type size() const {return _size;}

		bool empty() const {return _tree != NULL ? true : false;}

		size_type max_size() const {return allocator_type().max_size();}

//	------------------------------------------------


//	--------------->> MODIFIERS <<------------------

		void clear();

		std::pair<iterator, bool> insert( const value_type& value );

		iterator insert( iterator hint, const value_type& value );

		iterator erase(iterator pos);

		void erase( iterator first, iterator last );

		void swap(map& other);

//	------------------------------------------------


//	---------------->> LOOKUP <<--------------------

		size_type count( const Key& key ) const;

		iterator find( const Key& key );

		const_iterator find( const Key& key ) const;

		std::pair<iterator,iterator> equal_range( const Key& key );

		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

		iterator lower_bound( const Key& key );

		const_iterator lower_bound( const Key& key ) const;

		iterator upper_bound( const Key& key );

		const_iterator upper_bound( const Key& key ) const;

//	------------------------------------------------


//	--------------->> OBSERVERS <<------------------

		key_compare key_comp() const;

		map::value_compare value_comp() const;

//	------------------------------------------------

};

// //	---------------->> NON MEMBERS <<---------------
// // why use non members ? Because by default in a class,
// //	the first param is the instance of the class : this.
// //	Here we want the first element to be specifically something.

// template< class Key, class T, class Compare, class Alloc >
// bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
//                  const std::map<Key,T,Compare,Alloc>& rhs );

// template< class Key, class T, class Compare, class Alloc >
// bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
//                  const std::map<Key,T,Compare,Alloc>& rhs );

// template< class Key, class T, class Compare, class Alloc >
// bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
//                 const std::map<Key,T,Compare,Alloc>& rhs );

// template< class Key, class T, class Compare, class Alloc >
// bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
//                  const std::map<Key,T,Compare,Alloc>& rhs );

// template< class Key, class T, class Compare, class Alloc >
// bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
//                 const std::map<Key,T,Compare,Alloc>& rhs );

// template< class Key, class T, class Compare, class Alloc >
// bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
//                  const std::map<Key,T,Compare,Alloc>& rhs );

// template< class Key, class T, class Compare, class Alloc >
// void swap( std::map<Key,T,Compare,Alloc>& lhs,
//            std::map<Key,T,Compare,Alloc>& rhs );

}

#endif