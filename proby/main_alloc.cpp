#include "Vector.hpp"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include "Iterator.hpp"
#include "pair.hpp"
#include "map.hpp"
#include <map>

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

class A {
public:
   int i;
   int *a;

   void print() const {
      for (int c = 0; c < 5; c++)
         std::cout << a[c] << std::endl;
   }
   A() : i(1), a(new int[5]()) {
      for (int c = 0; c < 5; c++)
         a[c] = c;
      std::cout << "const" << std::endl; };
   A(A const &r) : i(r.i), a(new int[5]()) {
      for (int t = 0; t < 5; t++)
         a[t] = r.a[t];
      std::cout << "copy const" << std::endl; };
   ~A() { std::cout << "des" << std::endl; delete [] a; }
};

int main()
{
	My_class<int> myClass;
	pair<int, float> P(10, 10.5f);
	pair<int, float> P1;
	P1 = P;
	std::cout <<P1.first << "  \n" << P1.second << std::endl;


	map<int, int> *mm;


	mm->insert(pair<int, int>(10, 20));

	std:: cout << mm->size() << std::endl;

//	mm->insert(std::pair<int, std::string>(10, "PR10"));
//	mm->insert(std::pair<int, std::string>(15, "PR15"));
//	mm->insert(std::pair<int, std::string>(5, "PR5"));


//	std::map<int, float> *mmm;
//
//	std::cout << mm << std::endl << mmm << std::endl;
//
//	std::map<int, float>::iterator it;
//	std::map<int, float>::reverse_iterator r_it;
//
//	it = ++it;


//	std::vector<A> f(6, A());
//	int d = 8;
//
//	f.resize(d);
//
//	std::cout << f.size() << std::endl;
//	std::cout << f.capacity() << std::endl;

	//f[2] = 155;
	//::My_class<const int> mv(f.begin(), f.end());
	//::My_class<int>::const_iterator f_it_b = f.begin();
	//::My_class<int>::const_iterator f_it_e = f.end();
	//::My_class<int>::const_iterator f_it = 2 + f_it_b;

	//f_it_e = 2 + f_it_b;
	//std::cout << (f_it_b == f_it_e) << std::endl;

	//f.insert(f_it_b, 155);




	//std::My_class<int>::iterator f_it_e = f.end();
	//f_it_b[3] = 155;
	//f_it_b += 3;
	//std::cout << (++f_it_b + 2 < f_it_e) << std::endl;
	//std::My_class<int>::iterator f_it_e = f.end();
	//std::My_class<int> s(4, 12);
	//s.push_back(7);

	//s.swap(f);
	//s[1] = 5;
	//std::cout << (s > f) << std::endl;
	//std::My_class<int>::iterator it;
	//f.push_back(8);

	//for(std::My_class<int>::iterator it = f_it_b; it != f_it_e; ++it)
	//	std::cout <<*it << ", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl << std::endl;

	//for(std::My_class<int>::iterator it = s.begin(); it != s.end(); ++it)
	//	std::cout <<*it << ", ";
	//std::cout << std::endl << "s.size() = " << s.size() << ", s.capacity() = " << s.capacity() << std::endl << std::endl;
	//std::cout << s[5] << std::endl;


	//f.insert(f.begin()-2, s.begin(), s.end());

	//for(std::My_class<int>::iterator it = f.begin(); it != f.end(); ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl<< std::endl;
	//std::cout << *it << std::endl;

	//f.push_back(1000);
	//for(std::My_class<int>::iterator it = f.begin(); it != f.end(); ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl<< std::endl;

	//it = f.erase(f.begin() +2, f.begin() +2);
	//for(std::My_class<int>::iterator it = f.begin(); it != f.end(); ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl;
	//std::cout << "*it = " << *it << std::endl << f[5] << std::endl;

	//f.clear();

	//f.pop_back();

	//for(std::My_class<int>::iterator it = f.begin(); it != f.end() + 8; ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl;
	//std::cout << f[10] << std::endl;



}

