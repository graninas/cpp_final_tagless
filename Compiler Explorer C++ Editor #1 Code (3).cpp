
#include <iostream>
#include <string>


template<typename M>
concept Logger = requires(M a, const std::string& msg) {
    a.logMessage(msg);
};


class Game {

public:
    void logMessage(const std::string& msg) const
    {
        std::cout << msg;
    }
};

static_assert (Logger<Game>);


template <Logger M>
void movePlayer(const M& a)
{
    a.logMessage("abc");
}


int main(){
    Game game;

    movePlayer<Game>(game);
}