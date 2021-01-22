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

namespace p6
{

	template <bool cur, bool Next>
	constexpr static bool orValue = Next;

	template <bool Next>
	constexpr static bool orValue<true, Next> = true;

	template <size_t N>
	constexpr static bool isContain = (N == 1);

	template <size_t... inputs>
	constexpr static bool isContainsOne = false;

	template <size_t cur, size_t... inputs>
	constexpr static bool isContainsOne<cur, inputs...> = orValue < isContain<cur>, isContainsOne<inputs...> >;

}

int main()
{
	
	std::cout << p6::isContainsOne<2, 3, 4>;
}