#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include<iostream>
#include <fstream>
#include <string>
#include <cstddef>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

void comparison(char* str)
{
	if(system(str) == 0)
		std::cout << "\033[32m[OK] \033[m";
	else
		std::cout << "\033[31m[KO] \033[m";
	std::cout << std::flush;
}


int	main(void) {
	std::ofstream f_std;
	std::ofstream f_ft;

/* ****************************************************************************** */
/* ***************************** V E C T O R ************************************ */
/* ****************************************************************************** */
	std::cout << "\033[31m*********** V E C T O R ************* \033[m" << std::endl;

	{
		std::cout << "  constructor:\t\t\t";

		{
			f_std.open("./logs/f_std_constr");
			std::vector<int> vec;
			vec.push_back(10);
			std::vector<int> vec1(vec);
			for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
				f_std << *it << " ";
			f_std << vec1.size() << " " << vec.capacity() << " ";
			for (int i = 0; i < 1200000; ++i)
				vec1.push_back(i * 2);
			std::vector<int>::iterator it_b = vec1.begin();
			std::vector<int>::iterator it_e = vec1.end();
			it_b += 10000;
			it_e -= 120000;
			std::vector<int> vec2(it_b, it_e);
			for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
				f_std << *it << " ";
			f_std << vec2.size() << " " << vec2.capacity() << " ";
			std::vector<int> vec3(10, 15);
			for (std::vector<int>::iterator it = vec3.begin(); it != vec3.end(); ++it)
				f_std << *it << " ";
			f_std << vec3.size() << " " << vec3.capacity() << " ";
			f_std.close();
		}

		{
			f_ft.open("./logs/f_ft_constr");
			ft::vector<int> vec;
			vec.push_back(10);
			ft::vector<int> vec1(vec);
			for (ft::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
				f_ft << *it << " ";
			f_ft << vec1.size() << " " << vec.capacity() << " ";
			for (int i = 0; i < 1200000; ++i)
				vec1.push_back(i * 2);
			ft::vector<int>::iterator it_b = vec1.begin();
			ft::vector<int>::iterator it_e = vec1.end();
			it_b += 10000;
			it_e -= 120000;
			ft::vector<int> vec2(it_b, it_e);
			for (ft::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
				f_ft << *it << " ";
			f_ft << vec2.size() << " " << vec2.capacity() << " ";
			ft::vector<int> vec3(10, 15);
			for (ft::vector<int>::iterator it = vec3.begin(); it != vec3.end(); ++it)
				f_ft << *it << " ";
			f_ft << vec3.size() << " " << vec3.capacity() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_constr ./logs/f_ft_constr");
	}

	{
		std::cout << "\n  Iterators:\t\t\t";
		{
			f_std.open("./logs/f_std_iterators");
			std::vector<int> vec;
			for (int i = 0; i < 10000; ++i)
				vec.push_back(i);
			std::vector<int>::iterator it_b = vec.begin();
			std::vector<int>::iterator it_e = vec.end();
			f_std << *it_b << " " << *(--it_e) << " " << *(it_b++) << " " << *it_b;
			it_b += 100;
			it_b = 100 + it_b;
			it_b = it_b + 12;
			it_b -= 80;
			it_b = it_b - 37;
			f_std << *it_b << " ";
			size_t k = it_e - it_b;
			f_std << k << " ";
			it_e = it_b + 26;
			for (; it_b != it_e; ++it_b)
				f_std << *it_b << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_iterators");
			ft::vector<int> vec;
			for (int i = 0; i < 10000; ++i)
				vec.push_back(i);
			ft::vector<int>::iterator it_b = vec.begin();
			ft::vector<int>::iterator it_e = vec.end();
			f_ft << *it_b << " " << *(--it_e) << " " << *(it_b++) << " " << *it_b;
			it_b += 100;
			it_b = 100 + it_b;
			it_b = it_b + 12;
			it_b -= 80;
			it_b = it_b - 37;
			f_ft << *it_b << " ";
			size_t k = it_e - it_b;
			f_ft << k << " ";
			it_e = it_b + 26;
			for (; it_b != it_e; ++it_b)
				f_ft << *it_b << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_iterators ./logs/f_ft_iterators");
	}
	{
		std::cout << "\n  Revers iterator:\t\t";
		{
			f_std.open("./logs/f_std_reverse_it");
			std::vector<int> vec;
			for (int i = 0; i < 10000; ++i)
				vec.push_back(i);
			std::vector<int>::reverse_iterator it_b = vec.rbegin();
			std::vector<int>::reverse_iterator it_e = vec.rend();
			f_std << *it_b << " " << *(--it_e) << " " << *(it_b++) << " " << *it_b;
			it_b += 100;
			it_b = 100 + it_b;
			it_b = it_b + 12;
			it_b -= 80;
			it_b = it_b - 37;
			f_std << *it_b << " ";
			size_t k = it_e - it_b;
			f_std << k << " ";
			it_e = it_b + 26;
			for (; it_b != it_e; ++it_b)
				f_std << *it_b << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_reverse_it");
			ft::vector<int> vec;
			for (int i = 0; i < 10000; ++i)
				vec.push_back(i);
			ft::vector<int>::reverse_iterator it_b = vec.rbegin();
			ft::vector<int>::reverse_iterator it_e = vec.rend();
			f_ft << *it_b << " " << *(--it_e) << " " << *(it_b++) << " " << *it_b;
			it_b += 100;
			it_b = 100 + it_b;
			it_b = it_b + 12;
			it_b -= 80;
			it_b = it_b - 37;
			f_ft << *it_b << " ";
			size_t k = it_e - it_b;
			f_ft << k << " ";
			it_e = it_b + 26;
			for (; it_b != it_e; ++it_b)
				f_ft << *it_b << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_reverse_it ./logs/f_ft_reverse_it");
	}
	{
		std::cout << "\n  size:\t\t\t\t";
		{
			f_std.open("./logs/f_std_size");
			std::vector<int> vec;
			f_std << vec.size() << " ";
			vec.push_back(50);
			f_std << vec.size() << " ";
			std::vector<int> vec1(30000000, 123);
			std::vector<int>::iterator it_b = vec1.begin();
			for (; it_b != vec1.end(); ++it_b)
				vec.push_back(*it_b);
			f_std << vec.size() << " ";
			for (int i = 0; i < 100000; ++i)
				vec.pop_back();
			f_std << vec.size() << " ";
			it_b = vec.begin() + 500000;
			vec.insert(it_b, 1000, 300);
			f_std << vec.size() << " ";
			it_b = vec.begin() + 10000;
			vec.insert(it_b, vec1.begin() + 90000, vec1.end() - 10000000);
			f_std << vec.size() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_size");
			ft::vector<int> vec;
			f_ft << vec.size() << " ";
			vec.push_back(50);
			f_ft << vec.size() << " ";
			ft::vector<int> vec1(30000000, 123);
			ft::vector<int>::iterator it_b = vec1.begin();
			for (; it_b != vec1.end(); ++it_b)
				vec.push_back(*it_b);
			f_ft << vec.size() << " ";
			for (int i = 0; i < 100000; ++i)
				vec.pop_back();
			f_ft << vec.size() << " ";
			it_b = vec.begin() + 500000;
			vec.insert(it_b, 1000, 300);
			f_ft << vec.size() << " ";
			it_b = vec.begin() + 10000;
			vec.insert(it_b, vec1.begin() + 90000, vec1.end() - 10000000);
			f_ft << vec.size() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_size ./logs/f_ft_size");
	}
	{
		std::cout << "\n  resize:\t\t\t";
		{
			f_std.open("./logs/f_std_resize");
			std::vector<int> vec(150);
			f_std << vec.size() << " ";
			vec.resize(800, 112);
			for (std::vector<int>::iterator it_b = vec.begin(); it_b != vec.end(); ++it_b)
				f_std << *it_b << " ";
			f_std << vec.size() << " ";
			vec.resize(100, 50);
			for (std::vector<int>::iterator it_b = vec.begin(); it_b != vec.end(); ++it_b)
				f_std << *it_b << " ";
			f_std << vec.size() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_resize");
			ft::vector<int> vec(150);
			f_ft << vec.size() << " ";
			vec.resize(800, 112);
			for (ft::vector<int>::iterator it_b = vec.begin(); it_b != vec.end(); ++it_b)
				f_ft << *it_b << " ";
			f_ft << vec.size() << " ";
			vec.resize(100, 50);
			for (ft::vector<int>::iterator it_b = vec.begin(); it_b != vec.end(); ++it_b)
				f_ft << *it_b << " ";
			f_ft << vec.size() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_resize ./logs/f_ft_resize");
	}
	{
		std::cout << "\n  capacity:\t\t\t";
		{
			f_std.open("./logs/f_std_capacity");
			std::vector<int> vec;
			f_std << vec.capacity() << " ";
			vec.push_back(50);
			f_std << vec.capacity() << " ";
			std::vector<int> vec1(30000000, 123);
			std::vector<int>::iterator it_b = vec1.begin();
			for (; it_b != vec1.end(); ++it_b)
				vec.push_back(*it_b);
			f_std << vec.capacity() << " ";
			for (int i = 0; i < 100000; ++i)
				vec.pop_back();
			f_std << vec.capacity() << " ";
			it_b = vec.begin() + 500000;
			vec.insert(it_b, 1000, 300);
			f_std << vec.capacity() << " ";
			it_b = vec.begin() + 10000;
			vec.insert(it_b, vec1.begin() + 90000, vec1.end() - 10000000);
			f_std << vec.capacity() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_capacity");
			ft::vector<int> vec;
			f_ft << vec.capacity() << " ";
			vec.push_back(50);
			f_ft << vec.capacity() << " ";
			ft::vector<int> vec1(30000000, 123);
			ft::vector<int>::iterator it_b = vec1.begin();
			for (; it_b != vec1.end(); ++it_b)
				vec.push_back(*it_b);
			f_ft << vec.capacity() << " ";
			for (int i = 0; i < 100000; ++i)
				vec.pop_back();
			f_ft << vec.capacity() << " ";
			it_b = vec.begin() + 500000;
			vec.insert(it_b, 1000, 300);
			f_ft << vec.capacity() << " ";
			it_b = vec.begin() + 10000;
			vec.insert(it_b, vec1.begin() + 90000, vec1.end() - 10000000);
			f_ft << vec.capacity() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_capacity ./logs/f_ft_capacity");
	}
	{
		std::cout << "\n  empty:\t\t\t";
		{
			f_std.open("./logs/f_std_empty");
			std::vector<int> vec;
			f_std << vec.empty() << " ";
			vec.push_back(155);
			f_std << vec.empty() << " ";
			vec.pop_back();
			f_std << vec.empty() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_empty");
			ft::vector<int> vec;
			f_ft << vec.empty() << " ";
			vec.push_back(155);
			f_ft << vec.empty() << " ";
			vec.pop_back();
			f_ft << vec.empty() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_empty ./logs/f_ft_empty");
	}
	{
		std::cout << "\n  reserve:\t\t\t";
		{
			f_std.open("./logs/f_std_reserve");
			std::vector<int> vec;
			f_std << vec.size() << " " << vec.capacity() << " ";
			vec.reserve(150);
			f_std << vec.size() << " " << vec.capacity() << " ";
			std::vector<int> vec1(1000, 2);
			f_std << vec1.size() << " " << vec1.capacity() << " ";
			vec.reserve(50);
			f_std << vec1.size() << " " << vec1.capacity() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_reserve");
			ft::vector<int> vec;
			f_ft << vec.size() << " " << vec.capacity() << " ";
			vec.reserve(150);
			f_ft << vec.size() << " " << vec.capacity() << " ";
			ft::vector<int> vec1(1000, 2);
			f_ft << vec1.size() << " " << vec1.capacity() << " ";
			vec.reserve(50);
			f_ft << vec1.size() << " " << vec1.capacity() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_reserve ./logs/f_ft_reserve");
	}
	{
		std::cout << "\n  operator[]\t\t\t";
		{
			f_std.open("./logs/f_std_operator[]");
			std::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_std << vec[0] << " " << vec[10] << " " << vec[1000] << " ";
			vec[500] = 951;
			f_std << vec[500];
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_operator[]");
			ft::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_ft << vec[0] << " " << vec[10] << " " << vec[1000] << " ";
			vec[500] = 951;
			f_ft << vec[500];
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_operator[] ./logs/f_ft_operator[]");
	}
	{
		std::cout << "\n  at\t\t\t\t";
		{
			f_std.open("./logs/f_std_at");
			std::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_std << vec.at(0) << " " << vec.at(10) << " " << vec.at(1000) << " ";
			vec.at(500) = 951;
			f_std << vec.at(500);
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_at");
			ft::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_ft << vec.at(0) << " " << vec.at(10) << " " << vec.at(1000) << " ";
			vec.at(500) = 951;
			f_ft << vec.at(500);
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_at ./logs/f_ft_at");
	}
	{
		std::cout << "\n  front\t\t\t\t";
		{
			f_std.open("./logs/f_std_front");
			std::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_std << vec.front() << " ";
			vec.front() -=  vec.back();
			f_std << vec.front() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_front");
			ft::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_ft << vec.front() << " ";
			vec.front() -=  vec.back();
			f_ft << vec.front() << " ";
			f_ft.close();

		}
		comparison((char *) "diff ./logs/f_std_front ./logs/f_ft_front");
	}
	{
		std::cout << "\n  back\t\t\t\t";
		{
			f_std.open("./logs/f_std_back");
			std::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_std << vec.back() << " ";
			vec.back() -=  vec.back();
			f_std << vec.back() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_back");
			ft::vector<int> vec;
			for (int i = 150; i < 1500 ; ++i)
				vec.push_back(i * 2);
			f_ft << vec.back() << " ";
			vec.back() -=  vec.back();
			f_ft << vec.back() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_back ./logs/f_ft_back");
	}
	{
		std::cout << "\n  data\t\t\t\t";
		{
			f_std.open("./logs/f_std_data");
			std::vector<int> myvector (5);
			int* p = myvector.data();
			*p = 10;
			++p;
			*p = 20;
			p[2] = 100;
			for (unsigned i=0; i<myvector.size(); ++i)
				f_std << myvector[i] << " " << *p << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_data");
			ft::vector<int> myvector (5);
			int* p = myvector.data();
			*p = 10;
			++p;
			*p = 20;
			p[2] = 100;
			for (unsigned i=0; i<myvector.size(); ++i)
				f_ft << myvector[i] << " " << *p << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_data ./logs/f_ft_data");
	}
	{
		std::cout << "\n  assign\t\t\t";
		{
			f_std.open("./logs/f_std_assign");
			std::vector<int> vec1;
			vec1.assign(12,123);
			for (std::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_std << *it_b << " ";
			f_std << vec1.size() << " " << vec1.capacity();
			std::vector<int> vec2(120, 10);
			vec2.assign(vec2.begin() + 1, vec2.end() - 3);
			for (std::vector<int>::iterator it_b = vec2.begin(); it_b != vec2.end(); ++it_b)
				f_std << *it_b << " ";
			f_std << vec2.size() << " " << vec2.capacity();
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_assign");
			ft::vector<int> vec1;
			vec1.assign(12,123);
			for (ft::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_ft << *it_b << " ";
			f_ft << vec1.size() << " " << vec1.capacity();
			ft::vector<int> vec2(120, 10);
			vec2.assign(vec2.begin() + 1, vec2.end() - 3);
			for (ft::vector<int>::iterator it_b = vec2.begin(); it_b != vec2.end(); ++it_b)
				f_ft << *it_b << " ";
			f_ft << vec2.size() << " " << vec2.capacity();
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_assign ./logs/f_ft_assign");
	}
	{
		std::cout << "\n  push_back\t\t\t";
		{
			f_std.open("./logs/f_std_push_back");
			std::vector<int> vec1;
			for (int i = 0; i < 3000000; ++i) {
				vec1.push_back(i * 3);
			}
			for (std::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_std << *it_b << " ";
			f_std << vec1.size() << " " << vec1.capacity();
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_push_back");
			ft::vector<int> vec1;
			for (int i = 0; i < 3000000; ++i) {
				vec1.push_back(i * 3);
			}
			for (ft::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_ft << *it_b << " ";
			f_ft << vec1.size() << " " << vec1.capacity();
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_push_back ./logs/f_ft_push_back");
	}
	{
		std::cout << "\n  pop_back\t\t\t";
		{
			f_std.open("./logs/f_std_pop_back");
			std::vector<int> vec1;
			for (int i = 0; i < 3000000; ++i) {
				vec1.push_back(i * 3);
			}
			vec1.pop_back();
			vec1.pop_back();
			for (std::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_std << *it_b << " ";
			f_std << vec1.size() << " " << vec1.capacity();
			while (!vec1.empty())
				vec1.pop_back();
			f_std << vec1.size() << " " << vec1.capacity();
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_pop_back");
			ft::vector<int> vec1;
			for (int i = 0; i < 3000000; ++i) {
				vec1.push_back(i * 3);
			}
			vec1.pop_back();
			vec1.pop_back();
			for (ft::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_ft << *it_b << " ";
			f_ft << vec1.size() << " " << vec1.capacity();
			while (!vec1.empty())
				vec1.pop_back();
			f_ft << vec1.size() << " " << vec1.capacity();
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_pop_back ./logs/f_ft_pop_back");
	}
	{
		std::cout << "\n  insert:\t\t\t";
		{
			f_std.open("./logs/f_std_insert");
			std::vector<int> vec;
			std::vector<int>::iterator it;
			for (int i = 50; i < 100; ++i) {
				it = vec.begin();
				vec.insert(it, i * 3);
			}
			it = vec.begin();
			for (std::vector<int>::iterator it_b = it; it_b != vec.end(); ++it_b)
				f_std << *it_b << " ";
			vec.insert(vec.begin(), 25, 100);
			it = vec.begin();
			for (std::vector<int>::iterator it_b = it; it_b != vec.end(); ++it_b)
				f_std << *it_b << " ";
			std::vector<int> vec1(5, 8);
			vec1.insert(vec1.begin() + 2, vec.begin() + 15, vec.end() - 25);
			for (std::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_std << *it_b << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_insert");
			ft::vector<int> vec;
			ft::vector<int>::iterator it;
			for (int i = 50; i < 100; ++i) {
				it = vec.begin();
				vec.insert(it, i * 3);
			}
			it = vec.begin();
			for (ft::vector<int>::iterator it_b = it; it_b != vec.end(); ++it_b)
				f_ft << *it_b << " ";
			vec.insert(vec.begin(), 25, 100);
			it = vec.begin();
			for (ft::vector<int>::iterator it_b = it; it_b != vec.end(); ++it_b)
				f_ft << *it_b << " ";
			ft::vector<int> vec1(5, 8);
			it = vec1.begin() + 2;
			vec1.insert(it, vec.begin() + 15, vec.end() - 25);
			for (ft::vector<int>::iterator it_b = vec1.begin(); it_b != vec1.end(); ++it_b)
				f_ft << *it_b << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_insert ./logs/f_ft_insert");
	}
	{
		std::cout << "\n  erase:\t\t\t";
		{
			f_std.open("./logs/f_std_erase");
			std::vector<int> vec;
			std::vector<int>::iterator it;
			for (int i = 50; i < 10000; ++i) {
				vec.push_back(i * 3);
			}
			vec.erase(vec.begin() + 500);
			vec.erase(vec.begin() + 25, vec.end() - 25);
			for (std::vector<int>::iterator it_b = vec.begin(); it_b != vec.end(); ++it_b)
				f_std << *it_b << " ";
			vec.erase(vec.begin(), vec.end());
			f_std << vec.size() << " " << vec.capacity() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_erase");
			ft::vector<int> vec;
			ft::vector<int>::iterator it;
			for (int i = 50; i < 10000; ++i) {
				vec.push_back(i * 3);
			}
			vec.erase(vec.begin() + 500);
			vec.erase(vec.begin() + 25, vec.end() - 25);
			for (ft::vector<int>::iterator it_b = vec.begin(); it_b != vec.end(); ++it_b)
				f_ft << *it_b << " ";
			vec.erase(vec.begin(), vec.end());
			f_ft << vec.size() << " " << vec.capacity() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_erase ./logs/f_ft_erase");
	}
	{
		std::cout << "\n  swap:\t\t\t\t";
		{
			f_std.open("./logs/f_std_swap");
			std::vector<int> vec;
			std::vector<int>::iterator it;
			for (int i = 50; i < 10000; ++i) {
				vec.push_back(i * 3);
			}
			std::vector<int> vec1;
			for (int i = 500; i > 0; --i) {
				vec.push_back(i * 2);
			}
			vec.swap(vec1);
			for (it = vec.begin(); it != vec.end(); ++it)
				f_std << *it << " ";
			f_std << vec.size() << " " << vec.capacity() << " ";
			for (it = vec1.begin(); it != vec1.end(); ++it)
				f_std << *it << " ";
			f_std << vec1.size() << " " << vec1.capacity() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_swap");
			ft::vector<int> vec;
			ft::vector<int>::iterator it;
			for (int i = 50; i < 10000; ++i) {
				vec.push_back(i * 3);
			}
			ft::vector<int> vec1;
			for (int i = 500; i > 0; --i) {
				vec.push_back(i * 2);
			}
			vec.swap(vec1);
			for (it = vec.begin(); it != vec.end(); ++it)
				f_ft << *it << " ";
			f_ft << vec.size() << " " << vec.capacity() << " ";
			for (it = vec1.begin(); it != vec1.end(); ++it)
				f_ft << *it << " ";
			f_ft << vec1.size() << " " << vec1.capacity() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_swap ./logs/f_ft_swap");
	}
	{
		std::cout << "\n  clear:\t\t\t";
		{
			f_std.open("./logs/f_std_clear");
			std::vector<int> vec;
			std::vector<int>::iterator it;
			for (int i = 50; i < 10000; ++i) {
				vec.push_back(i * 3);
			}
			vec.clear();
			for (it = vec.begin(); it != vec.end(); ++it)
				f_std << *it << " ";
			f_std << vec.size() << " " << vec.capacity() << " ";
			f_std << vec.size() << " " << vec.capacity() << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_clear");
			ft::vector<int> vec;
			ft::vector<int>::iterator it;
			for (int i = 50; i < 10000; ++i) {
				vec.push_back(i * 3);
			}
			vec.clear();
			for (it = vec.begin(); it != vec.end(); ++it)
				f_ft << *it << " ";
			f_ft << vec.size() << " " << vec.capacity() << " ";
			f_ft << vec.size() << " " << vec.capacity() << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_clear ./logs/f_ft_clear");
	}

	/* ****************************************************************************** */
	/* ******************************* S T A C K ************************************ */
	/* ****************************************************************************** */

	std::cout << "\n\033[31m*********** S T A C K ************* \033[m" << std::endl;

	{
		{
			std::cout << "  constructor:\t\t\t";
			{
				f_std.open("./logs/f_std_stack_constr");
				std::vector<int> mydeque(3, 100);          // deque with 3 elements
				std::vector<int> myvector(2, 200);        // vector with 2 elements
				std::stack<int> first;                    // empty stack
				std::stack<int, std::vector<int> > second(mydeque);         // stack initialized to copy of deque
				std::stack<int, std::vector<int> > third;  // empty stack using vector
				std::stack<int, std::vector<int> > fourth(myvector);
				f_std << first.size() << " ";
				f_std << second.size() << " ";
				f_std << third.size() << " ";
				f_std << fourth.size() << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_stack_constr");
				ft::vector<int> mydeque(3, 100);          // deque with 3 elements
				ft::vector<int> myvector(2, 200);        // vector with 2 elements
				ft::stack<int> first;                    // empty stack
				ft::stack<int> second(mydeque);         // stack initialized to copy of deque
				ft::stack<int, ft::vector<int> > third;  // empty stack using vector
				ft::stack<int, ft::vector<int> > fourth(myvector);
				f_ft << first.size() << " ";
				f_ft << second.size() << " ";
				f_ft << third.size() << " ";
				f_ft << fourth.size() << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_stack_constr ./logs/f_ft_stack_constr");
		}
	}
	{
		{
			std::cout << "\n  empty:\t\t\t";
			{
				f_std.open("./logs/f_std_stack_empty");
				std::vector<int> mydeque(3, 100);          // deque with 3 elements
				std::vector<int> myvector(2, 200);        // vector with 2 elements
				std::stack<int> first;                    // empty stack
				std::stack<int, std::vector<int> > second(mydeque);         // stack initialized to copy of deque
				std::stack<int, std::vector<int> > third;  // empty stack using vector
				std::stack<int, std::vector<int> > fourth(myvector);
				f_std << first.empty() << " ";
				f_std << second.empty() << " ";
				f_std << third.empty() << " ";
				f_std << fourth.empty() << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_stack_empty");
				ft::vector<int> mydeque(3, 100);          // deque with 3 elements
				ft::vector<int> myvector(2, 200);        // vector with 2 elements
				ft::stack<int> first;                    // empty stack
				ft::stack<int, ft::vector<int> > second(mydeque);         // stack initialized to copy of deque
				ft::stack<int, ft::vector<int> > third;  // empty stack using vector
				ft::stack<int, ft::vector<int> > fourth(myvector);
				f_ft << first.empty() << " ";
				f_ft << second.empty() << " ";
				f_ft << third.empty() << " ";
				f_ft << fourth.empty() << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_stack_empty ./logs/f_ft_stack_empty");
		}
	}
	{
		{
			std::cout << "\n  size:\t\t\t\t";
			{
				f_std.open("./logs/f_std_stack_size");
				std::vector<int> mydeque(3, 100);
				std::vector<int> myvector(2, 200);
				std::stack<int> first;
				std::stack<int, std::vector<int> > second(mydeque);
				std::stack<int, std::vector<int> > third;
				std::stack<int, std::vector<int> > fourth(myvector);
				f_std << first.size() << " ";
				f_std << second.size() << " ";
				f_std << third.size() << " ";
				f_std << fourth.size() << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_stack_size");
				ft::vector<int> mydeque(3, 100);
				ft::vector<int> myvector(2, 200);
				ft::stack<int> first;
				ft::stack<int, ft::vector<int> > second(mydeque);
				ft::stack<int, ft::vector<int> > third;
				ft::stack<int, ft::vector<int> > fourth(myvector);
				f_ft << first.size() << " ";
				f_ft << second.size() << " ";
				f_ft << third.size() << " ";
				f_ft << fourth.size() << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_stack_size ./logs/f_ft_stack_size");
		}
		{
			std::cout << "\n  top:\t\t\t\t";
			{
				f_std.open("./logs/f_std_stack_top");
				std::stack<int> mystack;
				mystack.push(10);
				mystack.push(20);
				mystack.top() -= 5;
				f_std << mystack.top() << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_stack_top");
				ft::stack<int> mystack;
				mystack.push(10);
				mystack.push(20);
				mystack.top() -= 5;
				f_ft << mystack.top() << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_stack_top ./logs/f_ft_stack_top");
		}
	}
	{
		std::cout << "\n  push:\t\t\t\t";
		{
			f_std.open("./logs/f_std_stack_push");
			std::stack<int> mystack;
			for (int i = 0; i < 5; ++i)
				mystack.push(i);
			while (!mystack.empty())
			{
				f_std << mystack.top() << " ";
				mystack.pop();
			}
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_stack_push");
			ft::stack<int> mystack;
			for (int i = 0; i < 5; ++i)
				mystack.push(i);
			while (!mystack.empty())
			{
				f_ft << mystack.top() << " ";
				mystack.pop();
			}
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_stack_push ./logs/f_ft_stack_push");
	}
	{
		std::cout << "\n  pop:\t\t\t\t";
		{
			f_std.open("./logs/f_std_stack_pop");
			std::stack<int> mystack;

			for (int i=0; i<5; ++i)
				mystack.push(i);
			while (!mystack.empty())
			{
				f_std << mystack.top() << " ";
				mystack.pop();
			}
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_stack_pop");
			ft::stack<int> mystack;

			for (int i=0; i<5; ++i)
				mystack.push(i);
			while (!mystack.empty())
			{
				f_ft << mystack.top() << " ";
				mystack.pop();
			}
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_stack_pop ./logs/f_ft_stack_pop");
	}
	{
		std::cout << "\n  operator ==\t\t\t";
		{
			f_std.open("./logs/f_std_stack_==");
			std::vector<int> mydeque(3, 100);
			std::vector<int> myvector(2, 200);
			std::stack<int, std::vector<int> > first (mydeque);
			std::stack<int, std::vector<int> > second(mydeque);
			std::stack<int, std::vector<int> > third;
			std::stack<int, std::vector<int> > fourth(myvector);
			f_std << (first == second) << " ";
			f_std << (first == third) << " ";
			f_std << (second == fourth) << " ";
			f_std << (third == fourth) << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_stack_==");
			ft::vector<int> mydeque(3, 100);
			ft::vector<int> myvector(2, 200);
			ft::stack<int, ft::vector<int> > first (mydeque);
			ft::stack<int, ft::vector<int> > second(mydeque);
			ft::stack<int, ft::vector<int> > third;
			ft::stack<int, ft::vector<int> > fourth(myvector);
			f_ft << (first == second) << " ";
			f_ft << (first == third) << " ";
			f_ft << (second == fourth) << " ";
			f_ft << (third == fourth) << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_stack_== ./logs/f_ft_stack_==");
	}
	{
		std::cout << "\n  operator !=\t\t\t";
		{
			f_std.open("./logs/f_std_stack_!=");
			std::vector<int> mydeque(3, 100);
			std::vector<int> myvector(2, 200);
			std::stack<int, std::vector<int> > first (mydeque);
			std::stack<int, std::vector<int> > second(mydeque);
			std::stack<int, std::vector<int> > third;
			std::stack<int, std::vector<int> > fourth(myvector);
			f_std << (first != second) << " ";
			f_std << (first != third) << " ";
			f_std << (second != fourth) << " ";
			f_std << (third != fourth) << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_stack_!=");
			ft::vector<int> mydeque(3, 100);
			ft::vector<int> myvector(2, 200);
			ft::stack<int, ft::vector<int> > first (mydeque);
			ft::stack<int, ft::vector<int> > second(mydeque);
			ft::stack<int, ft::vector<int> > third;
			ft::stack<int, ft::vector<int> > fourth(myvector);
			f_ft << (first != second) << " ";
			f_ft << (first != third) << " ";
			f_ft << (second != fourth) << " ";
			f_ft << (third != fourth) << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_stack_!= ./logs/f_ft_stack_!=");
	}
	{
		std::cout << "\n  operator <\t\t\t";
		{
			f_std.open("./logs/f_std_stack_smaller");
			std::vector<int> mydeque(3, 100);
			std::vector<int> myvector(2, 200);
			std::stack<int, std::vector<int> > first (mydeque);
			std::stack<int, std::vector<int> > second(mydeque);
			std::stack<int, std::vector<int> > third;
			std::stack<int, std::vector<int> > fourth(myvector);
			f_std << (first < second) << " ";
			f_std << (first < third) << " ";
			f_std << (second < fourth) << " ";
			f_std << (third < fourth) << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_stack_smaller");
			ft::vector<int> mydeque(3, 100);
			ft::vector<int> myvector(2, 200);
			ft::stack<int, ft::vector<int> > first (mydeque);
			ft::stack<int, ft::vector<int> > second(mydeque);
			ft::stack<int, ft::vector<int> > third;
			ft::stack<int, ft::vector<int> > fourth(myvector);
			f_ft << (first < second) << " ";
			f_ft << (first < third) << " ";
			f_ft << (second < fourth) << " ";
			f_ft << (third < fourth) << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_stack_smaller ./logs/f_ft_stack_smaller");
	}
	{
		std::cout << "\n  operator <=\t\t\t";
		{
			f_std.open("./logs/f_std_stack_smaller=");
			std::vector<int> mydeque(3, 100);
			std::vector<int> myvector(2, 200);
			std::stack<int, std::vector<int> > first (mydeque);
			std::stack<int, std::vector<int> > second(mydeque);
			std::stack<int, std::vector<int> > third;
			std::stack<int, std::vector<int> > fourth(myvector);
			f_std << (first <= second) << " ";
			f_std << (first <= third) << " ";
			f_std << (second <= fourth) << " ";
			f_std << (third <= fourth) << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_stack_smaller=");
			ft::vector<int> mydeque(3, 100);
			ft::vector<int> myvector(2, 200);
			ft::stack<int, ft::vector<int> > first (mydeque);
			ft::stack<int, ft::vector<int> > second(mydeque);
			ft::stack<int, ft::vector<int> > third;
			ft::stack<int, ft::vector<int> > fourth(myvector);
			f_ft << (first <= second) << " ";
			f_ft << (first <= third) << " ";
			f_ft << (second <= fourth) << " ";
			f_ft << (third <= fourth) << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_stack_smaller= ./logs/f_ft_stack_smaller=");
	}
	{
		std::cout << "\n  operator >=\t\t\t";
		{
			f_std.open("./logs/f_std_stack_more=");
			std::vector<int> mydeque(3, 100);
			std::vector<int> myvector(2, 200);
			std::stack<int, std::vector<int> > first (mydeque);
			std::stack<int, std::vector<int> > second(mydeque);
			std::stack<int, std::vector<int> > third;
			std::stack<int, std::vector<int> > fourth(myvector);
			f_std << (first >= second) << " ";
			f_std << (first >= third) << " ";
			f_std << (second >= fourth) << " ";
			f_std << (third >= fourth) << " ";
			f_std.close();
		}
		{
			f_ft.open("./logs/f_ft_stack_more=");
			ft::vector<int> mydeque(3, 100);
			ft::vector<int> myvector(2, 200);
			ft::stack<int, ft::vector<int> > first (mydeque);
			ft::stack<int, ft::vector<int> > second(mydeque);
			ft::stack<int, ft::vector<int> > third;
			ft::stack<int, ft::vector<int> > fourth(myvector);
			f_ft << (first >= second) << " ";
			f_ft << (first >= third) << " ";
			f_ft << (second >= fourth) << " ";
			f_ft << (third >= fourth) << " ";
			f_ft.close();
		}
		comparison((char *) "diff ./logs/f_std_stack_more= ./logs/f_ft_stack_more=");
	}

	/* ****************************************************************************** */
	/* ******************************* M A P ************************************ */
	/* ****************************************************************************** */

	std::cout << "\n\033[31m*********** M A P ************* \033[m" << std::endl;

	{
		{
			std::cout << "  constructor:\t\t\t";
			{
				f_std.open("./logs/f_std_map_constr");
				std::map<char,int> first;
				first['a']=10;
				first['b']=30;
				first['c']=50;
				first['d']=70;
				std::map<char,int> second (first.begin(),first.end());
				for (std::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				std::map<char,int> third (second);
				for (std::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				std::map<char,int,classcomp> fourth;
				for (std::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				bool(*fn_pt)(char,char) = fncomp;
				std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
				for (std::map<char, int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_constr");
				ft::map<char,int> first;
				first['a']=10;
				first['b']=30;
				first['c']=50;
				first['d']=70;
				ft::map<char,int> second (first.begin(),first.end());
				for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				ft::map<char,int> third (second);
				for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				ft::map<char,int,classcomp> fourth;
				for (ft::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				bool(*fn_pt)(char,char) = fncomp;
				ft::map<char,int,bool(*)(char,char)> fifth (fn_pt);
				for (ft::map<char, int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_constr ./logs/f_ft_map_constr");
		}
		{
			std::cout << "\n  begin():\t\t\t";
			{
				f_std.open("./logs/f_std_map_begin");
				std::map<char,int> mymap;
				mymap['b'] = 100;
				mymap['a'] = 200;
				mymap['c'] = 300;
				for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_begin");
				ft::map<char,int> mymap;
				mymap['b'] = 100;
				mymap['a'] = 200;
				mymap['c'] = 300;
				for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_begin ./logs/f_ft_map_begin");
		}
		{
			std::cout << "\n  end():\t\t\t";
			{
				f_std.open("./logs/f_std_map_end");
				std::map<char,int> mymap;
				mymap['b'] = 100;
				mymap['a'] = 200;
				mymap['c'] = 300;
				for (std::map<char,int>::iterator it=mymap.end(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_end");
				ft::map<char,int> mymap;
				mymap['b'] = 100;
				mymap['a'] = 200;
				mymap['c'] = 300;
				for (ft::map<char,int>::iterator it=mymap.end(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_end ./logs/f_ft_map_end");
		}
		{
			std::cout << "\n  rbegin():\t\t\t";
			{
				f_std.open("./logs/f_std_map_rbegin");
				std::map<char,int> mymap;
				mymap['x'] = 100;
				mymap['y'] = 200;
				mymap['z'] = 300;
				std::map<char,int>::reverse_iterator rit;
				for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
					f_std << rit->first << " " << rit->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_rbegin");
				ft::map<char,int> mymap;
				mymap['x'] = 100;
				mymap['y'] = 200;
				mymap['z'] = 300;
				ft::map<char,int>::reverse_iterator rit;
				for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
					f_ft << rit->first << " " << rit->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_rbegin ./logs/f_ft_map_rbegin");
		}
		{
			std::cout << "\n  rend():\t\t\t";
			{
				f_std.open("./logs/f_std_map_rend");
				std::map<char,int> mymap;
				mymap['x'] = 100;
				mymap['y'] = 200;
				mymap['z'] = 300;
				std::map<char,int>::reverse_iterator rit;
				for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
					f_std << rit->first << " " << rit->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_rend");
				ft::map<char,int> mymap;
				mymap['x'] = 100;
				mymap['y'] = 200;
				mymap['z'] = 300;
				ft::map<char,int>::reverse_iterator rit;
				for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
					f_ft << rit->first << " " << rit->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_rend ./logs/f_ft_map_rend");
		}
		{
			std::cout << "\n  empty():\t\t\t";
			{
				f_std.open("./logs/f_std_map_empty");
				std::map<char,int> mymap;
				mymap['a']=10;
				mymap['b']=20;
				mymap['c']=30;
				while (!mymap.empty())
				{
					f_std << mymap.begin()->first << " " << mymap.begin()->second << " ";
					mymap.erase(mymap.begin());
				}
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_empty");
				ft::map<char,int> mymap;
				mymap['a']=10;
				mymap['b']=20;
				mymap['c']=30;
				while (!mymap.empty())
				{
					f_ft << mymap.begin()->first << " " << mymap.begin()->second << " ";
					mymap.erase(mymap.begin());
				}
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_empty ./logs/f_ft_map_empty");
		}
		{
			std::cout << "\n  size():\t\t\t";
			{
				f_std.open("./logs/f_std_map_size");
				std::map<char,int> mymap;
				mymap['a']=101;
				mymap['b']=202;
				mymap['c']=302;
				f_std << mymap.size() << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_size");
				ft::map<char,int> mymap;
				mymap['a']=101;
				mymap['b']=202;
				mymap['c']=302;
				f_ft << mymap.size() << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_size ./logs/f_ft_map_size");
		}
		{
			std::cout << "\n  operator[]:\t\t\t";
			{
				f_std.open("./logs/f_std_map_operator[]");
				std::map<char,std::string> mymap;
				mymap['a']="an element";
				mymap['b']="another element";
				mymap['c']=mymap['b'];
				f_std << mymap['a'] << " ";
				f_std << mymap['b'] << " ";
				f_std << mymap['c'] << " ";
				f_std << mymap['d'] << " ";
				f_std << mymap.size() << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_operator[]");
				ft::map<char,std::string> mymap;
				mymap['a']="an element";
				mymap['b']="another element";
				mymap['c']=mymap['b'];
				f_ft << mymap['a'] << " ";
				f_ft << mymap['b'] << " ";
				f_ft << mymap['c'] << " ";
				f_ft << mymap['d'] << " ";
				f_ft << mymap.size() << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_operator[] ./logs/f_ft_map_operator[]");
		}
		{
			std::cout << "\n  insert:\t\t\t";
			{
				f_std.open("./logs/f_std_map_insert");
				std::map<char,int> mymap;

				mymap.insert ( std::pair<char,int>('a',100) );
				mymap.insert ( std::pair<char,int>('z',200) );

				std::pair<std::map<char,int>::iterator,bool> ret;
				ret = mymap.insert ( std::pair<char,int>('z',500) );
				if (ret.second==false) {
					f_std << ret.first->second << '\n';
				}
				std::map<char,int>::iterator it = mymap.begin();
				mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
				mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
				std::map<char,int> anothermap;
				anothermap.insert(mymap.begin(),mymap.find('c'));
				for (it=mymap.begin(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				for (it=anothermap.begin(); it!=anothermap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_insert");
				ft::map<char,int> mymap;

				mymap.insert ( ft::pair<char,int>('a',100) );
				mymap.insert ( ft::pair<char,int>('z',200) );

				ft::pair<ft::map<char,int>::iterator,bool> ret;
				ret = mymap.insert ( ft::pair<char,int>('z',500) );
				if (ret.second==false) {
					f_ft << ret.first->second << '\n';
				}
				ft::map<char,int>::iterator it = mymap.begin();
				mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
				mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
				ft::map<char,int> anothermap;
				anothermap.insert(mymap.begin(),mymap.find('c'));
				for (it=mymap.begin(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				for (it=anothermap.begin(); it!=anothermap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_insert ./logs/f_ft_map_insert");
		}
		{
			std::cout << "\n  erase():\t\t\t";
			{
				f_std.open("./logs/f_std_map_erase");
				std::map<char,int> mymap;
				std::map<char,int>::iterator it;
				mymap['a']=10;
				mymap['b']=20;
				mymap['c']=30;
				mymap['d']=40;
				mymap['e']=50;
				mymap['f']=60;
				it=mymap.find('b');
				mymap.erase (it);
				mymap.erase ('c');
				it=mymap.find ('e');
				mymap.erase ( it, mymap.end() );
				for (it=mymap.begin(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_erase");
				ft::map<char,int> mymap;
				ft::map<char,int>::iterator it;
				mymap['a']=10;
				mymap['b']=20;
				mymap['c']=30;
				mymap['d']=40;
				mymap['e']=50;
				mymap['f']=60;
				it=mymap.find('b');
				mymap.erase (it);
				mymap.erase ('c');
				it=mymap.find ('e');
				mymap.erase ( it, mymap.end() );
				for (it=mymap.begin(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_erase ./logs/f_ft_map_erase");
		}
		{
			std::cout << "\n  swap():\t\t\t";
			{
				f_std.open("./logs/f_std_map_swap");
				std::map<char,int> foo,bar;
				foo['x']=100;
				foo['y']=200;
				bar['a']=11;
				bar['b']=22;
				bar['c']=33;
				foo.swap(bar);
				for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_swap");
				ft::map<char,int> foo,bar;
				foo['x']=100;
				foo['y']=200;
				bar['a']=11;
				bar['b']=22;
				bar['c']=33;
				foo.swap(bar);
				for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_swap ./logs/f_ft_map_swap");
		}
		{
			std::cout << "\n  clear():\t\t\t";
			{
				f_std.open("./logs/f_std_map_clear");
				std::map<char,int> mymap;
				mymap['x']=100;
				mymap['y']=200;
				mymap['z']=300;
				for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				mymap.clear();
				mymap['a']=1101;
				mymap['b']=2202;
				for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_clear");
				ft::map<char,int> mymap;
				mymap['x']=100;
				mymap['y']=200;
				mymap['z']=300;
				for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				mymap.clear();
				mymap['a']=1101;
				mymap['b']=2202;
				for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_clear ./logs/f_ft_map_clear");
		}
		{
			std::cout << "\n  find():\t\t\t";
			{
				f_std.open("./logs/f_std_map_find");
				std::map<char,int> mymap;
				std::map<char,int>::iterator it;
				mymap['a']=50;
				mymap['b']=100;
				mymap['c']=150;
				mymap['d']=200;
				it = mymap.find('b');
				if (it != mymap.end())
					mymap.erase (it);
				f_std << mymap.find('a')->second << " ";
				f_std << "c => " << mymap.find('c')->second << " ";
				f_std << "d => " << mymap.find('d')->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_find");
				ft::map<char,int> mymap;
				ft::map<char,int>::iterator it;
				mymap['a']=50;
				mymap['b']=100;
				mymap['c']=150;
				mymap['d']=200;
				it = mymap.find('b');
				if (it != mymap.end())
					mymap.erase (it);
				f_ft << mymap.find('a')->second << " ";
				f_ft << "c => " << mymap.find('c')->second << " ";
				f_ft << "d => " << mymap.find('d')->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_find ./logs/f_ft_map_find");
		}
		{
			std::cout << "\n  count():\t\t\t";
			{
				f_std.open("./logs/f_std_map_count");
				std::map<char,int> mymap;
				char c;
				mymap ['a']=101;
				mymap ['c']=202;
				mymap ['f']=303;
				for (c='a'; c<'h'; c++)
				{
					f_std << c;
					if (mymap.count(c)>0)
						f_std << " is an element of mymap.\n";
					else
						f_std << " is not an element of mymap.\n";
				}
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_count");
				ft::map<char,int> mymap;
				char c;
				mymap ['a']=101;
				mymap ['c']=202;
				mymap ['f']=303;
				for (c='a'; c<'h'; c++)
				{
					f_ft << c;
					if (mymap.count(c)>0)
						f_ft << " is an element of mymap.\n";
					else
						f_ft << " is not an element of mymap.\n";
				}
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_count ./logs/f_ft_map_count");
		}
		{
			std::cout << "\n  lower_bound():\t\t";
			{
				f_std.open("./logs/f_std_map_lower_bound");
				std::map<char,int> mymap;
				std::map<char,int>::iterator itlow,itup;
				mymap['a']=20;
				mymap['b']=40;
				mymap['c']=60;
				mymap['d']=80;
				mymap['e']=100;
				itlow=mymap.lower_bound ('b');  // itlow points to b
				itup=mymap.upper_bound ('d');   // itup points to e (not d!)
				mymap.erase(itlow,itup);        // erases [itlow,itup)
				for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_lower_bound");
				ft::map<char,int> mymap;
				ft::map<char,int>::iterator itlow,itup;
				mymap['a']=20;
				mymap['b']=40;
				mymap['c']=60;
				mymap['d']=80;
				mymap['e']=100;
				itlow=mymap.lower_bound ('b');  // itlow points to b
				itup=mymap.upper_bound ('d');   // itup points to e (not d!)
				mymap.erase(itlow,itup);        // erases [itlow,itup)
				for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_lower_bound ./logs/f_ft_map_lower_bound");
		}
		{
			std::cout << "\n  upper_bound():\t\t";
			{
				f_std.open("./logs/f_std_map_upper_bound");
				std::map<char,int> mymap;
				std::map<char,int>::iterator itlow,itup;
				mymap['a']=20;
				mymap['b']=40;
				mymap['c']=60;
				mymap['d']=80;
				mymap['e']=100;
				itlow=mymap.lower_bound ('b');
				itup=mymap.upper_bound ('d');
				mymap.erase(itlow,itup);
				for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_std << it->first << " " << it->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_upper_bound");
				ft::map<char,int> mymap;
				ft::map<char,int>::iterator itlow,itup;
				mymap['a']=20;
				mymap['b']=40;
				mymap['c']=60;
				mymap['d']=80;
				mymap['e']=100;
				itlow=mymap.lower_bound ('b');
				itup=mymap.upper_bound ('d');
				mymap.erase(itlow,itup);
				for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
					f_ft << it->first << " " << it->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_upper_bound ./logs/f_ft_map_upper_bound");
		}
		{
			std::cout << "\n  equal_range():\t\t";
			{
				f_std.open("./logs/f_std_map_equal_range");
				std::map<char,int> mymap;
				mymap['a']=10;
				mymap['b']=20;
				mymap['c']=30;
				std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
				ret = mymap.equal_range('b');
				f_std << ret.first->first << " " << ret.first->second << " ";
				f_std << ret.second->first << " " << ret.second->second << " ";
				f_std.close();
			}
			{
				f_ft.open("./logs/f_ft_map_equal_range");
				ft::map<char,int> mymap;
				mymap['a']=10;
				mymap['b']=20;
				mymap['c']=30;
				ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
				ret = mymap.equal_range('b');
				f_ft << ret.first->first << " " << ret.first->second << " ";
				f_ft << ret.second->first << " " << ret.second->second << " ";
				f_ft.close();
			}
			comparison((char *) "diff ./logs/f_std_map_equal_range ./logs/f_ft_map_equal_range");
		}
	}

}

