#include "LineGeneratorBuilder.hpp"

LineGeneratorBuilder::~LineGeneratorBuilder()
{
    delete lineGenerator_;
}

LineGeneratorBuilder& LineGeneratorBuilder::allPossibleLinesGenerator()