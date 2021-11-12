#ifndef MAP_ITERATOR_HPP_
#define MAP_ITERATOR_HPP_

#include "Iterator_traits.hpp"

///* ******************************************************************************** */
///* **********************************  BidirecIterator **************************** */
///* ******************************************************************************** */

namespace ft {
	template<class T, class P, class R, class A> //class  bool isConst>
	class BidirecIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	public:
		typedef BidirecIterator<T, T*, T&, A> 				iterator;
		typedef BidirecIterator<T, const T*, const T&, A> 	const_iterator;
		typedef P 											pointer;
		typedef T 											value_type;
		typedef ptrdiff_t 									difference_type;
		typedef R 											reference;
		typedef const T&									const_reference;
		typedef std::bidirectional_iterator_tag 			iterator_category;
		typedef RBNode <T, A> 								node_type;

	private:
	public:
		node_type *_ptr;

		BidirecIterator() {}

		BidirecIterator(iterator const &iter) : _ptr(iter._ptr) {}

//		BidirecIterator(const_iterator const &iter) : _ptr((iter._ptr)) {}

		BidirecIterator(node_type *x) : _ptr((x)) {}

		BidirecIterator &operator=(BidirecIterator const &x) {
			if (this != &x)
				_ptr = x._ptr;
			return *this;
		}

		BidirecIterator &operator++() {
			_ptr = _ptr->increm();
			return *this;
		}

		BidirecIterator operator++(int) {
			BidirecIterator tmp(*this);
			_ptr = _ptr->increm();
			return tmp;
		}

		BidirecIterator &operator--() {
			_ptr = _ptr->decrem();
			return *this;
		}

		BidirecIterator operator--(int) {
			BidirecIterator tmp(*this);
			_ptr = _ptr->decrem();
			return tmp;
		}

		reference operator*() { return _ptr->_Val; }
		reference operator*() const { return _ptr->_Val; }

		pointer operator->() const { return &(_ptr->_Val); }

/* ************  Non-member functions  *****************/

template<class _T, class _P, class _R, class _A, class _T1, class _P1, class _R1, class _A1>
friend bool operator==(BidirecIterator<_T, _P, _R, _A> const &lhs, BidirecIterator<_T1, _P1, _R1, _A1> const &rhs) {
	return lhs._ptr == rhs._ptr;
}

template<class _T, class _P, class _R, class _A, class _T1, class _P1, class _R1, class _A1>
friend bool operator!=(BidirecIterator<_T, _P, _R, _A> const &lhs, BidirecIterator<_T1, _P1, _R1, _A1> const &rhs) {
	return !(lhs == rhs);
}


	};

	template<class Iter>
	class Reverse_BiIterator {
	public:
		typedef typename iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename iterator_traits<Iter>::value_type value_type;
		typedef typename iterator_traits<Iter>::difference_type difference_type;
		typedef typename iterator_traits<Iter>::pointer pointer;
		typedef typename iterator_traits<Iter>::reference reference;

	private:
		Iter _itr;

	public:

		Reverse_BiIterator() : _itr() {}

		explicit Reverse_BiIterator(Iter x) : _itr(x) {}

		template<class _Iter>
		Reverse_BiIterator(const Reverse_BiIterator<_Iter> &other) : _itr(other.base()) {}

		Iter base() const { return _itr; }


		Reverse_BiIterator &operator++() {
			--_itr;
			return *this;
		}

		Reverse_BiIterator operator++(int) {
			Reverse_BiIterator tmp(*this);
			++(*this);
			return tmp;
		}

		Reverse_BiIterator &operator--() {
			++_itr;
			return *this;
		}

		Reverse_BiIterator operator--(int) {
			Reverse_BiIterator tmp(*this);
			--(*this);
			return tmp;
		}

		reference operator*() const {
			Iter temp = _itr;
			return *(--temp);
		}

		pointer operator->() const { return &(operator*()); }

		/* ************  Non-member functions  *****************/

		template<class Iterator>
		friend bool operator==(Reverse_BiIterator<Iterator> const &lhs, Reverse_BiIterator<Iterator> const &rhs) {
			return lhs.base() == rhs.base();
		}

		template<class Iterator>
		friend bool operator!=(Reverse_BiIterator<Iterator> const &lhs, Reverse_BiIterator<Iterator> const &rhs) {
			return !(lhs == rhs);
		}
	};

} //namespace

#endif