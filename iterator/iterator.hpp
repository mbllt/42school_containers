#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

template<typename T>
class iterator {

	public:
		typedef T value_type;
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef std::ptrdiff_t diff_type;

	private:

		pointer p;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		iterator() : p(NULL) {}
		iterator(pointer p) : p(p) {}
		iterator(iterator const & copy) : p(copy.p) {}
		~iterator() {}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		value_type& operator*() {return *p;}
		iterator& operator++() {++p;return *this;}
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {++p;return *this;}
		iterator operator--(int) {iterator tmp(*this); operator++(); return tmp;}
		bool operator==(const iterator& src) const {return p==src.p;}
		bool operator!=(const iterator& src) const {return p!=src.p;}

};

}
#endif