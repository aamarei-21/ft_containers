#include "Vector.hpp"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include "Iterator.hpp"

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

int main()
{

	std::vector<int> f(6, 9);
	f[2] = 155;
	std::vector<int> mv(f.begin(), f.end());
	std::vector<int>::reverse_iterator f_it_b = f.rbegin();
	std::vector<int>::reverse_iterator f_it_e = f.rend();

	f_it_b = 2 + f_it_b;
	std::cout << (f_it_e - f_it_b) << std::endl;

	//f.insert(f_it_b, 155);




	//std::vector<int>::iterator f_it_e = f.end();
	//f_it_b[3] = 155;
	//f_it_b += 3;
	//std::cout << (++f_it_b + 2 < f_it_e) << std::endl;
	//std::vector<int>::iterator f_it_e = f.end();
	//std::vector<int> s(4, 12);
	//s.push_back(7);

	//s.swap(f);
	//s[1] = 5;
	//std::cout << (s > f) << std::endl;
	//std::vector<int>::iterator it;
	//f.push_back(8);

	//for(std::vector<int>::iterator it = f_it_b; it != f_it_e; ++it)
	//	std::cout <<*it << ", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl << std::endl;

	//for(std::vector<int>::iterator it = s.begin(); it != s.end(); ++it)
	//	std::cout <<*it << ", ";
	//std::cout << std::endl << "s.size() = " << s.size() << ", s.capacity() = " << s.capacity() << std::endl << std::endl;
	//std::cout << s[5] << std::endl;


	//f.insert(f.begin()-2, s.begin(), s.end());

	//for(std::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl<< std::endl;
	//std::cout << *it << std::endl;

	//f.push_back(1000);
	//for(std::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl<< std::endl;

	//it = f.erase(f.begin() +2, f.begin() +2);
	//for(std::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl;
	//std::cout << "*it = " << *it << std::endl << f[5] << std::endl;

	//f.clear();

	//f.pop_back();

	//for(std::vector<int>::iterator it = f.begin(); it != f.end() + 8; ++it)
	//	std::cout << *it <<", ";
	//std::cout << std::endl << "f.size() = " << f.size() << ", f.capacity() = " << f.capacity() << std::endl;
	//std::cout << f[10] << std::endl;



}

