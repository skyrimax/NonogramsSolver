#ifndef ALLPOSSIBLELINESGENERATOR_H
#define ALLPOSSIBLELINESGENERATOR_H

#include "ILineGenerator.hpp"

#include "LineFilter/ILineFilter.hpp"

namespace NS
{
    class AllPossibleLinesGenerator : public ILineGenerator
    {
    public:
        // Constructors
        AllPossibleLinesGenerator(unsigned int nbBoxes);

        // Destructor
        ~AllPossibleLinesGenerator() = default;

        virtual std::vector<Line> generateLines(const ILineFilter& filter);

    private:
        std::vector<Line> createAllPossibilities(unsigned int nbBoxes);
        std::vector<Line> filterPossibilities(std::vector<Line> possibilities, const ILineFilter& filter);

        unsigned int nbBoxes_;
    };
}

#endif /* ALLPOSSIBLELINESGENERATOR_H */