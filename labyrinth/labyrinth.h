#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "../ft/ft.h"

namespace lab {

struct GameInfo {

};

class Game {

public:
    void logMessage(const std::string& msg) const {
        std::cout << msg;
    }

    std::string readFile(const std::string& msg) const {
        return "some content";
    }

    void put(int k, const GameInfo& v) {

    }

    void put2(const std::string& k, const std::string& v) {

    }
};

static_assert (ft::Logger<Game>);


template <typename M>
void movePlayer(M& m)
    requires ft::IO<M> && ft::Logger<M>
        && ft::KV_Write<M, int, GameInfo>
        && ft::KV_Write2<M>
{
    m.logMessage("abc");
    auto res = m.readFile("file.txt");
    m.put(1, GameInfo {});
}





}

#endif // LABYRINTH_H
