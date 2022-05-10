// Equivalent a #ifndef #define #endif
// C'est pour eviter les doubles inclusions
#pragma once

#define IS_INTEGRAL(TYPE)      \
	template <>                \
	struct is_integral<TYPE> { \
		enum { value = true }; \
	}

namespace ft {
	template <typename A, typename B>
	struct is_same {
		enum { value = false };
	};

	template <typename T>
	struct is_same<T, T> {
		enum { value = true };
	};

	template <typename T>
	struct is_integral {
		enum { value = false };
	};

	IS_INTEGRAL(bool);
	IS_INTEGRAL(char);
	IS_INTEGRAL(char16_t);
	IS_INTEGRAL(char32_t);
	IS_INTEGRAL(wchar_t);
	IS_INTEGRAL(short);
	IS_INTEGRAL(int);
	IS_INTEGRAL(long);
	IS_INTEGRAL(long long);

	template <bool cond, typename T>		// declaration de ma structure
	struct enable_if;

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <typename T>
	struct enable_if<false, T> {		// compile time : no error if tries to
	};									// read a type that is not there
}

#undef IS_INTEGRAL