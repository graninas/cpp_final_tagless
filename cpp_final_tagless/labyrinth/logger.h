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
concept bool Logger = requires(M a) {
    // logMessage(const std::string&) -> void;
    { a.logMessage() } -> bool;
};




}
#endif // LOGGER_H
