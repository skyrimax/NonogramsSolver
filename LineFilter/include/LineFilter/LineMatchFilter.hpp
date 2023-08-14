#ifndef ILINEMATCHFILTER_H
#define ILINEMATCHFILTER_H

#include "ILineFilter.hpp"

class LineMatchFilter: public ILineFilter
{
public:
    using ReferenceLine = std::vector<int>;

    // Constructors
    LineMatchFilter(const ReferenceLine& lineToMatch);

    // Destructor
    ~LineMatchFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const override;

protected:
    const ReferenceLine& lineToMatch_;
};

#endif /* ILINEMATCHFILTER_H */