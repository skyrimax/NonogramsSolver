#ifndef ILINEFILTERMODIFIER_H
#define ILINEFILTERMODIFIER_H

#include "ILineFilter.hpp"

class ILineFilterModifier: ILineFilter
{
public:
    // Constructors
    ILineFilterModifier(ILineFilter* lineFilter);

    // Destructor
    virtual ~ILineFilterModifier();

private:
    ILineFilter* lineFilter_;
};

#endif() /* ILINEFILTERMODIFIER_H */