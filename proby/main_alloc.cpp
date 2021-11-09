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
	namespace ft = std;
ft::vector<int> vect;
ft::vector<int> outvect(10);
for (int i = 0; i < 10; ++ i)
	outvect[i] = i * 5;
for (int i = 0; i < 10; ++i)
	std:: cout << outvect[i] << ",  ";
std::cout <<std::endl;

vect.push_back(100);
ft::vector<int>::iterator it_b;
ft::vector<int>::iterator it_e;
ft::vector<int>::iterator it;
//for (int i = 0; i < 10; ++i)
//	vect[i] = i;

it_b = ++outvect.begin();
it_e = --outvect.end();
it = vect.begin();

//for (int i = 0; i < 10; ++i)
//	std:: cout << vect[i] << ",  ";
std:: cout << std::endl;
std:: cout << "size = " << vect.size() << ", capacity = " << vect.capacity() << std:: endl;
//++it;
//++it;
//++it;
//std:: cout << "*it = " << *it << std::endl;
vect.insert(it, it_b, it_e);
for (int i = 0; i < vect.size(); ++i)
	std:: cout << vect[i] << ",  ";
std:: cout << std::endl;
std:: cout << "size = " << vect.size() << ", capacity = " << vect.capacity() << std:: endl;
//std:: cout << "*it = " << *it << std::endl;



}

