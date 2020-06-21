#ifndef LOGGER_H
#define LOGGER_H

#include "prelude.h"

namespace ft {

template<class M>
concept Logger = requires(M m, std::string msg) {
    { m.log_message(msg) } -> std::same_as<void>;
};



}
#endif // LOGGER_H
