#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <variant>
#include "unit.h"

namespace ft {

template <typename T>
using optional = std::variant<Unit, T>;

}

#endif // OPTIONAL_H


