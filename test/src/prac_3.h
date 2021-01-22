#pragma once
#include <iostream>
template< template <typename> class c, typename T>
void fun_t()
{
	std::cout << "first" << '\n';
	std::cout << sizeof(c<T>::type);
}

template <typename T>
struct p
{
	using type = T;
};
