#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <variant>
#include "unit.h"
#include "functional_concepts.h"

namespace ft {

template <typename T>
using optional = std::variant<Unit, T>;


template <typename A, typename B>
optional<B> fmap(const std::function<B(A)>& f, const optional<A>& ma)
{
    if (ma.index() == 0) {
        return optional<B>(Unit{});
    }
    auto a = std::get<1>(ma);
    return optional<B>(f(a));
}



template <typename A, typename B>
struct FOptHelper {
    static_assert(Functor<optional, A, B>);
};

FOptHelper<int, int> intOptHelper;

}

#endif // OPTIONAL_H


