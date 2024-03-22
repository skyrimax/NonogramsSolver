#include "Square.hpp"

bool NS::operator==(NS::Square s1, NS::DefinedSquare s2)
{
    return static_cast<int>(s1) == static_cast<int>(s2);
}

bool NS::operator!=(NS::Square s1, NS::DefinedSquare s2)
{
    return !(s1 == s2);
}

bool NS::operator==(NS::DefinedSquare s1, NS::Square s2)
{
    return static_cast<int>(s1) == static_cast<int>(s2);
}

bool NS::operator!=(NS::DefinedSquare s1, NS::Square s2)
{
    return !(s1 == s2);
}