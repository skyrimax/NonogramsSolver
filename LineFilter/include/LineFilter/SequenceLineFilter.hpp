#ifndef SEQUENCERLINEFILTER_H
#define SEQUENCERLINEFILTER_H

#include "ILineFilter.hpp"
#include "ILineSequencer.hpp"

#include <Sequence.hpp>

class SequenceLineFilter: public ILineFilter
{
public:
    // Contructors
    SequenceLineFilter(const NS::Sequence& sequence, const ILineSequencer& sequencer);

    // // Destructor
    ~SequenceLineFilter() = default;

    // Member methods
    virtual bool operator()(Line& line) const override;
protected:
    const NS::Sequence& sequence_;
    const ILineSequencer& sequencer_;
};

#endif /* SEQUENCERLINEFILTER_H */