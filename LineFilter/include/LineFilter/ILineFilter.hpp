#ifndef ILINEFILTER_H
#define ILINEFILTER_H

#include <vector>

class ILineFilter
{
public:
    using Line = std::vector<unsigned int>;

    // Contructors
    ILineFilter() = default;

    // Destructor
    virtual ~ILineFilter() = default;

    // Member methods
    virtual bool operator()(Line& line) const = 0;
};

#endif /* ILINEFILTER_H */