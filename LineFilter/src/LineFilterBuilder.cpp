#include "LineFilterBuilder.hpp"

#include "SequenceLineFilter.hpp"
#include "LineFilterInverter.hpp"

#include <stdexcept>

LineFilterBuilder& LineFilterBuilder::sequenceLineFilter(ILineFilter::Sequence sequence, ILineSequencer& sequencer)
{
    if(lineFilter_)
        throw(std::logic_error("Base line filter has already been created, cannot create SequenceLineFilter"));
    
    lineFilter_ = new SequenceLineFilter(sequence, sequencer);

    return *this;
}

LineFilterBuilder& LineFilterBuilder::lineFilterInverter()
{
    if(!lineFilter_)
        throw(std::logic_error("No base line filter has been created, cannot create LineFilterInverter"));

    lineFilter_ = new LineFilterInverter(lineFilter_);

    return *this;
}

ILineFilter* LineFilterBuilder::makeLineFilter()
{
    if(!lineFilter_)
        throw(std::logic_error("No line filter has been created"));

    ILineFilter* lineFilterTemp= lineFilter_;
    lineFilter_ = nullptr;

    return lineFilterTemp;
}

LineFilterBuilder& LineFilterBuilder::reset()
{
    delete lineFilter_;

    lineFilter_ = nullptr;

    return *this;
}