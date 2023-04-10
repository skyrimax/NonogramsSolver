#ifndef SEQUENCERLINEFILTER_H
#define SEQUENCERLINEFILTER_H

#include "ILineFilter.hpp"

#include "ILineSequencer.hpp"

class SequenceLineFilter: public ILineFilter
{
public:
    // Contructors
    SequenceLineFilter(const Sequence& sequence, const ILineSequencer& sequencer);

    // // Destructor
    ~SequenceLineFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const;
protected:
    const Sequence& sequence_;
    const ILineSequencer& sequencer_;
};

#endif /* SEQUENCERLINEFILTER_H */