#include "Node.hpp"


template<class T>
inline void Node<T>::delete_node(Node* temp){
//удаление листа
	if(!temp->_left && !temp->_right){
		if(temp->_parent->_left == temp)
			temp->_parent->_left = NULL;
		else if(temp->_parent->_right == temp)
			temp->_parent->_right = NULL;
		delete temp;
		return;
	}
//удаление узла, у которого только один потомок
	if(!temp->_left || !temp->_right){
		Node** temp_parent = (temp->_parent->_right == temp) ? &temp->_parent->_right : &temp->_parent->_left;
		Node** temp_son = (temp->_right) ? &temp->_right : &temp->_left;
		*temp_parent = *temp_son;
		(*temp_son)->_parent = temp->_parent;
		temp->_left = NULL;
		temp->_right = NULL;
		delete temp;
		return;
	}
	//удаление узла, у которого два потомка
	Node* tmp = temp->_right;
	while(tmp->_left)
		tmp = tmp->_left;
	swap(temp->_Val, tmp->_Val);
	//value_type ttt = temp->_Val;
	//temp->_Val = tmp->_Val;
	//tmp->_Val = ttt;
	delete_node(tmp);
} //delete_node(Node* temp)

template<class T>
inline Node<T>::Node() : _Val(T()), _parent(NULL), _left(NULL), _right(NULL) {}

template<class T>

inline Node<T>::Node(value_type const& arg) : _Val(arg), _parent(NULL), _left(NULL), _right(NULL) {}

template<class T>
inline Node<T>::Node(Node const& arg){}

template<class T>
inline Node<T>::~Node(){
	delete this->_left;
	delete this->_right;
}

template<class T>
inline Node<T>* Node<T>::serch_node(value_type const& arg) {
	Node* temp = this;
	while(arg != temp->_Val){
		if(arg < temp->_Val){
			if(!temp->_left)
				return NULL;
			temp = temp->_left;
		} else if(arg > temp->_Val){
			if(!temp->_right)
				return NULL;
			temp = temp->_right;
		}
	}
	return temp;
} //serch_node

template<class T>
inline void Node<T>::add_node(value_type const& arg){
	if (arg < this->_Val){
		if (!this->_left){
			this->_left = new Node(arg);
			this->_left->_parent = this;
		}
		else
			this->_left->add_node(arg) ;
	}
	else{
		if (!this->_right){
			this->_right = new Node(arg);
			this->_right->_parent = this;
		}
		else
			this->_right->add_node(arg);
	}
} //add_node

template<class T>
inline void Node<T>::print_node(Node const *arg){
	if (!arg)
		return;
		print_node(arg->_left);
		std::cout << arg->_Val << " ";
		print_node(arg->_right);
} //print_node

template<class T>
inline void Node<T>::delete_node(value_type const& arg){
	Node* temp = this->serch_node(arg);
	if(!temp)
		return;
	delete_node(temp);
}

template<typename U>
void swap(U& left, U& right){
	U temp;
	temp = left;
	left = right;
	right = temp;
}
