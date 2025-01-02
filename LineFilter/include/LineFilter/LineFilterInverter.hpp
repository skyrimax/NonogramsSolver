#ifndef LINEFILTERINVERTER_H
#define LINEFILTERINVERTER_H

#include "ILineFilterModifier.hpp"

class LineFilterInverter: public ILineFilterModifier
{
public:
    // Constructor
    LineFilterInverter(std::unique_ptr<ILineFilter> lineFilter);

    // Destructor
    virtual ~LineFilterInverter() = default;

    // Member methods
    virtual bool operator()(Line& line) const override;
};

#endif /* LINEFILTERINVERTER_H */