#include <vector>
#include <string>

namespace NS
{
    class ILineGenerator
    {
    public:
        virtual std::vector<std::vector<bool>> generateLines(unsigned int nbBoxes, const std::vector<unsigned int>& lineSequence) = 0;
    };
}
