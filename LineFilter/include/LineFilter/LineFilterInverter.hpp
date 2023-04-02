#ifndef LINEFILTERINVERTER_H
#define LINEFILTERINVERTER_H

#include "ILineFilterModifier.hpp"

class LineFilterInverter: public ILineFilterModifier
{
public:
    // Constructor
    LineFilterInverter(ILineFilter* lineFilter);

    // Destructor
    virtual ~LineFilterInverter() = default;

    // Member methods
    virtual bool operator()(Line line) const;
};

#endif /* LINEFILTERINVERTER_H */