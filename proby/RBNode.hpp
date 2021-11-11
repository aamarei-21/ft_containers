//
// Created by Annelle Amarei on 10/28/21.
//

#ifndef RBNODE_HPP
#define RBNODE_HPP

#include "pair.hpp"
#include <iostream>
#include <memory>

enum {BLACK, RED};

template<class T, class Allocator>
class RBNode {
private:
public:
	typedef T				value_type;
	typedef Allocator		allocator_type;
	typedef typename allocator_type::template rebind<RBNode>::other		allocator_node;

	value_type 		_Val;
	RBNode*			_parent;
	RBNode*			_left;
	RBNode*			_right;
	bool 			_color; // 0 - black, 1 - red
	allocator_node alloc;



	RBNode* grandfather(){ //поиск дедушки
		if(!_parent || !_parent->_parent)
			return NULL; //нет дедушки
		return _parent->_parent;
	}

	RBNode* uncle(){//поиск дяди
		RBNode* gr = grandfather();
		if(!gr)
			return NULL; //нет дедушки, а значит нет и дяди
		if(gr->_left == _parent)
			return gr->_right;
		return gr->_left;
	}

	RBNode* brother(){
		RBNode* br = NULL;
		if (_parent)
			br = (this->_parent->_left == this) ? _parent->_right : _parent->_left;
		return br;
	}

	RBNode* search_min(const RBNode& node){
		RBNode* temp = node;
		while (temp->_left->_left)
			temp = temp->_left;
		return temp;
	}

	RBNode* search_max(const RBNode& node){
		RBNode* temp = node;
		while (temp->_right->_right)
			temp = temp->_right;
		return temp;
	}

	template<class U>
			void swap(U& left, U& right){
		U temp = left;
		left = right;
		right = temp;
	}

public:
	RBNode() : _Val(value_type()), _parent(NULL), _left(NULL), _right(NULL), _color(1), alloc() {}
	RBNode(value_type const& arg) : _Val(arg), _parent(NULL), _left(NULL), _right(NULL), _color(1), alloc() {}

	RBNode(RBNode const& other) : _Val(other._Val), _parent(NULL), _left(NULL), _right(NULL), _color(other._color), alloc() {
		if (other._left){
			this->_left = alloc.allocate(1);
			alloc.construct(this->_left, *other._left);
			if (other._left->_parent)
				this->_left->_parent = this;
		}
		if (other._right){
			this->_right = alloc.allocate(1);
			alloc.construct(this->_right, *other._right);
			if (other._right->_parent)
				this->_right->_parent = this;
		}
	}

	~RBNode(){
		if (this->_left){
			alloc.destroy(this->_left);
			alloc.deallocate(this->_left, 1);
		}
		if (this->_right){
			alloc.destroy(this->_right);
			alloc.deallocate(this->_right, 1);
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
		if(temp->_left and temp->_left->_parent){
			temp = temp->_left;
			while(temp->_right and temp->_right->_left)
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
		if(temp->_right and temp->_right->_parent){
			temp = temp->_right;
			while(temp->_left and temp->_left->_left)
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

	RBNode *delete_node(RBNode *node){
		RBNode* parent = node->_parent;
		if (parent){
			if(parent->_left == node) {
				if(!node->_right->_left) {
					parent->_left = node->_left;
					if (node->_left->_parent)
						node->_left->_parent = parent;
					node->_left = NULL;
				} else{
					parent->_left = node->_right;
					if (node->_right->_parent)
						node->_right->_parent = parent;
					node->_right = NULL;
				}
//				parent = parent->_left;
			} else { // parent->_right == node
				if (!node->_right->_left) {
					parent->_right = node->_right;
					if (node->_right->_parent)
						node->_right->_parent = parent;
					node->_right = NULL;
				} else {
					parent->_right = node->_left;
					if (node->_left->_parent)
						node->_left->_parent = parent;
					node->_left = NULL;
				}
//				parent = parent->_right;
			}
		}
		else{
			node->_left->_parent = node->_right; // _first указывает на _last
			node->_right->_parent = NULL; // _last указывает на NULL
			node->_left = NULL;
			node->_right = NULL;
		}
		alloc.destroy(node);
		alloc.deallocate(node, 1);
		return parent;
	}



	RBNode* erase(){
		RBNode* node = this;


	}




	/* ******************* Вспомогательные функции ****************** */

	int	Height(RBNode *arg ){
		if(!arg)
			return 0;
		int h_left = Height(arg->_left);
		int	h_right = Height(arg->_right);
		if(h_left > h_right)
			return h_left + 1;
		else
			return  h_right + 1;
	}

	void print_n(RBNode const* root, int n, int level){
		if(root){
			if(n == level && root->_left) {
				std::cout << root->_Val.first;
				std::cout << (root->_color == RED ? 'r' : 'b') << ' ';
			}
			else{
				print_n(root->_left, n, level + 1);
				print_n(root->_right, n, level + 1);
			}
		}
	}

	/* ******************* Вспомогательные функции ****************** */

//	template<class Key,
//			class V,
//			class Compare,
//			class Alloc >
//	friend class map;

};


#endif //RBNODE_HPP

