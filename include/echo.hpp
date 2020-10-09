#pragma once
#include <iostream>
#include <type_traits>


/**
 *  Print expression, then evaluate it and print result.
 */
#define ECHO(X)                             \
    ([&] (auto const& x)                    \
     -> std::remove_const_t<decltype(X)> {  \
        std::cout                           \
            << (#X) << " : "                \
            << (X);                         \
        return x;                           \
    }(X))


/**
 *  Print expression, evaluate it and print result, then print a new line.
 */
#define ECHO_LN(X)                          \
    ([&] (auto const& x)                    \
     -> std::remove_const_t<decltype(X)> {  \
        std::cout                           \
            << (#X) << " : "                \
            << (X) << "\n";                 \
        return x;                           \
    }(X))


/**
 *  Print a new line
 */
#define NL(Stream)                          \
    ([](std::ostream& os = std::cout) {     \
        os << "\n";                         \
    }(Stream))
