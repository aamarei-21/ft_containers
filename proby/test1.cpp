#include <iostream>

template<bool _B, class T>
class Iterat{
private:
	std::conditional<_B, const T*, T*> ptr;
public:


};

template <class T>
class My_class
{
privave:
	T*	_t;
	//std::conditional<_B, const int*, int*>
public:


}


