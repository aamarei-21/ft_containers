#ifndef __AVLNODE_HPP__
#define __AVLNODE_HPP__

#include <iostream>
#include <cmath>

template<typename U>
void swap(U& left, U& right);

template<class T>
class AVLNode
{
public:
	typedef T		value_type;

public: //заменить на приват
	value_type			_Val;
	AVLNode*			_parent;
	AVLNode*			_left;
	AVLNode*			_right;
	int					_balans; //разность высоты правого поддерева и левого поддерева

	void delete_node(AVLNode* root){
		AVLNode* temp = root->_parent;
	//удаление листа
		if(!root->_left && !root->_right){
			if(root->_parent && root->_parent->_left == root)
				root->_parent->_left = NULL;
			else if(root->_parent && root->_parent->_right == root)
				root->_parent->_right = NULL;
			delete root;
		}
	//удаление узла у которого один потомок
		else if(!root->_left || !root->_right){
			AVLNode** temp_parent = (root->_parent->_right == root) ? &root->_parent->_right : &root->_parent->_left;
			AVLNode** temp_son = (root->_right) ? &root->_right : &root->_left;
			*temp_parent = *temp_son;
			(*temp_son)->_parent = root->_parent;
			root->_left = NULL;
			root->_right = NULL;
			delete root;
		}
	//удаление узла у которго два потомка
		else {
			AVLNode *tmp = root->_left;
			while (tmp->_right)
				tmp = tmp->_right;
			swap(root->_Val, tmp->_Val);
			delete_node(tmp);
		}
		int H_left;
		int H_right;
		while(temp){
			H_left = Height(temp->_left);
			H_right = Height(temp->_right);
			if (std::abs(H_left - H_right) > 1){
				if(H_left > H_right){//левое поддерево больше
					if(Height(temp->_left->_left) > Height(temp->_left->_right)) //BigRightTurn(temp);
						LeftTurn(temp->_left);
					RightTurn(temp);
				}
				else{//правое поддерево больше
					if(Height(temp->_right->_right) < Height(temp->_right->_left)) //BigLeftTurn(temp);
						RightTurn(temp->_right);
					LeftTurn(temp);
				}
				return;
			}
			temp = temp->_parent;
		}
	}

public:
	AVLNode() : _Val(T()), _parent(NULL), _left(NULL), _right(NULL), _balans(0) {}
	AVLNode(value_type const& arg) : _Val(arg), _parent(NULL), _left(NULL), _right(NULL), _balans(0) {}
	// нужно добавить конструктор копирования
	~AVLNode() {
		delete this->_left;
		delete this->_right;
	} //~AVLNode

	static void print_n(AVLNode const* root, int n, int level){
		if(root){
			if(n == level)
				std::cout << root->_Val << " ";
			else{
				print_n(root->_left, n, level + 1);
				print_n(root->_right, n, level + 1);
			}
		}
	}

	AVLNode* serch_node(value_type const& arg){
		AVLNode* temp = this;
		while (arg != temp->_Val){
			if(arg < temp->_Val){
				if(!temp->_left)
					return NULL;
				temp = temp->_left;
			}
			else{
				if(!temp->_right)
					return NULL;
				temp = temp->_right;
			}
		}
		return temp;
	}

	void delete_node(value_type const& arg){
		AVLNode* temp = this->serch_node(arg);
		if(!temp)
			return;
		delete_node(temp);
	}

	static void print_node(AVLNode const *arg){
		if(!arg)
			return;
		print_node(arg->_left);
		std::cout << arg->_Val << " ";
		print_node(arg->_right);
	} //print_node

	//вычисление высоты дерева
	int	Height(AVLNode<value_type> *arg ){
		if(!arg)
			return 0;
		int h_left = Height(arg->_left);
		int	h_right = Height(arg->_right);
		if(h_left > h_right)
			return h_left + 1;
		else
			return  h_right + 1;
	}

	//вычисление баланса узла
	void SetBalance(){

	}

//левый поворот
	void LeftTurn(AVLNode<value_type>* root){
		AVLNode *RightSubTree, *RightSubTreeLeft;
		RightSubTree = (root)->_right;
		RightSubTreeLeft = RightSubTree->_left;

		if (root->_parent){
			if(root->_parent->_right == root)
				root->_parent->_right = RightSubTree;
			else
				root->_parent->_left = RightSubTree;
		}
		RightSubTree->_parent = (root)->_parent;
		RightSubTree->_left = root;

		(root)->_right = RightSubTreeLeft;
		(root)->_parent = RightSubTree;
		if(RightSubTreeLeft)
			RightSubTreeLeft->_parent = root;
//		root = RightSubTree;
	} //LeftTurn()

//правый поворот
	void RightTurn(AVLNode<value_type >*root){
		AVLNode  *LeftSubTree, *LeftSubTreeRight;
		LeftSubTree = (root)->_left;
		LeftSubTreeRight = LeftSubTree->_right;

		if (root->_parent){
			if (root->_parent->_left == root)
				root->_parent->_left = LeftSubTree;
			else
				root->_parent->_right = LeftSubTree;
		}
		LeftSubTree->_parent = (root)->_parent;
		LeftSubTree->_right = root;

		(root)->_left = LeftSubTreeRight;
		(root)->_parent = LeftSubTree;
		if(LeftSubTreeRight)
			LeftSubTreeRight->_parent = root;
	}
//большой правый поворот - не используется
//	void BigRightTurn(AVLNode* root){
//		AVLNode *LeftSubTree, *LeftSubTreeRight, *LeftSubTreeRight_left, *LeftSubTreeRight_right;
//
//		LeftSubTree = root->_left;
//		LeftSubTreeRight = LeftSubTree->_right;
//		LeftSubTreeRight_left = LeftSubTreeRight->_left;
//		LeftSubTreeRight_right = LeftSubTreeRight->_right;
//
//		if(root->_parent) {
//			if (root->_parent->_left == root)
//				root->_parent->_left = LeftSubTreeRight;
//			else
//				root->_parent->_right = LeftSubTreeRight;
//		}
//		LeftSubTreeRight->_parent = root->_parent;
//		LeftSubTreeRight->_right = root;
//		root->_parent = LeftSubTreeRight;
//		root->_left = LeftSubTreeRight_right;
//		if(LeftSubTreeRight_right)
//			LeftSubTreeRight_right->_parent = root;
//		LeftSubTreeRight->_left = LeftSubTree;
//		LeftSubTree->_parent = LeftSubTreeRight;
//		LeftSubTree->_right = LeftSubTreeRight_left;
//		if(LeftSubTreeRight_left)
//			LeftSubTreeRight_left->_parent = LeftSubTree;
//	}//BigRightTurn

//большой левый поворот  - не используется
//	void BigLeftTurn(AVLNode* root){
//		AVLNode *RightSubTree, *RightSubTreeLeft, *RightSubTreeLeft_left, *RightSubTreeLeft_right;
//
//		RightSubTree = root->_right;
//		RightSubTreeLeft = RightSubTree->_left;
//		RightSubTreeLeft_left = RightSubTreeLeft->_left;
//		RightSubTreeLeft_right = RightSubTreeLeft->_right;
//
//		if(root->_parent){
//			if(root->_parent->_left == root)
//				root->_parent->_left = RightSubTreeLeft;
//			else
//				root->_parent->_right = RightSubTreeLeft;
//		}
//		RightSubTreeLeft->_parent = root->_parent;
//		RightSubTreeLeft->_right = RightSubTree;
//		RightSubTree->_parent = RightSubTreeLeft;
//		RightSubTree->_left = RightSubTreeLeft_right;
//		if(RightSubTreeLeft_right)
//			RightSubTreeLeft_right->_parent = RightSubTree;
//		RightSubTreeLeft->_left = root;
//		root->_parent = RightSubTreeLeft;
//		root->_right = RightSubTreeLeft_left;
//		if(RightSubTreeLeft_left)
//			RightSubTreeLeft_left->_parent = root;
//	}//BigLeftTurn

//добавление узла
	void add_node(value_type const& arg){
		if(arg < (this)->_Val){ //идем в левое поддерево
			if(!(this)->_left){
				(this)->_left = new AVLNode(arg);
				(this)->_left->_parent = (this);
				(this)->_left->_balans = 0;
			}
			else{
				this->_left->add_node(arg);
				if (Height((this)->_left) - Height((this)->_right) > 1){
					std::cout<< (this)->_Val<< "   " << Height((this)->_left) - Height((this)->_right) << std::endl;
					std::cout << "Balans is error - ";
					if(Height((this)->_left->_left) < Height((this)->_left->_right)){
						std::cout << "Bif right Turn\n";
//						BigRightTurn(this);
						LeftTurn(this->_left);
						RightTurn((this));
					}
					else{
						std::cout << "Right Turn\n";
						RightTurn((this));
					}
				}
			}
		}
		else{ //идем в правое поддерево
			if(!(this)->_right){
				(this)->_right = new AVLNode(arg);
				(this)->_right->_parent = (this);
				(this)->_right->_balans = 0;
			}
			else{
				this->_right->add_node(arg);
				if(Height((this)->_right) - Height((this)->_left) > 1){
					std::cout << (this)->_Val<< "   " << Height((this)->_right) - Height((this)->_left) << std::endl;
					std::cout << "Balans is error - ";
					if (Height((this)->_right->_right) < Height((this)->_right->_left)){
						std::cout << "Big left Turn\n";
//						BigLeftTurn(this);
						RightTurn(this->_right);
						LeftTurn(this);
					}
					else{
						std::cout << "Left Turn\n";
						LeftTurn((this));
					}
				}
			}
		}
	}

	AVLNode* min_node(){
		AVLNode* temp = this;
		while(temp->_left)
			temp = temp->_left;
		return temp;
	}

	AVLNode* max_node(){
		AVLNode* temp = this;
		while(temp->_right)
			temp = temp->_right;
		return temp;
	}

	AVLNode* increm(){
		AVLNode* temp = this;
		if(temp->_right)
			return temp->_right->min_node();
		else if(temp->_parent && temp->_parent->_left == temp)
			return temp->_parent;
		else if(temp->_parent && temp->_parent->_right == temp){
			while(temp->_parent && temp->_parent->_right == temp)
				temp = temp->_parent;
			}
		return temp->_parent;
	}

	AVLNode* decrem(){
		AVLNode* temp = this;
		if(temp->_left)
			return temp->_left->max_node();
		else if(temp->_parent && temp->_parent->_right == temp)
			return temp->_parent;
		else if(temp->_parent && temp->_parent->_left == temp){
			while(temp->_parent && temp->_parent->_left == temp)
				temp = temp->_parent;
			}
		return temp->_parent;
	}

	bool is_root(){
		return _parent == NULL;
	}

	AVLNode* parent(){
		return _parent;
	}

	template<typename U>
	friend void swap(U& left, U& right);
};

template<typename U>
void swap(U& left, U& right){
	U temp;
	temp = left;
	left = right;
	right = temp;
}

#endif
