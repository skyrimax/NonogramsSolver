#include "SequenceLineFilter.hpp"

SequenceLineFilter::SequenceLineFilter(std::shared_ptr<const NS::Sequence> sequence, std::shared_ptr<const ILineSequencer> sequencer)
    : sequence_{sequence}, sequencer_{sequencer}
{

}

bool SequenceLineFilter::operator()(const Line& line) const
{
    return (*sequencer_)(line) == *sequence_;
}