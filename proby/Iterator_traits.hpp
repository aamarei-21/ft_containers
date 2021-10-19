#ifndef __ITTRAITS_HPP__
#define __ITTRAITS_HPP__

template< class _Iter >
struct iterator_traits
{
	typedef typename _Iter::difference_type		difference_type;
	typedef typename _Iter::value_type			value_type;
	typedef typename _Iter::pointer				pointer;
	typedef typename _Iter::reference			reference;
	typedef typename _Iter::iterator_category	iterator_category;
};

template<bool B, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T>
{
	typedef T  type;
};


#endif
