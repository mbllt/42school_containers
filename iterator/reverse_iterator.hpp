#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {

template<typename T>
class reverse_iterator {

	public:
		typedef T value_type;
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef std::ptrdiff_t diff_type;

	private:

		pointer p;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		reverse_iterator() : p(NULL) {}
		reverse_iterator(pointer p) : p(p) {}
		reverse_iterator(reverse_iterator const & copy) : p(copy.p) {}
		~reverse_iterator() {}

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		value_type& operator*() {return *p;}
		reverse_iterator& operator--() {++p;return *this;}
		reverse_iterator operator--(int) {reverse_iterator tmp(*this); operator++(); return tmp;}
		reverse_iterator& operator++() {++p;return *this;}
		reverse_iterator operator++(int) {reverse_iterator tmp(*this); operator++(); return tmp;}
		bool operator==(const reverse_iterator& src) const {return p==src.p;}
		bool operator!=(const reverse_iterator& src) const {return p!=src.p;}

};

}
#endif