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
};


#endif //PAIR_HPP
