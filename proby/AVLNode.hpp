#ifndef __AVLNODE_HPP__
#define __AVLNODE_HPP__

#include <iostream>

template<class T>
class AVLNode
{
public:
	typedef T		value_type;

private:
	value_type			_Val;
	AVLNode*			_parent;
	AVLNode*			_left;
	AVLNode*			_right;
	int					_balans;

public:
	AVLNode() : _Val(T()), _parent(Null), _left(NULL), _right(NULL), _balans(0) {}
	AVLNode(value_type const& arg) : _Val(arg), _parent(NULL), _left(NULL), _right(NULL), _balans(0) {}
	~AVLNode() {
		delete this->_left;
		delete this->_right;
	}
	void add_node(value_type const& arg){
		AVLNode* temp = this;
		if(arg < temp->_Val){
			if(!temp->_left){
				temp->left = new AVLNode(arg);
				temp->_parent = temp;
				temp->_balans = 0
			}
		}
	}


};


#endif
