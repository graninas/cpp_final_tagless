#ifndef FUNCTIONAL_CONCEPTS_H
#define FUNCTIONAL_CONCEPTS_H

#include "prelude.h"


template <template<class> class F, typename A, typename B>
concept Functor = requires(F<A> ma, std::function<B(A)> f) {
    { fmap(f, ma) } -> std::same_as<F<B>>;
};



template <template<class> class F, typename A, typename B>
concept Foldable = requires(F<A> ma, std::function<B(A, B)> f, B val0) {
    { foldr(f, val0, ma) } -> std::same_as<B>;
};






#endif // FUNCTIONAL_CONCEPTS_H

