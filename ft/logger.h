#ifndef LOGGER_H
#define LOGGER_H

#include "prelude.h"

namespace ft {

template<typename M>
concept Logger = requires(M m, std::string msg) {
    m.logMessage(msg);
};



}
#endif // LOGGER_H
