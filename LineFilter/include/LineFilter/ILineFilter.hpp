#ifndef ILINEFILTER_H
#define ILINEFILTER_H

#include <vector>

class ILineFilter
{
public:
    using Sequence = std::vector<unsigned int>;
    using Line = std::vector<unsigned int>;

    // Contructors
    ILineFilter() = default;

    // Destructor
    ~ILineFilter() = default;

    // Member methods
    virtual bool operator()(Line line, Sequence sequence) = 0;
};

#endif /* ILINEFILTER_H */