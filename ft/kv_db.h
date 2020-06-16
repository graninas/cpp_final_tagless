#ifndef KVDB_H
#define KVDB_H

#include "prelude.h"
#include "unit.h"
#include "expected.h"

namespace ft {

enum class DBError {
    KeyNotFound
};

template <typename V>
using DBResult = std::expected<DBError, V>;


// -- Raw interface to KV DB

template<typename M>
concept KV_RawWrite = requires(M m, std::string k, std::string v) {
    { m.raw_write(k, v) } -> std::same_as<DBResult<Unit>>;
};

template<typename M>
concept KV_RawRead = requires(M m, std::string k) {
    { m.raw_read(k) } -> std::same_as<DBResult<std::string>>;
};

// -- Key & Value
template<typename M, typename K>
concept KV_Key = requires(M, K k) {
    { M::encode_key(k) } -> std::same_as<std::string>;
};

template<typename M, typename V>
concept KV_Value = requires(M, V v) {
    { M::encode_value(v) } -> std::same_as<std::string>;
};


// Helper, default impl, should be defined before concept

template<typename M, typename K, typename V>
DBResult<Unit> write(M& m, const K& k, const V& v) {
    return m.raw_write(M::encode_key(k), M::encode_value(v));
}

// Typed interface to KV DB

template<typename M, typename K, typename V>
concept KV_Write =
    KV_Key<M, K> && KV_Value<M, V>
    && KV_RawWrite<M>
    && requires(M m, K k, V v) {

    { ft::write(m, k, v) } -> std::same_as<DBResult<Unit>>;
};


}
#endif // KVDB_H
