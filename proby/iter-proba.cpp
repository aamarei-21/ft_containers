#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>

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

template<class Iterator>
void my_print(Iterator& Iter, std::random_access_iterator_tag)
{
	std::cout <<"Random acces iterator\n";
}

template<class Iterator>
void my_print(Iterator& Iter, std::bidirectional_iterator_tag)
{
	std::cout <<"bidirectional iterator\n";
}

template<class Iterator>
void my_print(Iterator& Iter, std::forward_iterator_tag)
{
	std::cout <<"forward iterator\n";
}

template<class Iterator, class IterCategory>
void my_print(Iterator& Iter, IterCategory)
{
	std::cout <<"another iterator\n";
}

template <class Iterator>
void switc_iter(Iterator& _Iter)
{
	my_print(_Iter, typename std::iterator_traits<Iterator>::iterator_category());
}
int main(void)
{
	std::vector<int> v(5);
	std::set<int> s;
	std::map<int, float> m;
	std::list<int> l;

	std::vector<Proba> ::iterator it;
	switc_iter(it);
}
