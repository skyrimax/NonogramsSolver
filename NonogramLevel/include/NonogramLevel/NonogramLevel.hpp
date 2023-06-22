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

        NonogramLevel(std::vector<Sequence> rows, std::vector<Sequence> cols);

        NonogramLevel(const NonogramLevel &nonogramLevel);

        NonogramLevel(NonogramLevel &&nonogramLevel);

    private:
        std::vector<Sequence> rows_;
        std::vector<Sequence> cols_;
    };
}

#endif /* IMAGE_H */