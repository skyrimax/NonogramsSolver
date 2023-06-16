#ifndef ISOLVER_H
#define ISOLVER_H

#include <vector>

namespace NS
{
    class ISolver
    {
    public:
        using Sequence = std::vector<unsigned int>;

        struct Nonogram
        {
            std::vector<Sequence> rows;
            std::vector<Sequence> columns;
        };
        
    };
}

#endif /* ISOLVER_H */