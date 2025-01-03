#ifndef ILINEFILLFILTER_H
#define ILINEFILLFILTER_H

#include "ILineFilter.hpp"

#include <memory>

class LineFillFilter: public ILineFilter
{
public:
    using ReferenceLine = std::vector<int>;

    // Constructors
    LineFillFilter(std::shared_ptr<const ReferenceLine> lineToMatch);

    // Destructor
    ~LineFillFilter() = default;

    // Member methods
    virtual bool operator()(const Line& line) const override;

protected:
    std::shared_ptr<const ReferenceLine> lineToMatch_;
};

#endif /* ILINEFILLFILTER_H */