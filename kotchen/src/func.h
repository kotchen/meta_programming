#pragma once
#include <iostream>
template<typename T>
struct Fun_ { using type = T; };

template<>
struct Fun_<int> { using type = unsigned int; };

template<>
struct Fun_<long> { using type = unsigned long; };

template<typename T>
using Fun = typename Fun_<T>::type;


template<bool AddOrRemoveRef> struct fun_;
template<>
struct fun_<true>
{
	template<typename T>
	using type = std::add_lvalue_reference<T>;
};

template<>
struct fun_<false>
{
	template<typename T>
	using type = std::remove_reference<T>;
};

template<typename T>
template<bool AddOrRemoveRef>
using fun = typename fun_<AddOrRemoveRef>::template type<T>;

template<typename T>
using Res_ = fun<false>;

template<template <typename> class T1, typename T2>
struct hello_
{
	using type = typename T1<T2>::type;
};

template <template <typename> class T1, typename T2>
using hello = typename hello_<T1, T2>::type;









