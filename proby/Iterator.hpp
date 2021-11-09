#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_


//#include <memory>
//#include"vector.hpp"
#include "Iterator_traits.hpp"
//#include "RBNode.hpp"

namespace ft {
	template<class T>
	class Randomiterator  {  //: public std::iterator<std::random_access_iterator_tag, T>
	public:
		typedef T iterator_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::value_type value_type;
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::reference reference;
//		typedef typename iterator_traits<T>:: const_reference;
		typedef std::random_access_iterator_tag iterator_category;


	private:
		iterator_type ptr;
	public:
		Randomiterator() {}

		Randomiterator(iterator_type x) :  ptr(x) {}
		template<class _T>
		Randomiterator(const Randomiterator<_T> &iter) : ptr(&(*iter)) {}

		pointer get_ptr()
		{
			return ptr;
		}

		Randomiterator &operator++() {
			++ptr;
			return *this;
		}

		Randomiterator operator++(int) {
			Randomiterator tmp(*this);
			++ptr;
			return tmp;
		}

		Randomiterator &operator--() {
			--ptr;
			return *this;
		}

		Randomiterator operator--(int) {
			Randomiterator tmp(*this);
			--(*this);
			return tmp;
		}

		Randomiterator operator+(difference_type const &x) {
			Randomiterator temp(ptr);
			return temp.ptr + x;
		}

		Randomiterator operator+=(int const &x) {
			ptr += x;
			return *this;
		}

		Randomiterator operator-(int const &x) {
			return (ptr - x);
		}

		difference_type operator-(Randomiterator const &x) { return ptr - x.ptr; }

		Randomiterator operator-=(int const &x) {
			ptr -= x;
			return *this;
		}

		reference operator*() { return *ptr; }

		const reference operator*() const { return *ptr; }

		pointer operator->() { return ptr; }

		reference operator[](difference_type n) {
			return *(ptr + n);
		}

		Randomiterator &operator=(Randomiterator const &x) {
			if (this == &x)
				return *this;
			ptr = x.ptr;
			return *this;
		}

/* ************  Non-member functions  *****************/

		friend bool operator==(Randomiterator const &larg,
				Randomiterator const &rarg) {
			return larg.ptr == rarg.ptr;
		}

		friend bool operator!=(Randomiterator const &larg,
				Randomiterator const &rarg) { return !(larg == rarg); }

		friend bool operator>(Randomiterator const &larg,
							  Randomiterator const &rarg) {
			return larg.ptr > rarg.ptr;
		}

		friend bool operator>=(Randomiterator const &larg,
				Randomiterator const &rarg) {
			return !(larg<rarg); }

		friend bool operator<(Randomiterator const &larg,
				Randomiterator const &rarg) {
			return larg.ptr<rarg.ptr;
		}

		friend bool operator<=(Randomiterator const &larg,
				Randomiterator const &rarg) {
			return !(larg > rarg); }

		friend Randomiterator
		operator+(typename Randomiterator::difference_type n,
				const Randomiterator &rev_it) {
			Randomiterator  temp(rev_it.ptr);
			return temp + n;
		}

	};

/* ********************************************************************************* */
/* **********************************  Reverse_Iterator **************************** */
/* ********************************************************************************* */


	template<class Iter>
	class Reverse_Iterator {
	public:
		typedef typename iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename iterator_traits<Iter>::value_type value_type;
		typedef typename iterator_traits<Iter>::difference_type difference_type;
		typedef typename iterator_traits<Iter>::pointer pointer;
		typedef typename iterator_traits<Iter>::reference reference;

	private:
		Iter _itr;

	public:
		Reverse_Iterator() : _itr() {}

		explicit Reverse_Iterator(const Iter &x) : _itr(x) {}

		template<class _Iter>
		Reverse_Iterator(const Reverse_Iterator<_Iter> &other) : _itr(other.base()) {}

		Iter base() const { return _itr; }

		Reverse_Iterator &operator=(const Reverse_Iterator &other) {
			if (this == &other)
				return *this;
			_itr = other._itr;
			return *this;
		}

		reference operator*() const {
			return *(this->base() - 1);
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[](difference_type n) const {
			return *(this->base() - n - 1);
		}

		Reverse_Iterator &operator++() {
			--base();
			return *this;
		}

		Reverse_Iterator operator++(int) {
			Reverse_Iterator temp(*this);
			++(*this);
			return temp;
		}

		Reverse_Iterator &operator--() {
			++base();
			return *this;
		}

		Reverse_Iterator operator--(int) {
			Reverse_Iterator temp(*this);
			--(*this);
			return temp;
		}

		Reverse_Iterator operator+(difference_type n) const {
			return Reverse_Iterator(base() - n);
		}

		Reverse_Iterator operator-(difference_type n) const {
			return Reverse_Iterator(base() + n);
		}

		Reverse_Iterator &operator+=(difference_type n) {
			_itr -= n;
			return *this;
		}

		Reverse_Iterator &operator-=(difference_type n) {
			_itr += n;
			return *this;
		}

		/* ************  Non-member functions  *****************/
		template<class Iterator>
		friend bool operator==(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<Iterator> &rhs) {
			return lhs.base() == rhs.base();
		}

		template<class Iterator>
		friend bool operator!=(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<Iterator> &rhs) {
			return lhs.base() != rhs.base();
		}

		template<class Iterator>
		friend bool operator<(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<Iterator> &rhs) {
			return lhs.base() > rhs.base();
		}

		template<class Iterator>
		friend bool operator<=(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<Iterator> &rhs) {
			return lhs.base() >= rhs.base();
		}

		template<class Iterator>
		friend bool operator>(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<Iterator> &rhs) {
			return lhs.base() < rhs.base();
		}

		template<class Iterator>
		friend bool operator>=(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<Iterator> &rhs) {
			return lhs.base() <= rhs.base();
		}

		template<class Iterator>
		friend Reverse_Iterator<Iterator> operator+(typename Reverse_Iterator<Iterator>::difference_type n,
				const Reverse_Iterator<Iterator> &rev_it) { return rev_it + n; }

		template<class Iterator>
		friend typename Reverse_Iterator<Iterator>::difference_type
		operator-(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<Iterator> &rhs) {
			return rhs.base() - lhs.base();
		}

	};

///* ******************************************************************************** */
///* **********************************  BidirecIterator **************************** */
///* ******************************************************************************** */


	template<class T, class P, class R, class A> //class  bool isConst>
	class BidirecIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	public:
		typedef P pointer;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef R reference;
		typedef const T &const_reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef RBNode<T, A> node_type;

	private:

	public:
		node_type *_ptr;

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
			--base();
			return *this;
		}

		Reverse_BiIterator operator++(int) {
			Reverse_BiIterator tmp(*this);
			++(*this);
			return tmp;
		}

		Reverse_BiIterator &operator--() {
			++base();
			return *this;
		}

		Reverse_BiIterator operator--(int) {
			Reverse_BiIterator tmp(*this);
			--(*this);
			return tmp;
		}

		reference operator*() {
			Iter temp = base();
			return --temp;
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

} //namespace ft


#endif





