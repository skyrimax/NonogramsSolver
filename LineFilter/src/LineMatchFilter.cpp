#include "LineMatchFilter.hpp"

#include <stdexcept>
#include <string>

LineMatchFilter::LineMatchFilter(const ReferenceLine& lineToMatch)
    : LineFillFilter(lineToMatch), LineEmptyFilter(lineToMatch)
{

}

bool LineMatchFilter::operator()(LineMatchFilter::Line line) const
{
    return LineFillFilter::operator()(line) && LineEmptyFilter::operator()(line);
}