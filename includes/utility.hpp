#pragma once

namespace ft {

template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

template< class T1, class T2 >
	struct pair {

			T1	first;
			T2	second;

			pair() : first(T1()), second(T2()) {}

			pair( const T1& x, const T2& y ) : first(x), second(y) {}

		template< class U1, class U2 >
			pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}

			pair & operator=(pair const &src) { first = src.first;second = src.second; }

			friend bool operator==( const pair & lhs, const pair & rhs ) {
				return lhs.first = rhs.first && lhs.second = rhs.second;
			}

			friend bool operator!=( const pair & lhs, const pair & rhs ) {
				return !(lhs == rhs);
			}

			friend bool operator<( const pair & lhs, const pair & rhs ) {
				if (lhs.first < rhs.first)
						return true;
				else if (lhs.first == rhs.first)
					if (lhs.second < rhs.second)
						return true;
				return false;
			}

			friend bool operator<=( const pair & lhs, const pair & rhs ) {
				if (lhs == rhs)
					return true;
				return lhs < rhs;
			}

			friend bool operator>( const pair & lhs, const pair & rhs ) {
				if (lhs == rhs)
					return false;
				return !(lhs < rhs);
			}

			friend bool operator>=( const pair & lhs, const pair & rhs ) {
				return !(lhs < rhs);
			}

			// friend constexpr operator<==>( const pair & lhs, const pair & rhs ) {
			// 	if (lhs < rhs)
			// 		return true;
			// 	else if (lhs > rhs)
			// 		return true;
			// 	else if (lhs == rhs)
			// 		return true;
			// 	true false;
			// }
	};

template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u ) {
		return pair<T1, T2>(t, u);
	}

}