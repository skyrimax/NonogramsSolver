#include "ILineFilterModifier.hpp"

ILineFilterModifier::ILineFilterModifier(ILineFilter* lineFilter)
    : lineFilter_{lineFilter}
{
    
}

ILineFilterModifier::~ILineFilterModifier()
{
    delete lineFilter_;
}