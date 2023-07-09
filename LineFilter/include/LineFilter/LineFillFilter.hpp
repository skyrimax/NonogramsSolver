#ifndef ILINEFILLFILTER_H
#define ILINEFILLFILTER_H

#include "ILineFilter.hpp"

class ILineFillFilter: public ILineFilter
{
public:
    // Constructors
    ILineFillFilter(Line lineToMatch);

    // Destructor
    ~ILineFillFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const override;

protected:
    const Line& lineToMatch_;
};

#endif /* ILINEFILLFILTER_H */