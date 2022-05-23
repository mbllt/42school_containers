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
//			struct bst			*parent;
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
				const Allocator& alloc = Allocator() ) :
				_alloc(alloc), _bst(NIL), _size(0), _cap(0)
		{
			size_type count = 0;
			while (first != last) {
				++count;
				++first;
			}
			for (size_type i = 0;i < count;++i)
				--first;
			_bst = _alloc.allocate(count);
			for (size_type i = 0; i < count; ++i) {
				_alloc.construct(&(_bst[i].root.key), *first);
				++first;
			}
			_size = count;
			_cap = count;
			(void)comp;
		}

		map( const map& other );

		~map() {}

//	------------------------------------------------


//	---------------->> GENERAL <<-----------------

		map & operator=(map const& other);

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

		T& operator[]( const Key& key );

		T& at( const Key& key );
		
		const T& at( const Key& key ) const;

//	------------------------------------------------


//	---------------->> CAPACITY <<------------------

		size_type size() const {return _size;}

		bool empty() const;

		size_type max_size() const;

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

		std::map::value_compare value_comp() const;

//	------------------------------------------------

};

// //	---------------->> NON MEMBERS <<---------------
// // why use non members ? Because by default in a class,
// //	the first param is the instance of the class : this.
// //	Here we want the first element to be specifically something.

// template< class Key, class T, class Compare, class Alloc >
// bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
//                  const std::map<Key,T,Compare,Alloc>& rhs );

}

#endif