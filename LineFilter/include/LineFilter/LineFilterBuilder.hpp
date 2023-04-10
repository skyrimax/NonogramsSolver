#ifndef LINEFILTERBUILDER_H
#define LINEFILTERBUILDER_H

#include "ILineFilter.hpp"
#include "ILineSequencer.hpp"

class LineFilterBuilder
{
public:
    // Contructors
    LineFilterBuilder() = default;

    // Destructor
    virtual ~LineFilterBuilder() = default;

    // Building methods
    // Base line filter
    LineFilterBuilder& sequenceLineFilter(ILineFilter::Sequence sequence,
                                            ILineSequencer& sequencer);

    // Line filter modifiers
    LineFilterBuilder& lineFilterInverter();

    // Make line filter
    ILineFilter* makeLineFilter();

    // Reset builder
    LineFilterBuilder& reset();

private:
    ILineFilter* lineFilter_ = nullptr;
};

#endif /* LINEFILTERBUILDER_H */