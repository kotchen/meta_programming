#pragma once
template <typename T, size_t size>
constexpr bool isEqual = ( sizeof(T) == size ? true : false);