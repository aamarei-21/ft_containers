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
	typedef Allocator													allocator_type;
	typedef Compare														key_compare;
	typedef Key															key_type;
	typedef T															mapped_type;
	typedef pair<const Key, T>											value_type;
	typedef RBNode<value_type, allocator_type>							node_type;
	typedef BidirecIterator<value_type, value_type*, value_type&, allocator_type>									iterator;
	typedef BidirecIterator<value_type, const value_type*, const value_type&, allocator_type>						const_iterator;
	typedef Reverse_BiIterator<iterator>									reverse_iterator;
	typedef Reverse_BiIterator<const_iterator>								const_reverse_iterator;
	typedef typename allocator_type::template rebind<node_type>::other 					allocator_node;
	typedef typename allocator_node::pointer								pointer;
//	typedef typename std::allocator<node_type>::pointer 				pointer;
	typedef typename std::allocator<node_type>::const_pointer				const_pointer;
	typedef size_t															size_type;

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

	}

//	void sheet(){
//		alloc.construct(_sheet);
//		_sheet->_parent = _sheet->_left = _sheet->_right = NULL;
//		_first->_color = _last->_color = _sheet->_color = 0;
//	}
//

public:

/**************************** Constructor **********************************/

explicit map(const Compare& comp = key_compare(), const Allocator& alloc = Allocator()) :
		 _root(NULL), _comp(comp), alloc(alloc), _size(0) {
		imaginary_nodes();
//		alloc.construct(_root, value_type());
//		_root->_left = _first;
//		_first->_parent = _root;
//		_root->_right = _last;
//		_last->_parent = _root;

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
//		alloc.destroy(_first);
//		alloc.deallocate(_first, 1);
//		alloc.destroy(_last);
//		alloc.deallocate(_last, 1);
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
	_root->_alloc = &alloc;
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
	ptr->_alloc = &alloc;
	ptr->_left = node->_left ;
	ptr->_right = alloc.allocate(1);
	alloc.construct(ptr->_right);
	ptr->_right->_color = 0;
	if (node->_left == _first)
		_first->_parent = ptr;
	node->_left = ptr;
	ptr->_parent = node;
	++_size;
	return ptr;
}

pointer make_right(const value_type& val, pointer node){
	pointer ptr = alloc.allocate(1);
	alloc.construct(ptr, val);
	ptr->_alloc = &alloc;
	ptr->_right = node->_right;
	ptr->_left = alloc.allocate(1);
	alloc.construct(ptr->_left);
	ptr->_right->_color = 0;
	if (node->_right == _last)
		_last->_parent = ptr;
	node->_right = ptr;
	ptr->_parent = node;
	++_size;
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
	/* необходимо добавить балансировку */
}


iterator insert (iterator position, const value_type& val) {
	insert(val);
}


template <class InputIterator>
void insert (InputIterator first,
			 typename enable_if <std::__is_input_iterator<InputIterator>::value, InputIterator>::type last){
	for(; first != last; ++first)
		insert(*first);
}




/**************************** Observers **********************************/

	key_compare key_comp() const {return key_compare(); }



};

#endif //MAP_HPP
