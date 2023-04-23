#include "LineGeneratorBuilder.hpp"

#include "AllPossibleLinesGenerator.hpp"

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

NS::LineGeneratorBuilder& 