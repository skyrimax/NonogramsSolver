#ifndef LINEFILTERBUILDER_H
#define LINEFILTERBUILDER_H

#include "ILineFilter.hpp"
#include "ILineSequencer.hpp"

#include <memory>
#include <Sequence.hpp>

class LineFilterBuilder
{
public:
    // Contructors
    LineFilterBuilder() = default;

    // Destructor
    virtual ~LineFilterBuilder() = default;

    // Building methods
    // Base line filter
    LineFilterBuilder& sequenceLineFilter(std::shared_ptr<const NS::Sequence> sequence,
                                            std::shared_ptr<const ILineSequencer> sequencer);

    // Line filter modifiers
    LineFilterBuilder& lineFilterInverter();

    // Make line filter
    std::unique_ptr<ILineFilter> makeLineFilter();

    // Reset builder
    LineFilterBuilder& reset();

private:
    std::unique_ptr<ILineFilter> lineFilter_ = std::unique_ptr<ILineFilter>();
};

#endif /* LINEFILTERBUILDER_H */