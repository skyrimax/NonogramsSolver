#ifndef SQUARE_H
#define SQUARE_H

namespace NS
{
    enum class Square: int {
        Empty=0,
        Filled=1,
        Undefined=-1
    };

    enum class DefinedSquare: int {
        Empty=0,
        Filled=1
    };

    bool operator==(NS::Square s1, NS::DefinedSquare s2);
    bool operator!=(NS::Square s1, NS::DefinedSquare s2);
    bool operator==(NS::DefinedSquare s1, NS::Square s2);
    bool operator!=(NS::DefinedSquare s1, NS::Square s2);
}

#endif /* SQUARE_H */