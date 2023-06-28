#ifndef NONOGREAMLEVEL_H
#define NONOGREAMLEVEL_H

#include <cstddef>
#include <vector>

namespace NS
{
    class NonogramLevel
    {
    public:
        typedef size_t size_type;
        using Sequence = std::vector<unsigned int>;

        NonogramLevel() = default;

        NonogramLevel(const std::vector<Sequence>& rowSequences, const std::vector<Sequence>& colSequences);

        NonogramLevel(const NonogramLevel &nonogramLevel);

        NonogramLevel(NonogramLevel &&nonogramLevel);

        // Accesseurs
        Sequence& rowSequence(size_type row);
        const Sequence& rowSequence(size_type row) const;
        std::vector<Sequence>& rowSequences();
        const std::vector<Sequence>& rowSequences() const;
        Sequence& colSequence(size_type col);
        const Sequence& colSequence(size_type col) const;
        std::vector<Sequence>& colSequences();
        const std::vector<Sequence>& colSequences() const;

        // Row sequences adding methods
        void addRowSequence(const Sequence& rowSequence);
        void addRowSequence(Sequence&& rosSequence);
        void addRowSequences(const std::vector<Sequence>& rowSequences);
        void addRowSequences(std::vector<Sequence>&& rowSequences);

        // Column sequences adding methods
        void addColSequence(const Sequence& rowSequence);
        void addColSequence(Sequence&& rosSequence);
        void addColSequences(const std::vector<Sequence>& rowSequences);
        void addColSequences(std::vector<Sequence>&& rowSequences);

    private:
        std::vector<Sequence> rowSequences_;
        std::vector<Sequence> colSequences_;
    };
}

#endif /* NONOGREAMLEVEL_H */