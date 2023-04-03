#ifndef SEQUENCERLINEFILTER_H
#define SEQUENCERLINEFILTER_H

#include "ILineFilter.hpp"

#include "ILineSequencer.hpp"

class SequencerLineFilter: public ILineFilter
{
public:
    // Contructors
    SequencerLineFilter(const Sequence& sequence, const ILineSequencer& sequencer);

    // // Destructor
    ~SequencerLineFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const override;
protected:
    const Sequence& sequence_;
    const ILineSequencer& sequencer_;
};

#endif /* SEQUENCERLINEFILTER_H */