#ifndef LABYRINTH_GAME_H
#define LABYRINTH_GAME_H

#include "../ft/ft.h"

#include <map>

namespace lab {

struct GameInfo {

};

std::string encode_key(int k) {
    return std::to_string(k);
}

std::string encode_value(GameInfo gi) {
    return "";   // TODO
}


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

    void raw_write(const std::string& k, const std::string& v) {
        kvdb[k] = v;
    }
};

static_assert (ft::KV_Key<int>);
static_assert (ft::KV_Value<GameInfo>);

static_assert (ft::Logger<Game>);
//static_assert (ft::KV_RawWrite<Game>);


//template <typename M>
//void move_player(M& m)
//    requires ft::IO<M>
//        && ft::Logger<M>
//        && ft::KV_Write<M, int, GameInfo>
//        && ft::KV_RawWrite<M>
//{
//    m.log_message("abc");
//    auto res = m.read_file("file.txt");
//    m.write(1, GameInfo {});
//}





}

#endif // LABYRINTH_GAME_H
