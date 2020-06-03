#ifndef FT_FEATURE_TEST_H
#define FT_FEATURE_TEST_H

#include <functional>
#include <string>
#include <variant>
#include <list>
#include <any>
#include <vector>

#include <string>
#include <locale>

using namespace std::literals;

namespace ft
{

constexpr int add(int a, int b)
{
    return a + b;
}

template<typename T>
concept bool EqualityComparable = requires(T a, T b) {
    { a == b } -> bool;
};


template<typename T>
int f(T&& t1, T&& t2) requires EqualityComparable<T>
{
    if (t1 == t2)
        return 0;
    return 1;
}



template<typename T>
    requires EqualityComparable<T>
int f2(T&& t1, T&& t2)
{
    if (t1 == t2)
        return 0;
    return 1;
}

int testF() {
  f("abc"s, "cde"s);
  f2("abc"s, "cde"s);

//  f(std::use_facet<std::ctype<char>>(std::locale{})); // Error: not EqualityComparable
}

} // namespace ft

#endif // FT_FEATURE_TEST_H
