#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_


#include <memory>
#include"Vector.hpp"
#include"Iterator_traits.hpp"
#include "RBNode.hpp"

template<class T, bool isConst>
class Randomiterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	typedef T*									pointer;
	typedef T									value_type;
	typedef ptrdiff_t							difference_type;
	typedef T&									reference;
	typedef const T&							const_reference;
	typedef std::random_access_iterator_tag		iterator_category;


private:
	typename conditional<isConst, const pointer, pointer>::type		ptr;
public:
	Randomiterator();
	Randomiterator(pointer x);
	Randomiterator(const Randomiterator& iter);
	Randomiterator& operator++();
	Randomiterator operator++(int);
	Randomiterator& operator--();
	Randomiterator operator--(int);
	Randomiterator operator+(difference_type const& x);
	Randomiterator operator+=(int const& x);
	Randomiterator operator-(int const& x);
	difference_type operator-(Randomiterator const& x) { return ptr - x.ptr; };
	Randomiterator operator-=(int const& x);
	typename conditional<isConst, const_reference, reference>::type operator*();
	typename conditional<isConst, const pointer, pointer>::type operator->();
	reference operator[](difference_type n);
	Randomiterator& operator=(Randomiterator const& x);

/* ************  Non-member functions  *****************/
	template<class V, class _V>
	friend bool operator==(Randomiterator<V, is_const<V>::value> const& larg,
		Randomiterator<_V, is_const<_V>::value> const&rarg);

	template<class V, class _V>
	friend bool operator!=(Randomiterator<V, is_const<V>::value> const& larg,
		Randomiterator<_V, is_const<_V>::value> const&rarg);

	template<class V, class _V>
	friend bool operator>(Randomiterator<V, is_const<V>::value> const& larg,
		Randomiterator<_V, is_const<_V>::value> const&rarg);

	template<class V, class _V>
	friend bool operator>=(Randomiterator<V, is_const<V>::value> const& larg,
		Randomiterator<_V, is_const<_V>::value> const&rarg);

	template<class V, class _V>
	friend bool operator<(Randomiterator<V, is_const<V>::value> const& larg,
		Randomiterator<_V, is_const<_V>::value> const&rarg);

	template<class V, class _V>
	friend bool operator<=(Randomiterator<V, is_const<V>::value> const& larg,
		Randomiterator<_V, is_const<_V>::value> const&rarg);

	template <class V>
	friend Randomiterator<V, is_const<V>::value>
		operator+(typename Randomiterator<V, is_const<V>::value>::difference_type n,
		const Randomiterator<V, is_const<V>::value>& rev_it);

	friend class My_class<T>;
};

/* ********************************************************************************* */
/* **********************************  Reverse_Iterator **************************** */
/* ********************************************************************************* */


template< class Iter >
class Reverse_Iterator
{
public:
	typedef typename iterator_traits<Iter>::iterator_category		iterator_category;
	typedef typename iterator_traits<Iter>::value_type				value_type;
	typedef typename iterator_traits<Iter>::difference_type			difference_type;
	typedef typename iterator_traits<Iter>::pointer					pointer;
	typedef typename iterator_traits<Iter>::reference				reference;

private:
	Iter	_itr;

public:
	Reverse_Iterator();
	explicit Reverse_Iterator(Iter x);
	Reverse_Iterator(const Reverse_Iterator& other);

	Iter base() const;
	Reverse_Iterator& operator=( const Reverse_Iterator& other );
	reference operator*() const;
	pointer operator->() const;
	reference operator[](difference_type n) const;
	Reverse_Iterator& operator++();
	Reverse_Iterator operator++(int);
	Reverse_Iterator& operator--();
	Reverse_Iterator operator--(int);
	Reverse_Iterator operator+(difference_type n) const;
	Reverse_Iterator operator-(difference_type n) const;
	Reverse_Iterator& operator+=(difference_type n);
	Reverse_Iterator& operator-=(difference_type n);

	/* ************  Non-member functions  *****************/
	template <class Iterator>
	friend bool operator==(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs);

	template <class Iterator>
	friend bool operator!=(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs);

	template <class Iterator>
	friend bool operator<(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs);

	template <class Iterator>
	friend bool operator<=(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs);

	template <class Iterator>
	friend bool operator>(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs);

	template <class Iterator>
	friend bool operator>=(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs);

	template <class Iterator>
	friend Reverse_Iterator<Iterator> operator+(typename Reverse_Iterator<Iterator>::difference_type n,
		const Reverse_Iterator<Iterator>& rev_it);

	template <class Iterator>
	friend typename Reverse_Iterator<Iterator>::difference_type
		operator-(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs);
};

/* ******************************************************************************** */
/* **********************************  BidirecIterator **************************** */
/* ******************************************************************************** */


template< class T, class P, class R, class A > //class  bool isConst>
class BidirecIterator : public  std::iterator<std::bidirectional_iterator_tag, T>
{
public:
	typedef P									pointer;
	typedef T									value_type;
	typedef ptrdiff_t							difference_type;
	typedef R									reference;
	typedef const T&							const_reference;
	typedef std::bidirectional_iterator_tag		iterator_category;
	typedef RBNode<T, A>							node_type;

private:
	node_type*			_ptr;

public:
	BidirecIterator() {}
	BidirecIterator(BidirecIterator const& iter) : _ptr(iter._ptr) {}
	BidirecIterator(const node_type* x) : _ptr(const_cast<node_type*>(x)) {}

	BidirecIterator& operator=(BidirecIterator const& x) {
		if (this != &x)
			_ptr = x._ptr;
		return *this;
	}

	BidirecIterator& operator++() { _ptr = _ptr->increm(); return *this; }
	BidirecIterator operator++(int) { BidirecIterator tmp(*this); _ptr = _ptr->increm(); return tmp; }
	BidirecIterator& operator--() { _ptr = _ptr->decrem(); return *this; }
	BidirecIterator operator--(int) { BidirecIterator tmp(*this); _ptr = _ptr->decrem(); return tmp; }
	reference operator*() { return _ptr->_Val; }
	pointer operator->() { return &(_ptr->_Val); }

/* ************  Non-member functions  *****************/

	template< class _T, class _P, class _R, class _A >
	friend bool operator==(BidirecIterator<_T, _P, _R, _A> const& lhs, BidirecIterator<_T, _P, _R, _A> const& rhs) {
		return lhs._ptr == rhs._ptr; }

		template< class _T, class _P, class _R, class _A >
	friend bool operator!=(BidirecIterator<_T, _P, _R, _A> const& lhs, BidirecIterator<_T, _P, _R, _A> const& rhs) {
		return !(lhs == rhs); }



};

template< class Iter >
class Reverse_BiIterator
{
public:
	typedef typename iterator_traits<Iter>::iterator_category		iterator_category;
	typedef typename iterator_traits<Iter>::value_type				value_type;
	typedef typename iterator_traits<Iter>::difference_type			difference_type;
	typedef typename iterator_traits<Iter>::pointer					pointer;
	typedef typename iterator_traits<Iter>::reference				reference;

private:
	Iter	_itr;

public:
	Reverse_BiIterator() : _itr() {}
	explicit Reverse_BiIterator(Iter x) : _itr(x) {}
	Reverse_BiIterator(const Reverse_BiIterator& other) : _itr(other._itr) {}

	Iter base() const { return _itr; }


	Reverse_BiIterator& operator++() { --base(); return *this; }
	Reverse_BiIterator operator++(int) { Reverse_BiIterator tmp(*this); ++(*this); return tmp; }
	Reverse_BiIterator& operator--() { ++base(); return *this; }
	Reverse_BiIterator operator--(int) { Reverse_BiIterator tmp(*this); --(*this); return tmp; }
	reference operator*() { Iter temp = base(); return --temp; }
	pointer operator->() { return &(operator*()); }

	/* ************  Non-member functions  *****************/

	template< class Iterator >
	friend bool operator==(Reverse_BiIterator<Iterator> const& lhs, Reverse_BiIterator<Iterator> const& rhs)
		{ return lhs.base() == rhs.base(); }

	template< class Iterator >
	friend bool operator!=(Reverse_BiIterator<Iterator> const& lhs, Reverse_BiIterator<Iterator> const& rhs)
		{ return !(lhs == rhs); }




};



#include"Iterator.cpp"

#endif

//template <class Category, class T, class Distance = ptrdiff_t,
//			class Pointer = T*, class Reference = T&>
//		struct iterator{
//	typedef T			value_type;
//	typedef Distance	difference_type;
//	typedef Pointer		pointer;
//	typedef Reference	reference;
//	typedef Category	iterator_category;
//};



