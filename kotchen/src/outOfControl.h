#pragma once
template <typename TW>
struct Wrapper
{
	template <typename T, typename fake = void>
	struct Fun_
	{
		constexpr static size_t value = 0;
	};

	template <typename fake>
	struct Fun_<int, fake>
	{
		constexpr static size_t value = 1;
	};
};