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
			if (key_comp()(key, temp->_left->_Val.first))
				temp = temp->_left;
			else if (key_comp()(temp->_right->_Val.first, key))
				temp = temp->_right;
			else
				return temp;
		}
		return temp;
	}

	template<class U>
	void swap(U& left, U& right){
		U temp = left;
		left = right;
		right = temp;
	}

	node_type* search_min(const node_type& node){
		node_type* temp = node;
		while (temp->_left->_left)
			temp = temp->_left;
		return temp;
	}

	node_type* search_max(const node_type& node){
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
		alloc.destroy(_root);
		alloc.deallocate(_root, 1);
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
		while (_root->_parent)
			_root = _root->_parent;
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

	void erase( iterator pos ){
		node_type* node = find_node((*pos).first);
		if (!node->_left)
			return end();
		node->erase();
	}
	void erase( iterator first, iterator last );
	size_type erase( const Key& key );

/* Удаление
 1. Если удаляемый элемент имеет два потомка, то меняем его значение со значением ближайшим большим (или меньшим).
	Далее решаем задачу удаления элемента с 1 или 0 потомками;
 2. Удаляемый элемент ЧЕРНЫЙ С ОДНИМ ПОТОМКОМ - (в этом случае этот потомок обязательно красный) - переносим его
 	значение в удаляемый узел и потом его (потомка) удаляем;
 3. Удаляемый элемент КРАСНЫЙ БЕЗ ПОТОМКОВ - просто удаляем этот узел;
 4. Удаляемый элемент ЧЕРНЫЙ БЕЗ ПОТОМКОВ - удаляем его и вызываем балансировку для родительского узла - 6 случаев:
 4.1. Родитель красный, левый ребенок черный с черными потомками;
 4.2. Родитель красный, левый ребенок черный с левым красным потомком (внуком);
 4.3. Родитель черны, левый ребенок красный, у правого внука черные правнуки;
 4.4. Родитель черный, левый ребенок красный, у правого внука левый правнук красный;
 4.5. Родитель черный, левый ребенок черный с правым красным внуком;
 4.6. Родитель черный, левый ребенок черный с черными внуками. */




/**************************** Observers **********************************/

	key_compare key_comp() const {return key_compare(); }



	/* **************** балансировка ********************** */
	void balancing(pointer ptr){
		if (!ptr->_parent){
			ptr->_color = 0;
			return;
		}
		pointer P = ptr->_parent;
		if (P->_color == 0)
			return;
		pointer G = ptr->grandfather();
		pointer U = ptr->uncle();
		if (P->_color == 1 && U->_color == 1){ //случай 3
			std::cout << "swap color\n";
			P->_color = 0;
			U->_color = 0;
			G->_color = 1;
			balancing(G);
		}
		else if (P->_color == 1 && U->_color == 0){ //случай 4
			if (P->_parent->_left == P){ // родитель P слева от своего предка (G)
				if (ptr->_parent->_right == ptr){
					LeftTurn(P); // поворот влево относительно P
				}
				P->_color = 0;
				G->_color = 1;
				RightTurn(G); // поворот вправо отностительно G
				return;
			}
			else{ // родитель P справа от своего предка (G)
				if (ptr->_parent->_left == ptr){
					RightTurn(P); // поворот вправо отностительно P
				}
				P->_color = 0;
				G->_color = 1;
				LeftTurn(G); // поворот влево относителтьно G
				return;
			}
		}
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
		if(RightSubTreeLeft && RightSubTreeLeft->_parent)
			RightSubTreeLeft->_parent = root;
	}

	void RightTurn(pointer root){
		std::cout << "LeftTurn\n";
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
		if (LeftSubTreeRight && LeftSubTreeRight->_parent)
			LeftSubTreeRight->_parent = root;
	}

};

#endif //MAP_HPP
