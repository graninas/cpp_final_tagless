#ifndef LOGGER_H
#define LOGGER_H

#include <functional>
#include <string>
#include <variant>
#include <list>
#include <any>
#include <vector>

#include <string>
#include <locale>


namespace lab {

template<typename M>
concept bool Logger = requires(M a, void(M::*pp)(std::string)) {
    { pp = &M::logMessage } -> void;
};




}
#endif // LOGGER_H
