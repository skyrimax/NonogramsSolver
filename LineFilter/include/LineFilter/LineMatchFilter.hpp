#ifndef ILINEMATCHFILTER_H
#define ILINEMATCHFILTER_H

#include "LineFillFilter.hpp"
#include "LineEmptyFilter.hpp"

class LineMatchFilter: public ILineFilter
{
public:
    using ReferenceLine = std::vector<int>;

    // Constructors
    LineMatchFilter(std::shared_ptr<const ReferenceLine> lineToMatch);

    // Destructor
    ~LineMatchFilter() = default;

    // Member methods
    virtual bool operator()(const Line& line) const override;

protected:
    const std::shared_ptr<const ReferenceLine> lineToMatch_;
};

#endif /* ILINEMATCHFILTER_H */