#ifndef FT_H
#define FT_H

#include "prelude.h"
#include "io.h"
#include "kv_db.h"
#include "logger.h"
#include "random.h"
#include "expected.h"
#include "optional.h"
#include "serialization.h"
#include "unit.h"

#endif // FT_H


/*

  Algorithms/Properties/capabilities/requirements::

    Sort

    Foldable
    Traverse

    EqualityComparable
    Incrementable
    Comparable

  Invariants:

    Sorted
    Ordered
    Capitalized

  eDSLs:

    getUser
    setUser


  System concepts:
    https://en.cppreference.com/w/cpp/concepts

  Concepts from ranges (algorithms):
    https://en.cppreference.com/w/cpp/algorithm/ranges#Algorithm_concepts_and_utilities
    https://en.cppreference.com/w/cpp/ranges#Range_concepts


  Standard classification:

    [concepts.equality]	Equality preservation
    [concepts.lang]	Language-related concepts	<concepts>
    [concepts.compare]	Comparison concepts
    [concepts.object]	Object concepts
    [concepts.callable]	Callable concepts
*/


/*

  Тезисы

1. Концепты по -fconcepts в gcc 8 отличаются по синтаксису от стандартных.

    Легенда:
    <  -fconcepts
    >  standard concepts

    Различия:

    < нужен тип bool после concept
    <    concept bool Logger = requires...
    < req clauses должны быть в curly braces без точек с запятой внутри

    <   { logInfo(a, msg) };
    <   { logInfo2(a, msg) };

    > req clauses могут быть просто выражениями на отдельных строчках без curly braces:
    >   logInfo(a, msg);
    >   logInfo2(a, msg);

1a. Концепты по -fconcepts-ts отличаются по синтаксису от стандартных.

   - В стандартных, return-type-constraint не работает с типами, и можно использовать только концепты:

     // не работает
     { toString<M>(m)   } -> std::string;
     { fromString<M>(v) } -> std::expected<ParseError, M>;

     // работает
     { toString<M>(m)    } -> std::convertible_to<std::string>;
     { fromString<M>(v)  } -> std::same_as<std::expected<ParseError, M>>;

     // (но неясно как это работает, ведь std::same_as и std::convertible_to имеют 2 шаблонных параметра)

     https://stackoverflow.com/questions/57751484/are-types-allowed-to-be-specified-for-return-type-requirement-in-a-requires-expr



2. Туториалов и документации нет.
3. Статьи сосредоточены на системных концептах и не раскрывают суть создания своих.
4. Концепты для определения eDSL - пока неосвещенная тема.
   - Классы типов четко описывают типы и методы. Синтаксис концептов более общий,
     менее сфокусированный и менее удобный.
   - Системные концепты большей частью затрагивают type level.
     Концепты для eDSL затрагивают term level.
   - Шаблонами можно сделать всё, что делают концепты, но более сложным образом,
     и с более плохими ошибками.
   - return-type-constraint не работает с типами:

     { toString<M>(m)   } -> std::string;
     { fromString<M>(v) } -> std::expected<ParseError, M>;

     std::string и std::expected указывать нельзя, можно только концепты (constraints).



5. Пропозалов концептов было много разных.
6?. Арифметические концепты - лишь теги, нет методов по работе с типами этих концептов.
7. Концепты работают в связке с templates.
8?. Есть синтакс для определения методов, но неясно, как его использовать, и что он вообще означает.

    > concept bool Logger = requires(M a, void(M::*pp)(std::string)) {
        { pp = &M::logMessage } -> void;
        };

9. 2 варианта eDSL: object-based & function-based

    - Object-based:
        template<typename M>
        concept Logger = requires(M a, std::string msg) {
            a.logMessage(msg);
        };
        class Game {

        public:
            void logMessage(const std::string& msg) const {
                std::cout << msg;
            }
        };

    - Function-based:
        * tempalte function-based:

            template<typename M>
            concept Logger = requires(M m, std::string msg) {
                logMessage2(m, msg);
            };

            template<typename M>
            void logMessage2(M m, const std::string& msg) {
                m.logMessage(msg);
            }
        * specific function-based (more or like an instance of a type class):
            template<typename M>
            concept Logger = requires(M m, std::string msg) {
                logMessage2(m, msg);
            };

            void logMessage3(Game g, const std::string& msg) {
                g.logMessage(msg);
            }

10. Стоит различать концепты как фичу языка и концепты как библиотечные примитивы.

  - concept some_concept  // feature
  - #include <concepts>  // built-in concepts library



  Доклады по теме
1. Ivan Čukić — Move only C++ design
   https://www.youtube.com/watch?v=04HcVuqlZ5E
2. CppCon 2018: Andrew Sutton “Concepts in 60: Everything you need to know and nothing you don't”
   https://www.youtube.com/watch?v=ZeU6OPaGxwM
3. Павел Филонов. Концепты C++ (-fconcepts) и классы типов Haskell.
   https://youtu.be/f6TmB6Zw8MQ?t=79
4. Hendrik Niemeyer "Intro to C++20's Concepts"
   https://www.youtube.com/watch?v=rROoYqDr2KM
*/
