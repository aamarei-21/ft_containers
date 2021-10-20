#include <iostream>

template <class T>
struct is_const{
	static const bool value = false;
};

template <class T>
struct is_const<const T>{
	static const bool value = true;
};

class A
{
	int c;
};


int main(){
	int i;
	std::cout << is_const<A>::value << std::endl;
	return 0;
}

