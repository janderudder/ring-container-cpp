#pragma once
#include <iostream>


/**
 *  Print expression, then evaluate it and print result.
 */
#define ECHO(X)                             \
    ([&] (auto const& x) {                  \
        std::cout                           \
            << (#X) << " : "                \
            << (X);                         \
    }(X))


/**
 *  Print expression, evaluate it and print result, then print a new line.
 */
#define ECHO_LN(X)                          \
    ([&] (auto const& x) {                  \
        std::cout                           \
            << (#X) << " : "                \
            << (X) << "\n";                 \
    }(X))


/**
 *  Print a new line
 */
#define NL(Stream)                          \
    ([](std::ostream& os = std::cout) {     \
        os << "\n";                         \
    }(Stream))
