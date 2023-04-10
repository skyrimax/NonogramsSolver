#include "SequenceLineFilter.hpp"

SequenceLineFilter::SequenceLineFilter(const Sequence& sequence, const ILineSequencer& sequencer)
    : sequence_{sequence}, sequencer_{sequencer}
{

}

bool SequenceLineFilter::operator()(Line line) const
{
    return sequencer_(line) == sequence_;
}