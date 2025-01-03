#include "LineGeneratorFilter.hpp"

#include <algorithm>

NS::LineGeneratorFilter::LineGeneratorFilter(std::shared_ptr<ILineFilter> lineFilter, std::unique_ptr<ILineGenerator> lineGenerator)
    : ILineGeneratorModifier(std::move(lineGenerator)), lineFilter_(lineFilter)
{

}

NS::LineGeneratorFilter::~LineGeneratorFilter()
{
    
}

std::vector<NS::ILineGenerator::Line> NS::LineGeneratorFilter::generateLines()
{
    auto predicate = [this](Line line) {
        return (*lineFilter_)(line);
    };
    auto lines = lineGenerator_->generateLines();

    lines.erase(std::remove_if(
        lines.begin(), lines.end(),
        predicate
    ), lines.end());

    return lines;
}