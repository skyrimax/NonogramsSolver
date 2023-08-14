#include "LineEmptyFilter.hpp"

#include <stdexcept>
#include <string>

LineEmptyFilter::LineEmptyFilter(const ReferenceLine& lineToMatch)
    : lineToMatch_(lineToMatch)
{

}

bool LineEmptyFilter::operator()(LineEmptyFilter::Line line) const
{
    auto lineSize = line.size();
    auto lineToMatchSize = lineToMatch_.size();

    if(lineSize != lineToMatchSize)
        throw(std::logic_error(std::string("Tested line is not the same length as reference line; "
                                            "tested line as length: ") + std::to_string(line.size()) + 
                                            std::string(" and reference line has a length of: ") +
                                            std::to_string(lineToMatch_.size())));

    for(auto i = 0; i < lineSize; ++i){
        if(lineToMatch_[i] == 0 && line[i] != 0)
            return false;
    }

    return true;
}