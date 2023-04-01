#ifndef ILINEGENERATOR_H
#define ILINEGENERATOR_H

#include <vector>
#include <string>

namespace NS
{
    class ILineGenerator
    {
    public:
        using Sequence = std::vector<unsigned int>;
        using Line = std::vector<unsigned int>;

        // Constructors
        ILineGenerator() = default;

        // Destructor
        ~ILineGenerator() = default;

        virtual std::vector<Line> generateLines(unsigned int nbBoxes, const Sequence& lineSequence) = 0;
    };
}

#endif /* ILINEGENERATOR_H */