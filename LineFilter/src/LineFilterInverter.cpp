#include "LineFilterInverter.hpp"

LineFilterInverter::LineFilterInverter(ILineFilter* lineFilter)
    : ILineFilterModifier(lineFilter)
{

}

bool LineFilterInverter::operator()(Line line) const
{
    return !(*lineFilter_)(line);
}