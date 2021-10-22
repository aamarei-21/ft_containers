#ifndef __NODE_HPP__
#define __NODE_HPP__

#include<iostream>

template<typename U>
void swap(U& left, U& right);

template<class T>
class Node
{
public:
	typedef T		value_type;
private:
	value_type	_Val;
	Node*		_parent;
	Node*		_left;
	Node*		_right;

	void delete_node(Node* temp);

public:
	Node();
	Node(value_type const& arg);
	Node(Node const& arg);
	~Node();

	Node* serch_node(value_type const& arg);
	void add_node(value_type const& arg);
	static void print_node(Node const *arg);
	void delete_node(value_type const& arg);
	template<typename U>
	friend void swap(U& left, U& right);
};

#include "Node.cpp"

#endif
