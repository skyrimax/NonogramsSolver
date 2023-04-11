#include "LineGeneratorFilter.hpp"

#include <algorithm>

NS::LineGeneratorFilter::LineGeneratorFilter(ILineFilter* lineFilter, ILineGenerator* lineGenerator)
    : ILineGeneratorModifier{lineGenerator}, lineFilter_{lineFilter}
{

}

NS::LineGeneratorFilter::~LineGeneratorFilter()
{
    delete lineFilter_;
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