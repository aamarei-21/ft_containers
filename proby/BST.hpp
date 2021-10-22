#ifndef __BST_HPP__
#define __BST_HPP__

#include "Node.hpp"

template<class T>
class Node;

template<class T>
class BST
{
public:
	typedef T		value_type;
private:
	Node<T>* _root;

public:
	BST() { _root = NULL; }
	BST(value_type const& arg) : _root(new Node<value_type>(arg)) {}
	BST(BST const& arg) {}
	~BST() { delete _root; }

	void print_tree() const{
		Node<value_type>::print_node(_root);
	} //print_tree

	void add_node(value_type arg){
		if(!_root)
			_root = new Node<value_type>(arg);
		else
			this->_root->add_node(arg);
	} //add_node

	void erase(value_type const& arg){
		_root->delete_node(arg);
	}

	Node<T>* serch(value_type arg){
		return _root->serch_node(arg);
	}

};

#endif
