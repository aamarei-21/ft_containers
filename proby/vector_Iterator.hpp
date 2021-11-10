#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_


#include "Iterator_traits.hpp"


namespace ft {
	template<class T>
	class Randomiterator  {  //: public std::iterator<std::random_access_iterator_tag, T>
	public:
		typedef T iterator_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::value_type value_type;
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::reference reference;
		typedef std::random_access_iterator_tag iterator_category;


	private:
		iterator_type ptr;
	public:
		Randomiterator() {}

		Randomiterator(iterator_type x) :  ptr(x) {}
		template<class _T>
		Randomiterator(const Randomiterator<_T> &iter) : ptr(&(*iter)) {}

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

		Randomiterator operator+(difference_type const &x) const {
//			Randomiterator temp(ptr);
			return ptr + x;
		}

		Randomiterator operator+=(int const &x) {
			ptr += x;
			return *this;
		}

		Randomiterator operator-(int const &x) const {
			return (ptr - x);
		}

		template<class _T>
		difference_type operator-(Randomiterator<_T> const &x) { return ptr - &(*x); }

		template<class _T>
		difference_type operator-(Randomiterator<_T> const &x) const { return ptr - &(*x); }

		Randomiterator operator-=(int const &x) {
			ptr -= x;
			return *this;
		}

		reference operator*() { return *ptr; }

		const reference operator*() const { return *ptr; }

		pointer operator->() { return ptr; }

		reference operator[](difference_type n) const {
			return *(ptr + n);
		}

		Randomiterator &operator=(Randomiterator const &x) {
			if (this == &x)
				return *this;
			ptr = x.ptr;
			return *this;
		}

/* ************  Non-member functions  *****************/

		template<class V, class _V>
		friend bool operator==(Randomiterator<V> const &larg, Randomiterator<_V> const &rarg) {
			return larg.ptr == rarg.ptr;
		}

		template<class V, class _V>
		friend bool operator!=(Randomiterator<V> const &larg,
				Randomiterator<_V> const &rarg) { return !(larg == rarg); }

		template<class V, class _V>
		friend bool operator>(Randomiterator<V> const &larg, Randomiterator<_V> const &rarg) {
			return larg.ptr > rarg.ptr;
		}

		template<class V, class _V>
		friend bool operator>=(Randomiterator<V> const &larg, Randomiterator<_V> const &rarg) {
			return !(larg<rarg); }

		template<class V, class _V>
		friend bool operator<(Randomiterator<V> const &larg, Randomiterator<_V> const &rarg) {
			return larg.ptr<rarg.ptr;
		}

		template<class V, class _V>
		friend bool operator<=(Randomiterator<V> const &larg, Randomiterator<_V> const &rarg) {
			return !(larg > rarg); }

		template<class _V>
		friend Randomiterator operator+(difference_type n, const Randomiterator<_V> &rev_it) {
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
			return *(_itr - 1);
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[](difference_type n) const {
			return *(_itr - n - 1);
		}

		Reverse_Iterator &operator++() {
			--_itr;
			return *this;
		}

		Reverse_Iterator operator++(int) {
			Reverse_Iterator temp(*this);
			++(*this);
			return temp;
		}

		Reverse_Iterator &operator--() {
			++_itr;
			return *this;
		}

		Reverse_Iterator operator--(int) {
			Reverse_Iterator temp(*this);
			--(*this);
			return temp;
		}

		Reverse_Iterator operator+(difference_type n) const {
			return Reverse_Iterator(_itr - n);
		}

		Reverse_Iterator operator-(difference_type n) const {
			return Reverse_Iterator(_itr + n);
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
		template<class Iterator, class _Iterator>
		friend bool operator==(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<_Iterator> &rhs) {
			return lhs._itr == rhs._itr;
		}

		template<class Iterator, class _Iterator>
		friend bool operator!=(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<_Iterator> &rhs) {
			return lhs._itr != rhs._itr;
		}

		template<class Iterator, class _Iterator>
		friend bool operator<(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<_Iterator> &rhs) {
			return lhs._itr > rhs._itr;
		}

		template<class Iterator, class _Iterator>
		friend bool operator<=(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<_Iterator> &rhs) {
			return lhs._itr >= rhs._itr;
		}

		template<class Iterator, class _Iterator>
		friend bool operator>(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<_Iterator> &rhs) {
			return lhs._itr < rhs._itr;
		}

		template<class Iterator, class _Iterator>
		friend bool operator>=(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<_Iterator> &rhs) {
			return lhs._itr <= rhs._itr;
		}

		template<class _Iterator>
		friend Reverse_Iterator operator+(difference_type n,
				const Reverse_Iterator<_Iterator> &rev_it) { return rev_it + n; }

		template<class Iterator, class _Iterator>
		friend typename Reverse_Iterator<Iterator>::difference_type
		operator-(const Reverse_Iterator<Iterator> &lhs, const Reverse_Iterator<_Iterator> &rhs) {
			return rhs._itr - lhs._itr;
		}

	};

} //namespace ft


#endif





