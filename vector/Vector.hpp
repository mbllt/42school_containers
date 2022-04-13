#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <memory>

//	------------------------------------------- ITERATOR -------------------------------------------

template<typename T>
class VectorIterator {

	public:
		typedef T value_type;
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef std::ptrdiff_t diff_type;

	private:

		pointer p;

		void	_delete() {
		}

		void	_copy(VectorIterator const & copy) {
			p = copy.p;
		}

	public:

//	--------------->> CONSTRUCTORS <<---------------

		VectorIterator() : p(NULL) {}
		VectorIterator(pointer p) : p(p) {}
		VectorIterator(VectorIterator const & copy) : p(copy.p) {}
		~VectorIterator() {}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		VectorIterator& operator++() {++p;return *this;}
		VectorIterator operator++(int) {VectorIterator tmp(*this); operator++(); return tmp;}
		VectorIterator& operator--() {++p;return *this;}
		VectorIterator operator--(int) {VectorIterator tmp(*this); operator++(); return tmp;}
		bool operator==(const VectorIterator& src) const {return p==src.p;}
		bool operator!=(const VectorIterator& src) const {return p!=src.p;}
		value_type& operator*() {return *p;}

		// VectorIterator& operator++(void) {}
		// VectorIterator operator++(int) {}
		// VectorIterator& operator--(void) {}
		// VectorIterator operator--(int) {}

};
//	------------------------------------------------------------------------------------------------



//	-------------------------------------------- VECTOR --------------------------------------------

template<typename T, class Alloc = std::allocator<T> >
class Vector {

	public:
		typedef VectorIterator<T> iterator;
		typedef VectorIterator<const T> const_iterator;
		typedef VectorIterator<T> reverse_iterator;
		typedef VectorIterator<const T> const_reverse_iterator;

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

		void	_copy(Vector const & copy) {
			int i = 0;
			_tab = _alloc.allocate(copy._size);
			while (i++ < copy._size) {
				_alloc.construct(_tab[i], &(copy._tab[i]));
				_tab++;
			}
		}

	public :

//	--------------->> CONSTRUCTORS <<---------------

		Vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _tab(), _size(0) {}

		Vector(size_t n, const T & val, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n) {
			_tab = _alloc.allocate(n);
			for(size_t i = 0;i < n;i++)
				_alloc.construct(&_tab[i], val);
		}

		// Vector(input iterator first, input iterator last) : _size(first - last) {_tab = new T[_size]}

		Vector(Vector const & cpy) {_copy(cpy);}

		~Vector() {_delete();}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		Vector & operator=(Vector const & src) {
			_delete();
			_copy(src);
			return *this;
		}

		T & operator[](const unsigned int index) {
			if (index >= this->_size)
				throw AccessorVectorInvalidExcpetion("Index to access Vector is invalid.");
			return _tab[index];
		}

		T const & operator[](const unsigned int index) const {
			T & ret = const_cast<Vector &>(*this).operator[](index);
			return const_cast<T const &>(ret);
		}

		Vector& operator++() {return ++(*this);}
		Vector operator++(int) {Vector tmp(*this); ++(*tmp); return tmp;}

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

		class AccessorVectorInvalidExcpetion : public std::exception {
		
			private :

				std::string		_messageErr;

			public :
		
				AccessorVectorInvalidExcpetion(std::string std) throw() : _messageErr(std) {};
				virtual ~AccessorVectorInvalidExcpetion() throw() {};
		
				virtual const char* what() const throw() {
					return _messageErr.c_str();
				}
		};

};
//	------------------------------------------------------------------------------------------------

#endif