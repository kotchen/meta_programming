#pragma once
#include <type_traits>


template<typename T>
struct has_member_type
{
	template<typename U>
	static auto check(int) -> decltype(declval<U::type>, std::true_type());

	template<typename U>
	static std::false_type check(...);

	static constexpr bool value = std::is_same<check<T>(0), std::true_type>::value;
};


struct A
{
	int a;
	using type = int;
};

struct B
{
	double B;
};

int main()
{
	

	
	

}