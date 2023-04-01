#ifndef ILINESEQUENCER_H
#define ILINESEQUENCER_H

#include <vector>

class ILineSequencer
{
public:
    using Sequence = std::vector<unsigned int>;
    using Line = std::vector<unsigned int>;

    // Constructor
    ILineSequencer() = default;

    // Destructor
    ~ILineSequencer() = default;

    // Member methods
    virtual Sequence operator()(Line line) const = 0;
};

#endif /* ILINESEQUENCER_H */