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
	AVLNode() : _Val(T()), _parent(NULL), _left(NULL), _right(NULL), _balans(0) {}
	AVLNode(value_type const& arg) : _Val(arg), _parent(NULL), _left(NULL), _right(NULL), _balans(0) {}
	~AVLNode() {
		delete this->_left;
		delete this->_right;
	} //~AVLNode

	//вычисление высоты дерева
	int	Height(){
		if(!this)
			return 0;
		int h_left = Height(this->_left);
		int	h_right = Height(this->_right);
		if(h_left > h_right)
			return h_left + 1;
		else
			return  h_right + 1;
	}

	void add_node(value_type const& arg){
		if(arg < this->_Val){
			if(!this->_left){
				this->_left = new AVLNode(arg);
				this->_left->_parent = this;
				this->_balans = 0;
			}
			else
				this->_left->add_node(arg);
		}
		else{
			if(!this->_right){
				this->_right = new AVLNode(arg);
				this->_right->_parent = this;
				this->_balans = 0;
			}
			else
				this->_left->add_node(arg);
		}
	}
};


#endif
