#include "ILineGenerator.hpp"

#include "LineFilter/ILineFilter.hpp"

namespace NS
{
    class LineGeneratorAllPossibleLines : public ILineGenerator
    {
    public:
        // Constructors
        LineGeneratorBruteForce() = default;

        // Destructor
        ~LineGeneratorBruteForce() = default;

        virtual std::vector<Line> generateLines(unsigned int nbBoxes, const ILineFilter& filter);

    private:
        std::vector<Line> createAllPossibilities(unsigned int nbBoxes);
        std::vector<Line> filterPossibilities(std::vector<Line> possibilities, const ILineFilter& filter);

        ILineFilter& filter_;
    };
}