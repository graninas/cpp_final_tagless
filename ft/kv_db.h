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
template<typename K>
concept KV_Key = requires(K k) {
    { encode_key(k) } -> std::same_as<std::string>;
};

template<typename V>
concept KV_Value = requires(V v) {
    { encode_value(v) } -> std::same_as<std::string>;
};

// Typed interface to KV DB

//template<typename M, typename K, typename V>
//concept KV_Write =
//    KV_Key<K> && KV_Value<V>
//    && KV_RawWrite<M>
//    && requires(M m, K k, V v) {

//    { write(m, k, v) } -> std::same_as<DBResult<Unit>>;

//};

// Helper, default impl

template<typename M, typename K, typename V>
DBResult<Unit> write(const M& m, const K& k, const V& v) {
    return m.raw_write(encode_key(k), encode_value(v));
}

}
#endif // KVDB_H
