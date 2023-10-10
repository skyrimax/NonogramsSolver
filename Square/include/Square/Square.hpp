#ifndef SQUARE_H
#define SQUARE_H

#include "DefinedSquare.hpp"

namespace NS
{
    enum class Square: int {
        Empty=0,
        Filled=1,
        Undefined=-1
    };
}

#endif /* SQUARE_H */