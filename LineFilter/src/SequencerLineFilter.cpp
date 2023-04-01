#include "SequencerLineFilter.hpp"

SequencerLineFilter::SequencerLineFilter(ILineSequencer& sequencer)
    : sequencer_{sequencer}
{

}

bool SequencerLineFilter::operator()(Line line, Sequence sequence)
{
    return sequencer_(line) == sequence;
}