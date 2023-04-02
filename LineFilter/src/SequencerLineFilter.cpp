#include "SequencerLineFilter.hpp"

SequencerLineFilter::SequencerLineFilter(const Sequence& sequence, const ILineSequencer& sequencer)
    : sequence_{sequence}, sequencer_{sequencer}
{

}

bool SequencerLineFilter::operator()(Line line) const
{
    return sequencer_(line) == sequence_;
}