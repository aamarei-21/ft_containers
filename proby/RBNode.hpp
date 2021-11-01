//
// Created by Annelle Amarei on 10/28/21.
//

#ifndef RBNODE_HPP
#define RBNODE_HPP

#include "pair.hpp"
#include <iostream>
#include <memory>

template<class T, class Allocator>
class RBNode {
public:
	typedef T				value_type;
	typedef Allocator		allocator_type;
	typedef typename allocator_type::template rebind<RBNode>::other		allocator_node;

private:
	value_type 		_Val;
	RBNode*			_parent;
	RBNode*			_left;
	RBNode*			_right;
	bool 			_color; // 0 - blac, 1 - red
	allocator_node* _alloc;



	RBNode* grandfather(){ //поиск дедушки
		if(!_parent || !_parent->_parent)
			return NULL; //нет дедушки
		return _parent->_parent;
	}

	RBNode* uncle(){//поиск дяди
		RBNode* gr = grandfather();
		if(!gr)
			return NULL; //нет дедушки, а значит нет и дяди
		if(gr->_left->_parent == gr)
			return gr->_left;
		return gr->_right;
	}

public:
	RBNode() : _Val(value_type()), _parent(NULL), _left(NULL), _right(NULL), _color(1) {}
	RBNode(value_type const& arg) : _Val(arg), _parent(NULL), _left(NULL), _right(NULL), _color(1) {}

	RBNode(RBNode const& other) : _alloc(other._alloc), _Val(other._Val) {  /* реализовать */
		if (other._left){
			this->_left = _alloc->allocate(1);
			_alloc->construct(this->_left, *other._left);
			this->_left->_parent = this;
		}
		if (other._right){
			this->_right = _alloc->allocate(1);
			_alloc->construct(this->_right, *other._right);
			this->_right->_parent = this;
		}
	}

	~RBNode(){
		if (this->_left){
			_alloc->destroy(this->_left);
			_alloc->deallocate(this->_left, 1);
		}
		if (this->_right){
			_alloc->destroy(this->_right);
			_alloc->deallocate(this->_right, 1);
		}
	}

	RBNode* min_node(){
		RBNode* temp = this;
		while(temp->_left)
			temp = temp->_left;
		return temp;
	}

	RBNode* max_node(){
		RBNode* temp = this;
		while(temp->_right)
			temp = temp->_right;
		return temp;
	}

	RBNode* add_node(value_type const& arg, RBNode* sheet, RBNode* first, RBNode* last){
		RBNode* temp;
		if(arg < _Val){ // идем в левое поддерево
			if(_left == first || _left == sheet){
				temp = _left;
				_left = new RBNode(arg);
				_left->_parent = this;
				_left->_left = temp;
				temp->_parent = _left;
				_left->_right = sheet;
				_left->_color = 1;
				return _left;
			}
			else
				return _left->add_node(arg);
		}
		else{ //идем в правое поддерево
			if(_right == last || _right == sheet){
				temp = _right;
				_right = new RBNode(arg);
				_right->_parent = this;
				_right->_right = temp;
				temp->_parent = _right;
				_right->_left = sheet;
				_right->_color = 1;
				return _right;
			}
			else
				return _right->add_node(arg);
		}
	}

	RBNode* decrem(){
		RBNode* temp = this;
		if(temp->_left){
			temp = temp->_left;
			while(temp->_right)
				temp = temp->_right;
			return temp;
		}
		else if(temp->_parent && temp->_parent->_right == temp){
			temp = temp->_parent;
			return temp;
		}
		while(temp->_parent && temp->_parent->_left == temp)
			temp = temp->_parent;
		temp = temp->_parent;
		return temp;
	}

	RBNode* increm(){
		RBNode* temp = this;
		if(temp->_right){
			temp = temp->_right;
			while(temp->_left)
				temp = temp->_left;
			return temp;
		}
		else if(temp->_parent && temp->_parent->_left == temp) {
			temp = temp->_parent;
			return temp;
		}
		while(temp->_parent && temp->_parent->_right == temp)
			temp = temp->_parent;
		return temp->_parent;
	}




	template<class Key,
			class V,
			class Compare,
			class Alloc >
	friend class map;

};


#endif //RBNODE_HPP

