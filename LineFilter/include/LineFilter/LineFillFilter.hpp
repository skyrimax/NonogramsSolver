#ifndef ILINEFILLFILTER_H
#define ILINEFILLFILTER_H

#include "ILineFilter.hpp"

class LineFillFilter: public ILineFilter
{
public:
    // Constructors
    LineFillFilter(Line lineToMatch);

    // Destructor
    ~LineFillFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const override;

protected:
    const Line& lineToMatch_;
};

#endif /* ILINEFILLFILTER_H */