#include "ILineGenerator.hpp"

namespace NS
{
    class LineGeneratorBruteForce : public ILineGenerator
    {
    public:
        virtual std::vector<Line> generateLines(unsigned int nbBoxes, const Sequence& lineSequence);

    private:
        std::vector<Line> createAllPossibilities(unsigned int nbBoxes);
        std::vector<Line> filterPossibilities(std::vector<Line>& possibilities, const Sequence& lineSequence);
    };
}