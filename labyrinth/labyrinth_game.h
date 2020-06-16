#ifndef LABYRINTH_GAME_H
#define LABYRINTH_GAME_H

#include "../ft/ft.h"

#include <map>

namespace lab {

struct GameInfo {

};

class Game {

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
    }

    // TODO: make methods independent
    static std::string encode_key(int k) {
        return std::to_string(k);
    }

    static std::string encode_value(GameInfo gi) {
        return "";   // TODO
    }
};

static_assert (ft::KV_Key<Game, int>);
static_assert (ft::KV_Value<Game, GameInfo>);

static_assert (ft::Logger<Game>);
static_assert (ft::IO<Game>);
static_assert (ft::KV_Write<Game, int, GameInfo>);


template <typename M>
void move_player(M& m)
    requires ft::Logger<M>
        && ft::KV_Write<M, int, GameInfo>
{
    m.log_message("abc");
    auto res = m.read_file("file.txt");
    ft::write(m, 1, GameInfo {});
}





}

#endif // LABYRINTH_GAME_H
