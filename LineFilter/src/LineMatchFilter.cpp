#include "LineMatchFilter.hpp"

#include <stdexcept>
#include <string>

LineMatchFilter::LineMatchFilter(std::unique_ptr<const ReferenceLine> lineToMatch)
    : lineToMatch_(std::move(lineToMatch))
{

}

bool LineMatchFilter::operator()(const LineMatchFilter::Line& line) const
{
    auto lineSize = line.size();
    auto lineToMatchSize = lineToMatch_->size();

    if(lineSize != lineToMatchSize)
        throw(std::logic_error(std::string("Tested line is not the same length as reference line; "
                                            "tested line as length: ") + std::to_string(line.size()) + 
                                            std::string(" and reference line has a length of: ") +
                                            std::to_string(lineToMatch_->size())));

    for(auto i = 0; i < lineSize; ++i){
        if(lineToMatch_->at(i) == line[i] || line[i] == -1)
            return false;
    }

    return true;
}