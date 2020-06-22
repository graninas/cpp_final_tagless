#ifndef KVDB_H
#define KVDB_H

#include "prelude.h"
#include "unit.h"
#include "expected.h"
#include "optional.h"

namespace ft {

enum class DBError {
    ConnectionError
};

template <typename V>
using DBResult = expected<DBError, V>;


// -- Raw interface to KV DB

template<class M>
concept KV_RawWrite = requires(M m, std::string k, std::string v) {
    { m.raw_write(k, v) } -> std::same_as<DBResult<Unit>>;
};

template<class M>
concept KV_RawRead = requires(M m, std::string k) {
    { m.raw_read(k) } -> std::same_as<DBResult<optional<std::string>>>;
};

// -- Key & Value
template<class M, typename K>
concept KV_Key = requires(M, K k) {
    { M::encode_key(k) } -> std::same_as<std::string>;
};

template<class M, typename V>
concept KV_Value = requires(M, V v, std::string vStr) {
    { M::encode_value(v)    } -> std::same_as<std::string>;
    { M::decode_value(vStr) } -> std::same_as<optional<V>>;
};


// Helper, default impl, should be defined before concept

// TODO: concepts for M::encode_key, M::decode_key, M::encode_value, M::decode_value

template<class M, typename K, typename V>
DBResult<Unit> kv_write(M& m, const K& k, const V& v) {
    return m.raw_write(M::encode_key(k), M::encode_value(v));
}

template<class M, typename K, typename V>
DBResult<optional<V>> kv_read(M& m, const K& k) {
   return M::decode_value(m.raw_read(M::encode_key(k)));
}

// Typed interface to KV DB

template<class M, typename K, typename V>
concept KV_Write =
    KV_Key<M, K> && KV_Value<M, V>
    && KV_RawWrite<M>
    && requires(M m, K k, V v) {

    { ft::kv_write<M, K, V>(m, k, v) } -> std::same_as<DBResult<Unit>>;
};

template<class M, typename K, typename V>
concept KV_Read =
    KV_Key<M, K> && KV_Value<M, V>
    && KV_RawRead<M>
    && requires(M m, K k) {

    { ft::kv_read<M, K, V>(m, k) } -> std::same_as<DBResult<optional<V>>>;
};

}
#endif // KVDB_H
