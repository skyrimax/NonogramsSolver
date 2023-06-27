#ifndef NONOGREAMLEVEL_H
#define NONOGREAMLEVEL_H

#include <vector>

namespace NS
{
    class NonogramLevel
    {
    public:
        using Sequence = std::vector<unsigned int>;

        NonogramLevel() = default;

        NonogramLevel(const std::vector<Sequence>& rows, const std::vector<Sequence>& cols);

        NonogramLevel(const NonogramLevel &nonogramLevel);

        NonogramLevel(NonogramLevel &&nonogramLevel);

        // Accesseurs
        std::vector<Sequence>& rows();
        const std::vector<Sequence>& rows() const;
        std::vector<Sequence>& cols();
        const std::vector<Sequence>& cols() const;

    private:
        std::vector<Sequence> rows_;
        std::vector<Sequence> cols_;
    };
}

#endif /* NONOGREAMLEVEL_H */