#include <iostream>

class My_class
{
public:
	int		x;
	float	y;
	char	ch;
	My_class& operator-();

	operator char() {return ch;}
	operator float() {return y;}
};

My_class& My_class::operator-()
{
	x = -x;
	y = -y;
	return *this;
}
	void printChar(char c) {std::cout << c << std::endl;}
	void printFloat(float f) {std::cout << f << std::endl;}

int main()
{
	My_class c;
	c.x = 100;
	c.y = 120.5;
	c.ch = 'A';
	std:: cout << c.x << " " << c.y << std::endl;
	c = -c;
	std:: cout << c.x << " " << c.y << std::endl;
	printChar(c);
	printFloat(c);
	return 0;

}
