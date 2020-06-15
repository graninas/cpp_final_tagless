#ifndef IO_H
#define IO_H

#include "prelude.h"

namespace ft {

template<typename M>
concept IO = requires(M m, std::string path) {
    m.readFile(path);
};



}
#endif // IO_H
