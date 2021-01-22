#include "prac_1.h"
#include "prac_2.h"
#include "prac_3.h"
#include <iostream>

namespace p1
{
	void fun()
	{
		std::cout << typeSize<int>;
	}
}

namespace p2
{
	void fun()
	{
		std::cout << isEqual<int, 4>() << '\n';
		std::cout << isEqual<int, 8>() << '\n';
	}
}

namespace p3
{
	void fun()
	{
		fun_t<p,int>();
	}
}

int main()
{
	using namespace p3;
	fun();
}