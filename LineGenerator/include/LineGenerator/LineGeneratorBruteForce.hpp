#include "ILineGenerator.hpp"

namespace NS
{
    class LineGeneratorBruteForce : public ILineGenerator
    {
    public:
        virtual std::vector<std::vector<bool>> generateLines(unsigned int nbBoxes, const std::vector<unsigned int>& lineSequence);

    private:
        void createAllPossibilities(unsigned int nbBoxes);
        void filterPossibilities(const std::vector<unsigned int>& lineSequence);

        std::vector<std::vector<bool>> _possibilities;
    };
}