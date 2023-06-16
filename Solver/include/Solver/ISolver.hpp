#ifndef ISOLVER_H
#define ISOLVER_H

#include <vector>
#include <grid.hpp>

namespace NS
{
    class ISolver
    {
    public:
        using Sequence = std::vector<unsigned int>;
        using Image = Grid<int>;

        struct Nonogram
        {
            std::vector<Sequence> rows;
            std::vector<Sequence> columns;
        };
        
        virtual int solve(Nonogram& nonogram, Image& returnImage) = 0;
    };
}

#endif /* ISOLVER_H */