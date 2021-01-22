#pragma once
#include <iostream>
template<bool IsFeedbackOut, typename T,
		std::enable_if_t<IsFeedbackOut>* = nullptr>
	auto FeedbackOut_(T&&) {}

template<bool IsFeedbackOut, typename T,
	std::enable_if_t<!IsFeedbackOut>* = nullptr>
	auto FeedbackOut_(T&&) {}

// branch and short out
template <size_t N>
constexpr static bool isOdd = (N % 2);

template <bool cur, typename TNext>
constexpr static bool AndValue = false;

template <typename TNext>
constexpr static bool AndValue<true, TNext> = TNext::value;

template <size_t N>
struct allOdd
{
	constexpr static bool cur = isOdd<N>;
	constexpr static bool value = AndValue < cur, allOdd<N - 1> >;
};
