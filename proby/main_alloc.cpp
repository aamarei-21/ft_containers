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
//	namespace ft = std;
std::vector<int> v;
ft::vector<int> vector;
for (int i = 0; i < 99000000; ++i)
	vector.push_back(i);
g_start2 = timer();
v.push_back(*(vector.erase(vector.begin() + 80000, vector.end() - 15000000)));
g_end2 = timer();
v.push_back(*(vector.begin() + 82000));
v.push_back(vector.size());
v.push_back(vector.capacity());

	std::cout << std::difftime(g_end2, g_start2) << std::endl;

//	std::string line;
//	char c;
//	int key, pos = 0;
//	std:: ifstream kin("./key.txt");
//
//	::map<int, int> mm;
////	mm.insert(::pair<int,int>(0, 10));
//	mm.insert(::pair<int,int>(10, 10));
//	mm.insert(::pair<int,int>(20, 10));
//	mm.insert(::pair<int,int>(30, 10));
//	mm.insert(::pair<int,int>(40, 10));
//	mm.insert(::pair<int,int>(50, 10));
//	mm.insert(::pair<int,int>(60, 10));
//	mm.insert(::pair<int,int>(70, 10));
//	mm.insert(::pair<int,int>(80, 10));
//	mm.insert(::pair<int,int>(90, 10));
//	mm.insert(::pair<int,int>(100, 10));
//
//	::map<int, int>::iterator it;
//	::pair<map<int, int>::iterator, map<int, int>::iterator> ret;
//	it = mm.upper_bound(20);
//	std::cout << "mm.upper_bound = " << it->first << std::endl;
//
//	ret = mm.equal_range(10);
//	std::cout << "lower bound points to: ";
//	std::cout << ret.first->first << " => " << ret.first->second << '\n';
//
//	std::cout << "upper bound points to: ";
//	std::cout << ret.second->first << " => " << ret.second->second << '\n';
//

//	mm.erase(20);
//	mm.erase(10);




//	std::cout <<"mm map:\n";
//	mm.print_n();

//	std:: cout << " mm: size = " << mm.size() << std:: endl;
//	mm[12] = 112;
//	std:: cout << mm[12] << " size = " << mm.size() << std:: endl;
//	::map<int, int>::iterator  it_b = mm.begin();
//	::map<int, int>::iterator  it_e = mm.end();
//	++it_b;
//	++it_b;
//	++it_b;
//	++it_b;
//
//	--it_e;
//	--it_e;
//	--it_e;
//	--it_e;
//	::map<int, int> m_cop(it_b, it_e);
//	m_cop = mm;
//	std::cout <<"m_cop map:\n";
//	m_cop.print_n();
//	std:: cout << " m_coop: size = " << m_cop.size() << std:: endl;
//
//	mm.swap(m_cop);
//	std::cout <<"mm map:\n";
//	mm.print_n();
//	std:: cout << " mm: size = " << mm.size() << std:: endl;
//	std::cout <<"m_cop map:\n";
//	m_cop.print_n();
//	std:: cout << " m_coop: size = " << m_cop.size() << std:: endl;
//
//	std:: cout << "count = " << m_cop.count(58) << std:: endl;
//
//	m_cop.clear();
//	std::cout <<"m_cop map:\n";
//	m_cop.print_n();
//	std:: cout << " m_coop: size = " << m_cop.size() << std:: endl;

//
//
//	mm.print_n();
//	mm.erase(60);
//	mm.erase(67);
//	mm.erase(54);


//	kin.close();
//	std:: ifstream in("./key2.txt");
//	pos = 0;
//	if (in.is_open()){
//		while (getline(in, line)){
//			while (pos < line.length()) {
//				key = std::stoi(line.substr(pos, line.find_first_of(" ", pos + 1) - pos));
//				pos = line.find_first_of(" ", pos + 1);
//				std:: cout << "erase = " << key << std:: endl;
//				mm.erase(key);
//				mm.print_n();
////				std:: cin >> c;
//			}
//		}
//	}

//	mm.erase(2);
//
//	mm.print_n();


//	::vector<pair<int, int> > my_vec;
//	std::cout <<my_vec.size() << "   " << my_vec.capacity() << std::endl;
//	my_vec.push_back(pair<int, int>(10,10));
//	std::cout <<my_vec.size() << "   " << my_vec.capacity() << std::endl;
//	my_vec.push_back(pair<int, int>(15,15));
//	std::cout <<my_vec.size() << "   " << my_vec.capacity() << std::endl;
//	my_vec.push_back(pair<int, int>(20,20));
//	std::cout <<my_vec.size() << "   " << my_vec.capacity() << std::endl;
//	my_vec.push_back(pair<int, int>(25,25));
//	std::cout <<my_vec.size() << "   " << my_vec.capacity() << std::endl;

//	::vector<pair<int, int> > myClass;
//	myClass.insert(::pair<int, int>(10, 20));

//	pair<int, float> P(10, 10.5f);
//	pair<int, float> P1;
//	P1 = P;
//	std::cout <<P1.first << "  \n" << P1.second << std::endl;


//	::map<int, int> mm;
//
//
//	mm.insert(::pair<int, int>(10, 20));
//	mm.insert(::pair<int, int>(20, 20));
//
//
//	mm.insert(::pair<int, int>(5, 20));
//	mm.insert(::pair<int, int>(8, 17));
//	mm.insert(::pair<int, int>(9, 19));
//	mm.insert(::pair<int, int>(7, 7));
//	mm.insert(::pair<int, int>(3, 3));
//	mm.insert(::pair<int, int>(2, 2));
//
//
//	std:: cout << "size = " << mm.size() << std::endl;
//
//	mm.erase(10);
//	mm.insert(::pair<int, int>(7, 7));
//
//	std:: cout << "size = " << mm.size() << std::endl;








}

