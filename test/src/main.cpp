#include "prac_1.h"
#include "prac_2.h"
#include "prac_3.h"
#include <iostream>
#include <type_traits>
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

namespace p4
{

	struct A
	{
		using type = int;
	};

	
	/*template<typename T>
	struct has_member_type
	{
	private:
		template<typename U>
		static auto Check(int) -> decltype(std::declval<U>::type, std::true_type());
		template<typename U>
		static std::false_type Check(...);
	public:
		enum { value = std::is_same<decltype(Check<T>(0)), std::true_type>::value };
	};*/

	template<typename T>
	bool check()
	{

		return true;
	}

	template <typename T>
	struct has_member_type
	{
		constexpr static bool value = check<T>();
	};

	


	void fun()
	{
		if (has_member_type<A>::value)
		{
			std::cout << "has type" << '\n';
		}
		else
		{
			std::cout << "don't have type" << '\n';
		}
		/*if (has_member_type<int>::value)
		{
			std::cout << "has type" << '\n';
		}
		else
		{
			std::cout << "don't have type" << '\n';
		}*/
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


	void fun()
	{
		std::cout << p6::isContainsOne<2, 3, 4>;
	}
}

namespace sfine
{

	template<typename T>
	struct has_member_foo
	{
	private:
		template<typename U>
		static auto Check(int) -> decltype(std::declval<U>().foo(), std::true_type());
		template<typename U>
		static std::false_type Check(...);
	public:
		enum { value = std::is_same<decltype(Check<T>(0)), std::true_type>::value };
	};

	struct myStruct
	{
		void foo() { std::cout << "hello" << std::endl; }
	};

	struct another
	{
		void test() { std::cout << "test" << std::endl; }
	};

	void fun()
	{
		if (has_member_foo<myStruct>::value)
			std::cout << "myStruct has foo funciton" << std::endl;
		else
			std::cout << "myStruct does't have foo funciton" << std::endl;

		if (has_member_foo<another>::value)
			std::cout << "another has foo function" << std::endl;
		else
			std::cout << "another does't have foo function" << std::endl;

	}
	
}

int main()
{
	
	using namespace p4;
	fun();
}