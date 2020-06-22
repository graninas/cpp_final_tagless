#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "prelude.h"
#include "expected.h"

namespace ft {

struct ParseError {
    std::string msg;
};

template<typename V>
concept Encode = requires(V v) {
    { encode<V>(v) } -> std::convertible_to<std::string>;
};


template<typename V>
concept Decode = requires(std::string str) {
    { decode<V>(str) } -> std::same_as<expected<ParseError, V>>;
};


}
#endif // SERIALIZATION_H
