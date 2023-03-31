#ifndef FSTLINESEQUENCER_H
#define FSTLINESEQUENCER_H

#include "ILineSequencer.hpp"

class FSTLineSequencer: public ILineSequencer
{
public:

    // Constructor
    FSTLineSequencer() = default;

    // Destructor
    ~FSTLineSequencer() = default;

    // Member methods
    virtual Sequence operator()(Line line);
};

#endif /* FSTLINESEQUENCER_H */