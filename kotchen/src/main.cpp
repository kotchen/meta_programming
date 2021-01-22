//#include "func.h"
#include "outOfControl.h"
#include "multiReturnType.h"
#include "circulation.h"
#include <type_traits>
#include <iostream>
#include "CRTP.h"


int main()
{
	/*Fun_<int>::type h = 3;
	Fun<int> h2 = 3;
	hello<std::remove_reference, int&> h3 = 0;
	Res_<int&>::type h4 = 3;*/

	size_t i = Wrapper<int>::Fun_<int>::value;
	std::cout << i << ' ';

	std::cerr << wrap2<true>() << ' ';
	
	constexpr size_t res = OneCount<45>;
	std::cout << res << ' ';

	constexpr size_t sum = Accumulate<1, 2, 3, 4, 5>;
	std::cout << sum << ' ';

	std::cout << fun_sum<1, 2, 3, 4, 5>();

	std::cout << add<1, 2, 3, 4, 5>;

	std::cout << function<1, 2, 3, 4, 5>();


	std::cout << '\n';

	Derive d;
	d.Fun("Implementation from derive class");
	
}

