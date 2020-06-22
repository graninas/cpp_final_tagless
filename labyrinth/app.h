#ifndef APP_H
#define APP_H

#include "../ft/ft.h"

#include <map>
#include <experimental/random>

namespace lab {

struct GameInfo {

};

class App {

private:

    std::map<std::string, std::string> kvdb;

public:
    void log_message(const std::string& msg) const {
        std::cout << msg;
    }

    std::string read_file(const std::string& msg) const {
        return "some content";
    }

    ft::DBResult<ft::Unit> raw_write(const std::string& k, const std::string& v) {
        kvdb[k] = v;
        return ft::Unit{};
    }

    ft::DBResult<ft::optional<std::string>> raw_read(const std::string& k) {
        if (kvdb.contains(k))
            return ft::optional<std::string>(kvdb[k]);
        return ft::Unit{};
    }

    // TODO: make methods independent
    static std::string encode_key(int k) {
        return std::to_string(k);
    }

    static std::string encode_value(GameInfo gi) {
        return "";   // TODO
    }

    static ft::optional<GameInfo> decode_value(const std::string& raw_val) {
        return GameInfo {};   // TODO
    }

    int get_random_int(int from, int to) const {
        return std::experimental::randint(from, to);
    }
};

static_assert (ft::Logger<App>);
static_assert (ft::Random<App, int>);
static_assert (ft::IO<App>);

static_assert (ft::KV_Key<App, int>);
static_assert (ft::KV_Value<App, GameInfo>);
static_assert (ft::KV_Write<App, int, GameInfo>);
static_assert (ft::KV_Read<App, int, GameInfo>);


template <typename M>
void test_method(M& m)
    requires ft::Logger<M>
        && ft::KV_Write<M, int, GameInfo>
{
    m.log_message("abc");
    auto res = m.read_file("file.txt");
    ft::kv_write(m, 1, GameInfo {});
    // GameInfo gi = ft::kv_read(m, 1);
}



template <typename M>
void generate_and_say(M& m)
    requires ft::Logger<M>
        && ft::Random<M, int>
{
    int die = m.get_random_int(1, 6);
    m.log_message("You got: " + std::to_string(die));
}




}

#endif // APP_H
