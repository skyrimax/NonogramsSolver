#ifndef ILINEEMPTYFILTER_H
#define ILINEEMPTYFILTER_H

#include "ILineFilter.hpp"

#include <memory>

class LineEmptyFilter: public ILineFilter
{
public:
    using ReferenceLine = std::vector<int>;

    // Constructors
    LineEmptyFilter(std::shared_ptr<const ReferenceLine> lineToMatch);

    // Destructor
    ~LineEmptyFilter() = default;

    // Member methods
    virtual bool operator()(const Line& line) const override;

protected:
    const std::shared_ptr<const ReferenceLine> lineToMatch_;
};

#endif /* ILINEEMPTYFILTER_H */