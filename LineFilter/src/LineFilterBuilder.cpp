#include "LineFilterBuilder.hpp"

#include "SequenceLineFilter.hpp"
#include "LineFilterInverter.hpp"

#include <stdexcept>

LineFilterBuilder& LineFilterBuilder::sequenceLineFilter(std::shared_ptr<const NS::Sequence> sequence, std::shared_ptr<const ILineSequencer> sequencer)
{
    if(lineFilter_)
        throw(std::logic_error("Base line filter has already been created, cannot create SequenceLineFilter"));
    
    lineFilter_ = std::make_unique<SequenceLineFilter>(sequence, sequencer);

    return *this;
}

LineFilterBuilder& LineFilterBuilder::lineFilterInverter()
{
    if(!lineFilter_)
        throw(std::logic_error("No base line filter has been created, cannot create LineFilterInverter"));

    lineFilter_ = std::make_unique<LineFilterInverter>(std::move(lineFilter_));

    return *this;
}

std::unique_ptr<ILineFilter> LineFilterBuilder::makeLineFilter()
{
    if(!lineFilter_)
        throw(std::logic_error("No line filter has been created"));

    return std::move(lineFilter_);
}

LineFilterBuilder& LineFilterBuilder::reset()
{
    lineFilter_.reset(nullptr);

    return *this;
}