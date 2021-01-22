#pragma once
#include <iostream>

template<int... vals> struct IntContainer;
template<bool... vals> struct BoolContainer;
template<typename... types> struct TypeContainer;
template<template <typename...> class T1, typename T2> struct TempContainer;
template<template <typename> class T1, typename T2> struct TempContainer2;

