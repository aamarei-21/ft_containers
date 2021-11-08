#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <memory>
#include "Iterator_traits.hpp"
#include "Iterator.hpp"

namespace ft {
	template<class InputIterator>
			size_t ft_distance(InputIterator const &first, InputIterator const &second) {
				size_t temp(0);
				for (InputIterator it = first; it != second; ++it)
					++temp;
				return temp;
			}

			template<class T>
					void ft_swap(T &larg, T &rarg) {
						T temp_arg;
						temp_arg = larg;
						larg = rarg;
						rarg = temp_arg;
					}

//	template<class T>
//	class Randomiterator;
//
//	template<class Iter>
//	class Reverse_Iterator;

	template<class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef size_t size_type;
		typedef Alloc allocator_type;
		typedef typename std::allocator<T>::reference reference;
		typedef typename std::allocator<T>::const_reference const_reference;
		typedef typename std::allocator<T>::pointer pointer;
		typedef typename std::allocator<T>::const_pointer const_pointer;
		typedef Randomiterator<pointer> iterator;
		typedef Randomiterator<const_pointer> const_iterator;
		typedef Reverse_Iterator<iterator> reverse_iterator;
		typedef Reverse_Iterator<const_iterator> const_reverse_iterator;

	private:
		allocator_type alloc;
		pointer ptr;
		size_type _size; //количество элементов в массиве (векторе)
		size_type _capacity; //размер аллоцированной памяти
	public:

/*************  Constructor  *****************/
	explicit vector(const allocator_type &al = allocator_type())
		: alloc(al), _size(0), _capacity(0) { ptr = alloc.allocate(_size); }

		explicit vector(size_type const &size, const T &val = T(), const allocator_type &al = allocator_type())
		: alloc(al), _size(size), _capacity(size) {
		ptr = alloc.allocate(_size);
		for (typename vector<T, Alloc>::size_type i = 0; i < _capacity; ++i)
			alloc.construct(ptr + i, val);
	}

	template<class InputIterator>
	vector(InputIterator first,
		   typename enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last,
		   const allocator_type &al = allocator_type()) : alloc(al) {
		_size = 0;
		while (first + _size != last)
			++_size;
		ptr = alloc.allocate(_size);
		_capacity = _size;
		for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
			alloc.construct(ptr + i, *(first + i));
	}

	vector(const vector &x) : alloc(x.alloc), _size(x._size), _capacity(x._capacity) {
		ptr = alloc.allocate(_size);
		for (typename vector<T, Alloc>::size_type i = 0; i < _capacity; ++i)
			alloc.construct(ptr + i, x[i]);
	}

/*************  operator=  *****************/
	vector &operator=(const vector &x) {
		alloc.deallocate(ptr, _capacity);
		_size = x._size;
		_capacity = x._capacity;
		ptr = alloc.allocate(_capacity);
		for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
			alloc.construct(ptr + i, x[i]);
		return *this;
	}

/*************  destructor  *****************/
	~vector() {
		this->clear();
		alloc.deallocate(ptr, _capacity);
	}

/* ======================  ITETATORS:  ====================== */

/*************  begin, end  *****************/
	iterator begin() { return ptr; }

	iterator end() { return (ptr + _size); }

	const_iterator begin() const { return ptr; }

	const_iterator end() const { return ptr + _size; }

/************* rbegin, rend  ****************/
	reverse_iterator rbegin() { return reverse_iterator (end() - 1); }

	const_reverse_iterator rbegin() const { return const_reverse_iterator(end() - 1); }

	reverse_iterator rend() { return reverse_iterator(begin()); }

	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }


/* ======================  CAPACITY:  ====================== */

/*************  size()  *****************/
	size_type size() const { return _size; }

/*************  max_size() **************/
	size_type max_size() const {
		return std::numeric_limits<std::size_t>::max() / sizeof(T);
	}

/*************  resize() ***************/
	void resize(size_type n, T val = T()) {
		if (n > _capacity) {
			typename vector<T, Alloc>::size_type temp_cap = _capacity;
			if (n <= 2 * _capacity)
				_capacity *= 2;
			else
				_capacity = n;
			T *temp_ptr;
			temp_ptr = alloc.allocate(_capacity);
			for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
				alloc.construct(temp_ptr + i, *(ptr + i));
			for (typename vector<T, Alloc>::size_type i = _size; i < n; ++i)
				alloc.construct(temp_ptr + i, val);
			this->clear();
			alloc.deallocate(ptr, temp_cap);
			ptr = temp_ptr;
		} else {
			if (n < _size) {
				for (typename vector<T, Alloc>::size_type i = n; i < _size; ++i)
					alloc.destroy(&(*this)[i]);
			} else {
				for (typename vector<T, Alloc>::size_type i = _size; i < n; ++i)
					alloc.construct(this->ptr + i, val);
			}
		}
		_size = n;
	}

/*************  capacity() *************/
	size_type capacity() const { return _capacity; }

/*************  empty()  ***************/
	bool empty() const { return (_size == 0); }

/*************  reserve()  *************/
	void reserve(size_type new_cap) {
		if (new_cap > _capacity) {
			T *temp_ptr;
			temp_ptr = alloc.allocate(new_cap);
			for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
				alloc.construct(temp_ptr + i, *(ptr + i));
			typename vector<T, Alloc>::size_type temp_size = _size;
			clear();
			alloc.deallocate(ptr, _capacity);
			_size = temp_size;
			_capacity = new_cap;
			ptr = temp_ptr;
		}
	}


/* ======================  ELEMENT ACCES:  ====================== */

/*************  operator []  *************/
	reference operator[](size_type pos) { return *(ptr + pos); }

	const_reference operator[](size_type pos) const { return *(ptr + pos); }

/*************  at()  *****************/
	reference at(size_type pos) {
		if(pos >= _size || pos < 0)
			throw std::out_of_range("My_class");
		return *(ptr + pos);
	}

	const_reference at(size_type pos) const {
		if (pos >= _size || pos < 0)
			throw std::out_of_range("vector");
		return *(ptr + pos);
	}

/*************  front()  *****************/
	reference front() { return *ptr; }

	const_reference front() const { return *ptr; }

/*************  back()  *****************/
	reference back() { return *(ptr + _size - 1); }

	const_reference back() const { return *(ptr + _size - 1); }

/*************  data()  *****************/
	pointer data() { return ptr; }

	const_pointer data() const { return (ptr + _size - 1); }


/* ======================  MODIFIERS:  ====================== */

/*************  assign  *****************/
	void assign(size_type count, const T &value) {
		reserve(count);
		for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
			alloc.construct(ptr + i, value);
		for (typename vector<T, Alloc>::size_type i = count; i < _size; ++i)
			alloc.destroy(ptr + i);
		_size = count;
	}

		template<class InputIterator>
		void assign(InputIterator first,
					typename enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last) {
		typename vector<T, Alloc>::size_type size;

		size = ft_distance(first, last);
		if (size <= _capacity) {
			for (typename vector<T, Alloc>::size_type temp = 0; temp < size; ++temp) {
				alloc.destroy(ptr + temp);
				alloc.construct(ptr + temp, *(first + temp));
			}
			for (typename vector<T, Alloc>::size_type i = size; i < _size; ++i)
				alloc.destroy(ptr + i);
		} else {
			reserve(size);
			for (typename vector<T, Alloc>::size_type i = 0; i < size; ++i)
				alloc.construct(ptr + i, *(first + i));
			for (typename vector<T, Alloc>::size_type i = size; i < _size; ++i)
				alloc.destroy(ptr + i);
		}
		_size = size;
	}

/*************  push_back()  *****************/
	void push_back(T const &value) {
		if (_size != _capacity)
			alloc.construct(ptr + _size, value);
		else {
			T *temp_ptr;
			size_type temp_cap;
			temp_cap = (_capacity == 0) ? 1 : _capacity * 2;
			temp_ptr = alloc.allocate(temp_cap);
			for (size_type i = 0; i < _capacity; ++i)
				alloc.construct(temp_ptr + i, *(ptr + i));
			alloc.construct(temp_ptr + _size, value);
			this->clear();
			alloc.deallocate(ptr, _capacity);
			_size = _capacity;
			_capacity = temp_cap;
			ptr = temp_ptr;
		}
		++_size;
	}

/*************  pop_back()  *****************/
	void pop_back() { --_size; }

/*************  insert()  *****************/
	iterator insert(iterator pos, const T &value) {
		if (_size == _capacity) {
			size_type temp_size;
			temp_size = (ptr < pos.get_ptr()) ? ft_distance(ptr, pos.get_ptr()) : -ft_distance(pos.get_ptr(), ptr);
			reserve(_capacity * 2);
			pos = iterator(ptr) + temp_size;
		}
		if (pos >= end()) {
			alloc.construct(pos.get_ptr(), value);
			_size = ft_distance(begin(), pos + 1);
		} else {
			for (iterator it = end(); it != pos; --it)
				alloc.construct(it.get_ptr(), *(it - 1));
			alloc.construct(pos.get_ptr(), value);
			++_size;
		}
		return pos;
	}

	void insert(iterator pos, size_type count, const T &value) {
		if (_size + count > _capacity) {
			typename vector<T, Alloc>::size_type temp_size;
			temp_size = (ptr < pos.ptr) ? ft_distance(ptr, pos.ptr) : -ft_distance(pos.ptr, ptr);
			reserve(_size + count);
			pos.ptr = ptr + temp_size;
		}
		if (pos >= end()) {
			for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
				alloc.construct((pos + i).ptr, value);
			_size = ft_distance(begin(), pos + count);
		} else {
			for (iterator it = end() + count; it != pos; --it)
				alloc.construct(it.ptr, *(it - count).ptr);
			for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
				alloc.construct((pos + i).ptr, value);
			_size += count;
		}
	}

	template<class InputIt>
	void insert(iterator pos, InputIt first,
				typename enable_if<std::__is_input_iterator<InputIt>::value, InputIt>::type last) {
		typename vector<T, Alloc>::size_type count;
		count = ft_distance(first, last);
		if (_size + count > _capacity) {
			size_type temp_size;
			temp_size = (ptr < pos.get_ptr()) ? ft_distance(ptr, pos.get_ptr()) : -ft_distance(pos.get_ptr(), ptr);
			(_size + count > 2 * _capacity) ? reserve(_size + count) : reserve(2 * _capacity);
			pos = iterator (ptr) + temp_size;
		}
		if (pos >= end()) {
			for (size_type i = 0; i < count; ++i)
				alloc.construct((pos + i).get_ptr(), *(first + i));
			_size = ft_distance(begin(), pos + count);
		} else {
			for (iterator it = end() + count; it != pos; --it)
				alloc.construct(it.get_ptr(), *(it - count));
			for (size_type i = 0; i < count; ++i)
				alloc.construct((pos + i).get_ptr(), *(first + i));
			_size += count;
		}
	}

/*************  erase()  *****************/
	iterator erase(iterator pos) {
		for (iterator it = pos; it != end(); ++it)
			*it = *(it + 1);
		alloc.destroy(&(*end()));
		_size = (pos >= end()) ? _size : --_size;
		return pos;
	}

	iterator erase(iterator first, iterator last) {
		size_type count;
		count = ft_distance(first, last);
		if (count < 0)
			return last;
		for (size_type i = 0; i < count; ++i)
			alloc.construct((first + i).get_ptr(), *(last + i));
		for (iterator it = last; it != end(); ++it){
			alloc.construct(it.get_ptr(), *(last + count));
			++count;
		}
		_size -= ft_distance(first, last);
		return first;
	}

/*************  swap()  *****************/
	void swap(vector &other) {
		ft_swap(ptr, other.ptr);
		ft_swap(_size, other._size);
		ft_swap(_capacity, other._capacity);
		ft_swap(alloc, other.alloc);
	}

/*************  clear()  *****************/
	void clear() {
		for (size_type i = 0; i < _size; ++i)
			alloc.destroy(&(ptr[i]));
		_size = 0;
	}


/* ======================  ALLOCATOR:  ====================== */

/*************  get_allocator()  *****************/
	allocator_type get_allocator() const { return alloc; }

/* ===============  NON-MEMBER FUNCTION OVERLOADS: ================= */

/*************  relational operators  *****************/

	friend bool operator==(const vector &lhs, const vector &rhs) {
		if (lhs._size != rhs._size)
			return false;
		for (size_type i = 0; i < lhs._size; ++i)
			if (*(lhs.ptr + i) != *(rhs.ptr + i))
				return false;
			return true;
	}


	friend bool operator!=(const vector &lhs, const vector &rhs) { return !(lhs == rhs); }

	friend bool operator<(const vector &lhs, const vector &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	friend bool operator<=(const vector &lhs, const vector &rhs)  { return !(lhs > rhs); }

	friend bool operator>(const vector &lhs, const vector &rhs) { return (rhs < lhs); }

	friend bool operator>=(const vector &lhs, const vector &rhs) { return !(lhs < rhs); }



	}; // class vector

/**************  swap()  *****************/

}//namespace ft

	namespace std {
		template<class V, class Al>
		void swap(ft::vector<V, Al> &lhs, ft::vector<V, Al> &rhs) { lhs.swap(rhs); }
	}

//#include "vector.cpp"

#endif


