#ifndef ISOLVER_H
#define ISOLVER_H

#include <vector>
#include <Image.hpp>
#include <NonogramLevel.hpp>

namespace NS
{
    class ISolver
    {
    public:
        virtual int solve(NonogramLevel& nonogram, Image& returnImage) = 0;
    };
}

#endif /* ISOLVER_H */