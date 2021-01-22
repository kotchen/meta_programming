#pragma once
template <size_t Input>
constexpr size_t OneCount = (Input % 2) + OneCount<Input / 2>;

template <> constexpr size_t OneCount<0> = 0;

template <size_t... Inputs>
constexpr size_t Accumulate = 0;

template <size_t CurInput, size_t... Inputs>
constexpr size_t Accumulate<CurInput, Inputs...> 
			= CurInput + Accumulate<Inputs...>;


template <size_t... values>
constexpr size_t fun_sum()
{
	return (0 + ... + values);
}




template<size_t... input>
constexpr size_t add = 0;

template<size_t cur, size_t... input>
constexpr size_t add<cur, input...>
= cur + add<input...>;




template<size_t... input>
auto function()
{
	return (0 + ... + input);
}



// 首先现在根据如今的理解，可以写出常数元函数的循环，但是如果写
// 成函数模板是没有实现的。