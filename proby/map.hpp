//
// Created by Annelle Amarei on 10/28/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "RBNode.hpp"
#include"Iterator_traits.hpp"
#include <iostream>

template< class T, class P, class R >
class BidirecIterator;


template<class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator <RBNode<pair<const Key, T> > > >//  <RBNode<pair<const Key, T> >
class map {

public:
	typedef Allocator													allocator_type;
	typedef Compare														key_compare;
	typedef RBNode<pair<const Key, T> >									node_type;
	typedef Key															key_type;
	typedef T															mapped_type;
	typedef pair<const Key, T>											value_type;
	typedef BidirecIterator<T, T*, T&>									iterator;
	typedef BidirecIterator<T, const T*, const T&>						const_iterator;
	typedef Reverse_BiIterator<iterator>								reverse_iterator;
	typedef Reverse_BiIterator<const_iterator>							const_reverse_iterator;
	typedef typename std::allocator<node_type>::pointer 				pointer;
	typedef typename std::allocator<node_type>::const_pointer			const_pointer;
	typedef size_t														size_type;

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
	pointer 		_root;
	pointer 		_first;
	pointer 		_last;
	pointer 		_sheet;

	allocator_type	alloc;
	key_compare 	_comp;
	size_type 		_size;

	void imaginary_nodes() {
		_root = alloc.allocate(1);
		_first = alloc.allocate(1);
		_last = alloc.allocate(1);
		_sheet = alloc.allocate(1);
	}

public:

/**************************** Constructor **********************************/

explicit map(const Compare& comp = key_compare(), const Allocator& alloc = Allocator()) :
			_comp(comp), alloc(alloc), _size(0) {
		imaginary_nodes();
//		alloc.construct(_root, value_type());
		_root->_left = _first;
		_first->_parent = _root;
		_root->_right = _last;
		_last->_parent = _root;
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


		 map (const map& x) {}; /*необходимо реализовать*/

/**************************** Destructor **********************************/

	~map() {
		delete _root;
		delete _first;
		delete _last;
		delete _sheet;
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


pointer make_head(value_type& val){
	pointer ptr = alloc.allocate(1);
	alloc.construct(ptr, val);
	ptr->_left = _first;
	ptr->_right = _last;
	ptr->_parent = NULL;
	_first->_parent = _last->_parent = ptr;
	++_size;
	return ptr;
}

pointer make_left(value_type& val, pointer node){
	pointer ptr = alloc.allocate(1);
	alloc.construct(ptr, val);
	ptr->_left = node->_left ;
	ptr->_right = _sheet;
	if (node->_left == _first)
		_first = ptr;
	node->_left = ptr;
	ptr->_parent = node;
	++_size;
	return ptr;
}

pointer make_right(value_type& val, pointer node){
	pointer ptr = alloc.allocate(1);
	alloc.construct(ptr, val);
	ptr->_right = node->_right;
	ptr->_left = _sheet;
	if (node->_left == _last)
		_last = ptr;
	node->_right = ptr;
	ptr->_parent = node;
	++_size;
	return ptr;
}

pair<iterator, bool> insert (const value_type& val) {
	if (_size == 0)
		return make_pair(make_head((value_type &)val), true);
	pointer temp = _root;
	while (temp->_left->_left){ //пока не дойдем по последнего узла (то есть за ним следует лист)
		if (key_comp()(val.first, temp->_Val.first))
			temp = temp->_left;
		else if (key_comp()(temp->_Val.first, val.first))
			temp = temp->_left;
		else  //найдет такой же ключ как и у val
		return (make_pair(temp, false));
	}
	if (temp->_parent->_left == temp)
		return (make_pair(make_left(val, temp), true));
	else
		return (make_pair(make_right(val, temp), true));
}


//iterator insert (iterator position, const value_type& val) {}
//
//template <class InputIterator>
//void insert (InputIterator first, InputIterator last){}




/**************************** Observers **********************************/

	key_compare key_comp() const {return key_compare(); }



};

#endif //MAP_HPP
