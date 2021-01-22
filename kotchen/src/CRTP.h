#pragma once
template <typename D>
struct Base
{
	template <typename TI>
	void Fun(const TI& input)
	{
		D* ptr = static_cast<D*> (this);
		ptr->Imp(input);
	}
};

struct Derive : public Base<Derive>
{
	template <typename TI>
	void Imp(const TI& input)
	{
		std::cout << input << '\n';
	}
};