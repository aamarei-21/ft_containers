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


#include "common.hpp"
#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif


#define TESTED_TYPE int

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
				   TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
				   {
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
				   }

int		main(void)
{
	std::vector<int> v;
	ft::map<int, int> mp;
	v.push_back(mp.erase(3));
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	ft::map<int, int>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(mp.erase(-5));
	v.push_back(mp.size());
	v.push_back(mp.erase(0));
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	ft::map<int, int>::iterator it4 = mp.begin();
	g_start2 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4->first);
	g_end2 = timer();
	ft::map<int, int>::iterator it2 = mp.end();
	it2--;
	v.push_back(mp.erase(299999));
	v.push_back(mp.size());
	ft::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(ft::make_pair(i, j));
	mp2.erase(2);
	mp2.erase(7);
	ft::map<int, int>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}

}

