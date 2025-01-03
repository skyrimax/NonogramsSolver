#include "LineGeneratorBuilder.hpp"

#include "AllPossibleLinesGenerator.hpp"
#include "LineGeneratorFilter.hpp"

#include <stdexcept>

NS::LineGeneratorBuilder& NS::LineGeneratorBuilder::allPossibleLinesGenerator(unsigned int nbBoxes)
{
    if(lineGenerator_)
        throw(std::logic_error("Base line generator has already been created, cannot create AllPossibleLinesGenerator"));
    
    lineGenerator_ = std::make_unique<NS::AllPossibleLinesGenerator>(nbBoxes);

    return *this;
}

NS::LineGeneratorBuilder& NS::LineGeneratorBuilder::lineGeneratorFilter(std::shared_ptr<ILineFilter> lineFilter)
{
    if(!lineGenerator_)
        throw(std::logic_error("No base line generator has been created, cannot create LineGeneratorFilter"));

    lineGenerator_ = std::make_unique<NS::LineGeneratorFilter>(lineFilter, std::move(lineGenerator_));

    return *this;
}

std::unique_ptr<NS::ILineGenerator> NS::LineGeneratorBuilder::makeLineGenerator()
{
    if(!lineGenerator_)
        throw(std::logic_error("No line generator has been created"));

    return std::move(lineGenerator_);
}

NS::LineGeneratorBuilder& NS::LineGeneratorBuilder::reset()
{
    lineGenerator_.reset(nullptr);

    return *this;
}