#include<iostream>

template <int...>
struct IntList;

template <int h, int... I>
struct IntList<h, I...>
{
    static const int Head = h;
    using Tail = IntList<I...>;
};

template<>
struct IntList<> {};

template <int value, class IL>
struct IntCons {};

template <int value, int... primes>
struct IntCons<value, IntList<primes...>>
{
    using type = IntList<value, primes...>;
};

using L1 = IntList<5,7,1,432,1243>;
using L2 = IntList<4,9,2,65,432>;	

template<typename L1, typename L2, template <int, int> class Op>
struct Zip;
 
template<int... Val1, int... Val2, template <int, int> class Op>
struct Zip<IntList<Val1...>, IntList<Val2...>, Op>
{
    using type = IntList<Op<Val1, Val2>::value...>;
};

template<template<int, int> class Op>
struct Zip<IntList<>, IntList<>, Op>{
    using type = IntList<>;
};

template<int a, int b>
struct sum
{
    static int const value = a + b;
};

int main() {
	using L3 = Zip<L1, L2, sum>::type;
}




























