#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "prelude.h"
#include "labyrinth/logger.h"

namespace lab {


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




}

#endif // LABYRINTH_H
