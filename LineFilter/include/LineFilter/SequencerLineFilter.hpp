#ifndef SEQUENCERLINEFILTER_H
#define SEQUENCERLINEFILTER_H

#include "ILineFilter.hpp"

#include "ILineSequencer.hpp"

class SequencerLineFilter: ILineFilter
{
public:
    // Contructors
    SequencerLineFilter(const Sequence& sequence, const ILineSequencer& sequencer);

    // // Destructor
    ~SequencerLineFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const;
protected:
    const Sequence& sequence_;
    const ILineSequencer& sequencer_;
};

#endif /* SEQUENCERLINEFILTER_H */