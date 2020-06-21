#ifndef IO_H
#define IO_H

#include "prelude.h"

namespace ft {

template<class M>
concept IO = requires(M m, std::string path) {
    m.read_file(path);
};



}
#endif // IO_H
