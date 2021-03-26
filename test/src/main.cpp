#include "prac_1.h"
#include "prac_2.h"
#include "prac_3.h"
#include <iostream>
#include <type_traits>
#include <utility>
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
		std::cout << isEqual<int, 4> << '\n';
		std::cout << isEqual<int, 8> << '\n';
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


	/*template<typename T>
	struct has_memberType
	{
	private:
		template<typename U>
		static auto Check(int) -> decltype(std::declval<U>::type, std::true_type());
		template<typename U>
		static std::false_type Check(...);
	public:
		enum { value = std::is_same<decltype(Check<T>(0)), std::true_type>::value };
	};*/

	/*template <typename T, std::enable_if_t<std::is_same<decltype()::type, std::true_type>::value>* = nullptr>
	struct has_member_type
	{
		constexpr static bool value = true;
	};

	template <typename T, std::enable_if_t<!std::is_same<typename T::type, std::true_type>::value>* = nullptr>
	struct has_member_type
	{
		constexpr static bool value = false;
	};*/



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

	template <int N, int divisor>
	struct evaluate_primer
	{
		constexpr static bool value = (N % divisor) && evaluate_primer<N, divisor - 1>::value;
	};

	template <int N>
	struct evaluate_primer<N, 1>
	{
		constexpr static bool value = true;
	};


	template <int N>
	struct is_primer
	{
		constexpr static bool value = evaluate_primer<N, N / 2>::value;
	};

	template <>
	struct is_primer<0>
	{
		constexpr static bool value = false;
	};

	template <>
	struct is_primer<1>
	{
		constexpr static bool value = false;
	};




	
	template<typename T>
	struct is_contain_type
	{
		template<typename U>
		static auto check(int) -> decltype(std::declval<U::type>, std::true_type());
		template<typename U>
		static std::false_type check(...);
		static constexpr bool value = std::is_same<decltype(check<T>(0)), std::true_type>::value;
	};

	template<typename T>
	struct has_member_type
	{
	private:
		template<typename U>
		static auto Check(int) -> decltype(std::declval<U::type>(), std::true_type());
		template<typename U>
		static std::false_type Check(...);
	public:
		enum { value = std::is_same<decltype(Check<T>(0)), std::true_type>::value };
	};

	struct A
	{
		using type = int;
	};

	struct B
	{
		double a;
	};


	void fun()
	{
		using namespace std;


		/*cout << has_member_type<A>::value << '\n';
		cout << has_member_type<int>::value << '\n';*/

		/*cout << is_primer<3>::value << '\n';

		if (has_member_foo<myStruct>::value)
			std::cout << "myStruct has foo funciton" << std::endl;
		else
			std::cout << "myStruct does't have foo funciton" << std::endl;

		if (has_member_foo<another>::value)
			std::cout << "another has foo function" << std::endl;
		else
			std::cout << "another does't have foo function" << std::endl;*/

		std::cout << is_contain_type<A>::value << " " << is_contain_type<B>::value;

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

namespace sfinae
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
namespace test
{
	template<typename T> class complex;
	template<typename T>
	std::ostream& operator<< (std::ostream& out, const test::complex<T>& out_object)
	{
		out << out_object.a << " " << out_object.b << '\n';
		return out;
	}

	template<typename T>
	class complex
	{
	public:
		T a;
		T b;
		complex(T src_a, T src_b) : a(src_a), b(src_b) {};
		friend std::ostream& operator<< <T>(std::ostream& out, const complex<T>& out_object);
	};


	void fun()
	{
		complex<int> p(1, 1);
		std::cout << p;

		int a = 0;

	}
	
}

int main()
{
	
	using namespace p4;
	fun();
}