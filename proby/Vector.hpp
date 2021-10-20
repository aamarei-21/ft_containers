#ifndef _ALLOC_HPP_
#define _ALLOC_HPP_

#include <iostream>
#include <memory>
#include"Iterator_traits.hpp"


template<class T, bool isConst>
class Randomiterator;

template< class Iter >
class Reverse_Iterator;

template <class T, class Alloc = std::allocator<T> >
class My_class
{
public:
	typedef Randomiterator<T, false>						iterator;
	typedef Randomiterator<const T, true>					const_iterator;
	typedef Reverse_Iterator<iterator>						reverse_iterator;
	typedef Reverse_Iterator<const_iterator>				const_reverse_iterator;
	typedef size_t											size_type;
	typedef Alloc											allocator_type;
	typedef typename std::allocator<T>::reference			reference;
	typedef typename std::allocator<T>::const_reference		const_reference;
	typedef typename std::allocator<T>::pointer				pointer;
	typedef typename std::allocator<T>::const_pointer		const_pointer;

private:
	allocator_type	alloc;
	pointer			ptr;
	size_type		_size; //количество элементов в массиве (векторе)
	size_type		_capacity; //размер аллоцированной памяти
public:
/* ************  Construct My_class  *****************/
	explicit My_class(const std::allocator<T>& al = Alloc()); /*пустой конструктор (по умолчанию)*/
	explicit My_class(size_type const& size, const T& val = T(),const std::allocator<T>& al = std::allocator<T>());
	template <class InputIterator>
	My_class (InputIterator first,
			typename enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last,
			const std::allocator<T>& al = Alloc());
	My_class(const My_class& x);

/* ************  My_class destructor  *****************/
	~My_class();

/* ************  operator=  *****************/
	My_class& operator= (const My_class& x);

/* ************  assign  *****************/
	void assign( size_type count, const T& value );

	template <class InputIterator>
	void assign (InputIterator first,
			typename std::enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last);


/* ************  ITETATORS:  *****************/

/*==============  begin, end  ================*/
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

/*==============  rbegin, rend  ================*/
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	reference operator [](size_type pos);
	const_reference operator[](size_type pos) const;

	void push_back(T const& value);

/* ************  clear()  *****************/
	void clear();

/* ************  resize()  *****************/
	void resize (size_type n, T val = T());


/* ************  size()  *****************/
size_type size() const;

/* ************  capacity()  *****************/
size_type capacity() const;

/* ************  reserve()  *****************/
void reserve(size_type new_cap);

/* ************  get_allocator()  *****************/
allocator_type get_allocator() const;

/* ************  front()  *****************/
reference front();
const_reference front() const;

/* ************  back()  *****************/
reference back();
const_reference back() const;

/* ************  data()  *****************/
pointer data();
const_pointer data() const;

/* ************  at()  *****************/
reference at( size_type pos );
const_reference at( size_type pos ) const;

/* ************  empty()  *****************/
bool empty() const;


/* ************  max_size()  *****************/
size_type max_size() const;

/* ************  max_size()  *****************/
iterator insert( iterator pos, const T& value );
void insert( iterator pos, size_type count, const T& value );
template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last );

/* ************  erase()  *****************/
iterator erase(iterator pos);
iterator erase( iterator first, iterator last );

/* ************  pop_back()  *****************/
void pop_back();

/* ************  swap()  *****************/
void swap(My_class& other);



/* ************  Non-member functions  *****************/
template<class V, class Al>
friend bool operator==(const My_class<V, Al>& lhs, const My_class<V, Al>& rhs);
template<class V, class Al>
friend bool operator!=(const My_class<V, Al>& lhs, const My_class<V, Al>& );
template<class V, class Al>
friend bool operator<(const My_class<V, Al>& lhs, const My_class<V, Al>& );
template<class V, class Al>
friend bool operator<=(const My_class<V, Al>& lhs, const My_class<V, Al>& );
template<class V, class Al>
friend bool operator>(const My_class<V, Al>& lhs, const My_class<V, Al>& );
template<class V, class Al>
friend bool operator>=(const My_class<V, Al>& lhs, const My_class<V, Al>& );
template<class V, class Al>

friend void swap(My_class<V,Al>& lhs, My_class<V,Al>& rhs);
};


#include "Vector.cpp"


#endif



