//
// Created by Annelle Amarei on 11/7/21.
//
#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
template <class T, class Container = vector<T, std::allocator<T> >  >
class stack
{
public:
	typedef T value_type;
	typedef Container container_type;
	typedef size_t size_type;

private:
	container_type c;

public:
	explicit stack (const container_type& c = container_type()) : c(c) 	{}

	bool empty() const 	{ return c.empty(); }

	size_type size() const { return c.size(); }

	value_type& top() { return c.back(); }

	const value_type& top() const { return c.back(); }

	void push (const value_type& val) { c.push_back(val); }

	void pop() { c.pop_back(); }

	template <class T_, class Container_>
	friend bool operator== (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs);

	template <class T_, class Container_>
	friend bool operator!= (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs);

	template <class T_, class Container_>
	friend bool operator< (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs);

	template <class T_, class Container_>
	friend bool operator> (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs);

	template <class T_, class Container_>
	friend bool operator<= (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs);

	template <class T_, class Container_>
	friend bool operator>= (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs);
};

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c == rhs.c; }

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c != rhs.c; }

template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c < rhs.c; }

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c <= rhs.c; }

template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c > rhs.c; }

template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c >= rhs.c; }

} //namespace

#endif

