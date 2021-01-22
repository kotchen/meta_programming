#pragma once
template <typename T, size_t size>
bool isEqual()
{
	if (sizeof(T) == size)
		return true;
	else
		return false;
}