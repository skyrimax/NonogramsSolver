#ifndef SEQUENCERLINEFILTER_H
#define SEQUENCERLINEFILTER_H

#include "ILineFilter.hpp"

#include "ILineSequencer.hpp"

class SequencerLineFilter: ILineFilter
{
public:
    // Contructors
    SequencerLineFilter(ILineSequencer& sequencer);

    // // Destructor
    ~SequencerLineFilter() = default;

    // Member methods
    virtual bool operator()(Line line, Sequence sequence);
protected:
    ILineSequencer& sequencer_;
};

#endif /* SEQUENCERLINEFILTER_H */