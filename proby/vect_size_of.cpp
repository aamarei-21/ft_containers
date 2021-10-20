#include <iostream>
#include <My_class>

int main(void)
{
	std::My_class<double>	v(1);
	v.push_back(10);
	int				s = sizeof(v);
	std::cout << "s = " << s << std::endl;
	v.push_back(12);
	v.push_back(24);
	s = sizeof(s);
	std::cout << "s = " << s << std::endl;
	std::cout << v[3] << std::endl;
	return 0;
}
