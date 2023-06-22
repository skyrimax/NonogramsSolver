#ifndef IMAGE_H
#define IMAGE_H

#include <vector>

namespace NS
{
    class NonogramLevel
    {
    public:
        using Sequence = std::vector<unsigned int>;

        NonogramLevel();

        NonogramLevel(Sequence rows, Sequence cols);

        NonogramLevel(const NonogramLevel &nonogramLevel);

        NonogramLevel(NonogramLevel &&nonogramLevel);
    };
}

#endif /* IMAGE_H */