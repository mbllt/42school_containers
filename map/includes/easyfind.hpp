#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>

class NumberNotFoundExcpetion : public std::exception {

	private :

		std::string		_messageErr;

	public :

		NumberNotFoundExcpetion(std::string std) throw() : _messageErr(std) {};
		virtual ~NumberNotFoundExcpetion() throw() {};

		virtual const char* what() const throw() {
			return _messageErr.c_str();
		}
};

// typename au debut car je veux preciser
//	au compilateur que mon template aura
//	un type ::iterator.

template<typename T>
int	easyfind(T element, int nb) {
	typename T ::iterator ret = std::find(element.begin(), element.end(), nb);
	if (ret == element.end())
		throw NumberNotFoundExcpetion("Number was not found.");
	return nb;
}

#endif