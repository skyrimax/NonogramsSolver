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

    bool operator==(Square s1, DefinedSquare s2)
    {
        return static_cast<int>(s1) == static_cast<int>(s2);
    }

    bool operator!=(Square s1, DefinedSquare s2)
    {
        return !(s1 == s2);
    }

    bool operator==(DefinedSquare s1, Square s2)
    {
        return static_cast<int>(s1) == static_cast<int>(s2);
    }

    bool operator!=(DefinedSquare s1, Square s2)
    {
        return !(s1 == s2);
    }
}

#endif /* SQUARE_H */