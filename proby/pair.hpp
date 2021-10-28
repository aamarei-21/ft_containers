//
// Created by Annelle Amarei on 10/27/21.
//

#ifndef PAIR_HPP
#define PAIR_HPP

template <class T1, class T2>
struct pair{

	typedef T1		first_type;
	typedef T2		second_type;

	first_type		first;
	second_type 	second;

	pair() : first(first_type()), second(second_type()) {}
	template<class U, class V>
	pair (const pair<U,V>& pr) { first = (first_type) pr.first; second = (second_type) pr.second; };
	pair (const first_type& a, const second_type& b) : first(a), second(b) {};

	pair& operator= (const pair& pr){ first = pr.first; second = pr.second; }

	/************************************************************/
	/*****************Non-member functions***********************/
	/************************************************************/

	template< class V1, class V2 >
	friend bool operator==( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs );

	template< class V1, class V2 >
	friend bool operator!=( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs );

	template< class V1, class V2 >
	friend bool operator<( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs );

	template< class V1, class V2 >
	friend bool operator<=( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs );

	template< class V1, class V2 >
	friend bool operator>( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs );

	template< class V1, class V2 >
	friend bool operator>=( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs );

};

template< class V1, class V2 >
bool operator==( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs ){
	return lhs.first == rhs.first && lhs.second == rhs.second;
}

template< class V1, class V2 >
bool operator!=( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs ){ return !(lhs == rhs); }

template< class V1, class V2 >
bool operator<( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs ){
	return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template< class V1, class V2 >
bool operator<=( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs ) { return !(lhs < rhs); }

template< class V1, class V2 >
bool operator>( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs ){ return rhs < lhs; }

template< class V1, class V2 >
bool operator>=( const pair<V1,V2>& lhs, const pair<V1,V2>& rhs ) { return  !(lhs > rhs); }

#endif //PAIR_HPP
