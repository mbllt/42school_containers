#pragma once

namespace ft {

template< class Iter >
	struct iterator_traits {

		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::std::ptrdiff_t		difference_type;
		typedef typename Iter::Iter 				value_type;
		typedef typename Iter::value_type *			pointer;
		typedef typename Iter::value_type &			reference;
	};

template< class T >
	struct iterator_traits<T*> {

		typedef std::random_access_iterator_tag		iterator_category; // i have to recode it
		typedef std::ptrdiff_t						difference_type; // maybe this one as well
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