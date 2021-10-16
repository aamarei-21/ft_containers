#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
#include <memory>
#include"Vector.hpp"
#include"Iterator_traits.hpp"

//template <class T, class Alloc>
//class My_class;

template<class T>
class Randomiterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	typedef T*								pointer;
	typedef T								value_type;
	typedef ptrdiff_t						difference_type;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;


private:
	pointer		ptr;
public:
	Randomiterator();
	Randomiterator(pointer x);
	Randomiterator(const Randomiterator& iter);
	Randomiterator& operator++();
	Randomiterator& operator++(int);
	Randomiterator& operator--();
	Randomiterator& operator--(int);
	Randomiterator operator+(size_t const& x);
	Randomiterator operator+=(int const& x);
	Randomiterator operator-(int const& x);
	difference_type operator-(Randomiterator const& x) { return ptr - x.ptr; };
	Randomiterator operator-=(int const& x);
	bool operator==(Randomiterator const& x);
	bool operator!=(Randomiterator const& x);
	bool operator>(Randomiterator const& x);
	bool operator>=(Randomiterator const& x);
	bool operator<(Randomiterator const& x);
	bool operator<=(Randomiterator const& x);
	reference operator*();
	pointer operator->();
	Randomiterator& operator=(Randomiterator const& x);

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
	reference operator[]( difference_type n ) const;
	Reverse_Iterator& operator++();
	Reverse_Iterator operator++(int);
	Reverse_Iterator& operator--();
	Reverse_Iterator operator--(int);
	Reverse_Iterator operator+(difference_type n) const;
	Reverse_Iterator operator-(difference_type n) const;
	Reverse_Iterator& operator+=(difference_type n);
	Reverse_Iterator& operator-=(difference_type n);
};



#include"Iterator.inl"

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

