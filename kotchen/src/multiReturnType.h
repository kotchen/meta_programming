#pragma once
#include <iostream>
template<bool Check, std::enable_if_t<Check>* = nullptr>
auto fun()
{
	return (int)0;
}

template<bool Check, std::enable_if_t<!Check>* = nullptr>
auto fun()
{
	return (double)0;
}

template<bool Check>
auto wrap2()
{
	return fun<Check>();
}

