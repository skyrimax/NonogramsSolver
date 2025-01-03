#ifndef ILINESEQUENCER_H
#define ILINESEQUENCER_H

#include <vector>

#include <Sequence.hpp>

class ILineSequencer
{
public:
    using Line = std::vector<unsigned int>;

    // Constructor
    ILineSequencer() = default;

    // Destructor
    ~ILineSequencer() = default;

    // Member methods
    virtual NS::Sequence operator()(const Line& line) const = 0;
};

#endif /* ILINESEQUENCER_H */