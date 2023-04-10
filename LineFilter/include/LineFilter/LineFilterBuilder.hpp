#ifndef LINEFILTERBUILDER_H
#define LINEFILTERBUILDER_H

#include "ILineFilter.hpp"

class LineFilterBuilder
{
public:
    // Contructors
    LineFilterBuilder() = default;

    // Destructor
    virtual ~LineFilterBuilder() = default;

    // Building methods
    // Base line filter
    LineFilterBuilder& sequenceLineFilter(ILineFilter::Sequence sequence);

    // Line filter modifiers
    LineFilterBuilder& lineFilterInverter();

    // Make line filter
    ILineFilter* makeLineFilter();

    // Reset builder
    LineFilterBuilder& reset();

private:
    ILineFilter* lineFilter_;
};

#endif /* LINEFILTERBUILDER_H */