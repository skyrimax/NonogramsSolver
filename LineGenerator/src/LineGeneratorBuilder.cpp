#include "LineGeneratorBuilder.hpp"

#include "AllPossibleLinesGenerator.hpp"
#include "LineGeneratorFilter.hpp"

#include <stdexcept>

NS::LineGeneratorBuilder::~LineGeneratorBuilder()
{
    delete lineGenerator_;
}

NS::LineGeneratorBuilder& NS::LineGeneratorBuilder::allPossibleLinesGenerator(unsigned int nbBoxes)
{
    if(lineGenerator_)
        throw(std::logic_error("Base line generator has already been created, cannot create AllPossibleLinesGenerator"));
    
    lineGenerator_ = new NS::AllPossibleLinesGenerator(nbBoxes);

    return *this;
}

NS::LineGeneratorBuilder& NS::LineGeneratorBuilder::lineGeneratorFilter(ILineFilter* lineFilter)
{
    if(!lineGenerator_)
        throw(std::logic_error("No base line generator has been created, cannot create LineGeneratorFilter"));

    lineGenerator_ = new NS::LineGeneratorFilter(lineFilter, lineGenerator_);

    return *this;
}

NS::ILineGenerator* NS::LineGeneratorBuilder::makeLineGenerator()
{
    if(!lineGenerator_)
        throw(std::logic_error("No line generator has been created"));

    ILineGenerator* lineGeneratorTemp= lineGenerator_;
    lineGenerator_ = nullptr;

    return lineGeneratorTemp;
}