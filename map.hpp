#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "RBNode.hpp"
#include "map_iterator.hpp"
#include <memory>
#include <functional>

namespace ft {

	template<class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<pair<const Key, T> > >
	class map {

	public:
		typedef Key 																						key_type;
		typedef T 																							mapped_type;
		typedef pair<const Key, T> 																			value_type;
		typedef Compare 																					key_compare;
		typedef Allocator 																					allocator_type;
		typedef value_type&																					reference;
		typedef const value_type&																			const_reference;
		typedef typename allocator_type::pointer															pointer;
		typedef typename allocator_type::const_pointer														const_pointer;
		typedef BidirecIterator<value_type, value_type *, value_type &, allocator_type> 					iterator;
		typedef Reverse_BiIterator <iterator> 																reverse_iterator;
		typedef BidirecIterator<value_type, const value_type *, const value_type &, allocator_type> 		const_iterator;
		typedef Reverse_BiIterator <const_iterator> 														const_reverse_iterator;
		typedef size_t 																						size_type;
	private:
		typedef RBNode<value_type, allocator_type> 															node_type;
		typedef typename allocator_type::template rebind<node_type>::other 									allocator_node;
		typedef typename allocator_node::pointer 															node_pointer;
	public:

		class value_compare {
			friend class map;
		protected:
			Compare comp;
			explicit value_compare(Compare c) : comp(c) {}
		public:
			bool operator()(const value_type &x, const value_type &y) const {
				return comp(x.first, y.first);
			}
		};

	private:
		node_pointer _root;
		node_pointer _first;
		node_pointer _last;

		allocator_node alloc;
		key_compare _comp;
		size_type _size;

	public:

/**************************** Constructor **********************************/

		explicit map(const Compare &comp = key_compare(), const Allocator &alloc = Allocator()) :
		_root(NULL), _first(NULL), _last(NULL), alloc(alloc), _comp(comp), _size(0) {
			imaginary_nodes();
		}

		template<class InputIterator>
		map(InputIterator first,
			typename enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last,
			const Compare &comp = Compare(),
			const Allocator &alloc = Allocator()) :
			_root(NULL), alloc(alloc), _comp(comp), _size(0) {
			imaginary_nodes();
			for (; first != last; ++first)
				insert(*first);
		}

		map(const map &x) : _root(NULL), _first(NULL), _last(NULL), alloc(x.alloc), _comp(x._comp), _size(x._size) {
			if (x._root) {
				_root = alloc.allocate(1);
				alloc.construct(_root, *x._root);
				node_pointer temp = _root;
				while (temp->_left)
					temp = temp->_left;
				_first = temp;
				temp = _root;
				while (temp->_right)
					temp = temp->_right;
				_last = temp;
			} else
				imaginary_nodes();
		}

/**************************** Destructor **********************************/

		~map() {
			if (_size) {
				alloc.destroy(_root);
				alloc.deallocate(_root, 1);
			} else {
				_last->_left = NULL;
				_last->_right = NULL;
				_first->_left = NULL;
				_first->_right = NULL;
				alloc.destroy(_first);
				alloc.destroy(_last);
				alloc.deallocate(_first, 1);
				alloc.deallocate(_last, 1);
				_last = NULL;
				_first = NULL;
			}
		}

/**************************** operator= **********************************/

		map &operator=(const map &x) {
			if (this == &x)
				return *this;
			if (_root) {
				alloc.destroy(_root);
				alloc.deallocate(_root, 1);
			}
			_root = NULL;
			if (x._root) {
				_root = alloc.allocate(1);
				alloc.construct(_root, *x._root);
				_size = x._size;
				node_pointer temp = _root;
				while (temp->_left)
					temp = temp->_left;
				_first = temp;
				temp = _root;
				while (temp->_right)
					temp = temp->_right;
				_last = temp;
			} else
				imaginary_nodes();
			return *this;
		}

/**************************** Iterators **********************************/

		iterator begin() { return iterator(_first->_parent); }

		const_iterator begin() const { return const_iterator(_first->_parent); }

		iterator end() { return iterator(_last); }

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

		mapped_type& at( const Key& key ){
			node_type *node = find_node(key);
			if (!node)
				throw std::out_of_range("map");
			return (node->_Val.second);
		}

		const mapped_type& at( const Key& key ) const{
			node_type *node = find_node(key);
			if (!node)
				throw std::out_of_range("map");
			return (node->_Val.second);
		}

		mapped_type &operator[](const key_type &k) {
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

/**************************** insert () **********************************/


		pair<iterator, bool> insert(const value_type &val) {
			if (_size == 0)
				return ft::make_pair(iterator(make_head(val)), true);
			node_pointer temp = _root;
			node_pointer previous;
			while (temp->_left) { //пока не дойдем по последнего узла (то есть за ним следует лист)
				previous = temp;
				if (key_comp()(val.first, temp->_Val.first))
					temp = temp->_left;
				else if (key_comp()(temp->_Val.first, val.first))
					temp = temp->_right;
				else
					return (ft::make_pair(iterator(temp), false));

			}
			temp = previous;
			if (key_comp()(val.first, temp->_Val.first))
				return (ft::make_pair(iterator(make_left(val, temp)), true));
			else if (key_comp()(temp->_Val.first, val.first))
				return (ft::make_pair(iterator(make_right(val, temp)), true));
			else  //найден такой же ключ как и у val
				return (ft::make_pair(iterator(temp), false));
		}

		iterator insert(iterator position, const value_type &val) {
			(void) position;
			return insert(val).first;
		}

		template<class InputIterator>
		void insert(InputIterator first,
					typename enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last) {
			for (; first != last; ++first)
				insert(*first);
		}

/****************************erase() **********************************/

		void erase(iterator pos) {
			erase(pos->first);
		}

		void erase(iterator first, iterator last) {
			iterator next = first;
			while (first != last) {
				++next;
				erase(first);
				first = next;
			}
		}

		size_type erase(const Key &key) {
			node_type *node = find_node(key);
			if (!node or !node->_left)
				return 0;
			if (node->_left->_left and node->_right->_left) { // узел имеет два потомка - случай 1
				node_type *temp = search_max(node->_left);
				swap_node(node, temp);
			}
			if (node->_color == BLACK and (node->_left->_left || node->_right->_left)) { //узел черный с одним потомком
				node_type *temp = (node->_left->_left) ? node->_left : node->_right;
				swap_node(node, temp);
				if (node->_color == RED)
					node = node->delete_node(node);
			} else if (node->_color == RED and !node->_left->_left and
					   !node->_right->_left) // узел красный без потомков
				node = node->delete_node(node);
			else if (node->_color == BLACK and !node->_left->_left and
					 !node->_right->_left) { // узел черный без потомков
				delete_case1(node);
				node = node->delete_node(node);
			}
			--_size;
			while (_root and _root->_parent)
				_root = _root->_parent;
			return 1;
		}

/**************************** swap () **********************************/

		void swap(map &x) {
			node_type *temp = this->_root;
			this->_root = x._root;
			x._root = temp;
			temp = this->_first;
			this->_first = x._first;
			x._first = temp;
			temp = this->_last;
			this->_last = x._last;
			x._last = temp;
			swap(this->_size, x._size);
		}

/**************************** clear () **********************************/

		void clear() {
			if (_root) {
				_first->_parent->_left = NULL;
				_first->_parent = _last;
				_last->_parent->_right = NULL;
				_last->_parent = NULL;
				alloc.destroy(_root);
				alloc.deallocate(_root, 1);
			}
			_root = NULL;
			_size = 0;
		}

/**************************** key_comp () **********************************/

		key_compare key_comp() const { return key_compare(); }

		value_compare value_comp() const { return value_compare(key_compare()); }


/**************************** find() **********************************/
		iterator find(const Key &key) {
			node_pointer temp = _root;
			while (temp->_left) {
				if (key_comp()(key, temp->_Val.first))
					temp = temp->_left;
				else if (key_comp()(temp->_Val.first, key))
					temp = temp->_right;
				else
					return iterator(temp);
			}
			return end();
		}

		const_iterator find(const Key &key) const {
			node_pointer temp = _root;
			while (temp->_left) {
				if (key_comp()(key, temp->_Val.first))
					temp = temp->_left;
				else if (key_comp()(temp->_Val.first, key))
					temp = temp->_right;
				else
					return iterator(temp);
			}
			return end();
		}

/**************************** count () **********************************/

		size_type count(const key_type &k) const {
			node_type *temp = this->_root;
			if (temp) {
				while (k != temp->_Val.first) {
					if (key_comp()(k, temp->_Val.first))
						temp = temp->_left;
					else if (key_comp()(temp->_Val.first, k))
						temp = temp->_right;
					if (temp->_left == NULL)
						return 0;
				}
				return 1;
			}
			return 0;
		}

/**************************** lower_bound () **********************************/

		iterator lower_bound(const key_type &k) {
			if (!_root)
				return end();
			node_type *temp = _root;
			while (temp != _first and temp != _last) {
				if (key_comp()(k, temp->_Val.first)) {
					if (temp->_left->_parent)
						temp = temp->_left;
					else
						return iterator(temp);
				} else if (key_comp()(temp->_Val.first, k)) {
					if (temp->_right->_parent)
						temp = temp->_right;
					else
						return ++iterator(temp);
				} else
					return iterator(temp);
			}
			return (temp == _first) ? iterator(temp->_parent) : iterator(temp);
		}

		const_iterator lower_bound(const key_type &k) const {
			if (!_root)
				return end();
			node_type *temp = _root;
			while (temp != _first and temp != _last) {
				if (key_comp()(k, temp->_Val.first)) {
					if (temp->_left->_parent)
						temp = temp->_left;
					else
						return const_iterator(temp);
				} else if (key_comp()(temp->_Val.first, k)) {
					if (temp->_right->_parent)
						temp = temp->_right;
					else
						return ++const_iterator(temp);
				} else
					return const_iterator(temp);
			}
			return (temp == _first) ? const_iterator(temp->_parent) : const_iterator(temp);
		}

/**************************** upper_bound () **********************************/

		iterator upper_bound(const key_type &k) {
			if (!_root)
				return end();
			node_type *temp = _root;
			while (temp != _first and temp != _last) {
				if (key_comp()(k, temp->_Val.first)) {
					if (temp->_left->_parent)
						temp = temp->_left;
					else
						return iterator(temp);
				} else if (key_comp()(temp->_Val.first, k)) {
					if (temp->_right and temp->_right->_parent)
						temp = temp->_right;
					else
						return ++iterator(temp);
				} else
					return ++iterator(temp);
			}
			return (temp == _first) ? iterator(temp->_parent) : iterator(temp);
		}

		const_iterator upper_bound(const key_type &k) const {
			if (!_root)
				return end();
			node_type *temp = _root;
			while (temp != _first and temp != _last) {
				if (key_comp()(k, temp->_Val.first)) {
					if (temp->_left->_parent)
						temp = temp->_left;
					else
						return const_iterator(temp);
				} else if (key_comp()(temp->_Val.first, k)) {
					if (temp->_right and temp->_right->_parent)
						temp = temp->_right;
					else
						return ++const_iterator(temp);
				} else
					return ++const_iterator(temp);
			}
			return (temp == _first) ? const_iterator(temp->_parent) : const_iterator(temp);
		}

/**************************** equal_range () **********************************/

		pair<iterator, iterator> equal_range(const key_type &k) {
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}


/**************************** get_allocator () **********************************/

		allocator_type get_allocator() const { return alloc; }


/* ===============  NON-MEMBER FUNCTION OVERLOADS: ================= */

	friend	bool operator==(const map& lhs, const map& rhs ){
		if (lhs._size != rhs._size)
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	friend bool operator!=( const map& lhs, const map& rhs ) { return !(lhs == rhs); }

	friend bool operator<( const map& lhs, const map& rhs ) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	friend bool operator>( const map& lhs, const map& rhs ) { return rhs < lhs; }

	friend bool operator<=(const map& lhs, const map& rhs) { return !(lhs > rhs); }

	friend bool operator>=(const map& lhs, const map& rhs) { return !(lhs < rhs); }


/* ******************* Вспомогательные функции ****************** */
	private:

		void print_n() const {
			if (!_root)
				return;
			int h = _root->Height(_root);
			for (int i = 0; i < h; ++i) {
				this->_root->print_n(_root, i, 0);
				std::cout << std::endl;
			}
		}

		void imaginary_nodes() {
			_first = alloc.allocate(1);
			alloc.construct(_first);
			_first->_left = NULL;
			_first->_right = NULL;
			_last = alloc.allocate(1);
			alloc.construct(_last);
			_last->_left = NULL;
			_last->_right = NULL;
			_first->_color = BLACK;
			_last->_color = BLACK;
			_first->_parent = _last;
			_last->_parent = NULL;
		}

		node_type *find_node(const Key &key) {
			node_pointer temp = _root;
			if (temp) {
				while (temp->_left) {
					if (key_comp()(key, temp->_Val.first))
						temp = temp->_left;
					else if (key_comp()(temp->_Val.first, key))
						temp = temp->_right;
					else
						return temp;
				}
			}
			return temp;
		}

		void swap_node(node_type *a, node_type *b) {
			node_type *a_left = a->_left;
			node_type *a_right = a->_right;
			node_type *a_parent = a->_parent;

			node_type *b_left = b->_left;
			node_type *b_right = b->_right;
			node_type *b_parent = b->_parent;

			if (a_parent and a_parent->_left == a)
				a_parent->_left = b;
			else if (a_parent)
				a_parent->_right = b;
			if (b_parent and b_parent->_left == b)
				b_parent->_left = a;
			else if (b_parent)
				b_parent->_right = a;
			if (a_left->_parent)
				a_left->_parent = b;
			if (a_right->_parent)
				a_right->_parent = b;
			if (b_left->_parent)
				b_left->_parent = a;
			if (b_right->_parent)
				b_right->_parent = a;
			swap(&(a->_left), &(b->_left));
			swap(&(a->_right), &(b->_right));
			swap(&(a->_parent), &(b->_parent));
			swap(a->_color, b->_color);
		}

		template<class U>
		void swap(U **left, U **right) {
			U *temp = *left;
			*left = *right;
			*right = temp;
		}

		template<class U>
		void swap(U &left, U &right) {
			U temp = left;
			left = right;
			right = temp;
		}

		node_type *search_min(node_type *node) {
			node_type *temp = node;
			while (temp->_left->_left)
				temp = temp->_left;
			return temp;
		}

		node_type *search_max(node_type *node) {
			node_type *temp = node;
			while (temp->_right->_right)
				temp = temp->_right;
			return temp;
		}

		node_pointer make_head(const value_type &val) {
			_root = alloc.allocate(1);
			alloc.construct(_root, val);
			_root->_left = _first;
			_root->_right = _last;
			_root->_parent = NULL;
			_first->_parent = _root;
			_last->_parent = _root;
			_root->_color = 0;
			++_size;
			return _root;
		}

		node_pointer make_left(const value_type &val, node_pointer node) {
			node_pointer ptr = alloc.allocate(1);
			alloc.construct(ptr, val);
			ptr->_left = node->_left;
			ptr->_right = alloc.allocate(1); // лист
			alloc.construct(ptr->_right);
			ptr->_right->_parent = NULL;
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

		node_pointer make_right(const value_type &val, node_pointer node) {
			node_pointer ptr = alloc.allocate(1);
			alloc.construct(ptr, val);
			ptr->_right = node->_right;
			ptr->_left = alloc.allocate(1); // лист
			alloc.construct(ptr->_left);
			ptr->_left->_parent = NULL;
			ptr->_left->_color = BLACK;
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

		void delete_case1(node_type *node) {
			if (node->_parent)
				delete_case2(node);
		}

		void delete_case2(node_type *node) {
			node_type *br = node->brother();
			if (br->_color == RED) {
				swap((node->_parent->_color), (br->_color));
				if (node == node->_parent->_left)
					LeftTurn(node->_parent);
				else
					RightTurn(node->_parent);
			}
			delete_case3(node);
		}

		void delete_case3(node_type *node) {
			node_type *br = node->brother();
			if (node->_parent->_color == BLACK and br->_color == BLACK and
				br->_left->_color == BLACK and br->_right->_color == BLACK) {
				br->_color = RED;
				delete_case1(node->_parent);
			} else
				delete_case4(node);
		}

		void delete_case4(node_type *node) {
			node_type *br = node->brother();
			if (br->_color == BLACK and br->_left->_color == BLACK and
				br->_right->_color == BLACK and
				node->_parent->_color == RED) {
				swap((br->_color), (node->_parent->_color));
			} else
				delete_case5(node);
		}

		void delete_case5(node_type *node) {
			node_type *br = node->brother();
			if (br->_color == BLACK) {
				if ((node == node->_parent->_left) and
					br->_right->_color == BLACK and
					br->_left->_color == RED) {
					br->_color = RED;
					br->_left->_color = BLACK;
					RightTurn(br);
				} else if ((node == node->_parent->_right) and
						   br->_left->_color == BLACK and
						   br->_right->_color == RED) {
					br->_color = RED;
					br->_right->_color = BLACK;
					LeftTurn(br);
				}
			}
			delete_case6(node);
		}

		void delete_case6(node_type *node) {
			node_type *br = node->brother();
			br->_color = node->_parent->_color;
			node->_parent->_color = BLACK;
			if (node == node->_parent->_left) {
				br->_right->_color = BLACK;
				LeftTurn(node->_parent);
			} else {
				br->_left->_color = BLACK;
				RightTurn(node->_parent);
			}
		}

/***************** балансировка ***********************/
		void balancing(node_pointer ptr) {
			if (!ptr->_parent) {
				ptr->_color = BLACK;
				return;
			}
			node_pointer P = ptr->_parent;
			if (P->_color == BLACK)
				return;
			node_pointer G = ptr->grandfather();
			node_pointer U = ptr->uncle();
			if (P->_color == RED and U->_color == RED) { //случай 3
				P->_color = BLACK;
				U->_color = BLACK;
				G->_color = RED;
				balancing(G);
				return;
			} else if (P->_color == RED and U->_color == BLACK) { //случай 4
				if (ptr == P->_right and P == G->_left) {
					LeftTurn(P);
					ptr = ptr->_left;
				} else if (ptr == P->_left and P == G->_right) {
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

		void LeftTurn(node_pointer root) {
			node_type *RightSubTree = root->_right;
			node_type *RightSubTreeLeft = RightSubTree->_left;
			if (root->_parent) {
				if (root->_parent->_left == root)
					root->_parent->_left = RightSubTree;
				else
					root->_parent->_right = RightSubTree;
			}
			RightSubTree->_parent = root->_parent;
			root->_parent = RightSubTree;
			RightSubTree->_left = root;
			root->_right = RightSubTreeLeft;
			if (RightSubTreeLeft and RightSubTreeLeft->_parent)
				RightSubTreeLeft->_parent = root;
		}

		void RightTurn(node_pointer root) {
			node_type *LeftSubTree = root->_left;
			node_type *LeftSubTreeRight = LeftSubTree->_right;
			if (root->_parent) {
				if (root->_parent->_left == root)
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

	};
} //namespace ft

namespace std {
	template<class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs) { lhs.swap(rhs); }
}

#endif
