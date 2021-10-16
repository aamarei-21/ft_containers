#include "Vector.hpp"

template<class InputIterator>
size_t ft_distance(InputIterator const& first, InputIterator const& second)
{
	size_t temp(0);
	for (InputIterator it = first; it != second; ++it)
		++temp;
	return temp;
}

/* ************  Construct vector  *****************/

template <class T, class Alloc>
inline My_class<T, Alloc>::My_class(const std::allocator<T>& al)
	: alloc(al), _size(0), _capacity(0) 	{ ptr = alloc.allocate(_size); }

template <class T, class Alloc>
inline My_class<T, Alloc>::My_class(size_type const& size, const T& val, const std::allocator<T>& al)
	: alloc(al), _size(size), _capacity(size)
{
	ptr = alloc.allocate(_size);
	for (typename My_class<T, Alloc>::size_type i = 0; i < _capacity; ++i)
		alloc.construct(ptr + i, val);
}

//template<class T, class Alloc>
//template<class InputIterator>
//inline My_class<T, Alloc>::My_class (InputIterator first, InputIterator last, const std::allocator<T>& al)
//{
//	_size = 0;
//	while (first + _size != last)
//		++_size;
//	ptr = alloc.allocate(_size);
//	_capacity = _size;
//	for (typename My_class<T, Alloc>::size_type i = 0; i < _size; ++i)
//		alloc.construct(ptr + i, *(first + i));
//}

template <class T, class Alloc>
inline My_class<T, Alloc>::My_class(const My_class& x) : alloc(x.alloc), _size(x._size), _capacity(x._capacity)
{
	ptr = alloc.allocate(_size);
	for (typename My_class<T, Alloc>::size_type i = 0; i < _capacity; ++i)
		alloc.construct(ptr + i, x[i]);
}

/* ************  Vector destructor  *****************/

template <class T, class Alloc>
inline My_class<T, Alloc>::~My_class() {
	this->clear();
	alloc.deallocate(ptr, _capacity);
}

/* ************  operator=  *****************/

template<class T, class Alloc>
inline My_class<T, Alloc>& My_class<T, Alloc>::operator=(const My_class& x)
{
	alloc.deallocate(ptr, _capacity);
	_size = x._size;
	_capacity = x._capacity;
	ptr = alloc.allocate(_capacity);
	for (typename My_class<T, Alloc>::size_type i = 0; i < _size; ++i)
		alloc.construct(ptr + i, x[i]);
	return *this;
}

/* ************  assign  *****************/
template<class T, class Alloc>
inline void My_class<T, Alloc>::assign( typename My_class<T, Alloc>::size_type count, const T& value ){
	reserve(count);
	for(typename My_class<T, Alloc>::size_type i = 0; i < count; ++i)
		alloc.construct(ptr + i, value);
	for(typename My_class<T, Alloc>::size_type i = count; i < _size; ++i)
		alloc.destroy(ptr + i);
	_size = count;
}

template<class T, class Alloc>
template <class InputIterator>
inline void My_class<T, Alloc>:: assign (InputIterator first, InputIterator last)
{
	typename My_class<T, Alloc>::size_type	size;

	size = ft_distance(first, last);
	if(size <= _capacity){
		for (typename My_class<T, Alloc>::size_type temp = 0; temp < size; ++temp){
			alloc.destroy(ptr + temp);
			alloc.construct(ptr + temp, *(first + temp));
		}
		for(typename My_class<T, Alloc>::size_type i = size; i < _size; ++i)
			alloc.destroy(ptr + i);
	}
	else{
		reserve(size);
		for(typename My_class<T, Alloc>::size_type i = 0; i < size; ++i)
			alloc.construct(ptr + i, *(first + i));
		for(typename My_class<T, Alloc>::size_type i = size; i < _size; ++i)
			alloc.destroy(ptr + i);
	}
	_size = size;
}


/* ************  ITETATORS:  *****************/

/*==============  begin, end  ================*/

template <class T, class Alloc>
inline typename My_class<T, Alloc>::iterator My_class<T, Alloc>:: begin()
{
	return iterator(ptr);
}

template <class T, class Alloc>
inline typename My_class<T, Alloc>::iterator My_class<T, Alloc>:: end()
{
	return iterator(ptr + _size);
}

template <class T, class Alloc>
inline typename My_class<T, Alloc>::const_iterator My_class<T, Alloc>::begin() const
{
	return const_iterator(ptr);
}

template<class T, class Alloc>
inline typename My_class<T, Alloc>::const_iterator My_class<T, Alloc>::end() const
{
	return const_iterator(ptr + _size);
}

/*==============  rbegin, rend  ================*/
//template<class T, class Alloc>
//inline typename My_class<T, Alloc>::iterator My_class<T, Alloc>::rbegin()
//{
//	return iterator(prt + _size - 1);
//}

//template<class T, class Alloc>
//inline typename My_class<T, Alloc>::iterator My_class<T, Alloc>::rend()
//{
//	return iterator(ptr - 1);
//}


/* вставка элемента в конец массива (вектора). Если аллоцированная память закончилась - аллоцируется новая размером
	в два раза больше имеющейся, все данные копируются на новое место. Старая память очищается */
template <class T, class Alloc>
inline void My_class<T, Alloc>::push_back(T const& value)
{
	if (_size != _capacity)
		alloc.construct(ptr + _size, value); /*Создаем объект value (типа T)
		в выделенном неинициализированном хранилище, на которое указывает ptr+_size*/
	else
	{
		T*	temp_ptr;
		temp_ptr = alloc.allocate(_capacity * 2); /*аллоцируем новую память в два раза больше имеющейся*/
		for (typename My_class<T, Alloc>::size_type i = 0; i < _capacity; ++i)
			alloc.construct(temp_ptr + i, *(ptr + i)); /*копируем все данные в новую выделенную память*/
		alloc.construct(temp_ptr + _size, value); /*дописываем в конец значение value*/
		this->clear();
		alloc.deallocate(ptr, _capacity); /* освобождаем старую память*/
		_size = _capacity;
		_capacity *= 2;
		ptr = temp_ptr;
	}
	++_size;
}


template <class T, class Alloc>
inline T& My_class<T, Alloc>:: operator[](typename My_class<T, Alloc>::size_type pos) { return *(ptr + pos); }

template <class T, class Alloc>
inline T const& My_class<T, Alloc>:: operator[](typename My_class<T, Alloc>::size_type pos) const { return *(ptr + pos); }

/* ************  clear()  *****************/
template<class T, class Alloc>
inline void My_class<T, Alloc>:: clear(){
	for (typename My_class<T, Alloc>::size_type i = 0; i < _size; ++i)
		alloc.destroy(&(*this)[i]);
	_size = 0;
}

/* ************  resize()  *****************/
template<class T, class Alloc>
void My_class<T, Alloc>:: resize (typename My_class<T, Alloc>::size_type n, T val){
	if (n > _capacity){
		typename My_class<T, Alloc>::size_type	temp_cap = _capacity;
		if (n <= 2 * _capacity)
			_capacity *= 2;
		else
			_capacity = n;
		T*	temp_ptr;
		temp_ptr = alloc.allocate(_capacity);
		for (typename My_class<T, Alloc>::size_type i = 0; i < _size; ++i)
			alloc.construct(temp_ptr + i, *(ptr + i));
		for (typename My_class<T, Alloc>::size_type i = _size; i < n; ++i)
			alloc.construct(temp_ptr + i, val);
		this->clear();
		alloc.deallocate(ptr, temp_cap);
		ptr = temp_ptr;
	}
	else{
		if(n < _size){
			for(typename My_class<T, Alloc>::size_type i = n; i < _size; ++i)
				alloc.destroy(&(*this)[i]);
		}
		else{
			for(typename My_class<T, Alloc>::size_type i = _size; i < n; ++i)
				alloc.construct(this->ptr + i, val);
		}
	}
	_size = n;
}

/* ************  size()  *****************/
template<class T, class Alloc>
inline typename My_class<T, Alloc>::size_type My_class<T, Alloc>::size() const { return _size; }

/* ************  capacity()  *****************/
template<class T, class Alloc>
inline typename My_class<T, Alloc>::size_type My_class<T, Alloc>::capacity() const { return _capacity; }

/* ************  reserve()  *****************/
template<class T, class Alloc>
inline void My_class<T, Alloc>::reserve(typename My_class<T, Alloc>::size_type new_cap){
	if (new_cap > _capacity){
		T*	temp_ptr;
		temp_ptr = alloc.allocate(new_cap);
		for(typename My_class<T, Alloc>::size_type i = 0; i < _size; ++i)
			alloc.construct(temp_ptr + i, *(ptr + i));
		typename My_class<T, Alloc>::size_type temp_size = _size;
		clear();
		alloc.deallocate(ptr, _capacity);
		_size = temp_size;
		_capacity = new_cap;
		ptr = temp_ptr;
	}
}

/* ************  get_allocator()  *****************/
template<class T, class Alloc>
inline typename My_class<T, Alloc>::allocator_type My_class<T, Alloc>::get_allocator() const { return alloc; }

/* ************  front()  *****************/
template<class T, class Alloc>
typename My_class<T, Alloc>::reference My_class<T, Alloc>::front(){
	return *ptr;
}

template<class T, class Alloc>
typename My_class<T, Alloc>::const_reference My_class<T, Alloc>::front() const { return *ptr; }

/* ************  back()  *****************/
template<class T, class Alloc>
typename My_class<T, Alloc>::reference My_class<T, Alloc>::back() { return *(ptr + _size - 1); }

template<class T, class Alloc>
typename My_class<T, Alloc>::const_reference My_class<T, Alloc>::back() const { return *(ptr + _size - 1); }

/* ************  data()  *****************/
template<class T, class Alloc>
typename My_class<T, Alloc>::pointer My_class<T, Alloc>::data(){
	return ptr;
}

template<class T, class Alloc>
typename My_class<T, Alloc>::const_pointer My_class<T, Alloc>::data() const { return (ptr + _size - 1); }

/* ************  at()  *****************/
template<class T, class Alloc>
typename My_class<T, Alloc>::reference My_class<T, Alloc>::at(typename My_class<T, Alloc>::size_type pos ){
	if(pos >= _size || pos < 0)
		throw std::out_of_range("vector");
	return *(ptr + pos);
}

template<class T, class Alloc>
typename My_class<T, Alloc>::const_reference My_class<T, Alloc>::at(typename My_class<T, Alloc>::size_type pos) const{
	if(pos >= _size || pos < 0)
		throw std::out_of_range("Vector");
	return *(ptr + pos);
}

/* ************  empty()  *****************/
template<class T, class Alloc>
bool My_class<T, Alloc>::empty() const{ return begin() == end(); }

/* ************  max_size()  *****************/
template<class T, class Alloc>
typename My_class<T, Alloc>::size_type My_class<T, Alloc>::max_size() const{
	return std::numeric_limits<std::size_t>::max()/sizeof(T);
}

/* ************  insert()  *****************/
template<class T, class Alloc>
typename My_class<T, Alloc>::iterator My_class<T, Alloc>::insert( iterator pos, const T& value ){
	if(_size == _capacity){
		typename My_class<T, Alloc>::size_type	temp_size;
		temp_size = (ptr < pos.ptr) ?  ft_distance(ptr, pos.ptr) : -ft_distance(pos.ptr, ptr);
		reserve(_capacity * 2);
		pos.ptr = ptr + temp_size;
	}
	if(pos >= end()){
		alloc.construct(pos.ptr, value);
		_size = ft_distance(begin(), pos + 1);
	}
	else{
		for(typename My_class<T, Alloc>::iterator it = end(); it != pos; --it)
			alloc.construct(it.ptr, *(it - 1).ptr);
		alloc.construct(pos.ptr, value);
		++_size;
	}
	return pos;
}

template<class T, class Alloc>
void My_class<T, Alloc>::insert( iterator pos, size_type count, const T& value ){
	if(_size + count > _capacity){
		typename My_class<T, Alloc>::size_type temp_size;
		temp_size = (ptr < pos.ptr) ? ft_distance(ptr, pos.ptr) : - ft_distance(pos.ptr, ptr);
		reserve(_size + count);
		pos.ptr = ptr + temp_size;
	}
	if(pos >= end()){
		for(typename My_class<T, Alloc>::size_type i = 0; i < count; ++i)
			alloc.construct((pos + i).ptr, value);
		_size = ft_distance(begin(), pos + count);
	}
	else{
		for(iterator it = end() + count; it != pos; --it)
			alloc.construct(it.ptr, *(it - count).ptr);
		for(typename My_class<T, Alloc>::size_type i = 0; i < count; ++i)
			alloc.construct((pos + i).ptr, value);
		_size += count;
	}
}

template<class T, class Alloc>
template<class InputIt >
void My_class<T, Alloc>::insert(iterator pos, InputIt first, InputIt last){
	typename My_class<T, Alloc>::size_type	count;
	count = ft_distance(first, last);
	if(_size + count > _capacity){
		typename My_class<T, Alloc>::size_type temp_size;
		temp_size = (ptr < pos.ptr) ? ft_distance(ptr, pos.ptr) : -ft_distance(pos.ptr, ptr);
		(_size + count > 2 * _capacity) ? reserve(_size + count) : reserve(2 * _capacity);
		pos.ptr = ptr + temp_size;
	}
	if(pos >=end()){
		for(typename My_class<T, Alloc>::size_type i = 0; i < count; ++i)
			alloc.construct((pos + i).ptr, *(first + i));
		_size = ft_distance(begin(), pos + count);
	}
	else{
		for(iterator it = end() + count; it != pos; --it)
			alloc.construct(it.ptr, *(it - count).ptr);
		for(typename My_class<T, Alloc>::size_type i = 0; i < count; ++i)
			alloc.construct((pos + i).ptr, *(first + i));
		_size += count;
	}
}

/* ************  erase()  *****************/
template<class T, class Alloc>
inline typename My_class<T, Alloc>::iterator My_class<T, Alloc>::erase(iterator pos) {
	for(iterator it = pos; it != end(); ++it)
		*it = *(it + 1);
	alloc.destroy(end().ptr);
	_size = (pos >= end()) ? _size : --_size;
	return pos;
}

template<class T, class Alloc>
inline typename My_class<T, Alloc>::iterator My_class<T, Alloc>::erase(iterator first, iterator last){
	typename My_class<T, Alloc>::size_type count;
	count = ft_distance(begin(), last);
	for(size_type i = 0; i < _size - count; ++i)
		alloc.construct((first + i).ptr, *(last + i));
	_size -= ft_distance(first, last);
	return first + 1;
}

/* ************  pop_back()  *****************/
template<class T, class Alloc>
void My_class<T, Alloc>::pop_back(){ --_size; }

/* ************  swap()  *****************/
template<class T, class Alloc>
void My_class<T, Alloc>::swap(My_class& other){
	typename My_class<T, Alloc>::size_type	temp_size;
	typename My_class<T, Alloc>::pointer	temp_point;
	temp_point = ptr;
	ptr = other.ptr;
	other.ptr = temp_point;
	temp_size = _size;
	_size = other._size;
	other._size = temp_size;
	temp_size = _capacity;
	_capacity = other._capacity;
	other._capacity = temp_size;
}


/*******************************************************/
/* ************  Non-member functions  *****************/
/*******************************************************/

template< class T, class Alloc >
inline bool operator==(const My_class<T,Alloc>& lhs, const My_class<T,Alloc>& rhs){
	if(lhs.size() != rhs.size())
		return false;
	for(typename My_class<T, Alloc>::size_type i = 0; i < lhs.size(); ++i)
		if (*(lhs.ptr + i) != *(rhs.ptr + 1))
			return false;
	return true;
}

template< class T, class Alloc >
inline bool operator!=(const My_class<T,Alloc>& lhs, const My_class<T,Alloc>& rhs){ return !(lhs == rhs); }

template< class T, class Alloc >
inline bool operator<(const My_class<T,Alloc>& lhs, const My_class<T,Alloc>& rhs){
	typename My_class<T, Alloc>::const_iterator lit_b = lhs.begin();
	typename My_class<T, Alloc>::const_iterator rit_b = rhs.begin();
	for(typename My_class<T, Alloc>::size_type i = 0; i < lhs.size(); ++i){
		if ((rit_b + i) != rhs.end() && *(lit_b + i) < *(rit_b + i))
			return true;
	}
	return false;
}

template< class T, class Alloc >
inline bool operator<=(const My_class<T,Alloc>& lhs, const My_class<T,Alloc>& rhs){ return !(lhs > rhs); }

template< class T, class Alloc >
inline bool operator>(const My_class<T,Alloc>& lhs, const My_class<T,Alloc>& rhs){
	typename My_class<T, Alloc>::const_iterator lit_b = lhs.begin();
	typename My_class<T, Alloc>::const_iterator rit_b = rhs.begin();
	for(typename My_class<T, Alloc>::size_type i = 0; i < lhs.size(); ++i){
		if ((rit_b + i) == rhs.end() || *(lit_b + i) > *(rit_b + i))
			return true;
	}
	return false;
}

template< class T, class Alloc >
inline bool operator>=(const My_class<T,Alloc>& lhs, const My_class<T,Alloc>& rhs){ return !(lhs < rhs); }
