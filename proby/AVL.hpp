//
// Created by Annelle Amarei on 10/25/21.
//

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "AVLNode.hpp"

template <class T>
class AVL{
public:
	typedef T	value_type;

public:  //заменить на private
	AVLNode<value_type>*		_root;

public:
	AVL() {_root = NULL; }
	AVL(value_type const& arg) : _root(new AVLNode<value_type>(arg)){}
	AVL(AVL const& other) {}
	~AVL() { delete _root; }

	void print_n() const{
		int h = _root->Height(_root);
		std::cout << "h = " << h << std::endl;
		for (int i = 0; i < h; ++i) {
			AVLNode<value_type>::print_n(_root, i, 0);
			std::cout <<std::endl;
		}
	}

	void print_tree() const {
		AVLNode<value_type>::print_node(_root);
		std::cout << std::endl << "Head = " << this->_root->_Val << std::endl;
	} //print_tree

	void add_node(value_type arg){
		if(!_root)
			_root = new AVLNode<value_type>(arg);
		else{
			this->_root->add_node(arg);
			while(!this->_root->is_root())
				this->_root = this->_root->parent();
		}
	}

	void erase(value_type const& arg){
		_root->delete_node(arg);
		while(!this->_root->is_root())
			this->_root = this->_root->parent();
	}

	AVLNode<value_type>* max(){
		AVLNode<value_type> * temp = this->_root;
		while(temp->_right)
			temp = temp->_right;
		return temp;
	}

	AVLNode<value_type>* min(){
		AVLNode<value_type> * temp = this->_root;
		while(temp->_left)
			temp = temp->_left;
		return temp;
	}

};


#endif //AVLTREE_HPP
