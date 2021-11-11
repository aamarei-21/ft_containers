#include "vector.hpp"
#include <string>
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include "vector_Iterator.hpp"
#include "pair.hpp"
#include "map.hpp"
#include <map>
#include <string>
#include <fstream>
#include "stack.hpp"

template <class C>
void    print(C& c)
{
    for (typename C::iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " " << std::endl;
    std::cout << std::endl;
    std::cout << "size: " << c.size() << std::endl;
    std::cout << "cap : " << c.capacity() << std::endl;
}

class Proba
{
private:
	int			num;
	std::string	str;
public:
	Proba() : num(5), str("_Hello_") {}
	Proba(int const& x, std::string const& str) : num(x), str(str) {}
	friend std::ostream& operator<<(std::ostream &out, Proba const arg);
};

std::ostream& operator<<(std::ostream& out, Proba const arg)
{
	out << "num = " << arg.num <<",_str = " << arg.str;
	return out;
}

//class A {
//public:
//   int i;
//   int *a;
//
//   void print() const {
//      for (int c = 0; c < 5; c++)
//         std::cout << a[c] << std::endl;
//   }
//   A() : i(1), a(new int[5]()) {
//      for (int c = 0; c < 5; c++)
//         a[c] = c;
//      std::cout << "const" << std::endl; };
//   A(A const &r) : i(r.i), a(new int[5]()) {
//      for (int t = 0; t < 5; t++)
//         a[t] = r.a[t];
//      std::cout << "copy const" << std::endl; };
//   ~A() { std::cout << "des" << std::endl; delete [] a; }
//};

#include <sys/time.h>

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}





class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

time_t g_start1;
time_t g_end1;
time_t g_start2;
time_t g_end2;


#include "/Users/aamarei/IRR/level_6/ft_container/proby/containers_test/srcs/map/common.hpp"
#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif




#define T1 char
#define T2 foo<float>
typedef TESTED_NAMESPACE::map<T1, T2> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;


void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

int		main(void)
{
	_map	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;
	printSize(mp);

	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
			ft_comp(mp, it1, it2);

		printSize(mp);
		return (0);


}

