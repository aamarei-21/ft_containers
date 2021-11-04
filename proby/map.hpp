//
// Created by Annelle Amarei on 10/28/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "RBNode.hpp"
#include"Iterator_traits.hpp"
#include <iostream>

template< class T, class P, class R, class A >
class BidirecIterator;


template<class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator <pair<const Key, T > > >//  <RBNode<pair<const Key, T> >
class map {

public:
	typedef Allocator																					allocator_type;
	typedef Compare																						key_compare;
	typedef Key																							key_type;
	typedef T																							mapped_type;
	typedef pair<const Key, T>																			value_type;
	typedef RBNode<value_type, allocator_type>															node_type;
	typedef BidirecIterator<value_type, value_type*, value_type&, allocator_type>						iterator;
	typedef BidirecIterator<value_type, const value_type*, const value_type&, allocator_type>			const_iterator;
	typedef Reverse_BiIterator<iterator>																reverse_iterator;
	typedef Reverse_BiIterator<const_iterator>															const_reverse_iterator;
	typedef typename allocator_type::template rebind<node_type>::other 									allocator_node;
	typedef typename allocator_node::pointer															pointer;
//	typedef typename std::allocator<node_type>::pointer 												pointer;
	typedef typename std::allocator<node_type>::const_pointer											const_pointer;
	typedef size_t																						size_type;

	class value_compare	{
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	public:
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

private:
//	tree			_tree;
	pointer 		_root;
	pointer 		_first;
	pointer 		_last;
	pointer 		_sheet;

	allocator_node	alloc;
	key_compare 	_comp;
	size_type 		_size;

	void imaginary_nodes() {
		_first = alloc.allocate(1);
		alloc.construct(_first);
		_first->_left = _first->_right = NULL;
		_last = alloc.allocate(1);
		alloc.construct(_last);
		_last->_left = _last->_right = NULL;
		_first->_color = _last->_color = 0;
		_first->_parent = _last;
		_last->_parent = _first;
	}

	node_type* find_node(const Key& key){
		pointer temp = _root;
		while (temp->_left){
			if (key_comp()(key, temp->_Val.first))
				temp = temp->_left;
			else if (key_comp()(temp->_Val.first, key))
				temp = temp->_right;
			else
				return temp;
		}
		return temp;
	}

	void swap_node(node_type* left, node_type* right){
		node_type* temp = left;
		if (right->_parent != left){ // узлы не являются прямыми потомками и предками друг друга
			if (left->_parent){
				if (left == left->_parent->_left)
					left->_parent->_left = right;
				else
					left->_parent->_right = right;
			}
			if (right->_parent){
				if (right == right->_parent->_left)
					right->_parent->_left = left;
				else
					right->_parent->_right = left;
			}
			swap(&(left->_parent), &(right->_parent));
			left->_right->_parent = right;
			left->_left->_parent = right;
			right->_left->_parent = left;
			right->_right->_parent = left;
			swap(&(left->_right), &(right->_right));
			swap(&(left->_left), &(right->_left));
		}
		else{ // один узел потомок другого
			if (right == left->_right){
				swap(&(left->_left), &(right->_left));
				left->_left->_parent = right;
				right->_left->_parent = left;
				if (left == left->_parent->_left){
					left->_parent->_left = right;
				}
				else{
					left->_parent->_right = right;
				}
				if (left->_right == right){
					left->_right = right->_right;
					right->_right->_parent = left;
					right->_right = left;

				}
				else{
					left->_left = right->_left;
					right->_left = left;
					right->_left->_parent = left;
				}
				right->_parent = left->_parent;
				left->_parent = right;
			}
		}
		swap(left->_color, right->_color);
	}

	template<class U>
	void swap(U **left, U **right){
		U* temp = *left;
		*left = *right;
		*right = temp;
	}
	template<class U>
	void swap(U &left, U &right){
	U temp = left;
	left = right;
	right = temp;
}

	node_type* search_min(node_type* node){
		node_type* temp = node;
		while (temp->_left->_left)
			temp = temp->_left;
		return temp;
	}

	node_type* search_max(node_type* node){
		node_type* temp = node;
		while (temp->_right->_right)
			temp = temp->_right;
		return temp;
	}

public:

/**************************** Constructor **********************************/

	explicit map(const Compare& comp = key_compare(), const Allocator& alloc = Allocator()) :
			 _root(NULL), _comp(comp), alloc(alloc), _size(0) {
			imaginary_nodes();
	}

	template <class InputIterator>
		map (InputIterator first,
			 typename enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last,
			 const Compare& comp = Compare(),
			 const Allocator& alloc = Allocator()) : _comp(comp), alloc(alloc), _size(0) {
		imaginary_nodes();
		InputIterator temp_it = first;
		/*необходимо реализовать*/
	}


	map (const map& x) :  _root(NULL), _comp(x._comp), alloc(x.alloc), _size(x._size){
		if (x._root){
			_root = alloc.allocate(1);
			alloc.construct(_root, *x._root);
		}
	}

/**************************** Destructor **********************************/

	~map() {
		if (_size) {
			alloc.destroy(_root);
			alloc.deallocate(_root, 1);
		}
	}

/**************************** Iterators **********************************/

	iterator begin(){ return iterator(_first->_parent); }
	const_iterator begin() const{ return const_iterator(_first->_parent); }

	iterator end() {return iterator(_last); }
	const_iterator end() const { return const_iterator(_last); }

	reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

/**************************** Capacity **********************************/

	bool empty() const { return !size(); }

	size_type size() const { return _size; }

	size_type max_size() const { return alloc.max_size(); }

/**************************** Element access **********************************/

	mapped_type& operator[] (const key_type& k){/*надо реализовать*/
//		if(k == _root->_Val.first)
//			return _root->_Val.second;
//		if(key_comp()(k, _root->_Val.first))
//		return _root->_Val.second;
	}

/**************************** Modifiers **********************************/


	pointer make_head(const value_type& val){
		_root = alloc.allocate(1);
		alloc.construct(_root, val);
		_root->_alloc = alloc;
		_root->_left = _first;
		_root->_right = _last;
		_root->_parent = NULL;
		_first->_parent = _last->_parent = _root;
		_root->_color = 0;
		++_size;
		return _root;
	}

	pointer make_left(const value_type& val, pointer node){
		pointer ptr = alloc.allocate(1);
		alloc.construct(ptr, val);
		ptr->_alloc = alloc;
		ptr->_left = node->_left ;
		ptr->_right = alloc.allocate(1); // лист
		alloc.construct(ptr->_right);
		ptr->_right->_parent = ptr;
		ptr->_right->_color = 0;
		if (node->_left == _first)
			_first->_parent = ptr;
		node->_left = ptr;
		ptr->_parent = node;
		++_size;
		balancing(ptr);
		while (_root->_parent)
			_root = _root->_parent;
		return ptr;
	}

	pointer make_right(const value_type& val, pointer node){
		pointer ptr = alloc.allocate(1);
		alloc.construct(ptr, val);
		ptr->_alloc = alloc;
		ptr->_right = node->_right;
		ptr->_left = alloc.allocate(1); // лист
		alloc.construct(ptr->_left);
		ptr->_left->_parent = ptr;
		ptr->_left->_color = 0;
		if (node->_right == _last)
			_last->_parent = ptr;
		node->_right = ptr;
		ptr->_parent = node;
		++_size;
		balancing(ptr);
		while (_root->_parent)
			_root = _root->_parent;
		return ptr;
	}

	pair<iterator, bool> insert (const value_type& val) {
		if (_size == 0)
			return ::make_pair(iterator(make_head(val)), true);
		pointer temp = _root;
		pointer previous;
		while (temp->_left){ //пока не дойдем по последнего узла (то есть за ним следует лист)
			previous = temp;
			if (key_comp()(val.first, temp->_Val.first))
				temp = temp->_left;
			else if (key_comp()(temp->_Val.first, val.first))
				temp = temp->_right;
			else
				return (::make_pair(iterator(temp), false));

		}
		temp = previous;
		if (key_comp()(val.first, temp->_Val.first))
			return (::make_pair(iterator(make_left(val, temp)), true));
		else if (key_comp()(temp->_Val.first, val.first))
			return (::make_pair(iterator(make_right(val, temp)), true));
		else  //найдет такой же ключ как и у val
			return (::make_pair(iterator(temp), false));
	}


	iterator insert (iterator position, const value_type& val) {
		return insert(val).first;
	}


	template <class InputIterator>
	void insert (InputIterator first,
				 typename enable_if <std::__is_input_iterator<InputIterator>::value, InputIterator>::type last){
		for(; first != last; ++first)
			insert(*first);
	}

/**************************** find() **********************************/
	iterator find( const Key& key ){
		pointer temp = _root;
		while (temp->_left){
			if (key_comp()(key, temp->_left->_Val.first))
				temp = temp->_left;
			else if (key_comp()(temp->_right->_Val.first, key))
				temp = temp->_right;
			else
				return iterator(temp);
		}
		return end();
	}

const_iterator find( const Key& key ) const;

/****************************erase() **********************************/

	void delete_case1(node_type* node){
		if (node->_parent)
			delete_case2(node);
	}

	void delete_case2(node_type* node){
		node_type *br = node->brother();
		if(br->_color == RED){
			swap((node->_parent->_color), (br->_color));
			if (node == node->_parent->_left)
				LeftTurn(node->_parent);
			else
				RightTurn(node->_parent);
		}
		delete_case3(node);
	}

	void delete_case3(node_type* node){
		node_type* br = node->brother();
		if(node->_parent->_color == BLACK and br->_color == BLACK and
			br->_left->_color == BLACK and br->_right->_color == BLACK){
			br->_color = RED;
			delete_case1(node->_parent);
		}
		else
			delete_case4(node);
	}

	void delete_case4(node_type* node){
		node_type *br = node->brother();
		if (br->_color == BLACK and br->_left->_color == BLACK and
			br->_right->_color == BLACK and
			node->_parent->_color == RED){
			swap((br->_color), (node->_parent->_color));
		}
		else
			delete_case5(node);
	}

	void delete_case5(node_type* node){
		node_type *br = node->brother();
		if (br->_color == BLACK){
			if ((node == node->_parent->_left) and
			br->_right->_color == BLACK and
			br->_left->_color == RED){
				br->_color = RED;
				br->_left->_color = BLACK;
				RightTurn(br);
			}
		}
		else if ((node == node->_parent->_right) and
			br->_left->_color == BLACK and
			br->_right->_color == RED){
			br->_color = RED;
			br->_right->_color = BLACK;
			LeftTurn(br);
		}
		delete_case6(node);
	}

	void delete_case6(node_type* node){
		node_type *br = node->brother();
		br->_color = node->_parent->_color;
		node->_parent->_color = BLACK;
		if (node == node->_parent->_left) {
			br->_right->_color = BLACK;
			LeftTurn(node->_parent);
		}
		else{
			br->_left->_color = BLACK;
			RightTurn(node->_parent);
		}
	}


	void erase( iterator pos ){
		node_type* node = find_node((*pos).first);
		if (!node->_left)
			return;
		if (node->_left->_left and node->_right->_left){ // узел имеет два потомка - случай 1
			node_type * temp = search_max(node->_left);
			swap_node(node, temp);
		}
		if (node->_color == 0 and (node->_left->_left || node->_right->_left)){ //узел черный с одним потомком
			node_type* temp = (node->_left->_left) ? node->_left : node->_right;
			swap_node(node, temp);
			if (node->_color == RED)
				node->delete_node(node);
		}
		else if (node->_color == RED and !node->_left->_left and !node->_right->_left) // узел красный без потомков
			node->delete_node(node);
		else if (node->_color == BLACK and !node->_left->_left and !node->_right->_left){ // узел черный без потомков
			node = node->delete_node(node);
			while (_root->_parent)
				_root = _root->_parent;
			delete_case1(node);
		}
		--_size;
		while (_root->_parent)
			_root = _root->_parent;
	}

//	void erase( iterator first, iterator last );
	size_type erase( const Key& key ){
		iterator pos = iterator(find_node(key));
		size_type temp = _size;
		erase(pos);
		return temp - _size;
	}

	/* Удаление
	 1. Если удаляемый элемент имеет два потомка, то меняем его значение со значением ближайшим большим (или меньшим).
		Далее решаем задачу удаления элемента с 1 или 0 потомками;
	 2. Удаляемый элемент ЧЕРНЫЙ С ОДНИМ ПОТОМКОМ - (в этом случае этот потомок обязательно красный) - переносим его
		 значение в удаляемый узел и потом его (потомка) удаляем;
	 3. Удаляемый элемент КРАСНЫЙ БЕЗ ПОТОМКОВ - просто удаляем этот узел;
	 4. Удаляемый элемент ЧЕРНЫЙ БЕЗ ПОТОМКОВ - удаляем его и вызываем балансировку для родительского узла - 6 случаев:
	 4.1. N - новый корень;
	 4.2. S - красный;
	 4.3. P, S и дети S (1 и 2) - черные;
	 4.4. S и его дети — чёрные, но P — красный;
	 4.5. S черный, его левый потомок - красный, а правый потомок - черный;
	 4.6. S — чёрный, правый потомок S — красный. */




/**************************** Observers **********************************/

	key_compare key_comp() const {return key_compare(); }



	/* **************** балансировка ********************** */
	void balancing(pointer ptr){
		if (!ptr->_parent){
			ptr->_color = BLACK;
			return;
		}
		pointer P = ptr->_parent;
		if (P->_color == BLACK)
			return;
		pointer G = ptr->grandfather();
		pointer U = ptr->uncle();
		if (P->_color == RED and U->_color == RED){ //случай 3
			std::cout << "swap color\n";
			P->_color = BLACK;
			U->_color = BLACK;
			G->_color = RED;
			balancing(G);
			return;
		}
		else if (P->_color == RED and U->_color == BLACK){ //случай 4
			if (ptr == P->_right and P == G->_left){
				LeftTurn(P);
				ptr = ptr->_left;
			}
			else if (ptr == P->_left and P == G->_right){
				RightTurn(P);
				ptr = ptr->_right;
			}
		}
		P = ptr->_parent;
		G = ptr->grandfather();
		U = ptr->uncle();
		P->_color = BLACK;
		G->_color = RED;
		if (ptr == P->_left and P == G->_left)
			RightTurn(G);
		else
			LeftTurn(G);
	}

	void LeftTurn(pointer root){
		std::cout << "LeftTurn\n";
		node_type* RightSubTree = root->_right;
		node_type* RightSubTreeLeft = RightSubTree->_left;
		if(root->_parent) {
			if (root->_parent->_left == root)
				root->_parent->_left = RightSubTree;
			else
				root->_parent->_right = RightSubTree;
		}
		RightSubTree->_parent = root->_parent;
		root->_parent = RightSubTree;
		RightSubTree->_left = root;
		root->_right = RightSubTreeLeft;
		if(RightSubTreeLeft and RightSubTreeLeft->_parent)
			RightSubTreeLeft->_parent = root;
	}

	void RightTurn(pointer root){
		std::cout << "RightTurn\n";
		node_type* LeftSubTree = root->_left;
		node_type* LeftSubTreeRight = LeftSubTree->_right;
		if (root->_parent){
			if(root->_parent->_left == root)
				root->_parent->_left = LeftSubTree;
			else
				root->_parent->_right = LeftSubTree;
		}
		LeftSubTree->_parent = root->_parent;
		root->_parent = LeftSubTree;
		LeftSubTree->_right = root;
		root->_left = LeftSubTreeRight;
		if (LeftSubTreeRight and LeftSubTreeRight->_parent)
			LeftSubTreeRight->_parent = root;
	}



	/* ******************* Вспомогательные функции ****************** */
	void print_n() const{
		int h = _root->Height(_root);
		std::cout << "h = " << h << std::endl;
		for (int i = 0; i < h; ++i) {
			this->_root->print_n(_root, i, 0);
			std::cout <<std::endl;
		}
	}
	/* ******************* Вспомогательные функции ****************** */

};

#endif //MAP_HPP
