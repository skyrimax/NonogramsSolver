#include "ILineFilterModifier.hpp"

ILineFilterModifier::ILineFilterModifier(std::unique_ptr<ILineFilter> lineFilter)
    : lineFilter_(std::move(lineFilter))
{
    
}

ILineFilterModifier::~ILineFilterModifier()
{

}