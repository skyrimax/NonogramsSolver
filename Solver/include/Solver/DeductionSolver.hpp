#ifndef DEDUCTIONSOLVER_H
#define DEDUCTIONSOLVER_H

#include "ISolver.hpp"

namespace NS
{
    class DeductionSolver: public ISolver
    {
    public:
        virtual int solve(const NonogramLevel& nonogramLevel, Image& returnImage) const override;
    };
}

#endif /* DEDUCTIONSOLVER_H */