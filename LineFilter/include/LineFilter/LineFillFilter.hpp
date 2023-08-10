#ifndef ILINEFILLFILTER_H
#define ILINEFILLFILTER_H

#include "ILineFilter.hpp"

class LineFillFilter: public ILineFilter
{
public:
    using ReferenceLine = std::vector<int>;

    // Constructors
    LineFillFilter(const ReferenceLine& lineToMatch);

    // Destructor
    ~LineFillFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const override;

protected:
    const ReferenceLine& lineToMatch_;
};

#endif /* ILINEFILLFILTER_H */