#ifndef ILINEMATCHFILTER_H
#define ILINEMATCHFILTER_H

#include "LineFillFilter.hpp"
#include "LineEmptyFilter.hpp"

class LineMatchFilter: public LineFillFilter, public LineEmptyFilter
{
public:
    using ReferenceLine = std::vector<int>;

    // Constructors
    LineMatchFilter(const ReferenceLine& lineToMatch);

    // Destructor
    ~LineMatchFilter() = default;

    // Member methods
    virtual bool operator()(Line line) const override;
};

#endif /* ILINEMATCHFILTER_H */