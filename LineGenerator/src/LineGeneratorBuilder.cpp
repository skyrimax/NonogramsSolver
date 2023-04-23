#include "LineGeneratorBuilder.hpp"

#include "AllPossibleLinesGenerator.hpp"

#include <stdexcept>

LineGeneratorBuilder::~LineGeneratorBuilder()
{
    delete lineGenerator_;
}

LineGeneratorBuilder& LineGeneratorBuilder::allPossibleLinesGenerator(unsigned int nbBoxes)
{
    if(lineGenerator_)
        throw(std::logic_error("Base line generator has already been created, cannot create AllPossibleLinesGenerator"));
    
    lineGenerator_ = new NS::AllPossibleLinesGenerator(nbBoxes);

    return *this;
}