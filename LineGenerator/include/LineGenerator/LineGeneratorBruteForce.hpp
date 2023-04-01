#include "ILineGenerator.hpp"

namespace NS
{
    class LineGeneratorBruteForce : public ILineGenerator
    {
    public:
        virtual std::vector<Line> generateLines(unsigned int nbBoxes, const Sequence& lineSequence);

    private:
        void createAllPossibilities(unsigned int nbBoxes);
        void filterPossibilities(const std::vector<unsigned int>& lineSequence);
    };
}