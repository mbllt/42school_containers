#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <iterator>

//	------------------------------------------- ITERATOR -------------------------------------------

template<typename T>
class VectorIterator:: std::iterator_traits {

	public:
		typedef T value_type;
		typedef pointer* value_type;
		typedef pointer const * value_type;
		typedef reference& value_type;
		typedef reference const & value_type;
		typedef std::ptrdiff_t diff_type;

	private:

		pointer _p;

		void	_delete() {
			delete [] _tab;
		}

		void	_copy(Vector const & copy) {
			_p = cpy._p;
		}

	public:

//	--------------->> CONSTRUCTORS <<---------------

		VectorIterator() : _p(NULL) {}
		VectorIterator(pointer p) : _p(p) {}
		VectorIterator(VectorIterator const & cpy) : _p(cpy._p) {}
		~VectorIterator() {}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		VectorIterator & operator=(Vector const & src) {
			_delete();
			_copy(src);
			return *this;
		}

		VectorIterator& operator++(void) {}
		VectorIterator operator++(int) {}
		VectorIterator& operator--(void) {}
		VectorIterator operator--(int) {}

		T & operator[](const unsigned int index) {
			if (index >= this->_size)
				throw AccessorVectorInvalidExcpetion("Index to access VectorIterator is invalid.");
			return _tab[index];
		}

		T const & operator[](const unsigned int index) const {
			T & ret = const_cast<Vector &>(*this).operator[](index);
			return const_cast<T const &>(ret);
		}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		// VectorIterator & begin() {}
		// VectorIterator const & begin() const {}

};
//	------------------------------------------------------------------------------------------------



//	-------------------------------------------- VECTOR --------------------------------------------

template<typename T>
class Vector {

	public:
			typedef VectorIterator iterator;

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

//	------------------------------------------------


//	---------------->> CAPACITY <<------------------

		// size_t	size() const {return _size;}

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