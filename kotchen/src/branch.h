#pragma once
#include <iostream>
template<bool IsFeedbackOut, typename T,
		std::enable_if_t<IsFeedbackOut>* = nullptr>
	auto FeedbackOut_(T&&) {}

template<bool IsFeedbackOut, typename T,
	std::enable_if_t<!IsFeedbackOut>* = nullptr>
	auto FeedbackOut_(T&&) {}