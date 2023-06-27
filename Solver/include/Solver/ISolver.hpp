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
        virtual int solve(const NonogramLevel& nonogramLevel, Image& returnImage) const = 0;
    };
}

#endif /* ISOLVER_H */