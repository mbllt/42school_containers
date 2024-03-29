#pragma once

#include <iterator>

namespace ft {

template< class Iter >
	struct iterator_traits {

		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type 			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	};

template< class T >
	struct iterator_traits<T*> {

		typedef std::random_access_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef T 									value_type;
		typedef value_type *						pointer;
		typedef value_type &						reference;
};

template< class T >
	struct iterator_traits<T const *> {

		typedef std::random_access_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef T 									value_type;
		typedef value_type const *					const_pointer;
		typedef value_type const &					const_reference;
};

}