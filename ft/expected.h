#ifndef EXPECTED_H
#define EXPECTED_H

#include <variant>

namespace ft {

template <typename E, typename T>
using expected = std::variant<E, T>;

}

#endif // EXPECTED_H


