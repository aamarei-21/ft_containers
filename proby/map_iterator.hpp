#ifndef MAP_ITERATOR_HPP_
#define MAP_ITERATOR_HPP_

#include "Iterator_traits.hpp"
//#include "RBNode.hpp"

///* ******************************************************************************** */
///* **********************************  BidirecIterator **************************** */
///* ******************************************************************************** */

namespace ft {
	template<class T, class P, class R, class A> //class  bool isConst>
	class BidirecIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	public:
		typedef P pointer;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef R reference;
		typedef const T &const_reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef RBNode <T, A> node_type;

	private:
		node_type *_ptr;
	public:

		BidirecIterator() {}

		BidirecIterator(BidirecIterator const &iter) : _ptr(iter._ptr) {}

		BidirecIterator(const node_type *x) : _ptr(const_cast<node_type *>(x)) {}

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

		pointer operator->() { return &(_ptr->_Val); }

/* ************  Non-member functions  *****************/

		template<class _T, class _P, class _R, class _A>
		friend bool operator==(BidirecIterator<_T, _P, _R, _A> const &lhs, BidirecIterator<_T, _P, _R, _A> const &rhs) {
			return lhs._ptr == rhs._ptr;
		}

		template<class _T, class _P, class _R, class _A>
		friend bool operator!=(BidirecIterator<_T, _P, _R, _A> const &lhs, BidirecIterator<_T, _P, _R, _A> const &rhs) {
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

		Reverse_BiIterator(const Reverse_BiIterator &other) : _itr(other._itr) {}

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

		reference operator*() {
			Iter temp = _itr;
			return *(--temp);
		}

		pointer operator->() { return &(operator*()); }

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



	/* =============const_BidirecIterator========================================== */


	template<class T, class P, class R, class A> //class  bool isConst>
	class const_BidirecIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	public:
		typedef P 									pointer;
		typedef T 									iterator_type;
		typedef ptrdiff_t 							difference_type;
		typedef R 									reference;
		typedef const T 							&const_reference;
		typedef std::bidirectional_iterator_tag 	iterator_category;
		typedef RBNode <T, A> 						node_type;

	private:
		iterator_type _ptr;
	public:

		const_BidirecIterator() {}

		const_BidirecIterator(const_BidirecIterator const &iter) : _ptr(iter._ptr) {}

		const_BidirecIterator(const node_type *x) : _ptr(const_cast<node_type *>(x)) {}

		const_BidirecIterator &operator=(const_BidirecIterator const &x) {
			if (this != &x)
				_ptr = x._ptr;
			return *this;
		}

		const_BidirecIterator &operator++() {
			++_ptr;
			return *this;
		}

		const_BidirecIterator operator++(int) {
			const_BidirecIterator tmp(*this);
			++(*this);
			return tmp;
		}

		const_BidirecIterator &operator--() {
			--_ptr;
			return *this;
		}

		const_BidirecIterator operator--(int) {
			const_BidirecIterator tmp(*this);
			--(*this);
			return tmp;
		}

		reference operator*() { return *_ptr; }

		pointer operator->() { return &(*_ptr); }

		/* ************  Non-member functions  *****************/

		template<class _T, class _P, class _R, class _A>
		friend bool operator==(const_BidirecIterator<_T, _P, _R, _A> const &lhs, const_BidirecIterator<_T, _P, _R, _A> const &rhs) {
			return lhs._ptr == rhs._ptr;
		}

		template<class _T, class _P, class _R, class _A>
		friend bool operator!=(const_BidirecIterator<_T, _P, _R, _A> const &lhs, const_BidirecIterator<_T, _P, _R, _A> const &rhs) {
			return !(lhs == rhs);
		}


	};
	/* ================================================= */
} //namespace

#endif