#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "prelude.h"
#include "labyrinth/logger.h"

namespace lab {


class Game {

public:
//    void logMessage(const std::string& msg)
    bool logMessage() const
    {
        std::cout << "abc";
        return true;
    }
};



template <Logger M>
void movePlayer(const M& a)
{
    a.logMessage();
}




}

#endif // LABYRINTH_H
