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

namespace ft
{

	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{

	public:
		typedef Key																			key_type;
		typedef T																			mapped_type;
		typedef ft::pair<const Key, T>														value_type;
		typedef typename Allocator::size_type												size_type;
		typedef typename Allocator::difference_type											difference_type;
		typedef Compare																		key_compare;
		typedef Allocator																	allocator_type;
		typedef Node<value_type>															node;
		typedef typename Allocator::template rebind<Node<value_type> >::other				alloc_node;
		//	->mon allocator de base est fait pour allouer des ft::pair. Pour changer ca,
		//	jutilise rebind, cest un typedef template que tous les allocators ont.
		typedef typename Allocator::reference												reference;
		typedef typename Allocator::const_reference											const_reference;
		typedef typename Allocator::pointer													pointer;
		typedef typename Allocator::const_pointer											const_pointer;
		typedef ft::iterator_map<value_type>												iterator;
		typedef ft::iterator_map<const value_type>											const_iterator;
		typedef ft::reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;

	private:
		allocator_type _allocPair;
		alloc_node _allocNode;
		Compare _comp;
		Node<value_type> *_root;
		Node<value_type> *_begin;
		Node<value_type> *_end;
		size_type _size;
		size_type _height;

		void _copy(map const &copy) {
			clear();
			_allocPair = copy._allocPair;
			_allocNode = copy._allocNode;
			_comp = copy._comp;
			_root = NULL;
			_begin = copy._begin;
			_end = copy._end;
			_size = copy._size;
			_height = copy.height;
			if (copy._root) {
				--_size;
				insert(copy.begin(), copy.end());
			}
		}

		void _print_info_node(node *node) {
			std::cout << "\n-------\n";
			if (node)
				std::cout << "node : " << (node->value).first << "\n";
			if (node->left)
				std::cout << "node->left : " << (node->left->value).first << "\n";
			if (node->right)
				std::cout << "node->right : " << (node->right->value).first << "\n";
			std::cout << "size of tree : " << _size << "\n";
			if (node->parent) {
				std::cout << "node->parent : " << (node->parent->value).first << "\n";
				if (node->parent->right && node->parent->right != _end)
					std::cout << "parent->right : " << (node->parent->right->value).first << "\n";
				if (node->parent->left)
					std::cout << "parent->left : " << (node->parent->left->value).first << "\n";
			}
			std::cout << "begin : " << (_begin->value).first << "\n";
			std::cout << "last : " << (_end->parent->value).first << "\n";
			std::cout << "_root : " << (_root->value).first << "\n";
			if (_root->right)
					std::cout << "_root->right : " << (_root->right->value).first << "\n";
			if (_root->left)
					std::cout << "_root->left : " << (_root->left->value).first << "\n";
			std::cout << "-------\n";
		}

		void _printBT(const std::string& prefix, const node* node, bool isLeft)
		{
			if(node && node != _end)
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );

				// print the value of the node
				std::cout << (node->value).first << std::endl;

				// enter the next tree level - left and right branch
				_printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
				_printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}

		void _printBT(const node* node)
		{
			std::cout << "\n----------\n";
			_printBT("", node, false);
			std::cout << "\n----------\n";
		}

		int _get_height(node *tree) const {
			if (!tree)
				return -1;
			if (tree == _end || (!tree->right && !tree->left))
				return 0;

			int H = 0;
			int Tl = 0;
			int Tr = 0;

			if (tree->left)
				Tl += _get_height(tree->left);
			if (tree->right)
				Tr += _get_height(tree->right);

			H = std::max(Tr, Tl) + 1;
			return H;
		}

		bool _is_balanced() {
			return (_get_height(_root->right) - _get_height(_root->left) <= 1 && _get_height(_root->right) - _get_height(_root->left) >= -1)
					   ? true
					   : false;
		}

		void _balance(node *tree) {
			if (_is_balanced())
				return;
			if (_get_height(tree->left) > _get_height(tree->right))
			{
				return;
				if (tree->left && (tree->left)->right)
					_left_rot(tree->left, (tree->left)->right);
				_right_rot(tree, tree->left);
			}
			else if (tree->right && tree->right != _end)
			{
				if (tree->right && (tree->right)->left)
					_right_rot(tree->right, (tree->right)->left);
				_left_rot(tree, tree->right);
			}
		}

		node *_new_node(value_type value) {
			node *new_node = _allocNode.allocate(1);
			_allocNode.construct(new_node, value);
			// il va utiliser le constructeur de value_type. Jaurais pu mettre
			// en deuxieme parametre Node(value) mais ca m'aurait creer un objet
			// pour ensuite copier lobjet dans new-node. Ici, je lui assigne directement
			// les valeurs.
			new_node->parent = NULL;
			new_node->right = NULL;
			new_node->left = NULL;
			++_size;
			return new_node;
		}

		node *_find_node(node* tree, const Key& key) {
			if (!tree || tree == _end)
				return _end;
			if (key == (tree->value).first)
				return tree;
			if (_comp(key, (tree->value).first))
				tree = _find_node(tree->left, key);
			else
				tree = _find_node(tree->right, key);
			return tree;
		}

		void _right_rot(node *a, node *b) {
			a->left = b->right;
			if (b->right)
				(b->right)->parent = a;
			b->right = a;
			b->parent = a->parent;

			//	if a parent exists they have to point to the good child
			if (a->parent && a->parent->right == a)
				a->parent->right = b;
			else if (a->parent)
				a->parent->left = b;

			//	updtae of root if we switched it
			a->parent = b;
			if (!b->parent)
				_root = b;
		}

		void _left_rot(node *a, node *b) {
			a->right = b->left;
			if (b->left)
				(b->left)->parent = a;
			b->left = a;
			b->parent = a->parent;
			if (b->parent && b->parent->right == a)
				b->parent->right = a;
			else if (b->parent)
				b->parent->left = a;
			a->parent = b;
			if (!b->parent)
				_root = b;
		}

		node *_insert_node(node* tree, const value_type& value, node* parent) {
			if (!tree || tree == _end) {
				node* new_node = _new_node(value);
				if (_root) {
					new_node->parent = parent;
					if (_comp((parent->value).first, (new_node->value).first))
						new_node->parent->right = new_node;
					else
						new_node->parent->left = new_node;
				}
				return new_node;
			}
			if (_comp(value.first, (tree->value).first))
				tree = _insert_node(tree->left, value, tree);
			else if (_comp((tree->value).first, value.first))
				tree = _insert_node(tree->right, value, tree);
			return tree;
		}

		void _erase_node_no_children(node *tree) {
			if (tree->parent && tree->parent->left == tree)
				tree->parent->left = NULL;
			else if (tree->parent && tree->parent->right == tree)
				tree->parent->right = NULL;
			// special case with begin
			if (tree == _begin && tree->parent) {
				node* tmp = tree->parent;
				while (tmp && tmp->left)
					tmp = tmp->left;
				_begin = tmp;
			}
			_delete_node(&tree);
			_balance(_root);
		}

		void _erase_node_one_child(node *tree) {
			// special case with root
			// if (tree == _root) {
			// std::cout << "special cas with root\n";
			// 	if (tree->right) {
			// 		_root = tree->right;
			// 		tree->right->parent = NULL;
			// 	}
			// 	else if (tree->left) {
			// 		_root = tree->left;
			// 		tree->left->parent = NULL;
			// 	}
			// 	_delete_node(&tree);
			// 	_balance(_root);
			// 	return;
			// }
			if (tree->right) {
				tree->right->parent = tree->parent;
				if (tree->parent && tree->parent->right == tree)
					tree->parent->right = tree->right;
				else if (tree->parent && tree->parent->left == tree)
					tree->parent->left = tree->right;
			}
			else if (tree->left) {
				tree->left->parent = tree->parent;
				if (tree->parent && tree->parent->right == tree)
					tree->parent->right = tree->left;
				else if (tree->parent && tree->parent->left == tree)
					tree->parent->left = tree->left;
			}
			// special case with begin
			if (tree == _begin && tree->parent) {
				node* tmp = tree->parent;
				while (tmp && tmp->left)
					tmp = tmp->left;
				_begin = tmp;
			}
			_delete_node(&tree);
			_balance(_root);
		}

		void _swap_nodes(node* first, node* second) {
			node* tmp(first);

			first->right = second->right;
			first->left = second->left;
			first->parent = second->parent;
			if (second->parent) {
				if (second->parent->right == second)
					second->parent->right = first;
				else if (second->parent->left == second)
					second->parent->left = first;
			}
			second->right = tmp->right;
			second->left = tmp->left;
			second->parent = tmp->parent;
			if (tmp->parent) {
				if (tmp->parent->right == tmp)
					tmp->parent->right = second;
				else if (tmp->parent->left == tmp)
					tmp->parent->left = second;
			}
		}

		void _erase_node_two_children(node *tree) {
			std::cout << "erase_node_with_two_children\n";
			node* lower = tree->right;
			while (lower->left)
				lower = lower->left;
			_swap_nodes(tree, lower);
			if (tree->right || tree->left)
				_erase_node_one_child(tree);
			else if (!tree->right && !tree->left)
				_erase_node_no_children(tree);
		}

		void _delete_node(node** deleteNode) {
			if (!(*deleteNode) || *deleteNode == _end)
				return;
			_allocNode.destroy((*deleteNode));
			_allocNode.deallocate((*deleteNode), 1);
			*deleteNode = NULL;
			if (_size)
				--_size;
		}

		void _clear_node(node** clearNode) {
			if (!(*clearNode))
				return;
			_clear_node(&(*clearNode)->left);
			_clear_node(&(*clearNode)->right);
			_delete_node(clearNode);
		}

	public:
		//	----------------->> CLASSES <<-----------------

		class value_compare : ft::binary_function<value_type, value_type, bool> {
		public:
			bool operator()(const value_type &lhs, const value_type &rhs) const { return comp(lhs.first, rhs.first); }

		protected:
			value_compare(Compare C) : comp(C) {}
			Compare comp;
		};

		//	------------------------------------------------


		//	--------------->> CONSTRUCTORS <<---------------

		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) :
					_allocPair(alloc), _allocNode(alloc), _comp(comp),
					_root(NULL), _begin(NULL), _end(NULL), _size(0), _height(0)
		{
			value_type value = ft::make_pair<const Key, T>(key_type(), mapped_type());
			node *new_node = _new_node(value);
			_end = new_node;
			--_size;
		}

		template <class InputIt>
		map(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) :
			_allocPair(alloc), _allocNode(alloc), _comp(comp),
			_root(NULL), _begin(NULL), _end(NULL), _size(0), _height(0)
		{
			value_type value = ft::make_pair<const Key, T>(key_type(), mapped_type());
			node *new_node = _new_node(value);
			_end = new_node;
			--_size;
			insert(first, last);
		}

		map(const map &other) :
		_allocPair(other._allocPair), _allocNode(other._allocNode), _comp(other._comp),
		_root(NULL), _begin(NULL), _end(NULL),_size(0), _height(0)
		{
			value_type value = ft::make_pair<const Key, T>(key_type(), mapped_type());
			node *new_node = _new_node(value);
			_end = new_node;
			if (other._root) {
				--_size;
				insert(other.begin(), other.end());
			}
		}

		~map() {
			clear();
			_allocNode.destroy(_end);
			_allocNode.deallocate(_end, 1);
			_end = NULL;
		}

		//	------------------------------------------------


		//	---------------->> GENERAL <<-----------------

		map &operator=(map const &other) {
			clear();
			_copy(other);
			return *this;
		}

		allocator_type get_allocator() const { return _allocPair; }

		//	------------------------------------------------


		//	----------------->> ACCESS <<-------------------

		T &operator[](const Key &key) {
			value_type value = ft::make_pair<const Key, T>(key, mapped_type());
			return (insert(value).first)->second;
		}

		T &at(const Key &key) {
			iterator it = find(key);
			if (it == end())
				throw std::out_of_range("map::at");
			return it->second;
		}

		const T &at(const Key &key) const;

		//	------------------------------------------------


		//	---------------->> ITERATORS <<-----------------

		iterator begin() { return _begin != NULL ? iterator(_begin) : iterator(); }
		const_iterator begin() const { return _begin != NULL ? const_iterator(_begin) : const_iterator(); }
		iterator end() { return iterator(_end); }
		const_iterator end() const { return const_iterator(_end); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		//	------------------------------------------------


		//	---------------->> CAPACITY <<------------------

		size_type size() const { return _size; }
		bool empty() const { return _root == NULL; }
		size_type max_size() const { return _allocNode.max_size(); }

		//	------------------------------------------------


		//	--------------->> MODIFIERS <<------------------

		void clear() {
			if (!this->empty())
				_clear_node(&_root);
			_root = NULL;
			_begin = NULL;
			_end->parent = NULL;
		}

		pair<iterator, bool> insert(const value_type &value) {
			node* found = _find_node(_root, value.first);
			if (found != _end)
				return ft::make_pair(iterator(found), false);

			node* new_node = _insert_node(_root, value, _root);

			if (!_root) {
				_end->parent = new_node;
				new_node->right = _end;
				_root = new_node;
				_begin = new_node;
			}

			//	reset _begin _end if needed
			if (_comp((_end->parent->value).first, (new_node->value).first))
			{
				if (_end->parent->parent && _end->parent->right == _end)
					_end->parent->right = NULL;
				new_node->right = _end;
				_end->parent = new_node;
			}
			if (_comp((new_node->value).first, (_begin->value).first)) {
				_begin = new_node;
			}

			// _print_info_node(new_node);
			_balance(_root);
			// _printBT(_root);

			return ft::make_pair(iterator(new_node), true);
		}

		iterator insert(iterator hint, const value_type &value) {
			(void)hint;
			insert(value);
			return iterator(find(value.first));
		}

		template <class InputIt>
		void insert(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last) {
			while (first != last) {
				insert(*first);
				++first;
			}
		}

		void erase(iterator pos) {
			erase(pos->first);
		}

		template <class InputIt>
		void erase(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, iterator last) {
			while (first != last) {
				erase(first);
				++first;
			}
		}

		size_type erase( const Key& key ) {
			node* tree = _find_node(_root, key);
			if (tree != _end) {
				// special case with end
				if (tree->right == _end && tree->parent) {
					tree->parent->right = _end;
					_end = tree->parent;
					tree->right = NULL;
				}
				if (!tree->right && !tree->left)
					_erase_node_no_children(tree);
				else if (tree->right && tree->left)
					_erase_node_two_children(tree);
				else if (tree->right || tree->left)
					_erase_node_one_child(tree);
				return 1;
			}
			return 0;
		}

		void swap(map &other) {
			ft::swap(_allocPair, other._allocPair);
			ft::swap(_allocNode, other._allocNode);
			ft::swap(_comp, other._comp);
			ft::swap(_root, other._root);
			ft::swap(_begin, other._begin);
			ft::swap(_end, other._end);
			ft::swap(_size, other._size);
			ft::swap(_height, other._height);
		}

		//	------------------------------------------------


		//	---------------->> LOOKUP <<--------------------

		size_type count(const Key &key) const {
			size_t ret = 0;
				const_iterator it = begin();

				while (it != end())
				{
					if (it->first == key)
						++ret;
					++it;
				}
				return (ret);
		}

		iterator find(const Key &key) {
			return iterator(_find_node(_root, key));
		}

		const_iterator find(const Key &key) const {
			iterator& ret = const_cast<map &>(*this).find(key);
			return ret;
		}

		pair<iterator, iterator> equal_range(const Key &key) {
			return pair<iterator, iterator>(lower_bound(key), upper_bound(key));
		}

		pair<const_iterator, const_iterator> equal_range(const Key &key) const {
			iterator& ret = const_cast<map &>(*this).equal_range(key);
			return ret;
		}

		iterator lower_bound(const Key &key) {
			iterator it = begin();

				for (; it != end(); ++it)
					if (!_comp(it->first, key))
						break;
				
				return it;
		}

		const_iterator lower_bound(const Key &key) const {
			iterator& ret = const_cast<map &>(*this).lower_bound(key);
			return ret;
		}

		iterator upper_bound(const Key &key) {
			iterator it = begin();

				for (; it != end(); ++it)
					if (_comp(key, it->first))
						break;
				
				return it;
		}

		const_iterator upper_bound(const Key &key) const {
			iterator& ret = const_cast<map &>(*this).upper_bound(key);
			return ret;
		}

		//	------------------------------------------------


		//	--------------->> OBSERVERS <<------------------

		key_compare key_comp() const { return _comp; }

		map::value_compare value_comp() const { return value_compare(_comp); }

		//	------------------------------------------------


		//	---------------->> NON MEMBERS <<---------------

		friend bool operator==( const map& lhs, const map& rhs ) {
			iterator itr = rhs._begin;
			iterator itl = lhs._begin;
			iterator itel = lhs._end;

			if (rhs.empty() && lhs.empty())
				return true;
			if (rhs.empty() || lhs.empty())
				return false;

			while (itl != itel) {
				if (itr != itl)
					return false;
				++itr;
				++itl;
			}
			if (itr == rhs.end())
				return true;
			return false;
			return lhs._root == rhs._root;
		}

		friend bool operator!=( const map& lhs, const map& rhs ) {return !(lhs == rhs); }
		friend bool operator<( const map& lhs, const map& rhs ) {return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
		friend bool operator<=( const map& lhs, const map& rhs ) {return ((lhs < rhs) || (lhs == rhs));}
		friend bool operator>( const map& lhs, const map& rhs ) {return (!(lhs < rhs) && (lhs != rhs));}
		friend bool operator>=( const map& lhs, const map& rhs ) {return !(lhs < rhs);}

		friend void swap(map& lhs, map& rhs) {lhs.swap(rhs);}

		//	------------------------------------------------
	};

}

#endif