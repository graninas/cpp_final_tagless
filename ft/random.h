#ifndef RANDOM_H
#define RANDOM_H

#include "prelude.h"
#include "unit.h"
#include "expected.h"
#include <concepts>

namespace ft {

template<class M, typename T>
concept Random = std::integral<T>
    && requires(M m, T from, T to) {
    { m.get_random_int(from, to) } -> std::same_as<T>;
};



}
#endif // RANDOM_H
