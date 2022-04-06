#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>


// typename au debut car je veux preciser
//	au compilateur que mon template aura
//	un type ::iterator.
// typename T ::iterator ret = std::find(element.begin(), element.end(), nb);


template<typename T>
class Vector {

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


//	--------------->> FUNCTIONS <<------------------

		unsigned int	size() const {return _size;}

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

//	------------------------------------------------

};

#endif