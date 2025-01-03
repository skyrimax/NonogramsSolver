#ifndef ILINEFILTERMODIFIER_H
#define ILINEFILTERMODIFIER_H

#include "ILineFilter.hpp"

#include <memory>

class ILineFilterModifier: public ILineFilter
{
public:
    // Constructors
    ILineFilterModifier(std::unique_ptr<ILineFilter> lineFilter);

    // Destructor
    virtual ~ILineFilterModifier();

protected:
    std::unique_ptr<ILineFilter> lineFilter_;
};

#endif /* ILINEFILTERMODIFIER_H */