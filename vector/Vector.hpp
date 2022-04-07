#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

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
		pointer& operator*() {return *p;}

		// VectorIterator& operator++(void) {}
		// VectorIterator operator++(int) {}
		// VectorIterator& operator--(void) {}
		// VectorIterator operator--(int) {}

//	------------------------------------------------


//	---------------->> FUNCTIONS <<-----------------

		// VectorIterator & begin() {}
		// VectorIterator const & begin() const {}

};
//	------------------------------------------------------------------------------------------------



//	-------------------------------------------- VECTOR --------------------------------------------

template<typename T>
class Vector {

	public:
			typedef VectorIterator<T> iterator;
			typedef VectorIterator<T> const_iterator;

	private :

		T *			_tab;
		size_t		_size;

		void	_delete() {
			delete [] _tab;
		}

		void	_copy(Vector const & copy) {
			_tab = new T[copy._size];
			_size = copy._size;
			for (size_t i = 0; i < _size; i++)
				_tab[i] = copy._tab[i];
		}

	public :

//	--------------->> CONSTRUCTORS <<---------------

		Vector() : _tab(), _size(0) {}

		Vector(size_t n, const T & val) : _size(n) {
			_tab = new T[_size];
			for (size_t i = 0;i < _size;++i)
				_tab[i] = val;
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


//	---------------->> CAPACITY <<------------------

		size_t	size() const {return _size;}

//	------------------------------------------------


//	----------------->> ACCESS <<-------------------

		// iterator	begin() const {return _tab[0];}
		// const iterator	end() const {return _tab[_size - 1];}

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