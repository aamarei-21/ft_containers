#include "Iterator.hpp"
/* ==================== Randomiterator ================*/
template <class T>
inline Randomiterator<T>::Randomiterator() {}

template <class T>
inline Randomiterator<T>::Randomiterator(pointer x) :  ptr(x) {}

template<class T>
inline Randomiterator<T>::Randomiterator(const Randomiterator& iter) : ptr(iter.ptr) {}

template<class T>
inline Randomiterator<T>& Randomiterator<T>::operator++() { ++ptr; return *this; }

template<class T>
inline Randomiterator<T>& Randomiterator<T>::operator++(int) {Randomiterator tmp(*this); ++ptr; return tmp; }

template<class T>
inline Randomiterator<T>& Randomiterator<T>::operator--() { --ptr; return *this; }

template<class T>
inline Randomiterator<T> Randomiterator<T>::operator--(int) {Randomiterator tmp(*this); --(*this); return tmp; }

template<class T>
inline Randomiterator<T> Randomiterator<T>::operator+(size_t const& x)
{
	Randomiterator temp(ptr);
	std::advance(temp.ptr, x);
	return temp;
}

template<class T>
inline Randomiterator<T> Randomiterator<T>::operator+=(int const& x) { ptr += x; return *this; }

template<class T>
inline Randomiterator<T> Randomiterator<T>::operator-(int const& x) { Randomiterator temp(ptr - x); return temp; }

template<class T>
inline Randomiterator<T> Randomiterator<T>::operator-=(int const& x) { ptr -= x; return *this; }

template<class T>
inline T& Randomiterator<T>::operator*() { return *ptr; }

template<class T>
inline T* Randomiterator<T>::operator->() { return ptr; }

template<class T>
inline typename Randomiterator<T>::reference Randomiterator<T>::
		operator[](typename Randomiterator<T>::difference_type n){
	return *(ptr + n);
}

template<class T>
inline Randomiterator<T>& Randomiterator<T>::operator=(Randomiterator const& x)
	{
		if (this == &x)
			return *this;
		ptr = x.ptr;
		return *this;
	}

/**********************************************************************/
/***********************  Non-member functions  ***********************/
/**********************************************************************/
template<class V>
inline bool operator==(Randomiterator<V> const& larg, Randomiterator<V> const& rarg){ return larg.ptr == rarg.ptr; }

template<class V>
inline bool operator!=(Randomiterator<V> const& larg, Randomiterator<V> const& rarg) { return !(larg == rarg); }

template<class V>
inline bool operator>(Randomiterator<V> const& larg, Randomiterator<V> const& rarg) { return larg.ptr > rarg.ptr; }

template<class V>
inline bool operator>=(Randomiterator<V> const& larg, Randomiterator<V> const& rarg){ return !(larg < rarg); }

template<class V>
inline bool operator<(Randomiterator<V> const& larg, Randomiterator<V> const& rarg) { return larg.ptr < rarg.ptr; }

template<class V>
inline bool operator<=(Randomiterator<V> const& larg, Randomiterator<V> const& rarg) { return !(larg > rarg); }


/*===============================================================*/
/*========================                  =====================*/
/*======================== Reverse_Iterator =====================*/
/*========================.                 =====================*/
/*===============================================================*/


template<class Iter>
inline Reverse_Iterator<Iter>::Reverse_Iterator() : _itr() { }

template<class Iter>
inline Reverse_Iterator<Iter>::Reverse_Iterator(Iter x) : _itr(x) {}

template<class Iter>
inline Reverse_Iterator<Iter>::Reverse_Iterator(const Reverse_Iterator& other) : _itr(other._itr) {}

template<class Iter>
inline Iter Reverse_Iterator<Iter>::base() const { return _itr; }

template<class Iter>
inline Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator=( const Reverse_Iterator& other) {
	if (this == &other)
		return *this;
	_itr = other._itr;
	return *this;
}

template<class Iter>
inline typename Reverse_Iterator<Iter>::reference Reverse_Iterator<Iter>::operator*() const {
	return *(this->base() - 1);
}

template<class Iter>
inline typename Reverse_Iterator<Iter>::pointer Reverse_Iterator<Iter>::operator->() const {
	return &(operator*()) ;
}

template<class Iter>
inline typename Reverse_Iterator<Iter>::reference Reverse_Iterator<Iter>::
	operator[](typename iterator_traits<Iter>::difference_type n) const {
		return *(this->base() - n - 1);
}

template<class Iter>
inline Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator++() {
	--base();
	return *this;
}

template<class Iter>
inline Reverse_Iterator<Iter> Reverse_Iterator<Iter>::operator++(int) {
	Reverse_Iterator temp(*this);
	++(*this);
	return temp;
}

template<class Iter>
inline Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator--() {
	++base();
	return *this;
}

template<class Iter>
inline Reverse_Iterator<Iter> Reverse_Iterator<Iter>::operator--(int) {
	Reverse_Iterator temp(*this);
	--(*this);
	return temp;
}

template<class Iter>
inline Reverse_Iterator<Iter> Reverse_Iterator<Iter>::
		operator+(typename iterator_traits<Iter>::difference_type n) const{
	return Reverse_Iterator(base() - n);
}

template<class Iter>
inline Reverse_Iterator<Iter> Reverse_Iterator<Iter>::
		operator-(typename iterator_traits<Iter>::difference_type n) const{
	return Reverense_Iterator(base() + n);
}

template<class Iter>
inline Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::
		operator+=(typename iterator_traits<Iter>::difference_type n){
	return ++(*this);
}

template<class Iter>
inline Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::
		operator-=(typename iterator_traits<Iter>::difference_type n){
	return --(*this);
}

/*======================================================================*/
/*=======================  Non-member functions  =======================*/
/*======================================================================*/
	template <class Iterator>
	inline bool operator==(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); }

	template <class Iterator>
	inline bool operator!=(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs) { return lhs.base() != rhs.base(); }

	template <class Iterator>
	inline bool operator<(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs) { return lhs.base() > rhs.base(); }

	template <class Iterator>
	inline bool operator<=(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs) { return lhs.base() >= rhs.base(); }

	template <class Iterator>
	inline bool operator>(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs) { return lhs.base() < rhs.base (); }

	template <class Iterator>
	inline bool operator>=(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs) { return lhs.base() <= rhs.base(); }

	template <class Iterator>
	inline Reverse_Iterator<Iterator> operator+ (typename Reverse_Iterator<Iterator>::difference_type n,
			const Reverse_Iterator<Iterator>& rev_it) { return rev_it + n; }

	template <class Iterator>
	inline typename Reverse_Iterator<Iterator>::difference_type operator-(const Reverse_Iterator<Iterator>& lhs, const Reverse_Iterator<Iterator>& rhs){
		return rhs.base() - lhs.base();
	}











