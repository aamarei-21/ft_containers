#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_


#include <memory>
#include"Vector.hpp"
#include"Iterator_traits.hpp"

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
	Randomiterator& operator++(int);
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



