#include "vector.hpp"
#include <string>
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include "Iterator.hpp"
#include "pair.hpp"
//#include "map.hpp"
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


int main()
{
//	namespace ft = std;
	ft::stack<int> stk;
	std::vector<int> v;
	ft::vector<int> deque;
	for (int i = 0; i < 1000000; ++i)
		deque.push_back(i);
	for (int i = 1000000; i < 2000000; ++i)
		stk.push(i);
	g_start2 = timer();
	ft::stack<int> stack(deque);
	ft::stack<int> stack2(stk);
	ft::stack<int> stack3;
	stack3 = stack2;
	g_end2 = timer();
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}



}

