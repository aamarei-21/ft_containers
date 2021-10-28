//
// Created by Annelle Amarei on 10/28/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "RBNode.hpp"

template<class T, bool isConst>
class BidirecIterator;


template<class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator <pair<const Key, T> > >
class map {
public:
	typedef pair<const Key, T>							value_type;
	typedef BidirecIterator<T, T*, T&>					iterator;
	typedef BidirecIterator<T, const T*, const T&>		const_iterator;

private:
	RBNode<value_type>*		_root;
	RBNode<value_type>*		_first;
	RBNode<value_type>*		_last;
	RBNode<value_type>*		_sheet;

	void imaginary_nodes() {
		_first = new RBNode<value_type>;
		_last = new RBNode<value_type>;
		_sheet = new RBNode<value_type>;
	}

public:

/**************************** Constructor **********************************/

	map() : _root(value_type()) {
		_root->_left = _first;
		_first->_parent = _root;
		_root->_right = _last;
		_last->_parent = _root;
	}

	explicit map(const Compare& comp, const Allocator& alloc = Allocator()) : _root(value_type()) {
		_root->_left = _first;
		_first->_parent = _root;
		_root->_right = _last;
		_last->_parent = _root;
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		 const Compare& comp = Compare(),
		 const Allocator& alloc = Allocator()) {} /*необходимо реализовать*/


		 map (const map& x) {}; /*необходимо реализовать*/

/**************************** Destructor **********************************/

	~map() {
		delete _root;
		delete _first;
		delete _last;
		delete _sheet;
	}

/**************************** Iterators **********************************/

	iterator begin(){};
	const_iterator begin() const{};


};



#endif //MAP_HPP
