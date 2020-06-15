
#include <iostream>
#include <string>


template<typename M>
concept Logger = requires(M m, std::string msg) {
    m.logMessage(msg);
};

template<typename M>
concept IO = requires(M m, std::string path) {
    m.readFile(path);
};

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


struct GameInfo {

};

template <typename M>
void movePlayer(M& m)
    requires IO<M> && Logger<M>
        && KV_Write<M, int, GameInfo>
        && KV_Write2<M>
{
    m.logMessage("abc");
    auto res = m.readFile("file.txt");
    m.put(1, GameInfo {});
}


// ----------------------------------------------------------------

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

static_assert (Logger<Game>);


int main() {
    Game game;

    movePlayer<Game>(game);
}
