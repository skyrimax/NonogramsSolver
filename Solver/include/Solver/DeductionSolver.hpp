#ifndef DEDUCTIONSOLVER_H
#define DEDUCTIONSOLVER_H

#include "ISolver.hpp"

namespace NS
{
    class DeductionSolver: public ISolver
    {
    public:
        virtual int solve(NonogramLevel& nonogramLevel, Image& returnImage);
    };
}

#endif /* DEDUCTIONSOLVER_H */