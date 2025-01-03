#ifndef SEQUENCERLINEFILTER_H
#define SEQUENCERLINEFILTER_H

#include "ILineFilter.hpp"
#include "ILineSequencer.hpp"

#include <memory>
#include <Sequence.hpp>

class SequenceLineFilter: public ILineFilter
{
public:
    // Contructors
    SequenceLineFilter(std::shared_ptr<const NS::Sequence> sequence, std::shared_ptr<const ILineSequencer> sequencer);

    // // Destructor
    ~SequenceLineFilter() = default;

    // Member methods
    virtual bool operator()(const Line& line) const override;

protected:
    std::shared_ptr<const NS::Sequence> sequence_;
    std::shared_ptr<const ILineSequencer> sequencer_;
};

#endif /* SEQUENCERLINEFILTER_H */