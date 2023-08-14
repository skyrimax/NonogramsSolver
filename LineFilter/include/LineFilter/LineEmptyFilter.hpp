#ifndef ILINEEMPTYFILTER_H
#define ILINEEMPTYFILTER_H

#include "ILineFilter.hpp"

class LineEmptyFilter: public ILineFilter
{
public:
    using ReferenceLine = std::vector<int>;

    // Constructors
    LineEmptyFilter(const ReferenceLine& lineToMatch);

    // Destructor
    ~LineEmptyFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const override;

protected:
    const ReferenceLine& lineToMatch_;
};

#endif /* ILINEEMPTYFILTER_H */