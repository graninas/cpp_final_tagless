#ifndef FT_TYPES_H
#define FT_TYPES_H

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

int testF() {
  return f("abc"s, "cde"s); // OK, std::string is EqualityComparable
//  f(std::use_facet<std::ctype<char>>(std::locale{})); // Error: not EqualityComparable
}

} // namespace ft

#endif // FT_TYPES_H
