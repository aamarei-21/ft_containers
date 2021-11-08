#include "vector.hpp"

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

/*************  Constructot *****************/

//	template<class T, class Alloc>
//	inline vector<T, Alloc>::vector(const std::allocator<T> &al)
//			: alloc(al), _size(0), _capacity(0) { ptr = alloc.allocate(_size); }

//	template<class T, class Alloc>
//	inline vector<T, Alloc>::vector(size_type const &size, const T &val, const std::allocator<T> &al)
//			: alloc(al), _size(size), _capacity(size) {
//		ptr = alloc.allocate(_size);
//		for (typename vector<T, Alloc>::size_type i = 0; i < _capacity; ++i)
//			alloc.construct(ptr + i, val);
//	}

//	template<class T, class Alloc>
//	template<class InputIterator>
//	inline vector<T, Alloc>::vector(InputIterator first,
//									typename enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type last,
//									const std::allocator<T> &al) : alloc(al) {
//		_size = 0;
//		while (first + _size != last)
//			++_size;
//		ptr = alloc.allocate(_size);
//		_capacity = _size;
//		for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
//			alloc.construct(ptr + i, *(first + i));
//	}

//	template<class T, class Alloc>
//	inline vector<T, Alloc>::vector(const vector &x) : alloc(x.alloc), _size(x._size), _capacity(x._capacity) {
//		ptr = alloc.allocate(_size);
//		for (typename vector<T, Alloc>::size_type i = 0; i < _capacity; ++i)
//			alloc.construct(ptr + i, x[i]);
//	}

/*************  operator=  *****************/
//	template<class T, class Alloc>
//	inline vector <T, Alloc> &vector<T, Alloc>::operator=(const vector &x) {
//		alloc.deallocate(ptr, _capacity);
//		_size = x._size;
//		_capacity = x._capacity;
//		ptr = alloc.allocate(_capacity);
//		for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
//			alloc.construct(ptr + i, x[i]);
//		return *this;
//	}

/************* destructor  *****************/

//	template<class T, class Alloc>
//	inline vector<T, Alloc>::~vector() {
//		this->clear();
//		alloc.deallocate(ptr, _capacity);
//	}

/* ======================  ITETATORS:  ====================== */

/*****************  begin, end  *******************/
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::iterator vector<T, Alloc>::begin() { return iterator(ptr); }
//
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::iterator vector<T, Alloc>::end() { return iterator(ptr + _size); }
//
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const { return const_iterator(ptr); }
//
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const {
//		return const_iterator(ptr + _size);
//	}

/******************  rbegin, rend  *****************/
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin() {
//		return reverse_iterator(end());
//	}
//
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const { return end(); }
//
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend() {
//		return reverse_iterator(begin());
//	}
//
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const { return begin(); }


/* ======================  CAPACITY:  ====================== */

/*************  size()  *****************/
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const { return _size; }
//
///*************  max_size()  *****************/
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {
//		return std::numeric_limits<std::size_t>::max() / sizeof(T);
//	}

/*************  resize()  *****************/
//	template<class T, class Alloc>
//	void vector<T, Alloc>::resize(typename vector<T, Alloc>::size_type n, T val) {
//		if (n > _capacity) {
//			typename vector<T, Alloc>::size_type temp_cap = _capacity;
//			if (n <= 2 * _capacity)
//				_capacity *= 2;
//			else
//				_capacity = n;
//			T *temp_ptr;
//			temp_ptr = alloc.allocate(_capacity);
//			for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
//				alloc.construct(temp_ptr + i, *(ptr + i));
//			for (typename vector<T, Alloc>::size_type i = _size; i < n; ++i)
//				alloc.construct(temp_ptr + i, val);
//			this->clear();
//			alloc.deallocate(ptr, temp_cap);
//			ptr = temp_ptr;
//		} else {
//			if (n < _size) {
//				for (typename vector<T, Alloc>::size_type i = n; i < _size; ++i)
//					alloc.destroy(&(*this)[i]);
//			} else {
//				for (typename vector<T, Alloc>::size_type i = _size; i < n; ++i)
//					alloc.construct(this->ptr + i, val);
//			}
//		}
//		_size = n;
//	}

/*************  capacity()  *****************/
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const { return _capacity; }

/*************  empty()  *****************/
//	template<class T, class Alloc>
//	bool vector<T, Alloc>::empty() const { return begin() == end(); }

/*************  reserve()  *****************/
//	template<class T, class Alloc>
//	inline void vector<T, Alloc>::reserve(typename vector<T, Alloc>::size_type new_cap) {
//		if (new_cap > _capacity) {
//			T *temp_ptr;
//			temp_ptr = alloc.allocate(new_cap);
//			for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
//				alloc.construct(temp_ptr + i, *(ptr + i));
//			typename vector<T, Alloc>::size_type temp_size = _size;
//			clear();
//			alloc.deallocate(ptr, _capacity);
//			_size = temp_size;
//			_capacity = new_cap;
//			ptr = temp_ptr;
//		}
//	}

/* ======================  ELEMENT ACCES:  ====================== */

/*************  operator []  *************/
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::reference vector<T, Alloc>::
//	operator[](typename vector<T, Alloc>::size_type pos) { return *(ptr + pos); }
//
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::const_reference vector<T, Alloc>::
//	operator[](typename vector<T, Alloc>::size_type pos) const { return *(ptr + pos); }

/*************  at()  *****************/
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::const_reference
//	vector<T, Alloc>::at(typename vector<T, Alloc>::size_type pos) const {
//		if (pos >= _size || pos < 0)
//			throw std::out_of_range("vector");
//		return *(ptr + pos);
//	}

/*************  front()  *****************/
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::reference vector<T, Alloc>::front() { return *ptr; }
//
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const { return *ptr; }

/*************  back()  *****************/
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::reference vector<T, Alloc>::back() { return *(ptr + _size - 1); }
//
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const { return *(ptr + _size - 1); }

/*************  data()  *****************/
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::pointer vector<T, Alloc>::data() { return ptr; }
//
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::const_pointer vector<T, Alloc>::data() const { return (ptr + _size - 1); }


/* ======================  MODIFIERS:  ====================== */

/*************  assign  *****************/
//	template<class T, class Alloc>
//	inline void vector<T, Alloc>::assign(typename vector<T, Alloc>::size_type count, const T &value) {
//		reserve(count);
//		for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
//			alloc.construct(ptr + i, value);
//		for (typename vector<T, Alloc>::size_type i = count; i < _size; ++i)
//			alloc.destroy(ptr + i);
//		_size = count;
//	}
//
//	template<class T, class Alloc>
//	template<class InputIterator>
//	inline void vector<T, Alloc>::assign(InputIterator first,
//										 typename enable_if<std::__is_input_iterator<InputIterator>::value,
//												   InputIterator>::type last) {
//		typename vector<T, Alloc>::size_type size;
//
//		size = ft_distance(first, last);
//		if (size <= _capacity) {
//			for (typename vector<T, Alloc>::size_type temp = 0; temp < size; ++temp) {
//				alloc.destroy(ptr + temp);
//				alloc.construct(ptr + temp, *(first + temp));
//			}
//			for (typename vector<T, Alloc>::size_type i = size; i < _size; ++i)
//				alloc.destroy(ptr + i);
//		} else {
//			reserve(size);
//			for (typename vector<T, Alloc>::size_type i = 0; i < size; ++i)
//				alloc.construct(ptr + i, *(first + i));
//			for (typename vector<T, Alloc>::size_type i = size; i < _size; ++i)
//				alloc.destroy(ptr + i);
//		}
//		_size = size;
//	}

/*************  push_back()  *****************/
//	template<class T, class Alloc>
//	inline void vector<T, Alloc>::push_back(T const &value) {
//		if (_size != _capacity)
//			alloc.construct(ptr + _size, value);
//		else {
//			T *temp_ptr;
//			size_type temp_cap;
//			temp_cap = (_capacity == 0) ? 1 : _capacity * 2;
//			temp_ptr = alloc.allocate(temp_cap);
//			for (typename vector<T, Alloc>::size_type i = 0; i < _capacity; ++i)
//				alloc.construct(temp_ptr + i, *(ptr + i));
//			alloc.construct(temp_ptr + _size, value);
//			this->clear();
//			alloc.deallocate(ptr, _capacity);
//			_size = _capacity;
//			_capacity = temp_cap;
//			ptr = temp_ptr;
//		}
//		++_size;
//	}

/*************  pop_back()  *****************/
//	template<class T, class Alloc>
//	void vector<T, Alloc>::pop_back() { --_size; }

/*************  insert()  *****************/
//	template<class T, class Alloc>
//	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, const T &value) {
//		if (_size == _capacity) {
//			typename vector<T, Alloc>::size_type temp_size;
//			temp_size = (ptr < pos.ptr) ? ft_distance(ptr, pos.ptr) : -ft_distance(pos.ptr, ptr);
//			reserve(_capacity * 2);
//			pos.ptr = ptr + temp_size;
//		}
//		if (pos >= end()) {
//			alloc.construct(pos.ptr, value);
//			_size = ft_distance(begin(), pos + 1);
//		} else {
//			for (typename vector<T, Alloc>::iterator it = end(); it != pos; --it)
//				alloc.construct(it.ptr, *(it - 1).ptr);
//			alloc.construct(pos.ptr, value);
//			++_size;
//		}
//		return pos;
//	}

//	template<class T, class Alloc>
//	void vector<T, Alloc>::insert(iterator pos, size_type count, const T &value) {
//		if (_size + count > _capacity) {
//			typename vector<T, Alloc>::size_type temp_size;
//			temp_size = (ptr < pos.ptr) ? ft_distance(ptr, pos.ptr) : -ft_distance(pos.ptr, ptr);
//			reserve(_size + count);
//			pos.ptr = ptr + temp_size;
//		}
//		if (pos >= end()) {
//			for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
//				alloc.construct((pos + i).ptr, value);
//			_size = ft_distance(begin(), pos + count);
//		} else {
//			for (iterator it = end() + count; it != pos; --it)
//				alloc.construct(it.ptr, *(it - count).ptr);
//			for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
//				alloc.construct((pos + i).ptr, value);
//			_size += count;
//		}
//	}

//	template<class T, class Alloc>
//	template<class InputIt>
//	void vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last) {
//		typename vector<T, Alloc>::size_type count;
//		count = ft_distance(first, last);
//		if (_size + count > _capacity) {
//			typename vector<T, Alloc>::size_type temp_size;
//			temp_size = (ptr < pos.ptr) ? ft_distance(ptr, pos.ptr) : -ft_distance(pos.ptr, ptr);
//			(_size + count > 2 * _capacity) ? reserve(_size + count) : reserve(2 * _capacity);
//			pos.ptr = ptr + temp_size;
//		}
//		if (pos >= end()) {
//			for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
//				alloc.construct((pos + i).ptr, *(first + i));
//			_size = ft_distance(begin(), pos + count);
//		} else {
//			for (iterator it = end() + count; it != pos; --it)
//				alloc.construct(it.ptr, *(it - count).ptr);
//			for (typename vector<T, Alloc>::size_type i = 0; i < count; ++i)
//				alloc.construct((pos + i).ptr, *(first + i));
//			_size += count;
//		}
//	}

/*************  erase()  *****************/
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos) {
//		for (iterator it = pos; it != end(); ++it)
//			*it = *(it + 1);
//		alloc.destroy(end().ptr);
//		_size = (pos >= end()) ? _size : --_size;
//		return pos;
//	}

//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {
//		typename vector<T, Alloc>::size_type count;
//		count = ft_distance(begin(), last);
//		for (size_type i = 0; i < _size - count; ++i)
//			alloc.construct((first + i).ptr, *(last + i));
//		_size -= ft_distance(first, last);
//		return first + 1;
//	}

/*************  swap()  *****************/
//	template<class T, class Alloc>
//	void vector<T, Alloc>::swap(vector &other) {
//		ft_swap(ptr, other.ptr);
//		ft_swap(_size, other._size);
//		ft_swap(_capacity, other._capacity);
//		ft_swap(alloc, other.alloc);
//	}

/*************  clear()  *****************/
//	template<class T, class Alloc>
//	inline void vector<T, Alloc>::clear() {
//		for (typename vector<T, Alloc>::size_type i = 0; i < _size; ++i)
//			alloc.destroy(&(*this)[i]);
//		_size = 0;
//	}


/* ======================  ALLOCATOR:  ====================== */

/*************  get_allocator()  *****************/
//	template<class T, class Alloc>
//	inline typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const { return alloc; }

/* ===============  NON-MEMBER FUNCTION OVERLOADS: ================= */

/*************  relational operators  *****************/

//	template<class T, class Alloc>
//	inline bool operator==(const vector <T, Alloc> &lhs, const vector <T, Alloc> &rhs) {
//		if (lhs.size() != rhs.size())
//			return false;
//		for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); ++i)
//			if (*(lhs.ptr + i) != *(rhs.ptr + 1))
//				return false;
//		return true;
//	}
//
//	template<class T, class Alloc>
//	inline bool operator!=(const vector <T, Alloc> &lhs, const vector <T, Alloc> &rhs) { return !(lhs == rhs); }
//
//	template<class T, class Alloc>
//	inline bool operator<(const vector <T, Alloc> &lhs, const vector <T, Alloc> &rhs) {
//		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
//	}
//
//	template<class T, class Alloc>
//	inline bool operator<=(const vector <T, Alloc> &lhs, const vector <T, Alloc> &rhs) { return !(lhs > rhs); }
//
//	template<class T, class Alloc>
//	inline bool operator>(const vector <T, Alloc> &lhs, const vector <T, Alloc> &rhs) { return rhs < lhs; }
//
//	template<class T, class Alloc>
//	inline bool operator>=(const vector <T, Alloc> &lhs, const vector <T, Alloc> &rhs) { return !(lhs < rhs); }


/*************  swap()  *****************/
//	template<class T, class Alloc>
//	void swap(vector <T, Alloc> &lhs, vector <T, Alloc> &rhs) { lhs.swap(rhs); }

} //namespace ft
