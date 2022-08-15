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
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef typename Allocator::size_type size_type;
		typedef typename Allocator::difference_type difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef Node<value_type> node;
		typedef typename Allocator::template rebind<Node<value_type> >::other alloc_node;
		//	->mon allocator de base est fait pour allouer des ft::pair. Pour changer ca,
		//	jutilise rebind, cest un typedef template que tous les allocators ont.
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::iterator_map<value_type> iterator;
		typedef ft::iterator_map<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		allocator_type _allocPair;
		alloc_node _allocNode;
		Compare _comp;
		Node<value_type> *_root;
		Node<value_type> *_begin;
		Node<value_type> *_end;
		size_type _size;

//----- UTILS -----
		void _copy(map const &copy)
		{
			_allocPair = copy._allocPair;
			_allocNode = copy._allocNode;
			_comp = copy._comp;
			_root = NULL;
			_begin = NULL;
			_end = NULL;
			_size = 0;

			value_type value = ft::make_pair<const Key, T>(key_type(), mapped_type());
			node *new_node = _new_node(value);
			_end = new_node;
			--_size;
			if (copy._root)
			{
				for (const_iterator it = copy.begin(); it != copy.end(); it++)
					insert(*it);
			}
		}

		void _print_info_node(node *node)
		{
			std::cout << "\n-------\n";
			if (node)
				std::cout << "node : " << (node->value).first << "," << (node->value).second << "\n";
			if (node->left)
				std::cout << "node->left : " << (node->left->value).first << "\n";
			if (node->right)
				std::cout << "node->right : " << (node->right->value).first << "\n";
			std::cout << "size of tree : " << _size << "\n";
			if (node->parent)
			{
				std::cout << "node->parent : " << (node->parent->value).first << "\n";
				if (node->parent->right && node->parent->right != _end)
					std::cout << "parent->right : " << (node->parent->right->value).first << "\n";
				if (node->parent->left)
					std::cout << "parent->left : " << (node->parent->left->value).first << "\n";
			}
			if (_begin)
				std::cout << "begin : " << (_begin->value).first << "\n";
			if (_end->parent)
				std::cout << "last : " << (_end->parent->value).first << "\n";
			if (_root) {
				std::cout << "_root : " << (_root->value).first << "\n";
				if (_root->right)
					std::cout << "_root->right : " << (_root->right->value).first << "\n";
				if (_root->left)
					std::cout << "_root->left : " << (_root->left->value).first << "\n";
			}
			std::cout << "-------\n";
		}

		void _printBT(const std::string &prefix, const node *node, bool isLeft)
		{
			if (node && node != _end)
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──");

				std::cout << (node->value).first << std::endl;

				// enter the next tree level - left and right branch
				_printBT(prefix + (isLeft ? "│   " : "	"), node->left, true);
				_printBT(prefix + (isLeft ? "│   " : "	"), node->right, false);
			}
		}

		void _printBT(const node *node)
		{
			std::cout << "\n----------\n";
			_printBT("", node, false);
			std::cout << "\n----------\n";
		}
//-----------------

		node *_new_node(value_type value)
		{
			node *new_node = _allocNode.allocate(1);
			_allocNode.construct(new_node, value);
			// il va utiliser le constructeur de value_type. Jaurais pu mettre
			// en deuxieme parametre Node(value) mais ca m'aurait creer un objet
			// pour ensuite copier lobjet dans new-node. Ici, je lui assigne directement
			// les valeurs.
			new_node->parent = NULL;
			new_node->right = NULL;
			new_node->left = NULL;
			new_node->height = 0;
			++_size;
			return new_node;
		}

		node *_find_node(node *tree, const Key &key)
		{
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

		pair<node*, bool> _insert_node(node *tree, const value_type &value, node *parent)
		{
			if (!tree || tree == _end)
			{
				node *new_node = _new_node(value);
				if (_root)
				{
					new_node->parent = parent;
					if (_comp((parent->value).first, value.first))
						new_node->parent->right = new_node;
					else
						new_node->parent->left = new_node;
				}
				_balanceTree(tree);
				// _balance_after_insert(tree);
				return ft::make_pair<node*, bool>(new_node, true);
			}
			pair<node*, bool> ret;

			// already there
			if (value.first == (tree->value).first)
				return ft::make_pair<node*, bool>(tree, false);
			else if (_comp(value.first, (tree->value).first))
				ret = _insert_node(tree->left, value, tree);
			else if (_comp((tree->value).first, value.first))
				ret = _insert_node(tree->right, value, tree);
			return ret;
		}

//------ AVL ------
		// void _balance_after_insert(node* tree) {
			
		// }

		int _heightTree(node *tree, int height) {
			if (!tree || tree == _end)
				return height - 1;

			int leftHeight = _heightTree(tree->left, height + 1);
			int rightHeight = _heightTree(tree->right, height + 1);

			return leftHeight > rightHeight ? leftHeight : rightHeight;
		}

		int _balanceOfSubtrees(node* node) {
			if (!node)
				return 0;
			return _heightTree(node->left, 1) - _heightTree(node->right, 1);
		}

		void _rotateRight(node* nodeGoingDown) {

			node* nodeGoingUp = nodeGoingDown->left;

			nodeGoingDown->left = nodeGoingUp->right;

			if (nodeGoingUp->right)
				nodeGoingUp->right->parent = nodeGoingDown;

			nodeGoingUp->right = nodeGoingDown;

			nodeGoingUp->parent = nodeGoingDown->parent;

			if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
				nodeGoingDown->parent->left = nodeGoingUp;
			else if (nodeGoingDown->parent)
				nodeGoingDown->parent->right = nodeGoingUp;

			nodeGoingDown->parent = nodeGoingUp;

			if (!nodeGoingUp->parent)
				_root = nodeGoingUp;
		}

		void _rotateLeft(node* nodeGoingDown) {
			node* nodeGoingUp = nodeGoingDown->right;

			nodeGoingDown->right = nodeGoingUp->left;

			if (nodeGoingUp->left)
				nodeGoingUp->left->parent = nodeGoingDown;

			nodeGoingUp->left = nodeGoingDown;

			nodeGoingUp->parent = nodeGoingDown->parent;

			if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
				nodeGoingDown->parent->left = nodeGoingUp;
			else if (nodeGoingDown->parent)
				nodeGoingDown->parent->right = nodeGoingUp;

			nodeGoingDown->parent = nodeGoingUp;

			if (!nodeGoingUp->parent)
				_root = nodeGoingUp;
		}

		void _balanceTree(node* tree)
		{
			while (tree)
			{
				int balance;
				if ((balance = _balanceOfSubtrees(tree)) < -1 && _balanceOfSubtrees(tree->right) < 0)
					_rotateLeft(tree);
				else if (balance < -1 && _balanceOfSubtrees(tree->right) >= 0)
				{
					_rotateRight(tree->right);
					_rotateLeft(tree);
				}
				else if (balance > 1 && _balanceOfSubtrees(tree->left) > 0)
					_rotateRight(tree);
				else if (balance > 1 && _balanceOfSubtrees(tree->left) <= 0)
				{
					_rotateLeft(tree->left);
					_rotateRight(tree);
				}
				tree = tree->parent;
				}
		}
//-----------------

		void _case_with_begin(node* tree) {
				
				if (tree->parent)
					tree = tree->parent;
				else if (!tree->parent)
					tree = tree->right;
				while (tree && tree->left)
					tree = tree->left;
				_begin = tree;
		}

		void _case_with_end(node* tree) {
				if (tree->left) {
					tree = tree->left;
					while (tree && tree->right)
						tree = tree->right;
					_end->parent = tree;
					tree->right = _end;
				}
				else if (tree->parent) {
					_end->parent = tree->parent;
					tree->parent->right = _end;
				}
		}

		void _erase_node_no_children(node *tree)
		{
			if (tree->parent && tree->parent->left == tree)
				tree->parent->left = NULL;
			else if (tree->parent && tree->parent->right == tree)
				tree->parent->right = NULL;
			if (tree->right == _end)
				_case_with_end(tree);
			if (tree == _begin)
				_case_with_begin(tree);
			_delete_node(&tree);
		}

		void _erase_node_one_child(node *tree)
		{
			if (tree->right)
			{
				tree->right->parent = tree->parent;
				if (tree->parent && tree->parent->right == tree)
					tree->parent->right = tree->right;
				else if (tree->parent && tree->parent->left == tree)
					tree->parent->left = tree->right;
				else if (!tree->parent) // case of root
					_root = tree->right;
			}
			if (tree->left)
			{
				tree->left->parent = tree->parent;
				if (tree->parent && tree->parent->right == tree)
					tree->parent->right = tree->left;
				else if (tree->parent && tree->parent->left == tree)
					tree->parent->left = tree->left;
				else if (!tree->parent) // case of root
					_root = tree->left;
			}
			if (tree->right == _end)
				_case_with_end(tree);
			else if (tree == _begin)
				_case_with_begin(tree);
			_delete_node(&tree);
		}

		void _swap_nodes(node *first, node *second)
		{
			node* first_left = first->left;
			node* first_right = first->right;
			node* first_parent = first->parent;
			int first_height = first->height;

			if (first->parent)
			{
				if (first->parent->right == first)
					first->parent->right = second;
				else if (first->parent->left == first)
					first->parent->left = second;
			}

			if (first->right)
				first->right->parent = second;
			if (first->left)
				first->left->parent = second;
			first->right = second->right;
			first->left = second->left;
			first->parent = second->parent;
			first->height = second->height;

			if (second->parent)
			{
				if (second->parent->right == second)
					second->parent->right = first;
				else if (second->parent->left == second)
					second->parent->left = first;
			}
			if (first_right == second)
				second->right = first_right->right;
			else
				second->right = first_right;
			second->left = first_left;
			second->parent = first_parent;
			second->height = first_height;
			if (!second->parent) // case of root
				_root = second;
		}

		void _erase_node_two_children(node *tree)
		{
			node *lower = tree->right;
			while (lower->left)
				lower = lower->left;
			_swap_nodes(tree, lower);
			if (tree->right || tree->left)
				_erase_node_one_child(tree);
			else if (!tree->right && !tree->left)
				_erase_node_no_children(tree);
		}

		void _delete_node(node **deleteNode)
		{
			if (!(*deleteNode))
				return;
			_allocNode.destroy((*deleteNode));
			_allocNode.deallocate((*deleteNode), 1);
			*deleteNode = NULL;
			if (_size)
				--_size;
		}

		void _clear_node(node **clearNode)
		{
			if (!(*clearNode))
				return;
			_clear_node(&(*clearNode)->left);
			_clear_node(&(*clearNode)->right);
			_delete_node(clearNode);
		}

	public:
		//	----------------->> CLASSES <<-----------------

		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
		public:
			bool operator()(const value_type &lhs, const value_type &rhs) const { return comp(lhs.first, rhs.first); }

		protected:
			value_compare(Compare C) : comp(C) {}
			Compare comp;
		};

		//	------------------------------------------------

		//	--------------->> CONSTRUCTORS <<---------------

		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : _allocPair(alloc), _allocNode(alloc), _comp(comp),
																	   _root(NULL), _begin(NULL), _end(NULL), _size(0)
		{
			value_type value = ft::make_pair<const Key, T>(key_type(), mapped_type());
			node *new_node = _new_node(value);
			_end = new_node;
			--_size;
		}

		template <class InputIt>
		map(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) : _allocPair(alloc), _allocNode(alloc), _comp(comp),
															  _root(NULL), _begin(NULL), _end(NULL), _size(0)
		{
			value_type value = ft::make_pair<const Key, T>(key_type(), mapped_type());
			node *new_node = _new_node(value);
			_end = new_node;
			--_size;
			insert(first, last);
		}

		map(const map &other) : _allocPair(other._allocPair), _allocNode(other._allocNode), _comp(other._comp),
								_root(NULL), _begin(NULL), _end(NULL), _size(0)
		{
			_copy(other);
		}

		~map()
		{
			clear();
		}

		//	------------------------------------------------

		//	---------------->> GENERAL <<-----------------

		map &operator=(map const &other)
		{
			clear();
			_copy(other);
			return *this;
		}

		allocator_type get_allocator() const { return _allocPair; }

		//	------------------------------------------------

		//	----------------->> ACCESS <<-------------------

		T &operator[](const Key &key)
		{
			iterator find_or_insert = find(key);
			if (find_or_insert != end()) {
				return find_or_insert->second;
			}
			else {
				value_type value = ft::make_pair<const Key, T>(key, mapped_type());
				iterator ret = insert(value).first;
				return ret->second;
			}
		}

		T &at(const Key &key)
		{
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

		void clear()
		{
			if (_root != NULL)
				_clear_node(&_root);
			else
				_clear_node(&_end);
			_root = NULL;
			_begin = NULL;
			_end = NULL;
		}

		pair<iterator, bool> insert(const value_type &value)
		{
			pair<node*, bool> ret = _insert_node(_root, value, _root);
			node *new_node = ret.first;
			if (!ret.second)
				return ft::make_pair(iterator(new_node), false);

			if (!_root)
			{
				if (!_end) {
					value_type value = ft::make_pair<const Key, T>(key_type(), mapped_type());
					node* new_end = _new_node(value);
					_end = new_end;
				}
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
			if (_comp((new_node->value).first, (_begin->value).first))
				_begin = new_node;
			// _balanceTree(new_node);

			return ft::make_pair(iterator(new_node), true);
		}

		iterator insert(iterator hint, const value_type &value)
		{
			(void)hint;
			insert(value);
			return iterator(find(value.first));
		}

		template <class InputIt>
		void insert(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		void erase(iterator pos)
		{
			erase(pos->first);
		}

		void erase(iterator first, iterator last)
		{
			iterator current;
			while (first != last) {
				iterator current = first++;
				this->erase(current);
			}
		}

		size_type erase(const Key &key) {
			node *tree = _find_node(_root, key);
			if (tree != _end)
			{
				node* balance = tree->parent;
				if (!tree->right && !tree->left)
					_erase_node_no_children(tree);
				else if (tree->right && tree->right != _end && tree->left)
					_erase_node_two_children(tree);
				else if (tree->right || tree->left)
					_erase_node_one_child(tree);
				_balanceTree(balance);
				return 1;
			}
			return 0;
		}

		void swap(map &other)
		{
			ft::swap(_allocPair, other._allocPair);
			ft::swap(_allocNode, other._allocNode);
			ft::swap(_comp, other._comp);
			ft::swap(_root, other._root);
			ft::swap(_begin, other._begin);
			ft::swap(_end, other._end);
			ft::swap(_size, other._size);
		}

		//	------------------------------------------------

		//	---------------->> LOOKUP <<--------------------

		size_type count(const Key &key) const
		{
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

		iterator find(const Key &key)
		{
			return iterator(_find_node(_root, key));
		}

		const_iterator find(const Key &key) const
		{
			iterator &ret = const_cast<map &>(*this).find(key);
			return ret;
		}

		pair<iterator, iterator> equal_range(const Key &key)
		{
			return pair<iterator, iterator>(lower_bound(key), upper_bound(key));
		}

		pair<const_iterator, const_iterator> equal_range(const Key &key) const
		{
			iterator &ret = const_cast<map &>(*this).equal_range(key);
			return ret;
		}

		iterator lower_bound(const Key &key)
		{
			iterator it = begin();

			for (; it != end(); ++it)
				if (!_comp(it->first, key))
					break;

			return it;
		}

		const_iterator lower_bound(const Key &key) const
		{
			iterator &ret = const_cast<map &>(*this).lower_bound(key);
			return ret;
		}

		iterator upper_bound(const Key &key)
		{
			iterator it = begin();

			for (; it != end(); ++it)
				if (_comp(key, it->first))
					break;

			return it;
		}

		const_iterator upper_bound(const Key &key) const
		{
			iterator &ret = const_cast<map &>(*this).upper_bound(key);
			return ret;
		}

		//	------------------------------------------------

		//	--------------->> OBSERVERS <<------------------

		key_compare key_comp() const { return _comp; }

		map::value_compare value_comp() const { return value_compare(_comp); }

		//	------------------------------------------------

		//	---------------->> NON MEMBERS <<---------------

		friend bool operator==(const map &lhs, const map &rhs)
		{
			if (lhs.empty() && rhs.empty())
					return true;
				else if (lhs.size() != rhs.size() )
					return false;
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		friend bool operator!=(const map &lhs, const map &rhs) { return !(lhs == rhs); }
		friend bool operator<(const map &lhs, const map &rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
		friend bool operator<=(const map &lhs, const map &rhs) { return ((lhs < rhs) || (lhs == rhs)); }
		friend bool operator>(const map &lhs, const map &rhs) { return (!(lhs < rhs) && (lhs != rhs)); }
		friend bool operator>=(const map &lhs, const map &rhs) { return !(lhs < rhs); }

		friend void swap(map &lhs, map &rhs) { lhs.swap(rhs); }

		//	------------------------------------------------
	};

}

#endif