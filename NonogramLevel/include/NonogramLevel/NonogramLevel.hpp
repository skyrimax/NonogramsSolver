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

        NonogramLevel(const std::vector<Sequence>& rowSequences, const std::vector<Sequence>& colSequences);

        NonogramLevel(const NonogramLevel &nonogramLevel);

        NonogramLevel(NonogramLevel &&nonogramLevel);

        // Accesseurs
        std::vector<Sequence>& rowSequences();
        const std::vector<Sequence>& rowSequences() const;
        std::vector<Sequence>& colSequences();
        const std::vector<Sequence>& colSequences() const;

        // Row adding methods
        void addRowSequence(const Sequence& rowSequence);
        void addRowSequence(Sequence&& rosSequence);
        void addRowSequences(const std::vector<Sequence>& rowSequences);
        void addRowSequences(std::vector<Sequence>&& rowSequences);

    private:
        std::vector<Sequence> rowSequences_;
        std::vector<Sequence> colSequences_;
    };
}

#endif /* NONOGREAMLEVEL_H */