#ifndef KVDB_H
#define KVDB_H

#include "prelude.h"

namespace ft {

template<typename M, typename K, typename V>
concept KV_Write = requires(M m, K k, V v) {
    m.put(k, v);
};

template<typename M>
concept KV_Write2 = requires(M m, std::string k, std::string v) {
    m.put2(k, v);
};

template<typename M, typename K, typename V>
concept KV_Read = requires(M m, K k) {
    m.get(k);
};

}
#endif // KVDB_H
