#ifndef FT_H
#define FT_H


namespace ft {


} // namespace ft

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

    < нужен тип bool после concepts
    <    concept bool Logger = requires...
    < req clauses должны быть в curly braces без точек с запятой внутри

    <   { logInfo(a, msg) };
    <   { logInfo2(a, msg) };

    > req clauses могут быть просто выражениями на отдельных строчках без curly braces:
    >   logInfo(a, msg);
    >   logInfo2(a, msg);


2. Туториалов и документации нет.
3. Статьи сосредоточены на системных концептах и не раскрывают суть создания своих.
4. Концепты для определения eDSL - пока неосвещенная тема.
5. Пропозалов концептов было много разных.
6?. Арифметические концепты - лишь теги, нет методов по работе с типами этих концептов.
7. Концепты работают в связке с templates.
8?. Есть синтакс для определения методов, но неясно, как его использовать, и что он вообще означает.

    > concept bool Logger = requires(M a, void(M::*pp)(std::string)) {
        { pp = &M::logMessage } -> void;
        };

9.

  Доклады по теме
1. Ivan Čukić — Move only C++ design
   https://www.youtube.com/watch?v=04HcVuqlZ5E
2. CppCon 2018: Andrew Sutton “Concepts in 60: Everything you need to know and nothing you don't”
   https://www.youtube.com/watch?v=ZeU6OPaGxwM
3. Павел Филонов. Концепты C++ (-fconcepts) и классы типов Haskell.
   https://youtu.be/f6TmB6Zw8MQ?t=79
*/
