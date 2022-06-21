#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include "iterator_map.hpp"
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
		typedef typename Allocator::size_type							size_type;
		typedef typename Allocator::difference_type						difference_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef Node<value_type>										node;
		typedef typename Allocator::rebind<Node<value_type> >::other	alloc_node;
//				mon allocator de base est fait pour allouer des ft::pair. Pour changer ca,
//				jutilise rebind, cest un typedef template que tous les allocators ont. 
		typedef typename Allocator::reference							reference;
		typedef typename Allocator::const_reference						const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef ft::iterator_map<value_type>							iterator;
		typedef ft::iterator_map<value_type>							const_iterator;
		// typedef ft::reverse_iterator<ft::pair<const Key, T> >			reverse_iterator;
		// typedef ft::reverse_iterator<const ft::pair<const Key, T> >		const_reverse_iterator;


	private :

		allocator_type		_alloc;
		alloc_node			_alloc_node;
		Compare				_comp;
		Node<value_type>*	_tree;
		Node<value_type>*	_begin;
		Node<value_type>*	_end;
		size_type			_size;
		size_type			_height;

		void _copy(map const &copy) {
			_size = copy._size();
			_height = copy._height();
			_begin = copy._begin;
			_end = copy._end;
			insert(copy._begin, copy._end);
		}

		node* init_node(value_type value) {
			node* new_node = _alloc_node.allocate(1);
			_alloc_node.construct(new_node, value);
			// il va utiliser le constructeur de value_type. Jaurais pu mettre
			// en deuxieme parametre Node(value) mais ca m'aurait creer un objet 
			// pour ensuite copier lobjet dans new-node. Ici, je lui assigne directement
			// les valeurs.
			return new_node;
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
						_alloc(alloc), _alloc_node(alloc), _comp(comp), _size(0), _height(0) {
			
			node * new_node = init_node(value_type());
			_begin = new_node;
			_end = new_node;
		}

		template< class InputIt >
		map(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type() ) :
				_alloc(alloc), _alloc_node(alloc), _comp(comp), _size(0), _height(0) {
			node* new_node = init_node(value_type());
			_begin = new_node;
			_end = new_node;
			// insert(first, last);
		}

		map( const map& other ) {
			insert(other.begin(), other.end());
		}

		~map() {clear();}

//	------------------------------------------------


//	---------------->> GENERAL <<-----------------

		map & operator=(map const& other) {clear(); _copy(other); return *this;}

		allocator_type get_allocator() const { return _alloc; }

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

		T& operator[]( const Key& key ) {
			value_type value= ft::make_pair<const Key, T>(key, mapped_type());
			return (insert(value).first)->second;
		}

		T& at( const Key& key );
		
		const T& at( const Key& key ) const;

//	------------------------------------------------


//	---------------->> ITERATORS <<-----------------

		iterator begin() {return _begin != NULL ? _begin : iterator();}

		const_iterator begin() const {return _begin != NULL ? _begin : const_iterator();}

		iterator end() {return _end != NULL ? _end : iterator();}

		const_iterator end() const {return _end != NULL ? _end : const_iterator();}

		// reverse_iterator rbegin();

		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();

		// const_reverse_iterator rend() const;

//	------------------------------------------------


//	---------------->> CAPACITY <<------------------

		size_type size() const { return _size; }

		bool empty() const {return _tree == NULL;}

		size_type max_size() const {return allocator_type().max_size();}

//	------------------------------------------------


//	--------------->> MODIFIERS <<------------------

		void clear() {
			node* tmp(_end);

			while (_end) {
				tmp = _end;
				_end = tmp->parent;
				_alloc_node.destroy(_end);
			}
			_size = 0;
		}

		pair<iterator, bool> insert( const value_type& value ) {
			if (_end->value == value)
				return ft::make_pair(iterator(_end), false);
			node* new_node = init_node(value);
			(_end->value).first > value.first ? _end->right = new_node : _end->left = new_node;
			++_size;
			return ft::make_pair(iterator(_end), true);
		}

		iterator insert( iterator hint, const value_type& value );

		template< class InputIt >
		void insert(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last);

		iterator erase(iterator pos);

		void erase( iterator first, iterator last );

		void swap(map& other);

//	------------------------------------------------


//	---------------->> LOOKUP <<--------------------

		size_type count( const Key& key ) const;

		iterator find( const Key& key );

		const_iterator find( const Key& key ) const;

		pair<iterator,iterator> equal_range( const Key& key );

		pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

		iterator lower_bound( const Key& key );

		const_iterator lower_bound( const Key& key ) const;

		iterator upper_bound( const Key& key );

		const_iterator upper_bound( const Key& key ) const;

//	------------------------------------------------


//	--------------->> OBSERVERS <<------------------

		key_compare key_comp() const { return _comp; }

		map::value_compare value_comp() const { return _comp; }

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