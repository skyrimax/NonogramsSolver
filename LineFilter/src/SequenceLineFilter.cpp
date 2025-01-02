#include "SequenceLineFilter.hpp"

SequenceLineFilter::SequenceLineFilter(const NS::Sequence& sequence, const ILineSequencer& sequencer)
    : sequence_{sequence}, sequencer_{sequencer}
{

}

bool SequenceLineFilter::operator()(const Line& line) const
{
    return sequencer_(line) == sequence_;
}