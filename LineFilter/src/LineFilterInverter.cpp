#include "LineFilterInverter.hpp"

LineFilterInverter::LineFilterInverter(std::unique_ptr<ILineFilter> lineFilter)
    : ILineFilterModifier(std::move(lineFilter))
{

}

bool LineFilterInverter::operator()(const Line& line) const
{
    return !(*lineFilter_)(line);
}