#ifndef ILINEGENERATOR_H
#define ILINEGENERATOR_H

#include <vector>

#include <Sequence.hpp>

namespace NS
{
    class ILineGenerator
    {
    public:
        using Line = std::vector<unsigned int>;

        // Constructors
        ILineGenerator() = default;

        // Destructor
        ~ILineGenerator() = default;

        virtual std::vector<Line> generateLines() = 0;
    };
}

#endif /* ILINEGENERATOR_H */